
from collections import deque

a = int(input("Enter Jug A capacity: "))
b = int(input("Enter Jug B capacity: "))
target = int(input("Enter target amount: "))

queue = deque([(0, 0)])
visited = {(0, 0)}
parent = {(0, 0): None}
steps = {}

goal = None

while queue:
    x, y = queue.popleft()

    if x == target or y == target:
        goal = (x, y)
        break

    moves = [
        ((a, y), "Fill A"),
        ((x, b), "Fill B"),
        ((0, y), "Empty A"),
        ((x, 0), "Empty B"),
        ((x - min(x, b-y), y + min(x, b-y)), "Pour A to B"),
        ((x + min(y, a-x), y - min(y, a-x)), "Pour B to A")
    ]

    for state, move in moves:
        if state not in visited:
            visited.add(state)
            parent[state] = (x, y)
            steps[state] = move
            queue.append(state)

if goal:
    path = []
    current = goal

    while current != (0, 0):
        path.append((steps[current], current))
        current = parent[current]

    path.reverse()

    print("\nSolution:")
    print("Step 0: (0, 0)")

    for i, (move, state) in enumerate(path, 1):
        print(f"Step {i}: {move} -> {state}")

    print("\nFinal Answer:", goal)
else:
    print("Solution not possible")

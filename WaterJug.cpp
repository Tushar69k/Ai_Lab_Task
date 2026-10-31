
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    int a, b, target;

    cout << "Enter Jug A capacity: ";
    cin >> a;

    cout << "Enter Jug B capacity: ";
    cin >> b;

    cout << "Enter target amount: ";
    cin >> target;

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;

    q.push({0, 0});
    visited.insert({0, 0});

    int step = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        step++;
        cout << "Step " << step << ": Jug A = " << x
             << ", Jug B = " << y << endl;

        if (x == target || y == target) {
            cout << "Target reached!";
            return 0;
        }

        int pour = min(x, b - y);
        int pourBack = min(y, a - x);

        pair<int, int> moves[] = {
            {a, y},                  // Fill Jug A
            {x, b},                  // Fill Jug B
            {0, y},                  // Empty Jug A
            {x, 0},                  // Empty Jug B
            {x - pour, y + pour},    // Pour A into B
            {x + pourBack, y - pourBack} // Pour B into A
        };

        for (auto next : moves) {
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
            }
        }
    }

    cout << "Target cannot be reached.";
    return 0;
}

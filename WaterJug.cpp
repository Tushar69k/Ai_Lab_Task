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

    cout << "Enter target: ";
    cin >> target;

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;

    q.push({0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cout << "(" << x << ", " << y << ")" << endl;

        if (x == target || y == target) {
            cout << "Target reached!";
            return 0;
        }

        pair<int, int> moves[] = {
            {a, y},
            {x, b},
            {0, y},
            {x, 0},
            {x - min(x, b-y), y + min(x, b-y)},
            {x + min(y, a-x), y - min(y, a-x)}
        };

        for (auto next : moves) {
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
            }
        }
    }

    cout << "Solution not possible";

    return 0;
}
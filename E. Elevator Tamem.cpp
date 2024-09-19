#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N + 1);
    vector<bool> elevator_status(4, true); // Elevator 1, 2, dan 3
    vector<int> current_floor(4, 1); // Elevator 1, 2, dan 3
    int total_cost = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int day = 1; day <= Q; day++) {
        int event_type;
        cin >> event_type;

        if (event_type == 1) {
            int x, y;
            cin >> x >> y;
            int min_cost = INT_MAX;
            int chosen_elevator = -1;

            for (int elevator = 1; elevator <= 3; elevator++) {
                if (elevator_status[elevator]) {
                    int cost = abs(current_floor[elevator] - x) + abs(x - y);
                    if (cost < min_cost) {
                        min_cost = cost;
                        chosen_elevator = elevator;
                    }
                }
            }

            total_cost += min_cost;
            current_floor[chosen_elevator] = y;
        } else if (event_type == 2) {
            int p;
            cin >> p;
            elevator_status[p] = !elevator_status[p];
        }
    }

    cout << total_cost << endl;

    return 0;
}

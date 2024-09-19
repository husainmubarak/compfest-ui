#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int total_uang = 0;

    for (int p = 0; p <= M - K; p++) {
        vector<pair<int, pair<int, int>>> options; 

        for (int i = 0; i < N; i++) {
            for (int y = p; y < p + K; y++) {
                options.push_back({A[i][y], {i, y}});
            }
        }

        auto max_option = max_element(options.begin(), options.end());
        total_uang += max_option->first;

        A[max_option->second.first][max_option->second.second] = 0;
    }

    cout << total_uang << endl;
}

#pragma warning(disable:4996)

#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int Tc;
int N, M, W;
int S, E, T;
vector<pair<int, int>> v[501];
int arr[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Tc;

    for (int t = 0; t < Tc; t++) {
        cin >> N >> M >> W;
        for (int i = 1; i <= N; i++) {
            arr[i] = INF;
            v[i].clear();
        }
        arr[1] = 0;
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            v[S].push_back({E, T});
            v[E].push_back({S, T});
        }
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            v[S].push_back({E, -T});
        }
        bool cycle = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 0; k < v[j].size(); k++) {
                    if (arr[v[j][k].first] > arr[j] + v[j][k].second) {
                        arr[v[j][k].first] = arr[j] + v[j][k].second;
                        if (i == N)
                            cycle = true;
                    }
                }
            }
        }

        cycle ? cout << "YES\n" : cout << "NO\n";
    }


    return 0;
}

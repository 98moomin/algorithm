#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, M;
int a, b, c;
int arr[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            i == j ? arr[i][j] = 0 : arr[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for (int i = 1; i <= N; i++) { //거쳐가는 노드
        for (int j = 1; j <= N; j++) { //출발 노드
            for (int k = 1; k <= N; k++) { //도착 노드
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] == INF ? cout << "0 ": cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

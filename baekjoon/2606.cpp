#pragma warning(disable:4996)

#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
bool visited[101];
int n, m, cnt;

void dfs(int currNode) {
    visited[currNode] = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && arr[currNode][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        arr[s][e] = arr[e][s] = 1;
    }

    dfs(1);

    for(int i=2;i<=n;i++){
        if(visited[i])
            cnt++;
    }

    cout << cnt;

    return 0;
}
#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int arr[1001][1001];
bool visited[1001];
queue<int> q;
int n, m, v;

void dfs(int currNode) {
    visited[currNode] = true;
    cout << currNode << " ";
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && arr[currNode][i] == 1) {
            dfs(i);
        }
    }
}

void bfs() {
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        cout << currNode << " ";
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && arr[currNode][i] == 1) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        arr[s][e] = arr[e][s] = 1;
    }

    dfs(v);
    cout << "\n";
    memset(visited, false, sizeof(visited));
    bfs();

    return 0;
}
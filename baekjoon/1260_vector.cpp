#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
bool visited[1001];
vector<int> v[1001];
queue<int> q;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << " ";
    for (int i = 0; i < v[cur].size(); i++) {
        if (!visited[v[cur][i]])
            dfs(v[cur][i]);
    }
}

void bfs() {
    q.push(V);
    visited[V] = false;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < v[node].size(); i++) {
            if (visited[v[node][i]]) {
                q.push(v[node][i]);
                visited[v[node][i]] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(V);

    cout << "\n";

    bfs();

    return 0;
}

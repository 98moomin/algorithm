#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
int u, v, w;
bool visited[20001];
int arr[20001];
vector<pair<int, int>> v1[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


void dijkstra(int start) {
    for (int i = 0; i < v1[start].size(); i++) {
        pq.push({v1[start][i].first, v1[start][i].second});
    }
    arr[start] = 0;
    while (!pq.empty()) {
        int edge = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(visited[edge])
            continue;
        visited[edge] = true;
        if (arr[edge] > dist)
            arr[edge] = dist;
        for (int i = 0; i < v1[edge].size(); i++) {
            if (!visited[v1[edge][i].second]) {
                pq.push({v1[edge][i].first + dist, v1[edge][i].second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        v1[u].push_back({w, v});
    }

    for (int i = 1; i < V + 1; i++) {
        arr[i] = 1111111111;
    }

    dijkstra(K);

    for (int i = 1; i < V + 1; i++) {
        if (arr[i] == 1111111111)
            cout << "INF\n";
        else
            cout << arr[i] << "\n";
    }

    return 0;
}

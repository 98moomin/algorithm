#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int N, M;
int s, e, w;
int start, goal;
bool visited[1001];
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start) {
    for (int i = 0; i < v[start].size(); i++) {
        pq.push(v[start][i]);
    }
    while (!pq.empty()) {
        int edge = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if (visited[edge])
            continue;
        visited[edge] = true;
        if (edge == goal) {
            cout << dist;
            return;
        }
        for (int i = 0; i < v[edge].size(); i++) {
            if (!visited[v[edge][i].second]) {
                pq.push({v[edge][i].first + dist, v[edge][i].second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> s >> e >> w;
        v[s].push_back({w, e});
    }

    cin >> start >> goal;

    dijkstra(start);

    return 0;
}
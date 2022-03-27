#pragma warning(disalbe:4996)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b, m;
int visited[101];
vector<int> v[101];
queue<int> q;

void bfs() {
	q.push(a);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			if (!visited[v[node][i]]) {
				q.push(v[node][i]);
				visited[v[node][i]] = visited[node] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs();

	if (visited[b] == 0)
		cout << "-1";
	else
		cout << visited[b];

	return 0;
}
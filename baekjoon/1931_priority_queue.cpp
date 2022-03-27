#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        pq.push({e, s});
    }

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        int start = pq.top().first;
        int end = pq.top().second;
        pq.pop();
        if(end >= tmp){
            tmp = start;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
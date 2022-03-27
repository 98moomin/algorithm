#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, p, cnt;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    int start = v[0];

    for (int i = 1; i < N; i++) {
        if (v[i] - start >= L) {
            cnt++;
            start = v[i];
        }
    }

    cout << cnt + 1;

    return 0;
}
#pragma warning(disable:4996)
#define ll long long

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N, l;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        cin >> l;
        v.push_back(l);
    }

    sort(v.begin(), v.end(), greater<int>());

    ll low = 1;
    ll high = v[0];
    ll mid;

    while (low <= high) {
        mid = (low + high) / 2;
        ll sum = 0;
        for (int i = 0; i < K; i++) {
            sum += v[i] / mid;
        }
        if (sum >= N)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << low - 1;

    return 0;
}
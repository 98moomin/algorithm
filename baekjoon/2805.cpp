#pragma warning(disable:4996)
#define ll long long

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, greater<ll>());

    ll low = 0;
    ll high = arr[0];
    ll mid;

    while (low + 1 < high) {
        mid = (low + high) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] - mid < 0)
                break;
            sum += arr[i] - mid;
        }
        if (sum >= M)
            low = mid;
        else
            high = mid;
    }

    cout << low;

    return 0;
}
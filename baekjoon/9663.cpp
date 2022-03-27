#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int N, ans;
int arr[16];

bool check(int p) {
    for (int i = 0; i < p; i++) {
        if (arr[i] == arr[p] || abs(arr[i] - arr[p]) == p - i)
            return false;
    }
    return true;
}

void nQueen(int cnt) {
    if (cnt == N) {
        ans++;
        return;
    }
    else {
        for (int i = 0; i < N; i++) {
            arr[cnt] = i;
            if (check(cnt))
                nQueen(cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    nQueen(0);

    cout << ans;

    return 0;
}
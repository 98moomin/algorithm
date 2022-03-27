#include <iostream>

using namespace std;

int n, s, arr[20];
int sum, cnt;

void DFS(int start, int sum) {
    if (start == n)
        return;
    sum += arr[start];
    if (sum == s)
        cnt++;
    DFS(start + 1, sum);
    DFS(start + 1, sum - arr[start]);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    DFS(0, 0);
    cout << cnt << '\n';
}
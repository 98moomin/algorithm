#include <iostream>

using namespace std;

int n, m;
int low, high, cnt, sum;
int arr[10000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sum = arr[0];
    while (high < n) {
        if (sum < m) {
            sum += arr[++high];
        }
        else if (sum == m) {
            cnt++;
            sum += arr[++high];
        }
        else {
            sum -= arr[low++];
        }
    }
    cout << cnt << '\n';
}

#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = n; i > 0; i--) {
        cout << i << "\n";
    }

    return 0;
}
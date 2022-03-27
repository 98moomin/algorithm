#pragma warning(disable:4996)

#include <iostream>
#include <string.h>

using namespace std;
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("cycle.inp", "r", stdin);
    freopen("cycle.out", "w", stdout);
    
    while (1) {
        cin >> a >> b;

        if (cin.eof()) break;

        cout << a << " " << b << " ";

        int tmp;
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }

        int max = 0, cnt, j;
        for (int i = a; i <= b; i++) {
            cnt = 1;
            j = i;
            while (j > 1) {
                if (j % 2 != 0) {
                    j = 3 * j + 1;
                }
                else {
                    j /= 2;
                }
                cnt++;
            }
            if (cnt > max) max = cnt;
        }

        cout << max << "\n";
    }

    return 0;
}
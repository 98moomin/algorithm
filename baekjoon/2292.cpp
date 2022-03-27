#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 1, tmp = 1;
    while(1){
        if(tmp >= n){
            break;
        }
        tmp += cnt * 6;
        cnt++;
    }

    cout << cnt;

    return 0;
}
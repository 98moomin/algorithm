#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++)
            cout << " ";
        for(int j=0;j<=i;j++)
            cout << "*";
        cout << "\n";
    }

    return 0;
}
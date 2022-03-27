#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a;
    cin >> b;
    int tmp = b%100%10;
    cout << a*tmp << "\n";
    tmp = b%100/10;
    cout << a*tmp << "\n";
    tmp = b/100;
    cout << a*tmp << "\n";
    cout << a*b << "\n";
}

#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    
    cin >> a >> b;
    if (1 <= a || b >= 10,000)
        return 0;
    
    cout << a+b << endl;
    cout << a-b << endl;
    cout << a*b << endl;
    cout << a/b << endl;
    cout << a%b << endl;
    
    return 0;
}

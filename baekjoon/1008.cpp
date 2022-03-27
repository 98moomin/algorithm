#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    double result;
    cin >> a >> b;
    if (a < 0 || b > 10)
        return 0;
    result = (double)a / b;
    cout.precision(15);
    cout << result << endl;

    return 0;
}

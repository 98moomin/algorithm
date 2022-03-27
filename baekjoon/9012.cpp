#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;

int main(void)
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int T = 0; T < t; T++)
    {
        string v;
        cin >> v;
        for (int j = 0; j < v.length(); j++) {
            if (v[j] == ')') {
                if (s.empty()) {
                    s.push('a');
                    break;
                }
                s.pop();
            }
            else {
                s.push(v[j]);
            }
        }
        if (s.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        while (!s.empty()) s.pop();
    }

    return 0;
}
#pragma warning(disable:4996)

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;

    for (int T = 0; T < n; T++) {
        string s;
        cin >> s;
        bool check = true;
        bool visited[26] = { false, };
        for (int i = 0; i < s.length(); i++) {
            if (visited[s[i] - 'a']) {
                check = false;
                break;
            }
            else {
                visited[s[i] - 'a'] = true;
                char tmp = s[i];
                while (1) {
                    if (s[i] == tmp)
                        i++;
                    else
                        break;
                }
                i--;
            }
        }
        if (check)
            cnt++;
    }

    cout << cnt;

    return 0;
}
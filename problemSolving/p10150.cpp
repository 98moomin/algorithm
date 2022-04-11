#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool blank, check;
bool visited[25144];
int idx;
int arr[25144];
string word, first, second;
vector<string> dict;
vector<string> ans;
queue<pair<int, string>> q;

bool isDoublets(string str1, string str2) {
    int cnt = 0;
    
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i])
            cnt++;
        if (cnt > 1)
            return false;
    }
    
    if (cnt == 1)
        return true;
    
    return false;
}

void bfs(string first, string second, int startIdx) {
    bool flag = false;
    int endIdx = 0;

    memset(arr, -1, sizeof(arr));
    memset(visited, false, sizeof(visited));

    while (!q.empty()) {
        q.pop();
    }

    q.push({ startIdx, first });

    while (!q.empty()) {
        int idx = q.front().first;
        string tmp = q.front().second;
        q.pop();

        if (tmp.compare(second) == 0) {
            ans.push_back(second);
            endIdx = idx;
            flag = true;
            while (arr[endIdx] != -1) {
                tmp = dict[arr[endIdx]];
                endIdx = arr[endIdx];
                ans.push_back(tmp);
            }
            for (int i = ans.size() - 1; i > -1; i--) {
                cout << ans[i] << "\n";
            }
            ans.clear();
            break;
        }

        if (visited[idx])
            continue;

        visited[idx] = true;
        for (int i = 0; i < dict.size(); i++) {
            if (tmp.length() == dict[i].length() && isDoublets(tmp, dict[i]) && !visited[i]) {
                q.push({ i, dict[i] });
                if (arr[i] == -1)
                    arr[i] = idx;
            }
        }
    }
    if (!flag)
        cout << "No solution.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("p10150.inp", "r", stdin);
    freopen("p10150.out", "w", stdout);

    while (1) {
        getline(cin, word);
        if (word == "")
            break;
        dict.push_back(word);
    }

    while (cin >> first >> second) {
        if (blank)
            cout << "\n";
        blank = true;
        if (first.compare(second) == 0) {
            cout << first << "\n" << first << "\n";
        }
        if (first.length() != second.length()) {
            cout << "No solution.\n";
            continue;
        }
        check = false;
        idx = 0;
        for (int i = 0; i < dict.size(); i++) {
            if (first.compare(dict[i]) == 0) {
                check = true;
                idx = i;
            }
        }
        if (!check)
            continue;

        check = false;
        for (int i = 0; i < dict.size(); i++) {
            if (second.compare(dict[i]) == 0)
                check = true;
        }
        if (!check)
            continue;

        bfs(first, second, idx);
    }

    return 0;
}
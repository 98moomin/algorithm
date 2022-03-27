#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10][10];
int cnt;
bool flag;
vector<pair<int, int>> v;

bool check(pair<int, int> p) {
    for (int i = 0; i < 9; i++) {
        if ((arr[i][p.second] == arr[p.first][p.second] && i != p.first) || (arr[p.first][i] == arr[p.first][p.second] && i != p.second))
            return false;
    }
    int tmpx = p.first / 3;
    int tmpy = p.second / 3;
    for (int i = tmpx * 3; i < tmpx * 3 + 3; i++) {
        for (int j = tmpy * 3; j < tmpy * 3 + 3; j++) {
            if (arr[i][j] == arr[p.first][p.second] && (i != p.first && j != p.second))
                return false;
        }
    }
    return true;
}

void sudoku(int n) {
    if (n == cnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    for (int i = 1; i < 10; i++) {
        arr[v[n].first][v[n].second] = i;
        if (check(v[n]))
            sudoku(n + 1);
        if (flag)
            return;
        else
            arr[v[n].first][v[n].second] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                v.push_back({ i, j });
                cnt++;
            }
        }
    }

    sudoku(0);

    return 0;
}
#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>

using namespace std;

int L, P, V, T, days;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;
        days = 0;
        days = V / P * L;
        days += V % P > L ? L : V % P;
        cout << "Case " << ++T << ": " << days << "\n";
    }

    return 0;
}
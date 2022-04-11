#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int N;
string inp;

bool isSlump(string str) {
	regex slump("^([DE]F+)+G$");

	return regex_match(str, slump);;
}

bool isSlimp(string str) {
	if (str.length() == 2) {
		if (str[1] == 'H')
			return true;
		else
			return false;
	}
	
	if (str[str.length() - 1] != 'C')
		return false;

	if (str[1] == 'B')
		return isSlimp(str.substr(2, str.length() - 3));
	else
		return isSlump(str.substr(1, str.length() - 2));
	
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	cout << "SLURPYS OUTPUT\n";
	for (int t = 0; t < N; t++) {
		cin >> inp;

		if (inp[0] != 'A' || inp.length() < 5) {
			cout << "NO\n";
			continue;
		}

		int slumpIdx = 0;
		bool check = false;
		while (1) {
			bool flag = false;
			for (int i = slumpIdx + 1; i < inp.length(); i++) {
				if (inp[i] == 'H' || inp[i] == 'C') {
					flag = true;
					slumpIdx = i;
					break;
				}
			}
			if (!flag)
				break;

			if (isSlimp(inp.substr(0, slumpIdx + 1))) {
				if (isSlump(inp.substr(slumpIdx + 1, inp.length() - slumpIdx))) {
					check = true;
					break;
				}				
			}
		}
		if (check)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	cout << "END OF OUTPUT";

	return 0;
}
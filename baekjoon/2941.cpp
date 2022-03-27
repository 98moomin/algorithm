#pragma warning(disable:4996)

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<s.length();i++){
        bool check = false;
        if(s[i] == 'c'){
            if(s[i+1] == '='){
                i++;
                cnt++;
                check = true;
            }
            if(s[i+1] == '-'){
                i++;
                cnt++;
                check = true;
            }
        }
        if(s[i] == 'd'){
            if(s[i+1] == 'z' && s[i+2] == '='){
                i += 2;
                cnt++;
                check = true;
            }
            if(s[i+1] == '-'){
                i++;
                cnt++;
                check = true;
            }
        }
        if(s[i] == 'l' && s[i+1] == 'j'){
            i++;
            cnt++;
            check = true;
        }
        if(s[i] == 'n' && s[i+1] == 'j'){
            i++;
            cnt++;
            check = true;
        }
        if(s[i] == 's' && s[i+1] == '='){
            i++;
            cnt++;
            check = true;
        }
        if(s[i] == 'z' && s[i+1] == '='){
            i++;
            cnt++;
            check = true;
        }
        if(!check)
            cnt++;
    }

    cout << cnt;

    return 0;
}
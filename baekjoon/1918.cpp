#pragma warning(disable:4996)

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> op;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for(int i=0;i<s.length();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            cout << s[i];
        }
        else {
            if(s[i] == '(')
                op.push(s[i]);
            else if(s[i] == ')'){
                while(!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
            else if(s[i] == '+' || s[i] == '-'){
                while(!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
            else if(s[i] == '*' || s[i] == '/'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                    cout << op.top();
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }
    while(!op.empty()){
        cout << op.top();
        op.pop();
    }

    return 0;
}
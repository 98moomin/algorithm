#pragma warning(disable:4996)

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int T=0;T<n;T++){
        int num;
        cin >> num;
        if(num == 0){
            s.pop();
        }
        else{
            s.push(num);
        }
    }

    int sum =0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}
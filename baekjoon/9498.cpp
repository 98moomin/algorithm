#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a;
    cin >> a ;
    if(89 < a){
        cout << "A";
    }
    else if(79 < a && a < 90){
        cout << "B";
    }
    else if(69 < a && a < 80){
        cout << "C";
    }
    else if(59 < a && a < 70){
        cout << "D";
    }
    else{
        cout << "F";
    }
}
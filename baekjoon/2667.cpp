#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
vector<int> v;
char arr[25][25];
int N, cnt, num;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x, int y){
    arr[x][y]=0;
    int tmpx,tmpy;
    for(int i=0;i<4;i++){
        tmpx=x+dx[i];
        tmpy=y+dy[i];
        if(arr[tmpx][tmpy]=='1'&&tmpx>=0&&tmpx<N&&tmpy>=0&&tmpy<N){
            dfs(tmpx,tmpy);
        }
    }
    cnt++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]=='1'){
                cnt = 0;
                dfs(i,j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(),v.end());
    cout << v.size() << "\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
}
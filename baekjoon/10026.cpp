#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
char arr[101][101];
bool visited[101][101];
bool visited_RG[101][101];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int N;
int cnt, cnt_RG;

void DFS(int x, int y){
    visited[x][y] = true;
    int tmpx, tmpy;
    for(int i=0;i<4;i++){
        tmpx = x+dx[i];
        tmpy = y+dy[i];
        if(!visited[tmpx][tmpy] && tmpx>=0 && tmpy>=0 && tmpx<N && tmpy<N && arr[tmpx][tmpy] == arr[x][y]){
            DFS(tmpx, tmpy);
        }
    }
}

void DFS_RG(int x, int y){
    visited_RG[x][y] = true;
    int tmpx, tmpy;
    for(int i=0;i<4;i++){
        tmpx = x+dx[i];
        tmpy = y+dy[i];
        if(!visited_RG[tmpx][tmpy] && tmpx>=0 && tmpy>=0 && tmpx<N && tmpy<N){
            if(arr[x][y] == 'B'){
                if(arr[tmpx][tmpy] == 'B'){
                    DFS_RG(tmpx, tmpy);
                }
            }
            else{
                if(arr[tmpx][tmpy] == 'R' || arr[tmpx][tmpy] == 'G'){
                    DFS_RG(tmpx, tmpy);
                }
            }
        }
    }
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
            if(!visited[i][j]){
                DFS(i, j);
                cnt++;
            }
            if(!visited_RG[i][j]){
                DFS_RG(i, j);
                cnt_RG++;
            }
        }
    }
    cout << cnt << " " << cnt_RG;
}
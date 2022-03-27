#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100][100];
bool visited[100][100];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int M, N, K;
int cnt;
vector<int> V;

void DFS(int x, int y){
    arr[x][y] = 1;
    for(int i=0;i<4;i++){
        int tmpx, tmpy;
        tmpx = x+dx[i];
        tmpy = y+dy[i];
        if(tmpx >=0 && tmpy>=0 && tmpx < M && tmpy<N && arr[tmpx][tmpy]==0){
            DFS(tmpx,tmpy);
        }
    }
    cnt++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
    cin >> M >> N >> K;
    
    for(int i=0;i<K;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=y1;j<y2;j++){
            for(int k=x1;k<x2;k++){
                arr[j][k] = 1;
            }
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==0){
                cnt = 0;
                DFS(i,j);
                V.push_back(cnt);
            }
        }
    }
    sort(V.begin(), V.end());
    cout << V.size() << "\n";
    for(int i=0;i<V.size();i++){
        cout << V[i] << " ";
    }
}
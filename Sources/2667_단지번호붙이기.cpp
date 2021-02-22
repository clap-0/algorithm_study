#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0}; //상하좌우
vector<string> adj; //인접행렬
vector<vector<int> > visited; //방문여부저장
int dfs(int y, int x) //단지내의 집의 개수 반환
{
  int ret=1;
  visited[y][x] = true;
  for(int i=0; i<4; i++){
    int ny = y+dy[i], nx = x+dx[i];
    if(ny==-1||ny==n||nx==-1||nx==n) continue;
    if(adj[ny][nx]=='0'||visited[ny][nx]) continue;
    ret += dfs(ny, nx);
  }
  return ret;
}
int main()
{
  int complexNum=0; //단지수
  vector<int> houseNum; //각 단지내의 
  cin >> n;
  adj.resize(n);
  visited.resize(n, vector<int>(n, false));
  for(int i=0; i<n; i++)
    cin >> adj[i];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(adj[i][j]=='1'&&!visited[i][j]){
        complexNum++;
        houseNum.push_back(dfs(i, j));
      }
  sort(houseNum.begin(), houseNum.end());
  cout << complexNum << endl;
  for(auto size : houseNum)
    cout << size << endl;
  return 0;
}

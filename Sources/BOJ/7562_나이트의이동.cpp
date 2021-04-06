#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dy[8]={1,2,2,1,-1,-2,-2,-1}, dx[8]={-2,-1,1,2,2,1,-1,-2}; //나이트가 이동가능한 위치
int length;
vector<vector<int> > shortest; //나이트가 시작점에서 각 칸에 가는데 걸리는 최소시간
//나이트가 curr칸에서 toMove칸까지 가는데 걸리는 최소시간을 BFS로 구함
int bfs(pair<int,int> curr, pair<int,int> toMove){
  shortest[curr.first][curr.second]=0;
  queue<pair<int,int> > q;
  q.push(curr);
  while(!q.empty()){
    int y=q.front().first, x=q.front().second;
    q.pop();
    if(y==toMove.first&&x==toMove.second) return shortest[y][x];
    for(int i=0; i<8; i++){
      int ny=y+dy[i], nx=x+dx[i];
      if(ny<0||nx<0||ny>=length||nx>=length) continue;
      if(shortest[ny][nx]==-1){ //아직 방문 안 한 경우
        shortest[ny][nx] = shortest[y][x]+1;
        q.push({ny,nx});
      }
    }
  }
  return -1;
}
int main()
{
  int t;
  cin >> t;
  while(t--){
    pair<int,int> curr, toMove;
    cin >> length;
    cin >> curr.first >> curr.second;
    cin >> toMove.first >> toMove.second;
    shortest.clear();
    shortest.resize(length, vector<int>(length, -1));
    cout << bfs(curr, toMove) << endl;
  }
}

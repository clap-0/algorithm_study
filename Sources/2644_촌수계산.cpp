#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> count; //start로부터 각 정점의 촌수저장
vector<int> adj[101]; //인접리스트
int bfs(int start, int end) //start와 end 사이의 촌수 계산
{
  queue<int> q;
  q.push(start);
  while(!q.empty()){
    int here = q.front();
    q.pop();
    if(here==end) return count[here]; //end 방문 시 촌수반환
    for(int there : adj[here])
      if(!count[there]){
        q.push(there);
        count[there] = count[here]+1;
      }
  }
  return -1;
}
int main()
{
  int n, m;
  pair<int, int> toSolve;
  cin >> n >> toSolve.first >> toSolve.second >> m;
  count.resize(n+1, 0);
  for(int i=0; i<m; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cout << bfs(toSolve.first, toSolve.second) << endl;
  return 0;
}

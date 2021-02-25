#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited; //방문했던 정점 저장
vector<vector<int> > adj; //인접리스트
//현재 정점과 직전에 방문한 정점을 인자로 받아
//깊이우선탐색을 하며 트리인지 반환
int dfs(int here, int parent)
{
  int check=true;
  visited[here] = true;
  for(auto there : adj[here]){
    if(!visited[there]){ //처음 보는 정점일 경우
      //방문한 다음, 현재 탐색 중인 컴포넌트가 트리인지 저장
      check = min(check, dfs(there, here)); 
    }
    else if(parent!=there){ //직전에 방문한 정점이 아닌경우 (역방향간선 혹은 교차간선인 경우)
      check = false; //해당 컴포넌트는 트리가 아님
    }
  }
  return check;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m, t=0;
  while(1){
    cin >> n >> m;
    if(n==0&&m==0) break;
    adj.clear(); adj.resize(n+1); //인접리스트 초기화
    visited.clear(); visited.resize(n+1, false); //정점방문여부 초기화
    int u, v, cnt=0;
    for(int i=0; i<m; i++){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
      if(!(visited[i]))
        cnt += dfs(i, i); //트리일 경우 개수증가
    cout<<"Case "<<++t<<": ";
    switch(cnt)
    {
      case 0:
        cout<<"No trees."<<endl;
        break;
      case 1:
        cout<<"There is one tree."<<endl;
        break;
      default:
        cout<<"A forest of "<<cnt<<" trees."<<endl;
    }
  }
}

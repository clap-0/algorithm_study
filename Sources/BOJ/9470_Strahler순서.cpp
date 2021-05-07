#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX=1001;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int k, m, p;
    vector<int> adj[MAX]; //인접리스트
    int indegrees[MAX]; //indegrees[i] = i로 들어오는 간선의 수
    int strahler[MAX]={0}; //strahler[i] = i의 Strahler 순서
    int pointing[MAX]={0}; //pointing[i] = i로 들어오는 강의 Strahler 순서 중 가장 큰 값
    cin >> k >> m >> p;
    for(int i=0; i<p; i++){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      indegrees[b]++;
    }
    
    //위상정렬 알고리즘
    queue<int> Q;
    for(int i=1; i<=m; i++)
      if(!indegrees[i]){ //들어오는 간선이 없는 경우 (강의 근원인 노드의 경우)
        Q.push(i);
        strahler[i] = 1;
      }
    for(int i=0; i<m; i++){
      int curr = Q.front();
      Q.pop();
      for(int next : adj[curr]){
        if(--indegrees[next]==0) Q.push(next);
        //어떤 노드로 들어오는 강의 순서 중 가장 큰 값이 두 개 이상이면
        //그 노드의 순서는 가장 큰 값 + 1
        if(pointing[next]==strahler[curr])
          strahler[next] = pointing[next]+1;
        //어떤 노드로 들어오는 강의 순서 중 가장 큰 값이 하나면
        //그 값과 노드의 순서는 같다
        else if(pointing[next]<strahler[curr])
          strahler[next] = pointing[next] = strahler[curr];
      }
    }
    cout << k << ' ' << strahler[m] << '\n';
  }
}

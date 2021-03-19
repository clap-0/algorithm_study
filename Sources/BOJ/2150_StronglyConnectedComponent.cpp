#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int vertexCnt, sccCnt; //정점방문순서카운터, 만들어진SCC개수 저장
vector<bool> finished(10001); //각 정점이 SCC에 속하는지 저장
vector<int> adj[10001], visited(10001); //인접리스트, 각 정점의 방문순서 저장
vector<vector<int> > sccArr;
stack<int> stk;
int tarjanScc(int here) //here정점에서 간선을 따라 갈 수 있는 최소방문순서 반환
{
  int ret = visited[here] = ++vertexCnt;
  stk.push(here);
  for(int i=0; i<adj[here].size(); i++){
    int there = adj[here][i];
    if(finished[there]) continue; //이미 SCC구성이 완료된 곳인 경우
    if(!(visited[there])) ret = min(ret, tarjanScc(there));
    else ret = min(ret, visited[there]);
  }
  if(ret==visited[here]){ //현위치를 루트로 하는 서브트리에서 발견할 수 있는 최소방문순서가 현위치일 때
    vector<int> scc;
    while(1){ //SCC구성
      int t=stk.top();
      stk.pop();
      scc.push_back(t);
      finished[t] = true;
      if(t==here) break;
    }
    sort(scc.begin(), scc.end());
    sccArr.push_back(scc);
    sccCnt++;
  }
  return ret;
}
int main()
{
  int v, e;
  cin >> v >> e;
  for(int i=0; i<e; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i=1; i<=v; i++)
    if(!(visited[i])) tarjanScc(i);
  sort(sccArr.begin(), sccArr.end());
  cout << sccCnt << endl;
  for(int i=0; i<sccCnt; i++){
    for(int j=0; j<sccArr[i].size(); j++)
      cout << sccArr[i][j] << ' ';
    cout << "-1" << endl;
  }
  return 0;
}

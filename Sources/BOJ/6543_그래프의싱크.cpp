#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX=5000;

vector<vector<int> > adj; //인접리스트
vector<int> bottom; //그래프의 싱크 집합
int discovered[MAX]; //각 정점의 방문순서
bool finished[MAX]; //각 정점이 SCC로 묶였는지 여부
bool sccOutdegree[MAX]; //각 정점에 대해 해당 정점에서 다른 SCC로 가는 간선존재여부
int counter;
stack<int> stk;

int tarjanSCC(int here){
  int ret = discovered[here] = ++counter;
  stk.push(here);
  for(int there : adj[here]){
    if(!discovered[there]) ret = min(ret, tarjanSCC(there));
    else if(!finished[there]) ret = min(ret, discovered[there]);
    if(finished[there]) sccOutdegree[here]=true; //there이 이미 SCC구성이 끝난 곳인 경우
  }
  if(ret==discovered[here]){
    vector<int> scc;
    bool isBottom = true;
    while(1){
      int tmp=stk.top(); stk.pop();
      scc.push_back(tmp);
      finished[tmp] = true;
      if(sccOutdegree[tmp]) isBottom=false; //이 SCC에서 다른 SCC로 가는 간선이 존재하면 싱크아님
      if(tmp==here) break;
    }
    if(isBottom) bottom.insert(bottom.end(), scc.begin(), scc.end());
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  while(1){
    int n, m;
    cin >> n;
    if(n==0) break;
    fill(discovered, discovered+n, 0);
    fill(finished, finished+n, 0);
    fill(sccOutdegree, sccOutdegree+n, 0);
    counter=0;
    adj.clear(); adj.resize(n);
    bottom.clear();
    cin >> m;
    for(int i=0; i<m; i++){
      int v, w;
      cin >> v >> w; v--; w--;
      adj[v].push_back(w);
    }
    
    for(int i=0; i<n; i++)
      if(!discovered[i]) tarjanSCC(i);
    sort(bottom.begin(), bottom.end());
    for(int node : bottom) cout << node+1 << ' ';
    cout << '\n';
  }
}

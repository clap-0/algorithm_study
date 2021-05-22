#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX=100000;

vector<int> adj[MAX];
int counter, sccCnt, discovered[MAX], sccId[MAX];
bool finished[MAX];
stack<int> stk;

//타잔의 SCC분리 알고리즘
int tarjanSCC(int here){
  int ret=discovered[here]=++counter;
  stk.push(here);
  for(int there : adj[here]){
    if(!discovered[there]) ret=min(ret, tarjanSCC(there));
    else if(!finished[there]) ret=min(ret, discovered[there]);
  }
  if(ret==discovered[here]){
    while(1){
      int tmp=stk.top(); stk.pop();
      sccId[tmp]=sccCnt;
      finished[tmp]=true;
      if(tmp==here) break;
    }
    sccCnt++;
  }
  return ret;
}

int main()
{
  int n, m, k=0;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  
  for(int i=0; i<n; i++)
    if(!discovered[i]) tarjanSCC(i);
  
  //들어오는 간선이 하나도 없는 SCC의 개수만큼 바이러스가 필요
  vector<bool> hasIndegree(sccCnt, false);
  for(int i=0; i<n; i++)
    for(int j : adj[i])
      if(sccId[i]!=sccId[j]) hasIndegree[sccId[j]]=true;
  for(bool s : hasIndegree)
    if(!s) k++;
  cout << k << '\n';
}

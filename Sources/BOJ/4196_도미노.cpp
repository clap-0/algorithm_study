#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAX=100000;
vector<int> adj[MAX];
int discovered[MAX], sccId[MAX];
bool finished[MAX];
int counter, sccCnt;
stack<int> stk;
int tarjanSCC(int here){
  int ret = discovered[here] = ++counter;
  stk.push(here);
  for(int there : adj[here]){
    if(!discovered[there]) ret = min(ret, tarjanSCC(there));
    else if(!finished[there]) ret = min(ret, discovered[there]);
  }
  if(ret==discovered[here]){
    while(1){
      int tmp = stk.top(); stk.pop();
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
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
      adj[i].clear();
      discovered[i]=sccId[i]=finished[i]=0;
    }
    sccCnt=counter=0;
    for(int i=0; i<m; i++){
      int x, y;
      cin >> x >> y; x--; y--;
      adj[x].push_back(y);
    }
    for(int i=0; i<n; i++)
      if(!discovered[i]) tarjanSCC(i);
    int domino=0;
    vector<bool> hasIndegrees(sccCnt, false);
    for(int i=0; i<n; i++)
      for(int j : adj[i])
        if(sccId[i]!=sccId[j]) hasIndegrees[sccId[j]] = true;
    for(bool s : hasIndegrees)
      if(!s) domino++;
    cout << domino << '\n';
  }
}

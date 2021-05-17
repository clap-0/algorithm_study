#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_N=10000;

vector<int> adj[MAX_N*2];
int discovered[MAX_N*2], sccId[MAX_N*2];
bool finished[MAX_N*2];
int counter, sccCnt;
stack<int> stk;

int Not(int x) {return x%2 ? x-1 : x+1;}

int tarjanSCC(int here){
  int ret = discovered[here] = ++counter;
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
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int cnt=0; cnt<m; cnt++){
    int i, j;
    cin >> i >> j;
    i = (i>0 ? 2*(i-1) : 2*(-i-1)+1);
    j = (j>0 ? 2*(j-1) : 2*(-j-1)+1);
    adj[Not(i)].push_back(j);
    adj[Not(j)].push_back(i);
  }
  
  for(int i=0; i<n*2; i++)
    if(!discovered[i]) tarjanSCC(i);
  
  for(int i=0; i<n*2; i+=2)
    if(sccId[i]==sccId[i+1]){
      cout << 0 << '\n';
      return 0;
    }
  cout << 1 << '\n';
  
  vector<int> res(n, -1);
  vector<pair<int, int> > order;
  for(int i=0; i<n*2; i++) order.push_back({-sccId[i], i});
  sort(order.begin(), order.end());
  for(int i=0; i<n*2; i++){
    int var = order[i].second;
    if(res[var/2]==-1) res[var/2]=var%2;
  }
  for(int x : res) cout << x << ' ';
}

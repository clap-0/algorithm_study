#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX=1000;

int counter, sccCnt;
vector<int> adj[MAX*2];
int discovered[MAX*2], sccId[MAX*2];
bool finished[MAX*2];
stack<int> stk;

int Not(int x) {return x%2 ? x-1 : x+1;}

//타잔의 SCC분리 알고리즘
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
  while(cin >> n >> m){
    for(int i=0; i<n*2; i++){
      adj[i].clear();
      discovered[i]=sccId[i]=finished[i]=0;
    }
    counter=sccCnt=0;
    
    for(int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;
      a = (a>0 ? 2*(a-1) : 2*(-a-1)+1);
      b = (b>0 ? 2*(b-1) : 2*(-b-1)+1);
      adj[Not(a)].push_back(b);
      adj[Not(b)].push_back(a);
    }
    
    for(int i=0; i<n*2; i++)
      if(!discovered[i]) tarjanSCC(i);
    
    bool isPerfect=true;
    for(int i=0; i<n*2; i+=2)
      if(sccId[i]==sccId[i+1]){
        isPerfect=false;
        break;
      }
    cout << isPerfect << '\n';
  }
}

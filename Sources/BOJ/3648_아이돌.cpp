#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX=1000;

vector<int> adj[MAX*2];
int discovered[MAX*2], sccId[MAX*2];
bool finished[MAX*2];
int counter, sccCnt;
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
      //참가자에 대한 찬성/반대표를 정점번호로 만듬
      //짝수면 찬성, 홀수면 반대표
      a = (a>0 ? 2*(a-1) : 2*(-a-1)+1);
      b = (b>0 ? 2*(b-1) : 2*(-b-1)+1);
      //심사위원의 두 표 중 하나가 원래 표와 다르면 나머지 하나는 무조건 똑같아야 한다.
      adj[Not(a)].push_back(b);
      adj[Not(b)].push_back(a);
    }
    adj[Not(0)].push_back(0); //상근이는 무조건 다음라운드 진출해야 하므로 (1||1)을 만족시키는 간선을 포함시킴
    
    for(int i=0; i<n*2; i++)
      if(!discovered[i]) tarjanSCC(i);
    
    bool success=true;
    for(int i=0; i<n*2; i+=2)
      if(sccId[i]==sccId[i+1]){
        success=false;
        break;
      }
    cout << (success ? "yes" : "no") << '\n';
  }
}

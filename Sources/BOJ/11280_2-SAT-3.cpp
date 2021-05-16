#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_N=10000;

vector<int> adj[MAX_N*2];
int discovered[MAX_N*2], sccId[MAX_N*2];
bool finished[MAX_N*2];
int counter, sccCnt;
stack<int> stk;

//참인 변수를 거짓으로, 거짓인 변수를 참으로 변환
int Not(int x) {return x%2 ? x-1 : x+1;}

//타잔의 SCC 분리 알고리즘
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
      finished[tmp]=true;
      sccId[tmp]=sccCnt;
      if(tmp==here) break;
    }
    sccCnt++;
  }
  return ret;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int cnt=0; cnt<m; cnt++){
    int i, j;
    cin >> i >> j;
    //x_k : 2*(k-1), not_x_k : 2*(k-1)+1
    i = i>0 ? 2*(i-1) : 2*(-i-1)+1;
    j = j>0 ? 2*(j-1) : 2*(-j-1)+1;
    //절의 두 변수 중 하나가 거짓이면 다른 하나는 참이어야 함
    adj[Not(i)].push_back(j);
    adj[Not(j)].push_back(i);
  }
  
  for(int i=0; i<n*2; i++)
    if(!discovered[i]) tarjanSCC(i);
  
  //x와 not_x가 같은 SCC에 있을 경우 모순
  bool sat=true;
  for(int i=0; i<n*2; i+=2){
    int j=i+1;
    if(sccId[i]==sccId[j]) sat=false;
  }
  cout << (sat ? 1 : 0) << '\n';
}

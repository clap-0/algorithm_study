#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX=10000;

vector<int> adj[MAX*2]; //인접리스트
int discovered[MAX*2], sccId[MAX*2]; //각 정점의 방문순서와 몇 번째 SCC에 속해있는지 저장
bool finished[MAX*2]; //각 정점이 SCC로 묶였는지 여부
int counter, sccCnt;
stack<int> stk;

//(x/2+1)번째에 낼 거에 대한 학생의 선택을 가위면 바위로, 바위면 가위로 바꿈
int Not(int x) {return x%2 ? x-1 : x+1;}

//타잔의 scc분리 알고리즘
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
      sccId[tmp] = sccCnt;
      finished[tmp] = true;
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
  for(int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    //학생의 선택을 정점번호로 바꿈. 짝수정점은 가위, 홀수정점은 바위
    x = (x>0 ? 2*(x-1) : 2*(-x-1)+1);
    y = (y>0 ? 2*(y-1) : 2*(-y-1)+1);
    adj[Not(x)].push_back(y);
    adj[Not(y)].push_back(x);
  }
  
  for(int i=0; i<m*2; i++)
    if(!discovered[i]) tarjanSCC(i);
  
  //같은 SCC의 모든 정점은 참/거짓여부가 같으므로
  //x번째에 가위를 낸다는 선택과 x번째에 바위를 낸다는 선택이
  //같은 SCC내부에 있으면 모순
  for(int i=0; i<m*2; i+=2)
    if(sccId[i]==sccId[i+1]){
      cout << "OTL\n";
      return 0;
    }
  cout << "^_^\n";
}

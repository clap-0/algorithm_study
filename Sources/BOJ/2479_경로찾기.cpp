#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K, A, B;
  int binaryCodes[1000]={0};
  cin >> N >> K;
  //코드를 입력받아 정수형으로 변환하여 저장한다
  for(int i=0; i<N; i++){
    string code;
    cin >> code;
    for(int k=0; k<K; k++)
      if(code[k]=='1'){
        binaryCodes[i] |= (1<<k);
      }
  }
  cin >> A >> B; A--; B--;
  
  //각 이진코드 사이의 해밍 거리가 1인 것만 인접리스트에 저장한다
  vector<int> adj[1000];
  for(int i=0; i<N; i++)
    for(int j=i+1; j<N; j++)
      //두 코드사이에 XOR연산을 했을 때 1인 비트가 1개뿐인 경우
      if(__builtin_popcount(binaryCodes[i]^binaryCodes[j])==1){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
  
  //너비우선탐색
  queue<int> Q;
  bool discovered[1000]={false};
  //BFS스패닝트리상에서 각 노드의 부모노드를 저장한다
  int prev[1000];
  Q.push(A);
  discovered[A]=true;
  prev[A]=-1;
  while(!Q.empty()){
    int curr = Q.front(); Q.pop();
    if(curr==B) break;
    for(int next : adj[curr])
      if(!discovered[next]){
        discovered[next]=true;
        prev[next] = curr;
        Q.push(next);
      }
  }
  //A에서 B로 가는 경로가 없는 경우
  if(!discovered[B]) cout << -1 << '\n';
  else{
    stack<int> stk;
    for(int p=B; p!=-1; p=prev[p]) stk.push(p);
    while(!stk.empty()){
      cout << stk.top()+1 << ' ';
      stk.pop();
    }
  }
}

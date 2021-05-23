#include <iostream>
#include <queue>
#include <cstring>
#include <stack>
#include <functional> //std::function 클래스

using namespace std;

const int MAX=100001;
const function<int(int)> f[3]={
  [](int n){return n*2;}, //람다 함수(lambda function)
  [](int n){return n-1;},
  [](int n){return n+1;}
};

int main()
{
  int n, k, cnt=0;
  int shortest[MAX]; //shortest[i] = n에서 i까지 가는데 걸리는 최단시간. -1로 초기화
  int prev[MAX]; //prev[i] = n을 루트로 하는 BFS스패닝트리에서 i의 부모노드. prev[n]=-1
  queue<int> Q;
  memset(shortest, -1, sizeof(shortest));
  cin >> n >> k;
  
  Q.push(n);
  shortest[n]=0; prev[n]=-1;
  while(!Q.empty()){
    int pos=Q.front(); Q.pop();
    
    if(pos==k) break; //동생을 찾으면 탐색중단
    
    for(int i=0; i<3; i++){
      int next = f[i](pos);
      if(next<0 || next>=MAX) continue;
      if(shortest[next]==-1){ //아직 발견하지 않은 곳이면
        Q.push(next);
        shortest[next]=shortest[pos]+1;
        prev[next]=pos;
      }
    }
  }
  cout << shortest[k] << '\n';
  stack<int> path;
  int tmp=k;
  while(tmp!=-1){
    path.push(tmp);
    tmp=prev[tmp];
  }
  while(!path.empty()){
    cout << path.top() << ' ';
    path.pop();
  }
}

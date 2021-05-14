#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX=100, INF=987654321;

vector<int> adj[MAX]; //인접리스트
int discovered[MAX], finished[MAX]; //각 정점의 발견순서와 SCC로 묶였는지 여부 저장
int cost[MAX]; //각 도시에 경찰서를 세우는데 드는 비용
int counter, totalCost;
stack<int> stk; //정점번호 담는 스택

//타잔의 SCC분리 알고리즘을 변형하여
//모든 도시에 경찰서를 세우는데 드는 최소비용을 구한다
//curr를 루트로 하는 서브트리에서 역방향간선이나 교차간선으로
//갈 수 있는 정점의 최소발견순서 반환
int getMinCost(int curr){
  int ret = discovered[curr] = ++counter;
  stk.push(curr);
  for(int next : adj[curr]){
    if(!discovered[next]) ret = min(ret, getMinCost(next));
    else if(!finished[next]) ret = min(ret, discovered[next]);
  }
  //서브트리에서 자신의 조상으로 가는 간선이 없는 경우
  if(ret==discovered[curr]){
    int minCost=INF;
    while(1){
      int t = stk.top();
      stk.pop();
      finished[t] = true;
      minCost = min(minCost, cost[t]); //SCC로 묶인 도시의 건설비용 중 최솟값 찾기
      if(curr==t) break;
    }
    totalCost += minCost;
  }
  return ret;
}

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> cost[i];
  for(int i=0; i<n; i++) //인접행렬로 입력된 것을 인접리스트로 바꿈
    for(int j=0; j<n; j++){
      char path;
      cin >> path;
      if(path=='1') adj[i].push_back(j);
    }
  
  for(int i=0; i<n; i++)
    if(!discovered[i]) getMinCost(i);
  cout << totalCost << '\n';
}

#include <iostream>
#include <vector>
using namespace std;
const int MAX=100000;

vector<int> adj[MAX];
int discovered[MAX];
int counter;
bool isCactus; //각 정점에 대해 자기 자신으로 돌아오는 경로가 하나 이하면 선인장

//각 정점마다 이 정점이 몇 개의 단순 사이클 내에 있는지 센다
int countCycles(int here, int parent){
  int ret = discovered[here] = ++counter;
  int cycles=0;
  for(int there : adj[here]){
    if(there == parent) continue;
    //아직 방문해보지 않은 정점을 루트로 하는 서브트리에서
    //역방향간선을 통해 갈 수 있는 최소방문순서가
    //자기자신 혹은 이전이면 이 정점은 사이클 내에 있다
    if(!discovered[there]){
      int subtree = countCycles(there, here); 
      if(subtree<=discovered[here]) cycles++;
      ret = min(ret, subtree);
    }
    else {
      ret = min(ret, discovered[there]);
      //역방향간선이 있으면 이 정점은 사이클 내에 있다
      if(discovered[there]<discovered[here]) cycles++;
    }
  }
  if(cycles>1) isCactus = false;
  return ret;
}
int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int x, y;
    cin >> x >> y; x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  isCactus = true;
  countCycles(0, -1);
  cout << (isCactus ? "Cactus\n" : "Not cactus\n");
}

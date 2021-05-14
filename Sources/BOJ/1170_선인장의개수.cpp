#include <iostream>
#include <vector>
using namespace std;
const int MAX=200;

vector<int> adj[MAX];
int discovered[MAX];
int counter;
bool isCactus;

int findCactus(int here, int parent){
  int ret = discovered[here] = ++counter;
  int cycles=0;
  for(int there : adj[here]){
    if(there==parent) continue;
    //방문하지 않은 인접정점을 루트로 하는 서브트리에서
    //갈 수 있는 최소방문순서가 현정점이거나 그 이전인 경우 사이클
    if(!discovered[there]){
      int subtree = findCactus(there, here);
      if(subtree<=discovered[here]) cycles++;
      ret = min(ret, subtree);
    }
    else{
      ret = min(ret, discovered[there]);
      if(discovered[there]<discovered[here]) cycles++; //역방향간선으로 자신 이전에 방문한 정점과 연결되있으면 사이클
    }
  }
  if(cycles>1) isCactus=false; //사이클이 하나 이상 있으면 이 연결요소는 선인장그래프가 아님
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cactusCnt=0;
  for(int i=0; i<n; i++)
    if(!discovered[i]){
      isCactus=true;
      findCactus(i, -1);
      if(isCactus) cactusCnt++;
    }
  cout << cactusCnt << '\n';
}

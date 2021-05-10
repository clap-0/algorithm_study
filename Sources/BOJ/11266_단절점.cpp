#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX=10000;
vector<int> adj[MAX]; //인접리스트
int discovered[MAX]; //각 정점의 방문순서 저장
int counter;
set<int> cutVertex; //단절점번호 저장

//here을 루트로 하는 서브트리에서 역방향간선으로 갈 수 있는 정점 중
//가장 먼저 방문된 정점의 방문순서 반환
int findCutVertex(int here, bool isRoot){
  int ret = discovered[here] = ++counter;
  int children=0; //이 정점의 서브트리개수
  for(int there : adj[here]){
    if(!discovered[there]){ //인접 정점이 아직 방문 안 한 곳인 경우
      children++;
      int subtree = findCutVertex(there, false); //해당 서브트리에서 갈 수 있는 가장 먼저 방문된 정점번호
      //서브트리에서 이 정점의 조상과 연결되지 않은 경우 이 정점은 단절점
      if(!isRoot && subtree>=discovered[here])
        cutVertex.insert(here);
      ret = min(ret, subtree);
    }
    else ret = min(ret, discovered[there]);
  }
  //루트는 서브트리가 두 개 이상이면 단절점
  if(isRoot && children>=2) cutVertex.insert(here);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int V, E;
  cin >> V >> E;
  for(int i=0; i<E; i++){
    int a, b;
    cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }
  for(int i=0; i<V; i++)
    if(!discovered[i]) findCutVertex(i, true);
  cout << cutVertex.size() << '\n';
  for(int v : cutVertex) cout << v+1 << ' ';
}

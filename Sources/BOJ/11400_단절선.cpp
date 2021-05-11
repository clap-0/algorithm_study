#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX=100000;
vector<int> adj[MAX]; //인접리스트
int discovered[MAX]; //각 정점의 방문순서 저장
int counter;
set<pair<int,int> > cutEdge; //단절선 저장

//here을 루트로 하는 서브트리에서 역방향간선으로 갈 수 있는 정점 중
//가장 먼저 방문된 정점의 방문순서 반환
int findCutEdge(int here, int parent){
  int ret = discovered[here] = ++counter;
  for(int there : adj[here]){
    if(there==parent) continue; //자기 부모로 가는 간선 무시
    if(!discovered[there]){
      int subtree = findCutEdge(there, here);
      //there의 서브트리에서 역방향간선으로 갈 수 있는 정점의
      //최소발견순서가 here 이후면 간선 (here,there)은 단절선
      if(subtree>discovered[here]){
        if(here<there) cutEdge.insert({here,there});
        else cutEdge.insert({there,here});
      }
      ret = min(ret, subtree);
    }
    else ret = min(ret, discovered[there]);
  }
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
    cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  findCutEdge(0, -1);
  cout << cutEdge.size() << '\n';
  for(auto &edge : cutEdge)
    cout << edge.first+1 << ' ' << edge.second+1 << '\n';
}

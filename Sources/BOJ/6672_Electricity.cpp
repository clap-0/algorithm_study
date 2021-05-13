#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=10000;

vector<vector<int> > adj; //인접리스트
int discovered[MAX]; //각 정점의 방문순서 저장
int counter, connectedParts;

//한 정점을 없앴을 때 나눠지는 컴포넌트 수의 최댓값 구하기
int getMaxConnection(int here, bool isRoot){
  int ret = discovered[here] = ++counter;
  int cutNum=0; //이 정점을 지웠을 때 단절되는 인접정점 수
  //이 정점의 서브트리에서 역방향간선으로 갈 수 있는 최소방문순서를 구하고
  //그 최소방문순서가 이 정점의 방문순서 이후면 이 정점은 단절점
  for(int there : adj[here]){
    if(discovered[there]) ret = min(ret, discovered[there]);
    else{
      int subtree = getMaxConnection(there, false);
      if(subtree>=discovered[here]) ++cutNum;
      ret = min(ret, subtree);
    }
  }
  if(!isRoot) ++cutNum;
  connectedParts = max(connectedParts, cutNum);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  while(1){
    int P, C;
    cin >> P >> C;
    if(P==0 && C==0) break;
    
    int components=0;
    connectedParts = counter=0;
    memset(discovered, 0, sizeof(int)*P);
    adj.clear(); adj.resize(P);
    for(int i=0; i<C; i++){
      int p1, p2;
      cin >> p1 >> p2;
      adj[p1].push_back(p2);
      adj[p2].push_back(p1);
    }
    for(int i=0; i<P; i++)
      if(!discovered[i]){
        components++;
        getMaxConnection(i, true);
      }
    cout << connectedParts+components-1 << '\n';
  }  
}

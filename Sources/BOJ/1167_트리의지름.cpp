#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V=100001;
vector<pair<int,int> > tree[MAX_V];
vector<bool> visited(MAX_V);
int diameter=0;
int height(int root){
  vector<int> heights;
  visited[root] = true;
  
  //root와 연결된 방문하지 않은 자식들을 방문하며 각 자식들을 루트로 하는 서브트리의 높이 구함
  for(auto &edge : tree[root]){
    int child=edge.first, weight=edge.second;
    if(visited[child]) continue;
    heights.push_back(height(child)+weight);
  }
  //자식이 없으면 0 반환
  if(heights.empty()) return 0;
  
  sort(heights.rbegin(), heights.rend());
  if(heights.size()>=2) diameter = max(diameter, heights[0]+heights[1]);
  return heights[0];
}
int main()
{
  int v;
  cin >> v;
  for(int i=0; i<v; i++){
    int u, v, w;
    cin >> u;
    while(1){
      cin >> v;
      if(v==-1) break;
      cin >> w;
      tree[u].push_back({v,w});
    }
  }
  int h = height(1);
  diameter = max(diameter, h);
  cout << diameter << endl;
}

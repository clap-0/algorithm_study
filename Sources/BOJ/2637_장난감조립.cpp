#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX=101;
vector<pair<int,int> > adj[MAX]; //인접리스트. 각각의 부품이나 완제품을 만드는데 필요한 {하위부품번호, 개수}쌍 저장
int indegrees[MAX]; //indegrees[i] = i로 들어가는 간선의 수
int needed[MAX]; //완제품 하나를 만드는데 각각 필요한 부품의 수
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int x, y, k;
    cin >> x >> y >> k;
    adj[x].push_back({y,k});
    indegrees[y]++;
  }
  
  //위상정렬 알고리즘
  //완제품부터 거꾸로 위상정렬을 한다
  queue<int> Q;
  vector<int> basicPart; //기본부품번호 저장
  Q.push(n);
  needed[n] = 1; //완제품 하나에는 완제품 1개만큼의 부품이 필요하다.
  for(int i=0; i<n; i++){
    int curr = Q.front();
    Q.pop();
    if(adj[curr].empty()){ //curr부품을 만드는데 필요한 부품이 없음 (기본부품)
      basicPart.push_back(curr);
      continue;
    }
    for(auto &next : adj[curr]){
      int nextPart = next.first;
      int cost = next.second;
      if(--indegrees[nextPart]==0) Q.push(nextPart);
      //완제품 만드는데 필요한 nextPart부품개수는
      //완제품 만드는데 필요한 curr부품개수 * curr부품 만드는데 필요한 nextPart개수
      needed[nextPart] += needed[curr]*cost; 
    }
  }
  sort(basicPart.begin(), basicPart.end());
  for(int part : basicPart) cout << part << ' ' << needed[part] << '\n';
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
//{i번쉼터의 높이, i}쌍 배열
pair<int,int> height[5000];
//인접리스트
vector<int> adj[5000];
int dp[5000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++){
    cin >> height[i].first;
    height[i].second=i;
  }
  //자신보다 높이가 높은 쉼터만을 가리키는 방향성 있는 그래프로 만든다
  for(int i=0; i<M; i++){
    int u, v;
    cin >> u >> v; u--; v--;
    if(height[u].first<height[v].first) adj[u].push_back(v);
    else adj[v].push_back(u);
  }
  //높이를 내림차순으로 정렬한다
  sort(height, height+N, greater<pair<int, int> >());
  //높이가 높은 쉼터부터 해당 쉼터에서 갈 수 있는 쉼터의 개수를
  //DP를 이용하여 구한다
  for(int i=0; i<N; i++){
    int curr=height[i].second;
    for(int next : adj[curr]) dp[curr]=max(dp[curr], dp[next]);
    dp[curr]++;
  }
  for(int i=0; i<N; i++) cout << dp[i] << '\n';
}

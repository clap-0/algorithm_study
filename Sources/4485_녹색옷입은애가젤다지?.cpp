#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0};
const int INF=999999;
vector<vector<int> > adj; //인접행렬. 해당 칸에서 잃는 루피 저장
int dijkstra(int y, int x)
{
  vector<vector<int> > cost(n, vector<int>(n, INF));
  cost[y][x]=adj[y][x];
  priority_queue<pair<int, pair<int, int> > > pq; // (잃는 루피수, y좌표, x좌표)
  pq.push({-adj[y][x], {y, x}});
  while(!pq.empty()){
    int rupee = -pq.top().first;
    int hereY=pq.top().second.first, hereX=pq.top().second.second;
    pq.pop();
    if(cost[hereY][hereX] < rupee) continue;
    for(int i=0; i<4; i++){ //상하좌우 조사
      int thereY=hereY+dy[i], thereX=hereX+dx[i];
      if(thereY==-1||thereY==n||thereX==-1||thereX==n) continue; //범위 밖이면 패스
      int nextRupee = adj[thereY][thereX] + rupee;
      if(cost[thereY][thereX] > nextRupee){
        cost[thereY][thereX] = nextRupee;
        pq.push({-nextRupee, {thereY, thereX}});
      }
    }
  }
  return cost[n-1][n-1];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int cnt=0;
  while(1){
    cin >> n;
    if(n==0) break;
    adj.clear(); adj.resize(n, vector<int>(n));
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> adj[i][j];
    int cost = dijkstra(0, 0);
    cout << "Problem " << ++cnt << ": " << cost << endl;
  }
  return 0;
}

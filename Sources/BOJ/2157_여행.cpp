#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, M, K;
int cache[300][301];
vector<pair<int,int> > adj[300];
//DP를 이용하여 city번 도시에서 N번 도시까지 cnt개 이하의 도시를 지나 여행할 때
//먹게되는 기내식 점수의 총합의 최댓값을 구한다
int inFlightFood(int city, int cnt){
  //메모이제이션
  int& ret = cache[city][cnt];
  if(ret!=-1) return ret;
  //기저사례 : 더 이상 갈 도시가 없고, 여기가 목적지가 아닌 경우 경우 0 반환
  if(cnt==1) return 0;
  ret=0;
  for(auto next : adj[city]){
    //다음에 가게 될 도시가 목적지라면 방문하지 않고 기내식점수만 얻는다
    if(next.first==N-1) ret=max(ret, next.second);
    //다음 도시에 방문하고, 가는 도중 먹은 기내식 점수를 더한다
    else{
      int tmp = inFlightFood(next.first, cnt-1);
      //다음 도시에 방문했을 때 이 도시를 통해 목적지에 갈 수 없는 경우 0을 저장한다
      ret=max(ret, tmp+(tmp?next.second:0));
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> M >> K;
  for(int i=0; i<K; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(a<b) adj[a-1].push_back({b-1, c});
  }
  memset(cache, -1, sizeof(cache));
  cout << inFlightFood(0, M) << '\n';
}

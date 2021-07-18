#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    //lunchbox[i].first = i번째 도시락을 먹는데 걸리는 시간
    //lunchbox[i].second = i번째 도시락을 데우는데 걸리는 시간
    vector<pair<int,int> > lunchbox(N);
    for(int i=0; i<N; i++) cin >> lunchbox[i].second;
    for(int i=0; i<N; i++) cin >> lunchbox[i].first;
    //먹는데 걸리는 시간 기준으로 내림차순 정렬한다
    sort(lunchbox.rbegin(), lunchbox.rend());
    //먹는데 오래 걸리는 도시락을 먼저 돌리고, 먹는 동안 다른 도시락을 돌리는게 낫다
    int ans=0, micrwaveEnd=0;
    for(int i=0; i<N; i++){
      int m=lunchbox[i].second, e=lunchbox[i].first;
      micrwaveEnd+=m;
      ans=max(ans, micrwaveEnd+e);
    }
    cout << ans << '\n';
  }
}

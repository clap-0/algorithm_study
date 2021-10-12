#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, minE=100001, maxS=0;
  cin >> N;
  // 욱제가 머무르는 시간을 최소로 하기 위해서는
  // 가장 먼저 오는 팬이 떠나는 시각에 가서
  // 가장 늦게 오는 팬이 오는 시각에 떠나면 된다
  for(int i=0; i<N; i++){
    int s, e;
    cin >> s >> e;
    minE=min(minE, e);
    maxS=max(maxS, s);
  }
  cout << max(maxS-minE, 0) << '\n';
}

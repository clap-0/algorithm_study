#include <iostream>
#include <algorithm>
using namespace std;

int section[500000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, H;
  cin >> N >> H;
  for(int i=0; i<N; i++) {
    int h;
    cin >> h;
    // 석순인 경우 [0, h)구간에서 파괴하는 장애물 개수가 늘어나므로
    // 이후 구간합을 고려해 아래와 같이 처리한다
    if(i % 2) {
      section[0]++;
      section[h]--;
    }
    // 종유석인 경우 [H-h, H)구간에서 파괴하는 쟁애물 개수가 늘어난다
    else section[H-h]++;
  }

  // 구간합을 이용하여 각각의 구간에서 파괴해야하는 장애물 개수를 구한다
  for(int i=1; i<H; i++) {
    section[i] += section[i-1];
  }

  int ans=1e9, cnt=1;
  for(int i=0; i<H; i++) {
    if(ans > section[i]) {
      ans = section[i];
      cnt = 1;
    }
    else if(ans == section[i]) cnt++;
  }

  cout << ans << ' ' << cnt << '\n';
}

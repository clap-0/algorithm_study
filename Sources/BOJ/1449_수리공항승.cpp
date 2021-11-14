#include <iostream>
#include <algorithm>
using namespace std;
int leak[1000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, L, ans=0;
  cin >> N >> L;
  for(int i=0; i<N; i++) cin >> leak[i];
  sort(leak, leak+N);
  // 가장 왼쪽에 있는 물이 새는 틈부터 시작하여 길이가 L인 테이프로 덮을 수 있는 범위를 구하고
  // 해당 범위에 속하지 않는 가장 왼쪽에 있는 틈부터 위 작업을 반복한다
  int reach=0;
  for(int pos : leak)
    if(reach < pos) {
      ans++;
      reach=pos+L-1;
    }
  cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

int weight[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> weight[i];

  sort(weight, weight+N);
  
  // 들어올릴 수 있는 최대중량 = 가장 버틸 수 있는 중량이 낮은 로프의 중량 * 로프의 개수
  int ans=0;
  for(int i=0; i<N; i++){
    ans = max(ans, weight[i]*(N-i));
  }
  cout << ans << '\n';
}

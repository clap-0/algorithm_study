#include <iostream>
#include <algorithm>
using namespace std;

// 키 순서로 줄 세워진 원생들에서 인접한 원생사이의 키 차이
int diff[300000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, K;
  cin >> N >> K;
  int prev, height;
  cin >> prev;
  // 인접한 원생사이의 키 차이를 구한다
  for(int i=0; i<N-1; i++){
    cin >> height;
    diff[i] = height-prev;
    prev = height;
  }

  // 키 차이에 대해 오름차순 정렬한다
  sort(diff, diff+N-1);

  // 작은 키 차이부터 N-K개를 선택해 K개의 조를 만든다
  int ans=0;
  for(int i=0; i<N-K; i++) ans += diff[i];
  cout << ans << '\n';
}

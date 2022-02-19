#include <iostream>
#include <algorithm>
using namespace std;

int straw[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> straw[i];
  // 빨대의 길이에 대하여 내림차순 정렬한다
  sort(straw, straw + N, greater<int>());
  
  for(int i = 0; i + 2 < N; i++)
    // 가장 긴 변의 길이가 다른 두 변의 길이보다 작아야 삼각형을 만들 수 있다.
    if(straw[i] < straw[i + 1] + straw[i + 2]) {
      cout << straw[i] + straw[i + 1] + straw[i + 2] << '\n';
      return 0;
    }
  
  cout << -1 << '\n';
}

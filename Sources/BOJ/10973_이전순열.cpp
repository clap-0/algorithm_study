#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> arr[i];

  // 이전 순열을 구한다. 사전순으로 정렬되어있는 경우는 isPermuted에 false가 저장된다
  bool isPermuted = prev_permutation(arr, arr + N);

  if(isPermuted)
    for(int i = 0; i < N; i++) cout << arr[i] << ' ';
  else cout << -1 << '\n';
}

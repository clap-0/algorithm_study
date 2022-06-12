#include <iostream>
using namespace std;

int arr[10];
int n, k, cnt;

// n을 사전순으로 1,2,3의 합으로 나타내며
// k번째 1,2,3의 합을 만들면 true를 반환하는 함수. 합이 k개가 없을 경우 false 반환
bool count123Sum(int n, int idx) {
  if(n == 0) return ++cnt == k;
  for(int i = 1; i <= min(n, 3); i++) {
    arr[idx] = i;
    if(count123Sum(n - i, idx + 1)) return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  if(count123Sum(n, 0)) {
    cout << arr[0]; n -= arr[0];
    for(int i = 1; n; n -= arr[i++])
      cout << "+" << arr[i];
  }
  else cout << -1 << '\n';
}

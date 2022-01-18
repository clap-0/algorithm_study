#include <iostream>
#include <algorithm>
using namespace std;

const int hour[4] = {100, 9900, 990000, 1000000000}, bill[4] = {2, 3, 5, 7};

// 내야하는 요금이 주어졌을 때 사용량을 반환한다
int costToAmount(int cost) {
  int ret = 0;
  for(int i=0; i<3; i++) {
    ret += min(cost / bill[i], hour[i]);
    if((cost -= bill[i] * hour[i]) <= 0) break;
  }
  if(cost > 0) ret += cost / 7;
  return ret;
}

// 사용량이 주어졌을 때 요금을 반환한다
int getCost(int amount) {
  int ret = 0;
  for(int i=0; i<4; i++) {
    ret += bill[i] * min(amount, hour[i]);
    if((amount -= hour[i]) <= 0) break;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(1) {
    int A, B; 
    cin >> A >> B;
    if(A+B==0) break;

    // sum = 상근이와 이웃의 사용량의 합
    int ans, sum = costToAmount(A);
    
    // 이분탐색
    int lo = 0, hi = sum / 2;
    while(lo <= hi) {
      int mid = (lo + hi) / 2;
      
      // 상근이의 사용량이 항상 이웃보다 적으므로 x가 상근이의 요금이다
      int x = getCost(mid), y = getCost(sum - mid);
      if(y - x > B) lo = mid + 1;
      else {
        hi = mid - 1;
        ans = x;
      }
    }
    cout << ans << '\n';
  }
}

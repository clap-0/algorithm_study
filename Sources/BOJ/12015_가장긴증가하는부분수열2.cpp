#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lis;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, A;
  cin >> N >> A;
  // 이분탐색을 활용하여 LIS 구하기
  lis.push_back(A);
  for(int i=0; i<N; i++) {
    cin >> A;
    // 수열의 마지막 수보다 A가 큰 경우 수열에 A를 추가한다
    if(lis.back() < A) {
      lis.push_back(A);
    }
    // A가 더 작은 경우 수열에서 A와 같거나 큰 수의 위치에 A를 대입한다
    else {
      auto it = lower_bound(lis.begin(), lis.end(), A);
      *it = A;
    }
  }
  cout << lis.size() << '\n';
}

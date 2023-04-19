#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string A;
    cin >> A;

    // A[idx - 1] < A[idx]를 만족하는 가장 큰 인덱스 idx를 구한다.
    int idx = A.length() - 1;
    while (idx >= 1 && A[idx] <= A[idx - 1]) {
      --idx;
    }

    // idx가 0인 경우 더 큰 수를 만들 수 없다.
    if (idx == 0) {
      cout << "BIGGEST\n";
      continue;
    }

    // 범위 A[idx...]는 내림차순으로 정렬되어 있으므로
    // 해당 범위를 뒤집어서 오름차순으로 만들고,
    reverse(A.begin() + idx, A.end());
    
    // A[idx...]에서 A[idx - 1]보다 큰, 가장 작은 수를 찾아서
    // 두 수의 위치를 바꾼다.
    auto greaterThan = upper_bound(A.begin() + idx, A.end(), A[idx - 1]);
    swap(A[idx - 1], *greaterThan);

    cout << A << '\n';
  }
}

#include <iostream>
using namespace std;

int sum[250001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, X;
  cin >> N >> X;

  sum[0] = 0;
  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    sum[i] = sum[i - 1] + num;
  }

  int maxVisitorCnt = 0, periodCnt = 0;
  for (int i = X; i <= N; i++) {
    int partialSum = sum[i] - sum[i - X];
    if (maxVisitorCnt < partialSum) {
      maxVisitorCnt = partialSum;
      periodCnt = 1;
    }
    else if (maxVisitorCnt == partialSum) {
      ++periodCnt;
    }
  }

  if (maxVisitorCnt == 0) {
    cout << "SAD\n";
  }
  else {    
    cout << maxVisitorCnt << '\n' << periodCnt << '\n';
  }
}

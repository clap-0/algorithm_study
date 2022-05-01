#include <iostream>
using namespace std;

int N, maxNum, minNum;
int A[11], opCnt[4];

void solve(int n, int number, int PLUS, int MINUS, int PRODUCT, int DIVISION) {
  if(n == N) {
    maxNum = max(maxNum, number);
    minNum = min(minNum, number);
    return;
  }

  if(PLUS < opCnt[0]) solve(n + 1, number + A[n], PLUS + 1, MINUS, PRODUCT, DIVISION);
  if(MINUS < opCnt[1]) solve(n + 1, number - A[n], PLUS, MINUS + 1, PRODUCT, DIVISION);
  if(PRODUCT < opCnt[2]) solve(n + 1, number * A[n], PLUS, MINUS, PRODUCT + 1, DIVISION);
  if(DIVISION < opCnt[3]) solve(n + 1, number / A[n], PLUS, MINUS, PRODUCT, DIVISION + 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < 4; i++) cin >> opCnt[i];

  maxNum = -2e9, minNum = 2e9;
  solve(1, A[0], 0, 0, 0, 0);
  cout << maxNum << '\n' << minNum << '\n';
}

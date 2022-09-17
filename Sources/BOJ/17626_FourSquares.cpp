#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> squares;
int dp[50001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;

  for (int i = 1; i * i <= n; i++)
    squares.push_back(i * i);
  
  for (int i = 1; i <= n; i++) {
    dp[i] = 5;
    int closestSquare = upper_bound(squares.begin(), squares.end(), i) - squares.begin() - 1;
    while (closestSquare >= 0)
      dp[i] = min(dp[i], 1 + dp[i - squares[closestSquare--]]);
  }
  cout << dp[n] << '\n';
}

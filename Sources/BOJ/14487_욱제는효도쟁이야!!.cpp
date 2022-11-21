#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, sum = 0, maxNum = -1;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    maxNum = max(maxNum, num);
    sum += num;
  }
  cout << sum - maxNum << '\n';
}

#include <iostream>
using namespace std;

int C, B;
int foods[21];

int backtracking(int idx, int calories)
{
  int ret = 0;
  for (int i = idx + 1; i < B; i++)
    if (calories + foods[i] <= C)
      ret = max(ret, foods[i] + backtracking(i, calories + foods[i]));
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> C >> B;
  for (int i = 0; i < B; i++)
    cin >> foods[i];
  
  cout << backtracking(-1, 0) << '\n';
}

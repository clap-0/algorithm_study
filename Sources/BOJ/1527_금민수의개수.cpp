#include <iostream>
using namespace std;

int A, B;

int goldMinsu(long long num)
{
  if (num > B)
    return 0;
  int ret = (num >= A ? 1 : 0);
  ret += goldMinsu(num * 10 + 4);
  ret += goldMinsu(num * 10 + 7);

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> A >> B;
  cout << goldMinsu(0) << '\n';
}

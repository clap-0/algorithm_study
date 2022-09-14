#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int x, n;
  while(cin >> x) {
    x *= 1e7;
    cin >> n;
    vector<int> length(n);
    for (int i = 0; i < n; i++)
      cin >> length[i];

    sort(length.begin(), length.end());

    // 두포인터 알고리즘
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      int sum = length[lo] + length[hi];
      if (sum == x)
        break;
      sum < x ? ++lo : --hi;
    }

    if (lo < hi)
      cout << "yes " << length[lo] << " " << length[hi] << '\n';
    else
      cout << "danger\n";
  }
}

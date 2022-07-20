#include <iostream>
using namespace std;

int box[1000], cache[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> box[i];
    cache[i] = 1;
    for(int j = 0; j < i; j++)
      if(box[i] > box[j])
        cache[i] = max(cache[i], 1 + cache[j]);
    ans = max(ans, cache[i]);
  }

  cout << ans << '\n';
}

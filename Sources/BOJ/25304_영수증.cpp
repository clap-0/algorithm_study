#include <iostream>
#include <algorithm>
using namespace std;

int scores[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, k;
  cin >> N >> k;
  for(int i = 0; i < N; i++) cin >> scores[i];

  sort(scores, scores + N, greater<int>());

  cout << scores[k - 1] << '\n';
}

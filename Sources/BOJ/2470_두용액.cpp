#include <iostream>
#include <algorithm>
using namespace std;

int solution[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> solution[i];

  sort(solution, solution+N);

  int lo=0, hi=N-1, mixed = 2000000001;
  pair<int,int> ans;
  while(lo < hi) {
    int sum = solution[lo] + solution[hi];
    if(mixed > abs(sum)) {
      mixed = abs(sum);
      ans = {solution[lo], solution[hi]};
    }
    if(sum < 0) lo++;
    else hi--;
  }
  cout << ans.first << " " << ans.second << '\n';
}

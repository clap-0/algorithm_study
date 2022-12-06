#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> trees[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> trees[i].first;
  for (int i = 0; i < N; i++)
    cin >> trees[i].second;
  
  sort(trees, trees + N, [](const pair<int,int>& a, const pair<int,int>& b){
    return a.second < b.second;
  });

  long long ans = 0LL;
  for (int i = 0; i < N; i++)
    ans += trees[i].first + trees[i].second * i;
  cout << ans << '\n';
}

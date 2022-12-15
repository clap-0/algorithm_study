#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> pos[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> pos[i].first >> pos[i].second;
  
  sort(pos, pos + N, [](const pair<int,int>& a, const pair<int,int>& b){
    if (a.first != b.first)
      return a.first < b.first;
    return a.second < b.second;
  });

  for (int i = 0; i < N; i++)
    cout << pos[i].first << ' ' << pos[i].second << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> numbers[1000000];
int ans[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    numbers[i] = {x, i};
  }

  sort(numbers, numbers + N);
  ans[numbers[0].second] = 0;
  for(int i = 1; i < N; i++) 
    ans[numbers[i].second] = ans[numbers[i - 1].second] + (numbers[i - 1].first == numbers[i].first ? 0 : 1);
  
  for(int i = 0; i < N; i++) cout << ans[i] << ' ';
}

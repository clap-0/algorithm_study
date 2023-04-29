#include <iostream>
using namespace std;

int arr[100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, v;
  cin >> N;
  for (int i = 0; i < N; i++) 
    cin >> arr[i];
  cin >> v;

  int ans = 0;
  for (int i = 0; i < N; i++)
    if (arr[i] == v)
      ++ans;
  cout << ans << '\n';
}

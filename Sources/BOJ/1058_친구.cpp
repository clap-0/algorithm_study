#include <iostream>
using namespace std;

int dist[50][50];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char isFriend;
      cin >> isFriend;
      dist[i][j] = isFriend == 'Y' ? 1 : 987654321;
    }
  }

  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


  int ans = 0;
  for (int i = 0; i < N; i++) {
    int friends = 0;
    for (int j = 0; j < N; j++)
      if (i != j && dist[i][j] <= 2)
        ++friends;
    ans = max(ans, friends);
  }

  cout << ans << '\n';
}

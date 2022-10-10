#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, newScore, P;
  cin >> N >> newScore >> P;
  int rank = 1, cnt = 1;
  for (int i = 0; i < N; i++) {
    int score;
    cin >> score;
    if (newScore < score)
      ++rank;
    if (newScore <= score)
      ++cnt;
  }

  cout << (cnt <= P ? rank : -1) << '\n';
}

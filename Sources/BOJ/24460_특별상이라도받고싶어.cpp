#include <iostream>
#include <algorithm>
using namespace std;

int numbers[1024][1024];

int lotteryNumber(int r, int c, int size)
{
  if (size == 1)
    return numbers[r][c];
  
  int half = size / 2;
  int candidates[4];
  candidates[0] = lotteryNumber(r, c, half);
  candidates[1] = lotteryNumber(r + half, c, half);
  candidates[2] = lotteryNumber(r, c + half, half);
  candidates[3] = lotteryNumber(r + half, c + half, half);
  
  sort(candidates, candidates + 4);
  return candidates[1];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> numbers[i][j];

  cout << lotteryNumber(0, 0, N) << '\n';
}

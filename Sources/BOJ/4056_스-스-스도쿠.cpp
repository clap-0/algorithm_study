#include <iostream>
#include <cstring>
using namespace std;

int board[9][9];
pair<int,int> blanks[5];

// 스도쿠를 완성할 수 있으면 스도쿠를 완성시켜 출력하고, 불가능하면 false를 반환하는 함수
bool sudoku(int idx)
{
  // 5개의 빈 칸을 모두 채운 경우, 스도쿠 출력 후 true 반환
  if (idx == 5) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++)
        cout << board[i][j];
      cout << '\n';
    }
    return true;
  }

  int y = blanks[idx].first, x = blanks[idx].second;
  int exists = 0, tmp = 0;

  // 가로줄
  for (int i = 0; i < 9; i++)
    if (board[y][i]) {
      if (exists & (1 << (board[y][i] - 1)))  // 가로줄에 중복되는 수가 있는 경우 false 반환
        return false;
      exists |= (1 << (board[y][i] - 1));
    }
  
  // 세로줄
  for (int i = 0; i < 9; i++)
    if (board[i][x]) {
      if (tmp & (1 << (board[i][x] - 1))) // 세로줄에 중복되는 수가 있는 경우 false 반환
        return false;
      tmp |= (1 << (board[i][x] - 1));
    }
  exists |= tmp;

  // 3*3 칸
  tmp = 0;
  int yBound = y / 3 * 3 + 3, xBound = x / 3 * 3 + 3;
  for (int i = yBound - 3; i < yBound; i++)
    for (int j = xBound - 3; j < xBound; j++)
      if (board[i][j]) {
        if (tmp & (1 << (board[i][j] - 1))) // 3*3 칸내에 중복되는 수가 있는 경우 false 반환
          return false;
        tmp |= (1 << (board[i][j] - 1));
      }
  exists |= tmp;
  
  // idx번째 빈 칸에 들어올 수 있는 후보로 칸을 채우고
  // 다음 칸으로 넘어간다.
  for (int i = 0; i < 9; i++)
    if (!(exists & (1 << i))) {
      board[y][x] = i + 1;
      if (sudoku(idx + 1))
        return true;
    }

  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int idx = 0;
    char num;
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++) {
        cin >> num;
        if ((board[i][j] = num - '0') == 0)
          blanks[idx++] = {i, j};
      }

    if (!sudoku(0))
      cout << "Could not complete this grid.\n";
    cout << '\n';
  }
}

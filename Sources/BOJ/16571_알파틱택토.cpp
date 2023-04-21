#include <iostream>
using namespace std;

const int BLANK = 0, PLAYER_X = 1, PLAYER_O = 2;
const int LOSE = 0, DRAW = 1, WIN = 2;

// 최선의 게임결과를 얻어야하는 플레이어
int player;
int state[9];

// 현재 상태에서 player의 승패무를 확인한다.
int checkResult()
{
  int winner = BLANK;

  // 틱택토의 행과 열 확인
  for (int i = 0; i < 3; i++) {
    int row = state[i * 3];
    int col = state[i];
    if (row != BLANK && row == state[i * 3 + 1] && row == state[i * 3 + 2]) {
      winner = row;
      break;
    }
    if (col != BLANK && col == state[i + 3] && col == state[i + 6]) {
      winner = col;
      break;
    }
  }

  // 틱택토의 오른쪽 아래 대각선 확인
  if (state[0] != BLANK && state[0] == state[4] && state[0] == state[8]) {
    winner = state[0];
  }

  // 틱택토의 왼쪽 아래 대각선 확인
  if (state[2] != BLANK && state[2] == state[4] && state[2] == state[6]) {
    winner = state[2];
  }

  return (winner == player ? WIN : (winner == BLANK ? DRAW : LOSE));
}

// player의 턴인 경우 자신의 점수가 높은 경우를 반환하고,
// 상대방의 턴인 경우 player의 점수가 낮은 경우를 반환한다.
int checkWinnability(int progress, bool isMax)
{
  int turn = (progress & 1 ? PLAYER_O : PLAYER_X);
  int result = checkResult();

  if (progress == 9 || result != DRAW) {
    return result;
  }

  if (isMax) {
    int value = LOSE;
    for (int i = 0; i < 9; i++)
      if (state[i] == BLANK) {
        state[i] = turn;
        value = max(value, checkWinnability(progress + 1, false));
        state[i] = BLANK;

        // 가지치기
        if (value == WIN) {
          break;
        }
      }
    return value;
  }
  else {
    int value = WIN;
    for (int i = 0; i < 9; i++)
      if (state[i] == BLANK) {
        state[i] = turn;
        value = min(value, checkWinnability(progress + 1, true));
        state[i] = BLANK;
        
        // 가지치기
        if (value == LOSE) {
          break;
        }
      }
    return value;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int progress = 0;
  for (int i = 0; i < 9; i++) {
    cin >> state[i];
    if (state[i]) {
      ++progress;
    }
  }


  player = (progress & 1 ? PLAYER_O : PLAYER_X);
  
  string resToChar = "LDW";
  int result = checkWinnability(progress, true);
  cout << resToChar[result] << '\n';
}

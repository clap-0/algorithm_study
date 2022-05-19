#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9]; // 스도쿠 판
vector<pair<int,int> > blankSpace;  // 비어있는 칸들

// 백트래킹을 사용하여 스도쿠 판을 채우는 함수
bool fillBlankSpace(int current) {
  // 모든 빈 칸을 채워 스도쿠를 완성한 경우 true 반환
  if(current == blankSpace.size()) return true;

  // isUsed[i]: current번째 빈 칸에 들어갈 수 있는 수이면 false, 들어갈 수 없으면 true
  bool isUsed[10] = {false};
  int y = blankSpace[current].first, x = blankSpace[current].second;
  
  // 빈 칸을 기준으로 같은 행과 열에서 사용된 수들을 구한다
  for(int i = 0; i < 9; i++) {
    isUsed[sudoku[y][i]] = true;
    isUsed[sudoku[i][x]] = true;
  }
  // 빈 칸이 포함된 3*3 정사각형에서 사용된 수들을 구한다
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      isUsed[sudoku[y / 3 * 3 + i][x / 3 * 3 + j]] = true;
  
  // 빈 칸에 가능한 수들을 전부 넣어보며 나머지 빈 칸들을 채운다
  for(int i = 1; i <= 9; i++)
    if(!isUsed[i]) {
      sudoku[y][x] = i;
      // 다음 빈 칸에 대해서 시도해보고, 이후에 스도쿠가 완성되었다면 true 반환
      if(fillBlankSpace(current + 1)) return true;
      sudoku[y][x] = 0;
    }
  
  // 이전 빈 칸에 값이 잘못 들어가 스도쿠판을 채울 수 없는 경우 false 반환
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++) {
      cin >> sudoku[i][j];
      if(sudoku[i][j] == 0) blankSpace.push_back({i, j});
    }

  fillBlankSpace(0);
  
  // 스도쿠 판이 완성된 경우 출력
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++)
      cout << sudoku[i][j] << ' ';
    cout << '\n';
  }
}

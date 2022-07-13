#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

int N, M;
bool visited[MAX * MAX][MAX * MAX]; // 두 좌표(y * MAX + x)를 코인이 방문했는지 여부를 저장한다. 좌표가 오름차순이 되도록만 저장한다.
bool board[MAX][MAX]; // 보드의 정보를 저장한다. true면 벽, false면 빈 칸.

// 넓이우선탐색을 이용하여 coins에 저장된 두 동전 중 하나만 보드에서 떨어뜨리기 위해
// 눌러야 하는 버튼 수의 최솟값을 구한다. 불가능하거나 10번보다 많이 눌러야한다면 -1을 반환한다.
int bfs(vector<int> &coins)
{
  queue<pair<int,int> > Q;
  Q.push({coins[0], coins[1]});
  visited[coins[0]][coins[1]] = true;
  
  int ret = 1;  // 버튼을 누르는 횟수
  while(!Q.empty() && ret <= 10)
  {
    int qSize = Q.size();
    while(qSize--)
    {
      int y1 = Q.front().first / MAX, x1 = Q.front().first % MAX; // 1번 동전의 y좌표와 x좌표
      int y2 = Q.front().second / MAX, x2 = Q.front().second % MAX; // 2번 동전의 y좌표와 x좌표
      Q.pop();

      for(int i = 0; i < 4; i++)
      {
        int ny1 = y1 + dy[i], nx1 = x1 + dx[i];
        int ny2 = y2 + dy[i], nx2 = x2 + dx[i];

        // 버튼을 눌러 두 코인이 이동할 좌표가 각각 보드의 바깥인지 구한다.
        bool isOut1 = ny1 < 0 || nx1 < 0 || ny1 >= N || nx1 >= M;
        bool isOut2 = ny2 < 0 || nx2 < 0 || ny2 >= N || nx2 >= M;

        if(isOut1 ^ isOut2) // 둘 중 하나의 코인만 보드의 바깥인 경우
          return ret;
        else if(!(isOut1 && isOut2))  // 두 코인 모두 보드의 안쪽인 경우
        {
          // 코인이 이동할 위치가 벽인 경우 이동시키지 않는다.
          if(board[ny1][nx1])
          {
            ny1 = y1;
            nx1 = x1;
          }
          if(board[ny2][nx2])
          {
            ny2 = y2;
            nx2 = x2;
          }

          int pos1 = ny1 * MAX + nx1, pos2 = ny2 * MAX + nx2;
          if(pos1 > pos2) // pos1 <= pos2를 만족하도록 강제한다.
            swap(pos1, pos2);

          if(visited[pos1][pos2])
            continue;

          Q.push({pos1, pos2});
          visited[pos1][pos2] = true;
        }
      }
    }
    ++ret;
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  vector<int> coins;
  cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
    {
      char ch;
      cin >> ch;
      switch(ch)
      {
        case 'o':
          coins.push_back(i * MAX + j);
          break;
        case '#':
          board[i][j] = 1;
          break;
        default: ;
      }
    }

  cout << bfs(coins) << '\n';
}

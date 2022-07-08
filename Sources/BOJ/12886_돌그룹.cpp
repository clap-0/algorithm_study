#include <iostream>
#include <queue>
using namespace std;

// visited[i][j] = 돌 그룹 중에서 가장 적은 수가 i개이고, 가장 많은 수가 j개인 그룹을 탐색했는지 저장
bool visited[501][501];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int A, B, C;
  cin >> A >> B >> C;

  // 너비 우선 탐색 알고리즘
  int sum = A + B + C;
  bool ans = false;
  queue<pair<int,int> > Q;
  // 돌그룹에서 {가장 적은 그룹, 가장 많은 그룹}을 큐에 넣는다
  Q.push({min(A, min(B, C)), max(A, max(B, C))});
  visited[min(A, min(B, C))][max(A, max(B, C))] = true;
  while(!Q.empty())
  {
    int group[3] = {Q.front().first, Q.front().second, sum - group[0] - group[1]};
    Q.pop();

    // 모든 그룹의 돌의 개수가 같으면 탐색 종료
    if(group[0] == group[1] && group[1] == group[2])
    {
      ans = true;
      break;
    }

    for(int i = 0; i < 3; i++)
    {
      int X = min(group[(i + 2) % 3], group[(i + 1) % 3]), Y = max(group[(i + 2) % 3], group[(i + 1) % 3]);
      Y -= X; X *= 2; // 단계에 따라 Y = Y - X , X = X + X 를 실행한다
      int minElement = min(group[i], min(X, Y)), maxElement = max(group[i], max(X, Y));
      if(!visited[minElement][maxElement])
      {
        visited[minElement][maxElement] = true;
        Q.push({minElement, maxElement});
      }
    }
  }
  
  cout << ans << '\n';
}

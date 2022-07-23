#include <iostream>
#include <queue>
using namespace std;

int belt[200];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K, NN;
  cin >> N >> K;
  NN = 2 * N;
  for(int i = 0; i < NN; i++)
    cin >> belt[i];
  
  // start : 올리는 위치, step : 진행중인 단계
  int start = 0, step = 0;
  // 로봇의 현재 위치 저장
  queue<int> robots;
  
  while(K > 0)
  {
    // 올리는 위치와 내리는 위치를 한 칸씩 줄여 벨트가 회전한 것과 동일한 효과를 낸다.
    start = (start - 1 + NN) % NN;
    int end = (start - 1 + N) % NN;
    
    // 가장 먼저 벨트에 올라간 로봇부터 한 칸 이동할 수 있다면 이동시킨다.
    int robotsCnt = robots.size(), prevRobot = -1;
    while(robotsCnt--)
    {
      int pos = robots.front();
      robots.pop();
      // 벨트의 회전으로 로봇이 내리는 위치에 도달하면 내린다.
      if(pos == end)
        continue;
      int nextPos = (pos + 1) % NN;
      // 이동하려는 칸에 내구도가 1 이상이고, 로봇이 없다면 이동한다.
      if(belt[nextPos] && nextPos != prevRobot)
      {
        if(--belt[nextPos] == 0)
          --K;
        // 로봇이 이동한 칸이 내리는 위치이면 내린다.
        if(nextPos == end)
          continue;
        // 로봇이 이동한 경우와 이동하지 못한 경우를 모두 표현하기 위해 pos를 바꾼다.
        pos = nextPos;
      }
      robots.push(pos);
      prevRobot = pos;
    }

    // 올리는 위치의 내구도가 0이 아니면 로봇을 올린다.
    if(belt[start])
    {
      robots.push(start);
      if(--belt[start] == 0)
        --K;
    }
    ++step;
  }
  cout << step << '\n';
}

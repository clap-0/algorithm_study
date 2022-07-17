#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
bool visited[MAX];

// 버튼 B를 눌렀을 때 N이 변하게 되는 수를 반환하는 함수
int buttonB(int N)
{
  N *= 2;
  for(int i = 10000; i >= 1; i /= 10)
    if(N / i)
      return N - i;
  return 0;
}

// N을 G로 바꾸는 데에 눌러야 하는 버튼 수의 최솟값을 넓이우선탐색으로 구하는 함수
// T번보다 많이 눌러야하거나 바꿀 수 없는 경우 -1을 반환한다.
int bfs(int N, int T, int G)
{
  queue<int> Q;
  Q.push(N);
  visited[N] = true;
  int ret = 0;
  while(!Q.empty() && ret <= T)
  {
    int qSize = Q.size();
    while(qSize--)
    {
      int curr = Q.front();
      Q.pop();
      // N을 G로 바꾸는 것에 성공한 경우 버튼을 누른 횟수를 반환한다.
      if(curr == G)
        return ret;
      // 버튼 A를 누르는 경우
      if(curr + 1 < MAX && !visited[curr + 1])
      {
        Q.push(curr + 1);
        visited[curr + 1] = true;
      }
      // 버튼 B를 누르는 경우
      if(curr * 2 < MAX)
      {
        int next = buttonB(curr);
        if(!visited[next])
        {
          Q.push(next);
          visited[next] = true;
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

  int N, T, G;
  cin >> N >> T >> G;
  
  int ans = bfs(N, T, G);
  if(ans != -1)
    cout << ans << '\n';
  else
    cout << "ANG\n";
}

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool isPrime[10000];  // isPrime[i] = i가 소수면 true, 소수가 아니거나 1000 미만의 수이면 false.
bool visited[10000];  // bfs()에서 각 숫자의 방문 여부

// 에라토스테네스의 체 알고리즘을 이용하여
// isPrime 배열을 완성한다
void eratosthenes()
{
  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i < 100; i++)
    if(isPrime[i])
      for(int j = i * i; j < 10000; j += i)
        isPrime[j] = false;
  
  // 1000 미만의 비밀번호를 허용하지 않도록 하기 위해 isPrime[k] = false로 한다. (k < 1000)
  memset(isPrime, false, sizeof(bool) * 1000);
}

// 넓이우선탐색 알고리즘을 이용하여
// 비밀번호 S에서 E로 변경하는 데에 필요한 최소 횟수를 반환한다.
// 불가능한 경우 -1을 반환한다.
int bfs(int S, int E)
{
  memset(visited, false, sizeof(visited));
  queue<int> Q;
  Q.push(S);
  visited[S] = true;

  int cnt = 0;
  while(!Q.empty())
  {
    int qSize = Q.size();
    while(qSize--)
    {
      int curr = Q.front();
      Q.pop();
      
      // 비밀번호를 성공적으로 변경한 경우 횟수 cnt 반환
      if(curr == E)
        return cnt;

      // curr에서 하나의 자리만을 변경하여 나오는 1000 이상의
      // 아직 확인하지 않은 소수들을 모두 큐에 넣는다
      for(int i = 10, j = 1; i <= 10000; i *= 10, j *= 10)
        for(int k = 0; k < 10; k++)
        {
          // next는 curr에서 j의 자릿수만을 k로 변경한 수
          int next = (curr / i * i) + (k * j) + (curr % j);
          if(isPrime[next] && !visited[next])
          {
            Q.push(next);
            visited[next] = true;
          }
        }
    }
    ++cnt; 
  }

  // 비밀번호 변경이 불가능한 경우 -1 반환
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  eratosthenes();

  int T;
  cin >> T;
  while(T--)
  {
    int oldPassword, newPassword;
    cin >> oldPassword >> newPassword;
    int ans = bfs(oldPassword, newPassword);
    if(ans != -1)
      cout << ans << '\n';
    else
      cout << "Impossible\n";
  }
}

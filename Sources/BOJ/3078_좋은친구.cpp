#include <iostream>
#include <queue>
using namespace std;

// nameLength[i] = 이름의 길이가 i인 학생의 수
int nameLength[21];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N >> K;

  long long ans = 0;
  queue<int> Q;
  string name;
  // 등수가 i인 학생에 대해서 그보다 등수 차이가 K를 넘지 않는
  // 학생들의 이름 길이를 큐에 넣는다. K를 넘는 학생들은 바로바로 큐에서 뺀다.
  // 즉, 큐의 길이를 K로 유지한다.
  for(int i = 0; i < N; i++)
  {
    cin >> name;
    Q.push(name.length());
    ans += nameLength[name.length()]++;
    if(i >= K)
    {
      --nameLength[Q.front()];
      Q.pop();
    }
  }

  cout << ans << '\n';
}

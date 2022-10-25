#include <iostream>
#include <stack>
using namespace std;

stack<int> note[6];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, P;
  cin >> N >> P;
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    int stringNum, fretNum;
    cin >> stringNum >> fretNum; 
    --stringNum;
    // 주어진 번호의 기타 줄을 누르고 있는 가장 높은 프렛의 번호가 
    // 현재 연주해야 하는 프렛의 번호보다 큰 경우 해당 손가락을 뗀다
    while (!note[stringNum].empty() && note[stringNum].top() > fretNum) 
    {
      note[stringNum].pop();
      ++ans;
    }
    // 해당 줄을 누르고 있는 손가락이 없거나, 누르고 있는 가장 높은 프렛의 번호가
    // 현재 연주해야 하는 프렛의 번호보다 작으면 주어진 번호의 프렛을 누른다.
    if (note[stringNum].empty() || note[stringNum].top() < fretNum) 
    {
      note[stringNum].push(fretNum);
      ++ans;
    }
  }
  cout << ans << '\n';
}

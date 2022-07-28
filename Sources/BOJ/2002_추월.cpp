#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> enterOrder;
bool discovered[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  string carNumber;
  cin >> N;
  // 각 차량번호의 입장순서를 저장한다.
  for(int i = 0; i < N; i++)
  {
    cin >> carNumber;
    enterOrder[carNumber] = i;
  }

  int ans = 0, order = 0;
  for(int i = 0; i < N; i++)
  {
    cin >> carNumber;
    discovered[enterOrder[carNumber]] = true;
    // 출구로 나간 차량이 순서에 맞게 나갔다면 아직 안 나간 차량 중 가장 작은 것이 다음 순서이다.
    if(enterOrder[carNumber] == order)
      while(discovered[order])
        ++order;
    else
      ++ans;
  }
  cout << ans << '\n';
}

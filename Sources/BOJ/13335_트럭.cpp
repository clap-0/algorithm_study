#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, w, L;
  cin >> n >> w >> L;
  
  // 다리의 왼쪽부터 오른쪽까지 하나의 단위길이마다 위에 있는 트럭의 무게를 큐에 저장한다.
  // 위에 트럭이 없을 경우 0을 저장한다.
  queue<int> Q;
  int totalWeight = 0, ans = 0;
  // 큐 Q의 size가 w이도록 유지시킨다.
  for(int i = 0; i < w; i++)
    Q.push(0);
  for(int i = 0; i < n; i++)
  {
    int weight;
    cin >> weight;
    // 다리 위의 트럭무게의 합(totalWeight)이 L이하일 때까지 트럭을 움직인다.
    // i번째 트럭이 들어갈 공간을 만들기 위해 while문이 끝났을 때 큐의 길이가 w - 1이도록 한다.
    while(true)
    {
      totalWeight -= Q.front();
      Q.pop();
      ++ans;
      if(totalWeight + weight <= L)
        break;
      Q.push(0);
    }
    // 다리의 오른쪽 끝에 트럭을 놓는다.
    Q.push(weight);
    totalWeight += weight;
  }
  cout << ans + w << '\n';
}

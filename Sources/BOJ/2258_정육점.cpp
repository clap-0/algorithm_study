#include <iostream>
#include <algorithm>
using namespace std;

// meats[i] = {고깃덩어리의 무게 , 가격}
pair<int,int> meats[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> meats[i].first >> meats[i].second;
  
  // 각 고깃덩어리들을 가격에 대해 오름차순 정렬한다.
  // 가격이 같은 경우, 무게에 대해 내림차순 정렬한다.
  sort (meats, meats + n, [](pair<int,int> &a, pair<int,int> &b) {
    if (a.second != b.second)
      return a.second < b.second;
    return a.first > b.first;
  });

  int weight = meats[0].first, price = meats[0].second;
  int ans = (weight >= m ? price : -1); // 0번째 고깃덩어리가 필요한 양 이상이면 해당 고기의 가격으로 초기화
  for (int i = 1; i < n; i++) {
    // i번째 고기가 (i-1)번째 고기와 가격이 같다면 모두 사는 경우로 가정한다.
    if (meats[i - 1].second == meats[i].second)
      price += meats[i].second;
    else
      price = meats[i].second;
    
    // i번째 고기까지 구매했을 때의 무게가 필요한 양 이상이고
    // 동일한 가격의 고깃덩어리 여러개를 사는 것보다 그보다 비싼 고기 하나 사는게 이득인 경우
    if ((weight += meats[i].first) >= m && (ans == -1 || ans > price))
      ans = price;
  }
  cout << ans << '\n';
}

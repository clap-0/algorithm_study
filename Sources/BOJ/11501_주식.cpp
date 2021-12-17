#include <iostream>
#include <algorithm>
using namespace std;

int price[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> price[i];
    
    // 뒤에서부터 maxPrice보다 작은 주가들은 사고
    // maxPrice보다 큰 주가가 있을 시 maxPrice에 대입한다
    int maxPrice=0;
    long long ans=0;
    for(int i=N-1; i>=0; i--)
      if(price[i] < maxPrice) ans += maxPrice - price[i];
      else maxPrice = price[i];
    cout << ans << '\n';
  }
}

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--){
    long long x, y, dist;
    cin >> x >> y;
    dist=y-x;
    long long a=(int)sqrt(dist);
    //두 지점사이의 거리가 제곱수인 경우
    if(dist==a*a) cout << 2*a-1 << '\n';
    //제곱수가 아니고, (a^2,a^2+a]범위 내의 수일 경우
    else if(a*a<dist&&dist<=a*a+a) cout << 2*a << '\n';
    //(a^2+a,(a+1)^2)범위 내의 수일 경우
    else cout << 2*a+1 << '\n';
  }
}

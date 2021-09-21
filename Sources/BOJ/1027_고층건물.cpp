#include <iostream>
using namespace std;
int N;
int height[50];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N;
  for(int i=0; i<N; i++) cin >> height[i];
  int ans=0;
  int canSee[50]={0};
  long long dy, dx;
  // 1. 자신의 오른쪽에 있는 빌딩들에 대하여 가장 최근에 본 빌딩과의 기울기보다 기울기가 더 큰 빌딩만을 볼 수 있다
  // 2. 빌딩 A가 빌딩 B를 볼 수 있는 경우 빌딩 B도 빌딩 A를 볼 수 있다
  for(int n=0; n<N; n++){
    dy=-1000000000, dx=1;
    for(int i=n+1; i<N; i++){
      //실수비교연산의 오차를 고려하지 않기 위해 식 dy/dx < (height[i]-height[n])/(i-n)을 풀어서 계산했다
      if(dy*(i-n)<dx*(height[i]-height[n])){
        dy=height[i]-height[n], dx=i-n;
        canSee[n]++;
        canSee[i]++;
      }
    }
    ans=max(ans, canSee[n]);
  }
  cout << ans << '\n';
}

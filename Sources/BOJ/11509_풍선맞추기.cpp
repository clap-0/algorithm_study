#include <iostream>
using namespace std;

int H[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, ans=0;
  cin >> N;
  for(int i=0; i<N; i++){
    int height;
    cin >> height;
    // height위치에 있는 풍선 왼쪽에 height+1위치인 풍선이 있는 경우
    if(H[height+1]){
      H[height+1]--;
      H[height]++;
    } else {
      H[height]++;
      ans++;
    }
  }
  cout << ans << '\n';
}

#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int r, c, q;
  int brightness;
  int psum[1001][1001]={0};
  cin >> r >> c >> q;
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++){
      cin >> brightness;
      psum[i][j]+=(brightness+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]);
    }
  while(q--){
    int r1,c1,r2,c2;
    int ans;
    cin>>r1>>c1>>r2>>c2;
    ans=psum[r2][c2]-psum[r2][c1-1]-psum[r1-1][c2]+psum[r1-1][c1-1];
    ans/=(r2-r1+1)*(c2-c1+1);
    cout << ans << '\n';
  }
}

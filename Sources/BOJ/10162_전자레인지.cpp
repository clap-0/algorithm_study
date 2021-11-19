#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  int button[3] = {300, 60, 10}, ans[3];
  cin >> T;
  int temp = T, sum=0;
  for(int i=0; i<3; i++){
    ans[i] = temp / button[i];
    temp %= button[i];
    sum += ans[i]*button[i];
  }
  if(sum == T){
    for(int a : ans) cout << a << ' ';
  }
  else cout << -1 << '\n';
}

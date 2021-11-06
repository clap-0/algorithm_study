#include <iostream>
using namespace std;
int A[10];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  cin >> N >> K;
  for(int i=N-1; i>=0; i--) cin >> A[i];
  int ans=0;
  for(int i=0; i<N; i++){
    ans += K/A[i];
    K %= A[i];
  }
  cout << ans << '\n';
}

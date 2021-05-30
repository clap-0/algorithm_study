#include <iostream>
using namespace std;
const int MAX=200000;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, q, sum=0;
  int a[MAX], m[MAX];
  cin >> n >> q;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) sum += m[i] = a[i]*a[(i+1)%n]*a[(i+2)%n]*a[(i+3)%n];
  while(q--){
    int select;
    cin >> select; select--;
    for(int i=0; i<4; i++){
      m[(select+n-i)%n]*=-1;
      sum+=m[(select+n-i)%n]*2;
    }
    cout << sum << '\n';
  }
}

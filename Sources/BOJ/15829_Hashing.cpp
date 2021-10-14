#include <iostream>
using namespace std;
const int MOD=1234567891;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int L;
  string A;
  long long H=0ll, r=1ll;
  cin >> L >> A;
  for(int i=0; i<L; i++){
    H=(H+(A[i]-'a'+1)*r%MOD)%MOD;
    r=(r*31)%MOD;
  }
  cout << H << '\n';
}

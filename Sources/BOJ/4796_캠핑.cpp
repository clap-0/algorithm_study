#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc=0;
  while(1){
    int L, P, V;
    cin >> L >> P >> V;
    if(L==0) break;
    cout << "Case " << ++tc << ": " << V/P*L + min(V%P, L) << '\n';
  }
}

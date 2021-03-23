#include <iostream>
using namespace std;
int gcd(int p, int q){
  if(q==0) return p;
  return gcd(q, p%q);
}
int main()
{
  int x, y, a;
  cin >> x >> y;
  a=gcd(x, y);
  cout << x+y-a << endl;
  return 0;
}

#include <iostream>
using namespace std;
int GCD(int p, int q){
  if(q==0) return p;
  return GCD(q, p%q);
}
int main()
{
  int a, b, gcd, lcm;
  cin >> a >> b;
  gcd=GCD(a,b);
  lcm=(a*b)/gcd;
  cout << gcd << '\n' << lcm << '\n';
}

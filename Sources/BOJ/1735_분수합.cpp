#include <iostream>
using namespace std;
int gcd(int p, int q){
  if(q==0) return p;
  return gcd(q, p%q);
}
int main()
{
  pair<int, int> frc1, frc2, simple; //두 분수와 기약분수
  cin >> frc1.first >> frc1.second;
  cin >> frc2.first >> frc2.second;
  simple.first = frc1.first*frc2.second + frc1.second*frc2.first;
  simple.second = frc1.second*frc2.second;
  int aliquot=gcd(simple.first, simple.second);
  simple.first/=aliquot, simple.second/=aliquot;
  cout << simple.first << ' ' << simple.second << endl;
  return 0;
}

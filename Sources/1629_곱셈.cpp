#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ullint;
ullint solve(ullint a, ullint b, ullint c)
{
  if(b==1) return a%c;
  if(b%2) return (solve(a, b-1, c) * a)%c; //b가 홀수면 a^b == a * a^(b-1)
  else { //b가 짝수면 a^b == a^(b/2) * a^(b/2)
    ullint power = solve(a, b/2, c);
    return (power*power)%c;
  }
}
int main()
{
  ullint a, b, c;
  cin >> a >> b >> c;
  cout << solve(a, b, c) << endl;
  return 0;
}

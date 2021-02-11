#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string cantorSet(string s)
{
  if(s.length()==1) return s; // 기저사례:호출된 문자열길이가 1일때
  int size = s.length()/3;
  s.replace(size, size, size, ' '); // 가운데 문자열 공백변환
  s.replace(0, size, cantorSet(s.substr(0, size))); // 왼쪽 문자열 재귀호출 통해 변환
  s.replace(size*2, size, cantorSet(s.substr(size*2, size))); // 오른쪽 문자열 재귀호출 통해 변환
  return s;
}
int main()
{
  int n;
  string s;
  while(cin >> n){
    s.assign(pow(3,n),'-');
    cout << cantorSet(s) << endl;
  }
  return 0;
}

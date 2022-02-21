#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1000000;

int n;
string code;
int cache[5001];

// DP를 이용하여 code[pos..]를 해독할 때 나올 수 있는 경우의 수를 구한다
int decode(int pos = 0) {
  int& ret = cache[pos];
  if(ret != -1) return ret;
  
  // 하나의 암호해독을 발견한 경우 1 반환
  if(pos == n) return 1;
  // A ~ Z가 1 ~ 26에 대응되므로 "0" 혹은 "0X"에 해당하는 암호는 없다
  if(code[pos] == '0') return ret = 0;
  
  // pos위치의 한 자릿수에 해당하는 알파벳으로 암호를 바꾼다
  ret = decode(pos + 1);
  // pos와 pos+1위치의 두 자릿수에 해당하는 알파벳으로 암호를 바꾼다
  if(pos + 2 <= n && stoi(code.substr(pos, 2)) <= 26) ret += decode(pos + 2);
  
  return ret %= MOD;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> code;
  memset(cache, -1, sizeof(cache));
  n = code.length();
  cout << decode() << '\n';
}

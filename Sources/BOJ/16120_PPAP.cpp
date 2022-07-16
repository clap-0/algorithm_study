#include <iostream>
using namespace std;

const string PPAP = "PPAP";

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str;
  cin >> str;

  int len = str.length(), k = 0;
  char *tmp = new char[len];
  for(int i = 0; i < len; i++)
  {
    tmp[k] = str[i];
    if(k >= 3)
    {
      // tmp의 마지막 네 문자열이 "PPAP"인지 확인한다.
      bool isPPAP = true;
      for(int j = 0; j < 4; j++)
        if(tmp[k - 3 + j] != PPAP[j])
        {
          isPPAP = false;
          break;
        }
      
      // 마지막 네 문자열이 "PPAP"이면 뒤의 문자 세 개를 삭제해 "P"로 바꾼다.
      if(isPPAP)
        k -= 3;
    }
    ++k;
  }

  cout << (k == 1 && tmp[0] == 'P' ? "PPAP\n" : "NP\n");
  delete []tmp;
}

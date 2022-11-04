#include <iostream>
using namespace std;

// 문자열 str에 포함된 문자 oldChar들을 모두 newChar로 바꾸는 함수
void convertChar(string& str, char oldChar, char newChar)
{
  for (int i = 0; i < str.size(); i++)
    if (str[i] == oldChar)
      str[i] = newChar;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string A, B;
  cin >> A >> B;

  convertChar(A, '6', '5');
  convertChar(B, '6', '5');
  cout << stoi(A) + stoi(B) << ' ';

  convertChar(A, '5', '6');
  convertChar(B, '5', '6');
  cout << stoi(A) + stoi(B) << '\n';
}

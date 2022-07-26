#include <iostream>
#include <vector>
using namespace std;

vector<string> records; // 눈을 깜빡일 때마다 바뀌는 단어들을 저장한다.

// word라는 단어의 앞부분과 뒷부분이 섞인 단어를 반환한다.
string mixWord(string word)
{
  int len = word.length();
  string ret = "";
  for(int i = 0; i < len; i += 2)
    ret.push_back(word[i]);
  for(int i = len + (len % 2 ? -2 : -1); i >= 0; i -= 2)
    ret.push_back(word[i]);
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int X;
  string word;
  cin >> X >> word;

  // 바뀐 단어가 처음 단어와 같아질 때까지 전부 저장한다.
  string tmp = word;
  while(true)
  {
    records.push_back(tmp);
    tmp = mixWord(tmp);
    if(tmp == word)
      break;
  }

  cout << records[X % records.size()] << '\n';
}

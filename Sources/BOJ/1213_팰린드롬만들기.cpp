#include <iostream>
using namespace std;

int alphabet[26];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string name;
  cin >> name;
  for(char ch : name)
    ++alphabet[ch - 'A'];
  
  int len = name.length(), cnt = (len + 1) / 2;
  string ans;
  ans.resize(len);
  for(int i = 0; i < cnt; i++)
  {
    bool isChanged = false;
    if(len % 2 && i == len / 2)
    {
      for(int j = 0; j < 26; j++)
        if(alphabet[j] >= 1)
        {
          ans[i] = 'A' + j;
          alphabet[j]--;
          isChanged = true;
          break;
        }
    }
    else
    {
      for(int j = 0; j < 26; j++)
        if(alphabet[j] >= 2)
        {
          ans[i] = ans[len - i - 1] = 'A' + j;
          alphabet[j] -= 2;
          isChanged = true;
          break;
        }
    }
    if(!isChanged)
    {
      ans = "I'm Sorry Hansoo";
      break;
    }
  }
  cout << ans << '\n';
}

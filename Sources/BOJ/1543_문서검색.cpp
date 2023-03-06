#include <iostream>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string document, word;
  getline(cin, document);
  getline(cin, word);

  int ans = 0;
  int i = 0;
  int docLength = document.length(), wordLength = word.length();
  while (i < docLength) {
    int j = 0;
    while (j < wordLength && i + j < docLength && word[j] == document[i + j]) ++j;
    if (j == wordLength) {
      ++ans;
      i += wordLength;
    }
    else ++i;
  }

  cout << ans << '\n';
}

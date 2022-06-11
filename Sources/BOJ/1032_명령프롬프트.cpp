#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  string pattern;
  cin >> N >> pattern;
  for(int n = 1; n < N; n++) {
    string filename;
    cin >> filename;
    for(int i = 0; i < pattern.length(); i++) {
      if(pattern[i] == '?') continue;
      else if(pattern[i] != filename[i]) pattern[i] = '?';
    }
  }
  cout << pattern << '\n';
}

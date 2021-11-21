#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int alphabetToNum[26];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    string word;
    cin >> word;
    int wordLen = word.length();
    for(int i=0; i<wordLen; i++){
      alphabetToNum[word[i]-'A'] += pow(10, wordLen-i-1);
    }
  }
  
  sort(alphabetToNum, alphabetToNum+26, greater<int>());

  int ans=0;
  for(int i=9; i>0; i--){
    ans += i * alphabetToNum[9-i];
  }
  
  cout << ans << '\n';
}

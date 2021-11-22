#include <iostream>
#include <string>
using namespace std;

int alphabetToNum[26];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  string S;
  getline(cin, S);
  
  int SLen = S.length();
  int cnt[2]={0};
  for(int i=0; i<SLen; i++){
    if(i==0 || S[i]!=S[i-1]){
      cnt[S[i]-'0']++;
    }
  }
  cout << min(cnt[0], cnt[1]) << '\n';
}

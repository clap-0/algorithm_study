#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getPartialMatch(string &K)
{
  int m = K.size();
  vector<int> pi(m, 0);
  for(int i=1, matched=0; i<m; i++){
    while(matched>0&&K[i]!=K[matched]) matched = pi[matched-1];
    if(K[i]==K[matched]) pi[i] = ++matched;
  }
  return pi;
}
//KMP알고리즘을 이용해 문자열S에서 문자열K를 찾으면 1, 아님 0반환
bool isKeyword(string &S, string &K)
{
  int n = S.size(), m = K.size();
  vector<int> pi = getPartialMatch(K);
  for(int i=0, matched=0; i<n; i++){
    while(matched>0&&S[i]!=K[matched]) matched = pi[matched-1];
    if(S[i]==K[matched]){
      matched++;
      if(matched==m){
        return 1;
      }
    }
  }
  return 0;
}
int main()
{
  string S, K, temp;
  cin >> temp >> K;
  for(auto &c : temp)
    if(c<'0'||c>'9') S.push_back(c);
  cout << isKeyword(S, K) << endl;
}

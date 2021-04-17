#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> getPartialMatch(string &P){
  int m = P.size();
  vector<int> pi(m, 0);
  for(int i=1, match=0; i<m; i++){
    while(match>0&&P[i]!=P[match]) match=pi[match-1];
    if(P[i]==P[match]) pi[i]=++match;
  }
  return pi;
}
vector<int> kmpSearch(string &T, string &P){
  int n = T.size(), m = P.size();
  vector<int> pi = getPartialMatch(P);
  vector<int> ret;
  for(int i=0, match=0; i<n; i++){
    while(match>0&&T[i]!=P[match]) match=pi[match-1];
    if(T[i]==P[match]){
      match++;
      if(match==m){
        ret.push_back(i-m+2); //문제조건에 따라 +1함
        match=pi[match-1];
      }
    }
  }
  return ret;
}
int main()
{
  string T, P;
  vector<int> ans;
  getline(cin, T);
  getline(cin, P);
  ans = kmpSearch(T, P);
  cout << ans.size() << endl;
  for(auto &index : ans)
    cout << index << ' ';
}

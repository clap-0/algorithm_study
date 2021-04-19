#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> getPartialMatch(string &N)
{
  int m=N.size();
  vector<int> pi(m, 0);
  for(int i=1, matched=0; i<m; i++){
    while(matched>0&&N[i]!=N[matched]) matched=pi[matched-1];
    if(N[i]==N[matched]) pi[i]=++matched;
  }
  return pi;
}
bool kmpSearch(string &H, string &N)
{
  int n=H.size(), m=N.size();
  vector<int> pi=getPartialMatch(N);
  for(int i=0, matched=0; i<n; i++){
    while(matched>0&&H[i]!=N[matched]) matched = pi[matched-1];
    if(H[i]==N[matched]){
      ++matched;
      if(matched==m) return true;
    }
  }
  return false;
}
int main()
{
  string A, B, printed;
  cin >> A >> B >> printed;
  cout << ((kmpSearch(A, printed)&&kmpSearch(B, printed)) ? "YES" : "NO") << '\n';
}

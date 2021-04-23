//KMP알고리즘을 이용한 BOJ 1701 풀이
//접미사 배열(LCP) 이용한 풀이도 가능
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//s의 부분일치테이블 구하기
vector<int> getPartialMatch(string &s){
  int n = s.size();
  vector<int> pi(n, 0);
  for(int i=1, matched=0; i<n; i++){
    while(matched>0&&s[i]!=s[matched]) matched=pi[matched-1];
    if(s[i]==s[matched]) pi[i] = ++matched;
  }
  return pi;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int longest=0;
  //각 접미사의 부분일치테이블을 구하여 가장 큰 값 구하면 가장 긴 부분문자열 길이
  for(int i=0, n=s.size(); i<n-1; i++){
    string suffix = s.substr(i);
    vector<int> pi = getPartialMatch(prefix);
    for(int &length : pi) longest=max(longest, length);
  }
  cout << longest << endl;
}

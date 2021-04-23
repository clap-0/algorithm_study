#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX=200000;
int t;
int group[MAX+1], sa[MAX], lcp[MAX], pos[MAX];
bool comparator(int a, int b){
  if(group[a]!=group[b]) return group[a] < group[b];
  return group[a+t] < group[b+t];
}
void getSuffixArray(string &s){
  int n = s.size();
  for(int i=0; i<n; i++){
    group[i] = s[i];
    sa[i] = i;
  }
  group[n]=-1;
  for(t=1;;t*=2){
    sort(sa, sa+n, comparator);
    int newGroup[MAX]={0};
    for(int i=0; i<n-1; i++) newGroup[i+1] = newGroup[i] + comparator(sa[i], sa[i+1]);
    if(newGroup[n-1]==n-1) break;
    for(int i=0; i<n; i++) group[sa[i]] = newGroup[i];
  }
}
void longestCommonPrefix(string &s){
  int n = s.size();
  int length=0;
  for(int i=0; i<n; i++) pos[sa[i]] = i;
  for(int i=0, k=0; i<n; i++, k=max(k-1, 0)){
    if(pos[i]==n-1) continue;
    for(int j=sa[pos[i]+1]; s[i+k]==s[j+k]; k++);
    lcp[pos[i]] = k;
    length = max(length, k);
  }
  cout << length << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int l;
  string s;
  cin >> l >> s;
  getSuffixArray(s);
  longestCommonPrefix(s);
}

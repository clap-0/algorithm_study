#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Comparator {
  const vector<int>& group;
  int t;
  Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {}
  bool operator() (int a, int b){
    if(group[a]!=group[b]) return group[a] < group[b];
    return group[a+t] < group[b+t];
  }
};
vector<int> getSuffixArray(string &s)
{
  int n=s.size(), t=1;
  vector<int> group(n+1), perm(n);
  for(int i=0; i<n; i++){
    group[i]=s[i];
    perm[i]=i;
  }
  group[n]=-1;
  while(t<n){
    Comparator cmpUsing2t(group, t);
    sort(perm.begin(), perm.end(), cmpUsing2t);
    if((t*=2)>=n) break;
    vector<int> newGroup(n+1, 0);
    newGroup[n]=-1;
    for(int i=0; i<n-1; i++)
      newGroup[perm[i+1]]=newGroup[perm[i]]+cmpUsing2t(perm[i], perm[i+1]);
    group=newGroup;
  }
  return perm;
}
int commonPrefix(string &s, int a, int b){
  int ret=0, n=s.size();
  while(a<n && b<n && s[a]==s[b]){
    a++; b++; ret++;
  }
  return ret;
}
int main()
{
  string s;
  vector<int> suffixArr;
  cin >> s;
  suffixArr = getSuffixArray(s);
  for(auto &p : suffixArr) cout << p+1 << ' ';
  cout << "\nx ";
  for(int i=1; i<s.size(); i++) cout << commonPrefix(s, suffixArr[i-1], suffixArr[i]) << ' ';
}

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
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;

  int n=s.size(), t=1;
  vector<int> group(n+1), sa(n);
  for(int i=0; i<n; i++){
    group[i]=s[i];
    sa[i]=i;
  }
  group[n]=-1;
  while(t<n){
    Comparator cmpUsing2t(group, t);
    sort(sa.begin(), sa.end(), cmpUsing2t);
    if((t*=2)>=n) break;
    vector<int> newGroup(n+1, 0);
    newGroup[n]=-1;
    for(int i=0; i<n-1; i++)
      newGroup[sa[i+1]]=newGroup[sa[i]]+cmpUsing2t(sa[i], sa[i+1]);
    group=newGroup;
  }
  for(int i=0; i<n; i++) cout << sa[i]+1 << ' '; cout <<'\n';

  vector<int> lcp(n);
  for(int i=0, k=0; i<n; i++, k=max(k-1, 0)){
    if(group[i] == n-1) continue;
    for(int j=sa[group[i]+1]; s[i+k]==s[j+k]; k++);
    lcp[group[i]]=k;
  }
  cout << "x ";
  for(int i=0; i<n-1; i++) cout << lcp[i] << ' ';
}

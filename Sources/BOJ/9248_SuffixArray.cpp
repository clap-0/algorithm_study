#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int pos[500001]; //segfault(outOfBound)가 계속 나와서 따로 만듬. (접미사배열을 완성시켰을 때 group[]과 동일)
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

  //접미사 배열을 만드는 맨버-마이어스의 알고리즘
  int n=s.size(), t=1;
  //group[i] = 접미사들을 첫 t글자 기준으로 정렬하고 
  //           첫 t글자가 같은 것끼리 묶었을 때 s[i...]가 속한 그룹번호
  vector<int> group(n+1), sa(n); 
  for(int i=0; i<n; i++){
    group[i]=s[i]; //t==1일 때 각 접미사의 첫글자를 그룹번호로 지정. 어차피 대소관계만 이용하므로.
    sa[i]=i;
  }
  group[n]=-1;
  while(t<n){
    //첫 2t글자 기준으로 sa정렬
    Comparator cmpUsing2t(group, t);
    sort(sa.begin(), sa.end(), cmpUsing2t);
    if((t*=2)>=n) break; //2t글자가 n이상이면 접미사배열 완성
    //2t글자 기준으로 그룹 만들기
    vector<int> newGroup(n+1, 0);
    newGroup[n]=-1;
    for(int i=0; i<n-1; i++)
      newGroup[sa[i+1]] = newGroup[sa[i]]+cmpUsing2t(sa[i], sa[i+1]); //sa[i]와 sa[i+1]의 첫 2t글자 비교해 그룹번호 지정
    group=newGroup;
  }
  for(int i=0; i<n; i++) cout << sa[i]+1 << ' '; cout <<'\n';

  // 최장공통접두사(Longest-Common-Prefix)를 구하는 Kasai's Algorithm
  // 접미사배열상에서 인접한 두 접미사 X, Y의 LCP값이 k(k>0)이면
  // 앞의 한 글자씩 뺀 X', Y'의 LCP값은 최소 k-1임을 이용
  vector<int> lcp(n);
  for(int i=0; i<n; i++) pos[sa[i]] = i; //pos[i]는 i의 접미사배열상의 인덱스번호
  for(int i=0, k=0; i<n; i++, k=max(k-1, 0)){
    if(pos[i] == n-1) continue; //접미사 배열의 마지막 글자는 비교불가능
    //인접한 뒤의 접미사와 겹치는 글자 수 구하기
    for(int j=sa[pos[i]+1]; s[i+k]==s[j+k]; k++);
    lcp[pos[i]]=k;
  }
  cout << "x ";
  for(int i=0; i<n-1; i++) cout << lcp[i] << ' ';
}

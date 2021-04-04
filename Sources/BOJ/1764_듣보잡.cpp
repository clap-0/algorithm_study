#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  set<string> unheard, neverHeardAndSeen;
  cin >> n >> m;
  //듣도 못한 사람 명단 입력받기
  for(int i=0; i<n; i++){
    string name;
    cin >> name;
    unheard.insert(name);
  }
  //보도 못한 사람 명단 입력받으면서
  //각 사람의 이름이 듣도 못한 사람 명단에 있으면
  //듣보잡 명단에 추가
  for(int i=0; i<m; i++){
    string name;
    cin >> name;
    if(unheard.find(name)!=unheard.end())
      neverHeardAndSeen.insert(name);
  }
  cout << neverHeardAndSeen.size() << endl;
  set<string>::iterator iter=neverHeardAndSeen.begin();
  for(; iter!=neverHeardAndSeen.end(); iter++)
    cout << *iter << endl;
  return 0;
}

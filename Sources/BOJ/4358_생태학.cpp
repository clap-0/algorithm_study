#include <iostream>
#include <map>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int treeCnt=0;
  char treeName[31];
  map<string,int> treeMap;
  while(cin.getline(treeName, sizeof(treeName))){
    treeMap[treeName]++;
    ++treeCnt;
  }
  cout << fixed;
  cout.precision(4);
  for(map<string,int>::iterator iter=treeMap.begin(); iter!=treeMap.end(); iter++)
    cout << iter->first << " " << iter->second*100.0/treeCnt << '\n';
}

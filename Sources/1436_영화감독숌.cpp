#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n, cnt=0, i=666;
  string name;
  cin >> n;
  while(cnt!=n){
    name=to_string(i);
    if(name.find("666")!=-1) cnt++;
    i++;
  }
  cout << name << endl;
  return 0;
}

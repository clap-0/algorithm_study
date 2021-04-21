#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  string str;
  set<string> s;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> str;
    s.insert(str);
  }
  int ans = 0;
  for(int i=0; i<m; i++){
    cin >> str;
    if(s.find(str)!=s.end()) ans++;
  }
  cout << ans << endl;
}

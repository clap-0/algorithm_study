#include <iostream>
#include <set>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  set<int> A;
  cin >> n;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    A.insert(a);
  }
  cin >> m;
  for(int i=0; i<m; i++){
    int num;
    cin >> num;
    cout << (A.find(num)!=A.end() ? 1 : 0) << '\n';
  }
}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  vector<int> psum;
  cin >> n >> m;
  psum.push_back(0);
  for(int i=1; i<=n; i++){
    int num;
    cin >> num;
    psum.push_back(psum[i-1]+num);
  }
  for(int i=0; i<m; i++){
    int s, e;
    cin >> s >> e;
    cout << psum[e]-psum[s-1] << '\n';
  }
  return 0;
}

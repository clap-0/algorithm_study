#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, num;
  vector<int> lis;
  cin >> N >> num;
  lis.push_back(num);
  for(int i = 1; i < N; i++) {
    cin >> num;
    if(lis.back() < num) lis.push_back(num);
    else *lower_bound(lis.begin(), lis.end(), num) = num;
  }
  cout << lis.size() << '\n';
}

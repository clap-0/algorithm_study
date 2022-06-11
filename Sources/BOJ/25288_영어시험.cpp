#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  string alp;
  cin >> N >> alp;
  while(N--) 
    cout << alp;
}

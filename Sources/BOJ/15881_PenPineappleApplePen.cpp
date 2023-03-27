#include <iostream>
#include <string>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
  
	int n;
  string str;
  int ans = 0;
	cin >> n >> str;
	for (int i = 0; i < n - 3; i++) {
    if (str.substr(i, 4) == "pPAp") {
      ++ans;
      i += 3;
    }
  }

	cout << ans << '\n';
}

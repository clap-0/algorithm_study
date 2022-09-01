#include <iostream>
#include <algorithm>
using namespace std;

string arr[20000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n, [](string a, string b){
    if (a.length() != b.length())
      return a.length() < b.length();
    return a < b;
  });

  string prev = "";
  for (int i = 0; i < n; i++) {
    if (arr[i] == prev)
      continue;
    cout << arr[i] << '\n';
    prev = arr[i];
  }
}

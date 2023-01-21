#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string,int> um;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string book;
    cin >> book;
    ++um[book];
  }

  vector<pair<string,int> > salesRecord(um.begin(), um.end());
  sort(salesRecord.begin(), salesRecord.end(), [](pair<string,int> &a, pair<string,int> &b) {
    if (a.second != b.second)
      return a.second > b.second;
    return a.first < b.first;
  });

  cout << salesRecord[0].first << '\n';
}

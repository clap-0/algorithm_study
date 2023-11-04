#include <iostream>
using namespace std;

string genes[100000];
pair<int, int> fronts[27];
pair<int, int> backs[27];
bool ans[27];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> genes[i];
    int front = genes[i][0] - 'A', back = genes[i][1] - 'A';
    
    fronts[front] = {fronts[front].first + 1, i};
    backs[back] = {backs[back].first + 1, i};
  }

  int ansCnt = 0;

  for (int i = 0; i < n; i++) {
    int front = genes[i][0] - 'A', back = genes[i][1] - 'A';

    if (!ans[front]) {
      for (int j = 0; j <= front; j++) {
        if (backs[j].first > 1 || 
            (backs[j].first == 1 && backs[j].second != i)) {
          ans[front] = true;
          ++ansCnt;
          break;
        }
      }
    }

    if (!ans[back]) {
      for (int j = 0; j <= back; j++) {
        if (fronts[j].first > 1 || 
            (fronts[j].first == 1 && fronts[j].second != i)) {
          ans[back] = true;
          ++ansCnt;
          break;
        }
      }
    }
  }

  cout << ansCnt << '\n';
  for (int i = 0; i < 27; i++)
    if (ans[i]) {
        cout << (char)('A' + i) << ' ';
    }
}

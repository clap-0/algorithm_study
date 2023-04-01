#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  string colorList;
  cin >> N >> colorList;
  
  int colorCnt[2] = {0};
  char prev = ' ';
  for (int i = 0; i < N; i++) {
    if (colorList[i] != prev) {
      ++colorCnt[colorList[i] == 'B'];
      prev = colorList[i];
    }
  }

  cout << 1 + min(colorCnt[0], colorCnt[1]) << '\n';
}

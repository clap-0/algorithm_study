#include <iostream>
using namespace std;

int heights[500];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int H, W;
  int sum = 0;
  
  cin >> H >> W;
  for (int i = 0; i < W; i++) {
    cin >> heights[i];
  }

  // from left to right
  int maxHeight = -1;
  int temp = 0;
  for (int i = 0; i < W; i++) {
    if (maxHeight <= heights[i]) {
      maxHeight = heights[i];
      sum += temp;
      temp = 0;
    }
    else {
      temp += maxHeight - heights[i];
    }
  }

  // from right to left
  maxHeight = -1;
  temp = 0;
  for (int i = W - 1; i >= 0; i--) {
    if (maxHeight < heights[i]) {
      maxHeight = heights[i];
      sum += temp;
      temp = 0;
    }
    else {
      temp += maxHeight - heights[i];
    }
  }

  cout << sum << '\n';
}

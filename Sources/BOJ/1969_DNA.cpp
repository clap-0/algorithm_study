#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int cnt[50][4];
char intToChar[4] = {'A', 'C', 'G', 'T'};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  unordered_map<char, int> charToInt;
  charToInt['A'] = 0;
  charToInt['C'] = 1;
  charToInt['G'] = 2;
  charToInt['T'] = 3;
  
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    char ch;
    for (int j = 0; j < M; j++) {
      cin >> ch;
      cnt[j][charToInt[ch]]++;
    }
  }

  int distance = 0;
  for (int i = 0; i < M; i++) {
    int idx = max_element(cnt[i], cnt[i] + 4) - cnt[i];
    cout << intToChar[idx];
    for (int j = 0; j < 4; j++) {
      if (j == idx) continue;
      distance += cnt[i][j];
    }
  }
  cout << '\n' << distance << '\n';
}

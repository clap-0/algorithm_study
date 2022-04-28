#include <iostream>
#include <unordered_map>
using namespace std;

int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1}, dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  pair<int,int> king, stone;
  string str;
  cin >> str; king = {str[0]-'A', str[1]-'1'};
  cin >> str; stone = {str[0]-'A', str[1]-'1'};
  cin >> N;

  unordered_map<string,int> dirNum;
  string dir[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
  for(int i = 0; i < 8; i++) dirNum.insert({dir[i], i});

  for(int i = 0; i < N; i++) {
    cin >> str;
    int d = dirNum[str];
    int kx = king.first + dx[d], ky = king.second + dy[d];
    if(ky < 0 || kx < 0 || ky >= 8 || kx >= 8) continue;
    if(kx == stone.first && ky == stone.second) {
      int sx = stone.first + dx[d], sy = stone.second + dy[d];
      if(sx < 0 || sy < 0 || sx >= 8 || sy >= 8) continue;
      stone = {sx, sy};
    }
    king = {kx, ky};
  }
  cout << (char)(king.first + 'A') << (char)(king.second + '1') << '\n';
  cout << (char)(stone.first + 'A') << (char)(stone.second + '1') << '\n';
}

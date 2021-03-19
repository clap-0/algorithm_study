#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int matrix[1024][1024];
int pulling(int y, int x, int size)
{
  if(size==1) return matrix[y][x];
  int half;
  vector<int> ret(4);
  half=size/2;
  ret[0] = pulling(y, x, half);
  ret[1] = pulling(y, x+half, half);
  ret[2] = pulling(y+half, x, half);
  ret[3] = pulling(y+half, x+half, half);
  sort(ret.begin(), ret.end()); //두번째로 큰 수 찾기
  return ret[2];
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> matrix[i][j];
  cout << pulling(0, 0, n) << endl;;
  return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
int n;
int score[2][100000];
int cache[2][100001];
int maxScore(int row, int column)
{
  if(column>=n) return 0;
  int& ret=cache[row][column];
  if(ret!=-1) return ret;
  return ret=max(maxScore((row+1)%2,column+1),maxScore((row+1)%2,column+2))+score[row][column]; //다음 열에서 선택 or 다다음열에서 선택
}
int main()
{
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    for(int i=0; i<n; i++) cin >> score[0][i];
    for(int i=0; i<n; i++) cin >> score[1][i];
    memset(cache, -1, sizeof(cache));
    cout << max(maxScore(0, 0), maxScore(1, 0)) << endl;
  }
  return 0;
}

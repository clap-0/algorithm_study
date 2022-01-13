#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string column[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int R, C;
  char ch;
  cin >> R >> C;
  // 테이블을 입력받아 각 테이블의 열을 위에서 아래로 읽은 형태로 저장한다
  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++) {
      cin >> ch;
      column[j] += ch;
    }
  
  // 열을 읽은 문자열을 뒤집고, 문자열들을 사전순으로 정렬한다
  for(int i=0; i<C; i++) reverse(column[i].begin(), column[i].end());
  sort(column, column+C);
  
  // 가장 긴 접두사의 길이를 구한다
  int maxPrefix = 0;
  for(int i=1; i<C; i++) {
    int j=0, cnt=0;
    while(column[i-1][j]==column[i][j++]) ++cnt;
    maxPrefix = max(cnt, maxPrefix);
  }
  cout << R-1-maxPrefix << '\n';
}

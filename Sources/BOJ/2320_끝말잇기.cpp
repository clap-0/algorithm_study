#include <iostream>
#include <cstring>
using namespace std;

int N;
string words[16];
int cache[5][1 << 16];

// A, E, I, O, U를 각각 0, 1, 2, 3, 4로 바꾸는 함수
int letter2Num(char letter) {
  switch(letter) {
    case 'A': return 0;
    case 'E': return 1;
    case 'I': return 2;
    case 'O': return 3;
    case 'U': return 4;
  }
}

// 단어의 앞글자여야 하는 글자 letter와 현재까지 선택된 단어들을 비트마스킹으로 저장하는 chosenWords를
// 매개변수로 받아 DP를 이용하여 최대 점수를 반환하는 함수
int getMaxScores(int letter, int chosenWords) {
  // 메모이제이션
  int& ret = cache[letter][chosenWords];
  if(ret != -1) return ret;

  ret = 0;
  for(int i = 0; i < N; i++)
    if(!(chosenWords & (1 << i)) && letter2Num(words[i][0]) == letter)
      ret = max(ret, (int)words[i].length() + getMaxScores(letter2Num(words[i].back()), chosenWords | (1 << i)));

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> words[i];

  memset(cache, -1, sizeof(cache));
  int ans = -1;
  for(int i = 0; i < N; i++)
    ans = max(ans, (int)words[i].length() + getMaxScores(letter2Num(words[i].back()), 1 << i));

  cout << ans << '\n';
}

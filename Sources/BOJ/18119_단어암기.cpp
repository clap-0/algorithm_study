#include <iostream>
using namespace std;

// usedAlphabet[i] = i번째 단어에 사용된 알파벳들의 종류를 비트마스크를 이용하여 저장한다.
int usedAlphabet[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    string word;
    cin >> word;
    // 비트마스크를 이용하여 word에 사용된 알파벳의 종류를 저장한다.
    for(char letter : word)
      usedAlphabet[i] |= (1 << (letter - 'a'));
  }

  // memorizedAlphabet = 현재 암기하고 있는 알파벳의 종류를 비트마스크를 이용하여 저장한다.
  int memorizedAlphabet = (1 << 26) - 1;
  for(int i = 0; i < M; i++)
  {
    int o;
    char x;
    cin >> o >> x;
    if(o == 1)  // 주어진 알파벳을 잊는다.
      memorizedAlphabet ^= (1 << (x - 'a'));
    else  // 주어진 알파벳을 기억해난다.
      memorizedAlphabet |= (1 << (x - 'a'));

    // 현재 암기하고 있는 알파벳들로 각각의 단어들을 표현할 수 있는지 확인한다.
    int ans = 0;
    for(int j = 0; j < N; j++)
      if((usedAlphabet[j] & memorizedAlphabet) == usedAlphabet[j])
        ++ans;
    cout << ans << '\n';
  }
}

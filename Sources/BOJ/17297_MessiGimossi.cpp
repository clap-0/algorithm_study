#include <iostream>
using namespace std;

const string word = "Messi Gimossi ";
int cnt;
int wordLength[40];

char getCharOf(int M)
{
  if (M <= wordLength[1])
    return (M > 0 ? word[M - 1] : ' ');
  int i = 2;
  while (i < cnt && wordLength[i] <= M)
    ++i;
  return getCharOf(M - wordLength[i - 1]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int M;
  cin >> M;
  wordLength[0] = 6;
  wordLength[1] = 14;
  for (cnt = 2; wordLength[cnt - 1] + wordLength[cnt - 2] <= M; cnt++)
    wordLength[cnt] = wordLength[cnt - 1] + wordLength[cnt - 2];
  char ans = getCharOf(M);
  if (ans != ' ')
    cout << ans << '\n';
  else
    cout << "Messi Messi Gimossi\n";
} 

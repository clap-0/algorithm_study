#include <iostream>
#include <cstring>
using namespace std;

string dna;
int cache[500][500];

// dna[from..to]에서 길이가 최대가 되는 KOI 유전자의 길이를 구한다
int solve(int from, int to) {
  int& ret = cache[from][to];
  if(ret != -1) return ret;
  
  // [from..to] 범위에 문자가 하나거나 없으면 해당 문자가 없는 걸로 생각하고 종료한다
  if(from >= to) return ret = 0;

  // 양 끝이 a와 t, 혹은 g와 c인 경우
  if((dna[from] == 'a' && dna[to] == 't') || (dna[from] == 'g' && dna[to] == 'c'))
    ret = 2 + solve(from + 1, to - 1);
  
  // dna[from..to]를 XY로 나누어 각각을 길이가 최대가 되도록 구한다
  for(int i = from; i < to; i++) 
    ret = max(ret, solve(from, i) + solve(i + 1, to));
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> dna;
  memset(cache, -1, sizeof(cache));

  cout << solve(0, dna.length() - 1) << '\n';
}

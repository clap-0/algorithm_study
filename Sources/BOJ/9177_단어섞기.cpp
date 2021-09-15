#include <iostream>
#include <cstring>
using namespace std;
string A, B, C;
int aSize, bSize, cSize;
int cache[201][201];
// 첫번째 단어의 접미사 A[a..]와 두번째 단어의 접미사 B[b..]를 통해
// 세번째 단어의 접미사 C[a+b..]를 만들 수 있는지 여부를 DP를 이용하여 구한다.
// aSize+bSize==cSize이므로 별도로 C의 인덱스를 나타내는 변수를 선언하지 않고 a+b를 이용한다
int canMix(int a, int b){
  // 메모이제이션
  int& ret=cache[a][b];
  if(ret!=-1) return ret;
  // 기저사례: A와 B로 C를 형성할 수 있는 경우 1반환
  if(a+b==cSize) return 1;
  ret=0;
  // 일치하는 문자가 있는 경우 해당 문자를 사용했을 때 C를 형성가능한지 확인한다
  if(a<aSize&&A[a]==C[a+b]) ret|=canMix(a+1, b);
  if(b<bSize&&B[b]==C[a+b]) ret|=canMix(a, b+1);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> A >> B >> C;
    aSize=A.size(), bSize=B.size(), cSize=C.size();
    memset(cache, -1, sizeof(cache));
    cout << "Data set " << t << ": " << (canMix(0,0) ? "yes" : "no") << '\n';
  }
}

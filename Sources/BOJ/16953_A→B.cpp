#include <iostream>

using namespace std;

// 그리디 알고리즘을 이용한 풀이
// B에서 A로 거꾸로 거슬러 올라가며 구한다
int greed(int A, int B){
  int ret = 1;
  while(1){
    if(A > B) return -1;
    if(A == B) return ret;

    if(B % 2 == 0) B /= 2;
    else if(B % 10 == 1) B /= 10;
    else return -1;
    ++ret;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int A, B;
  cin >> A >> B;
  
  cout << greed(A, B) << '\n';
}

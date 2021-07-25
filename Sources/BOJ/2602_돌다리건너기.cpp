#include <iostream>
#include <cstring>
using namespace std;
string scroll;
string bridge[2];
int N, M;
int cache[2][100][20];
//DP를 이용하여 돌다리의 종류와 현재 위치, 두루마리의 현재 글자가 주어질 때
//다리를 건너갈 수 있는 방법의 수 출력
int crossingBridge(bool type, int stone, int letter){
  //기저사례 : 두루마리대로 다리를 건넌 경우 1 반환
  if(letter==N) return 1;
  //기저사례 : 돌다리를 다 건너도 두루마리대로 못 건넌 경우 0 반환
  if(stone==M) return 0;
  //메모이제이션
  int& ret = cache[type][stone][letter];
  if(ret!=-1) return ret;
  //현재 돌을 무시하고 다음 돌을 확인한다
  ret=crossingBridge(type, stone+1, letter);
  //현재 돌이 두루마리의 글자와 일치하면 반대쪽 돌다리를 이용한다
  if(bridge[type][stone]==scroll[letter]) ret += crossingBridge(!type, stone+1, letter+1);
  return ret;
}
int main()
{
  cin >> scroll >> bridge[0] >> bridge[1];
  N=scroll.size(); M=bridge[0].size();
  memset(cache, -1, sizeof(cache));
  cout << crossingBridge(false, 0, 0)+crossingBridge(true, 0, 0) << '\n';
}

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
const int START=100; //현재 보고 있는 채널
//숫자 n에 broken에 저장된 수가 있는지 확인. 있으면 True.
bool find(int n, vector<char> broken){ 
  for(auto &p : broken)
    if(to_string(n).find(p)!=string::npos)
      return true;
  return false;
}
//n이 몇자리 수인지 반환
int intLen(int n){
  int ret=1;
  while((n/=10)!=0) ret++;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  vector<char> broken;
  cin >> n >> m;
  broken=vector<char>(m);
  for(int i=0; i<m; i++) //고장난 버튼들
    cin >> broken[i];
  //n을 기준으로 +/-를 최소로 누르는 채널을 찾아
  //(그 채널을 누른 버튼 수 + 누른 +/-수)와 (현재 채널에서 n까지 누른 +/-수) 중 더 작은 답 찾기
  int pushed=0, ret;
  while(1){
    int up = n+pushed, down = n-pushed;
    if(up==START||down==START){ //+/- 누르다 지금 보고있는 채널까지 오면 누른 +/-수가 답
      ret = abs(n-START);
      break;
    }
    if(down>=0&&!find(down, broken)){
      ret = min(pushed+intLen(down), abs(n-START));
      break;
    }
    else if(!find(up, broken)){
      ret = min(pushed+intLen(up), abs(n-START));
      break;
    }
    pushed++;
  }
  cout << ret << '\n';
}

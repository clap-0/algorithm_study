#include <iostream>
#include <vector>
using namespace std;
int n;
long long atk; //초기 공격력
vector<vector<int> > dungeonInfo; //모든방의 정보저장
bool beatDragon(long long maxHP){ //최대생명력이 maxHP일 때 드래곤을 잡을 수 있는지 반환
  long long curHP=maxHP, curATK=atk;
  for(auto roomInfo : dungeonInfo){
    switch(roomInfo[0]){
      case 1: //몬스터 방인 경우
      {
        long long turnsToKill=(roomInfo[2]+curATK-1)/curATK; //몬스터를 죽이는데 걸리는 턴 수
        long long turnsToDie=(curHP+roomInfo[1]-1)/roomInfo[1]; //내가 몬스터한테 죽는데 걸리는 턴 수
        if(turnsToKill > turnsToDie) return false; //죽이기 전에 죽으면 드래곤 못 잡음
        curHP -= roomInfo[1]*(turnsToKill-1); //선공이므로 (내가 죽이는데 걸린 턴 수-1)*(몬스터공격력)만큼 생명력 깎기
        break;
      }
      case 2: //포션 방인 경우
        curATK += roomInfo[1];
        curHP = min(curHP+roomInfo[2], maxHP);
        break;
    }
  }
  return true;
}
int main()
{
  cin >> n >> atk;
  for(int i=0; i<n; i++){
    vector<int> roomInfo(3);
    cin >> roomInfo[0] >> roomInfo[1] >> roomInfo[2];
    dungeonInfo.push_back(roomInfo);
  }
  //이분탐색
  //최대 생명력이 lo일 때는 무조건 드래곤 못 잡음
  //최대 생명력이 hi일 때는 무조건 드래곤 
  long long lo=1, hi=1e18, ans=1e18;
  while(lo<=hi){
    long long mid=(lo+hi)/2;
    if(beatDragon(mid)){
      ans = min(ans, mid);
      hi=mid-1;
    }
    else lo=mid+1;
  }
  cout << ans << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, string>>> rooms;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // p: 플레이어 수    m: 방의 정원
  // l: 플레이어 레벨  n: 닉네임
  int p, m, l;
  string n;

  cin >> p >> m;
  for (int i = 0; i < p; i++) {
    cin >> l >> n;

    // isEntered: i번 플레이어가 기존의 방에 입장했다면 true
    bool isEntered = false;
    for (auto &room : rooms) {
      // 방의 정원이 모두 찬 경우, 다음 방 탐색
      if (room.size() == m) {
        continue;
      }
      // 처음 입장한 플레이어 레벨 기준으로 -10부터 +10까지 입장 가능
      if (room[0].first - 10 <= l && l <= room[0].first + 10) {
        room.push_back({l, n});
        isEntered = true;
        break;
      }
    }

    // 기존 방 중에 입장 가능한 방이 없다면, 새로운 방 생성
    if (!isEntered) {
      rooms.push_back({{l, n}});
    }
  }

  for (auto room : rooms) {
    cout << (room.size() == m ? "Started!\n" : "Waiting!\n");
    // 닉네임이 사전순으로 앞서는 플레이어부터 출력
    sort(room.begin(), room.end(), [](pair<int,string> a, pair<int,string> b) {
      return a.second < b.second;
    });
    for (auto player : room) {
      cout << player.first << ' ' << player.second << '\n';
    }
  }
}

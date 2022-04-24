#include <iostream>
using namespace std;

// N*M 집터내의 높이가 i인 칸의 수를 heightCount[i]에 저장한 후, 누적합으로 만든다
int heightCount[257];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, B;
  int lowest = 256, highest = 0;
  cin >> N >> M >> B;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) {
      int height;
      cin >> height;
      lowest = min(lowest, height); // 집터내에서 가장 낮은 높이
      highest = max(highest, height); // 집터내에서 가장 높은 높이
      heightCount[height]++;  // 집터내의 높이가 height인 칸의 빈도수를 구한다
    }

  // inventory : 가지고 있는 블럭의 개수. B + 높이를 h로 만들려 할 때 부숴야하는 블럭의 수
  // requiredBlocks : 높이를 h로 만들려 할 때 설치해야하는 블럭의 수
  // 두 값 모두 만들려는 높이가 highest일 때로 가정하고 초기화한다.
  int inventory = B, requiredBlocks = 0;
  
  // heightCount를 누적합으로 바꾸고
  // 높이를 highest로 만들기 위해 필요한 블럭의 수를 구한다
  for(int i = lowest; i < highest; i++) {
    heightCount[i + 1] += heightCount[i];
    requiredBlocks += heightCount[i];
  }

  int minTime = 1e9, height;
  for(int h = highest; h >= lowest; --h) {
    // 높이를 h로 만들기 위해 필요한 블럭 수만큼 블럭을 가지고 있는 경우
    if(requiredBlocks <= inventory) {
      // h로 만들 때 드는 시간을 구해 최소값을 구한다
      int time = requiredBlocks + 2 * (inventory - B);
      if(minTime > time) {
        minTime = time;
        height = h;
      }
    }
    if(h > 0) {
      requiredBlocks -= heightCount[h - 1];
      inventory += heightCount[highest] - heightCount[h - 1];
    }
  }

  cout << minTime << ' ' << height << '\n';
}

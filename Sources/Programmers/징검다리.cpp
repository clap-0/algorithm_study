#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 지점사이의 거리가 최소 minDist가 되도록 하기 위해
// 제거해야 하는 바위의 개수를 구한다
int countRemove(int minDist, vector<int>& rocks) {
    int ret = rocks.size(), prev = 0;
    for(int rock : rocks) {
        int dist = rock - prev;
        if(dist >= minDist) {
            prev = rock;
            --ret;
        }
    }
    return ret;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    // countRemove() 함수에서 특정지점과 도착지점 사이의 거리를
    // 쉽게 구하도록 하기 위해 rocks에 distance를 추가했다
    rocks.push_back(distance);
    
    // 이분탐색 알고리즘
    int lo = 0, hi = distance;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(countRemove(mid, rocks) <= n) lo = mid;
        else hi = mid;
    }
    return lo;
}

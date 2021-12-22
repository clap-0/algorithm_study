#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    if(a[0] != b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
  
    // 오름차순 정렬
    sort(routes.begin(), routes.end(), compare);
    
    // 카메라의 위치
    int out = -30001;
    for(vector<int> route : routes) {
        // 현재 카메라의 위치보다 오른쪽에 진입지점이 있는 경우
        // 해당 경로에 카메라가 없으므로 경로의 진출지점에 설치한다
        if(out < route[0]) {
            out = route[1];
            ++answer;
        }
    }
    return answer;
}

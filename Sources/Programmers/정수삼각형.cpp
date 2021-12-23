#include <string>
#include <vector>

using namespace std;

int dp[501];

int solution(vector<vector<int>> triangle) {
    int height = triangle.size();
    // 삼각형의 마지막 행부터 시작해서 위로 올라가며 합이 최대가 되는 경로를 찾는다
    for(int i = height - 1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[j] = triangle[i][j] + max(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}

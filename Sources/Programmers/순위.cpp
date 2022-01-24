#include <string>
#include <vector>

using namespace std;

// path[i][j] = i에서 j로 가는 직.간접적 경로의 유무
bool path[100][100];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(auto& res : results) {
        path[res[0] - 1][res[1] - 1] = true;
    }
    
    // 플로이드 알고리즘을 이용해 도달가능성 찾기
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(!path[i][k]) continue;
            for(int j = 0; j < n; j++) {
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
      
        // i번 선수에게서 승패를 확신할 수 있는 사람의 수가 n-1인 경우를 찾는다
        for(int j = 0; j < n; j++) {
            sum += path[i][j] || path[j][i];
        }
        if(sum == n - 1) {
            ++answer;
        }
    }
    
    return answer;
}

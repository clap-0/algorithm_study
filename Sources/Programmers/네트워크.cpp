#include <string>
#include <vector>

using namespace std;

bool visited[200];

// 깊이우선탐색 알고리즘
void dfs(int here, int n, vector<vector<int>>& computers) {
    visited[here] = true;
    for(int i = 0; i < n; i++) {
        if(computers[here][i] && !visited[i]) {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // 깊이우선탐색을 하며 컴포넌트의 수를 구한다
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n, computers);
            ++answer;
        }
    }
    
    return answer;
}

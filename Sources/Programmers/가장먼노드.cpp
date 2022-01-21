#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[20001];
bool discovered[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    // edge 배열을 이용해 인접리스트 adj를 만든다
    for(vector<int>& e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    // 넓이우선탐색 알고리즘
    // 1을 루트로 하는 트리에서 BFS를 수행한다
    queue<int> Q;
    discovered[1] = true;
    Q.push(1);
    while(!Q.empty()) {
        // 깊이별로 구분짓기 위해 qsize만큼만 반복문을 돌린다
        int qsize = Q.size();
        for(int i = 0; i < qsize; i++) {
            int curr = Q.front();
            Q.pop();
            for(int next : adj[curr]) {
                if(!discovered[next]) {
                    discovered[next] = true;
                    Q.push(next);
                }
            }
        }
        // answer는 가장 마지막으로 돌린 반복문의 횟수(가장 깊은 정점의 개수)가 된다
        answer = qsize;
    }
    return answer;
}

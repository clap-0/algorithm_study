#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// 유니온파인드 알고리즘
int uf[100];

int find(int u){
    if(uf[u] < 0) return u;
    return uf[u] = find(uf[u]);
}

// 섬 u와 v가 직,간접적으로 연결되지 않은 경우 두 섬을 연결시킨다
bool merge(int u, int v){
    u = find(u), v = find(v);
    // 두 섬이 연결되있는 경우 false 반환
    if(u == v) return false;
    uf[v] = u;
    return true;
}

// 다리 건설 비용을 기준으로 오름차순 정렬한다
bool compare(const vector<int>& a, const vector<int>& b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), compare);
    memset(uf, -1, sizeof(uf));
    
    // 크루스칼 알고리즘을 이용하여 최소 스패닝 트리를 만든다
    // 건설 비용이 적은 섬들부터 먼저 연결을 시킨다.
    // 이때 두 섬을 직,간접적으로 연결하는 경로가 있는 경우 해당 건설은 하지 않는다
    int cnt = 0;
    for(auto& cost : costs){
        if(merge(cost[0], cost[1])){
            answer += cost[2];
            if(++cnt == n-1) break;
        }
    }
    return answer;
}

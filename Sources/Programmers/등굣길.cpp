#include <string>
#include <vector>

using namespace std;

int paths[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    paths[1][1] = 1;
    for(vector<int>& puddle : puddles) paths[puddle[1]][puddle[0]] = -1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(paths[i][j] < 0) continue;
            if(i + 1 <= n && paths[i + 1][j] >= 0) paths[i + 1][j] = (paths[i + 1][j] + paths[i][j]) % 1000000007;
            if(j + 1 <= m && paths[i][j + 1] >= 0) paths[i][j + 1] = (paths[i][j + 1] + paths[i][j]) % 1000000007;
        }
    }
    return paths[n][m];
}

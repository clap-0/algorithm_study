#include<vector>
#include<queue>
using namespace std;

bool visited[100][100];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    int n = maps.size(), m = maps[0].size();
    
    queue<pair<int,int> > q;
    q.push({0, 0});
    
    while (!q.empty()) {
        int qsize = q.size();
        
        while (qsize--) {
            int y = q.front().first, x = q.front().second;
            q.pop();
            
            if (y == n - 1 && x == m - 1) {
                return answer;
            }
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m
                        || !maps[ny][nx] || visited[ny][nx])
                    continue;
                
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
        ++answer;
    }
    
    return -1;
}

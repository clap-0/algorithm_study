#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0, N = words.size(), M = begin.length();
    queue<string> Q;
    vector<bool> discovered(N, false);
    
    // 넓이우선탐색 알고리즘
    Q.push(begin);
    while(!Q.empty()) {
        int qsize = Q.size();
        for(int i = 0; i < qsize; i++) {
            string curr = Q.front();
            Q.pop();
            
            // target으로 변환이 완료된 경우 while문의 반복횟수 리턴
            if(curr == target) return answer;
            
            for(int j = 0; j < N; j++) {
                if(discovered[j]) continue;
                
                // curr와 next간의 서로 다른 문자의 개수 diff를 구한다
                string next = words[j];
                int diff = 0;
                for(int k = 0; k < M; k++) {
                    diff += curr[k] != next[k];
                }
                
                // 한 번에 한 개의 알파벳만 변환 가능하므로
                // diff가 1인 경우 변환한다
                if(diff == 1) {
                    Q.push(next);
                    discovered[j] = true;
                }
            }
        }
        ++answer;
    }
    
    return 0;
}

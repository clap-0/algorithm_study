#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> uniforms(n+2, 0);
    
    for(int l : lost){
        --uniforms[l];
    }
    
    for(int r : reserve){
        ++uniforms[r];
    }
    
    for(int i=1; i<=n; i++){
        if(uniforms[i] == -1){
            if(uniforms[i-1] == 1){
                uniforms[i-1] = uniforms[i] = 0;
            }
            else if(uniforms[i+1] == 1){
                uniforms[i+1] = uniforms[i] = 0;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(uniforms[i] != -1){
            ++answer;
        }
    }
    
    return answer;
}

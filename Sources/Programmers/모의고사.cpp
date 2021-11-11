#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int> > mark = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    vector<int> scores(mark.size(), 0);
    
    for(int i=0; i<answers.size(); i++){
        for(int j=0; j<mark.size(); j++){
            if(answers[i] == mark[j][i%mark[j].size()]){
                scores[j]++;
            }
        }
    }
    
    int highestScore = *max_element(scores.begin(), scores.end());
    for(int i=0; i<scores.size(); i++){
        if(scores[i] == highestScore){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compareGenrePlays(pair<string,int> a, pair<string,int> b){
    return a.second>b.second;
}

bool compareGenreSongs(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first) return a.first>b.first;
    return a.second<b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,int> genrePlays;
    // 장르별 재생횟수를 구한 뒤 재생횟수에 대해 내림차순으로 장르를 정렬시킨다
    for(int i=0; i<genres.size(); i++)
        genrePlays[genres[i]]+=plays[i];
    vector<pair<string,int> > genrePlaysVec(genrePlays.begin(), genrePlays.end());
    sort(genrePlaysVec.begin(), genrePlaysVec.end(), compareGenrePlays);
    // 재생횟수가 많은 장르순으로 해당 장르의 노래중 가장 재생횟수가 많은 두 곡을 answer에 삽입한다
    for(auto& p : genrePlaysVec){
        string genre=p.first;
        vector<pair<int,int> > genreSongs;
        for(int i=0; i<genres.size(); i++)
            if(genres[i]==genre)
                genreSongs.push_back({plays[i], i});
        sort(genreSongs.begin(), genreSongs.end(), compareGenreSongs);
        // 장르에 속한 곡이 한 개인 경우를 대비하여 std::min()을 사용했다
        for(int i=0; i<std::min(2lu, genreSongs.size()); i++)
            answer.push_back(genreSongs[i].second);
    }
    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 1. 장르 map을 만든다
    unordered_map<string, vector<pair<size_t, int>>> genreMap;
    for (size_t i = 0; i < genres.size(); ++i)
    {
        genreMap[genres[i]].emplace_back(i, plays[i]);
    }

    // 2. (장르, 장르별 재생 수) vector 만든다
    vector<pair<string, int>> genrePlays;
    for (const auto& [genre, idPlays] : genreMap)
    {
        int sumPlays = 0;
        for (const auto& [id, play] : idPlays)
        {
            sumPlays += play;
        }

        genrePlays.emplace_back(genre, sumPlays);
    }

    // 3. 장르별 재생 수 기준으로 vector 정렬
    sort(genrePlays.begin(), genrePlays.end(), [](const auto& left, const auto& right) { return (left.second > right.second); });

    // 4. 정렬된 vecotr의 장르 순서로 장르 map 순회
    for (const auto& [genre, play] : genrePlays)
    {
        // 5. 장르 별 (고유 식별 번호, 재생 수)를 재생 수 기준 정렬
        vector<pair<size_t, int>>& idPlays = genreMap.at(genre);
        sort(idPlays.begin(), idPlays.end(),
            [](const auto& left, const auto& right) { return (left.second != right.second) ? (left.second > right.second) : (left.first < right.first); });

        // 6. 재생 수 높은 것 기준으로 2개를 뽑아서 추가
        for (size_t i = 0; i < idPlays.size() && i < 2; ++i)
        {
            answer.push_back(static_cast<int>(idPlays[i].first));
        }
    }
    

    return answer;
}

#ifdef LOCAL
int main()
{
    const vector<int>& answer1 = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 }); // [4, 1, 3, 0]

    return 0;
}
#endif
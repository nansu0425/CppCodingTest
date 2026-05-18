#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> participantCount;
    for (const string& name : participant)
    {
        ++participantCount[name];
    }

    unordered_map<string, int> completionCount;
    for (const string& name : completion)
    {
        ++completionCount[name];
    }

    for (const auto& [name, count] : participantCount)
    {
        // 1. 참가자 이름이 완주자에 있는지 확인
        // 2. 참가자 카운트보다 완주자 카운트가 적은지 확인
        auto iter = completionCount.find(name);
        if (iter == completionCount.end() || iter->second < count)
        {
            return name;
        }
    }
    
    return answer;
}

#ifdef LOCAL

int main()
{
    string answer = solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" });

    return 0;
}
#endif
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // 1. 참가자 카운트 맵을 만든다
    unordered_map<string, int> countMap;
    for (const string& p : participant)
    {
        ++countMap[p];
    }

    // 2. 완주할 경우 1을 뺀다
    for (const string& c : completion)
    {
        --countMap[c];
    }

    // 3. 0이 되지 못한 참가자를 찾는다
    for (const auto& [name, count] : countMap)
    {
        if (count > 0)
        {
            return name;
        }
    }
    
    return "";
}

#ifdef LOCAL

int main()
{
    string answer = solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }); // mislav

    return 0;
}
#endif
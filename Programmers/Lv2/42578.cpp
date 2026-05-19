#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    // 1. 종류별 의상의 개수 map 생성
    unordered_map<string, int> categoryToCount;
    for (const auto& cloth : clothes)
    {
        ++categoryToCount[cloth[1]];
    }

    // 2. 입지 않는 경우도 포함해서 의상 종류별 (의상의 개수 + 1)을 모두 곱한다
    for (const auto& [category, count] : categoryToCount)
    {
        answer *= count + 1;
    }

    // 3. 모든 의상을 입지 않는 경우의 수 한 개를 제외
    return answer - 1;
}

#ifdef LOCAL
int main()
{
    int answer1 = solution({ {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} }); // 5
    int answer2 = solution({ {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} }); // 3

    return 0;
}
#endif

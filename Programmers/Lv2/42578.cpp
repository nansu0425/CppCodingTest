#include <string>
#include <vector>
#include <unordered_map>

int solution(std::vector<std::vector<std::string>> clothes) {
    // 의상 종류별 의상의 개수 + 1(착용하지 않는 경우) 모두 곱한 후 모두 1(모두 착용하지 않은 경우)을 뺀다

    // 1. (의상 종류, 의상 개수) map을 만든다
    std::unordered_map<std::string, int> categoryToCount;
    for (const auto& c : clothes)
    {
        ++categoryToCount[c[1]];
    }

    // 2. map을 순회하며 의상 개수 + 1 누적곱
    int answer = 1;
    for (const auto& [category, count] : categoryToCount)
    {
        answer *= count + 1;
    }

    // 3. 1을 뺀후 반환
    return answer - 1;
}

#ifdef LOCAL
int main()
{
    int answer1 = solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}); // 5
    int answer2 = solution({ {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} }); // 3

    return 0;
}
#endif
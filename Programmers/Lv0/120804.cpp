#include <string>
#include <vector>

int solution(int num1, int num2) {
    int answer = num1 * num2;
    return answer;
}

#ifdef LOCAL
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << solution(3, 4) << "\n";
    std::cout << solution(27, 19) << "\n";

    return 0;
}
#endif

#include <string>
#include <vector>

int solution(int num1, int num2) {
    int answer = (num1 == num2) ? 1 : -1;
    return answer;
}

#ifdef LOCAL
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << solution(2, 3) << "\n";
    std::cout << solution(11, 11) << "\n";
    std::cout << solution(7, 99) << "\n";

    return 0;
}
#endif
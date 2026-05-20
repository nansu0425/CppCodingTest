#include <vector>

std::vector<int> solution(std::vector<int> arr)
{
    std::vector<int> answer;
    answer.reserve(arr.size());

    // arr의 원소를 연속으로 중복되지 않도록 answer에 넣는다
    for (int x : arr)
    {
        if (answer.empty() || answer.back() != x)
        {
            answer.push_back(x);
        }
    }

    return answer;
}

#ifdef LOCAL
int main()
{
    return 0;
}
#endif

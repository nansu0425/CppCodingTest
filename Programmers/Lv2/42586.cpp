#include <string>
#include <vector>
#include <queue>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds) {
    std::vector<int> answer;

    size_t front = 0;
    while (front < progresses.size())
    {
        // 1. 진행 중인 작업에 speeds를 더한다
        for (size_t i = front; i < progresses.size(); ++i)
        {
            progresses[i] += speeds[i];
        }

        // 2. 완료된 작업 개수 확인
        int completed = 0;
        while (progresses[front] >= 100)
        {
            ++completed;
            ++front;
            if (front == progresses.size())
            {
                break;
            }
        }

        // 3. 완료된 작업 반영
        if (completed > 0)
        {
            answer.push_back(completed);
        }
    }

    return answer;
}

#ifdef LOCAL
int main()
{
    const auto answer1 = solution({ 93, 30, 55 }, { 1, 30, 5 }); // [2, 1]
    const auto answer2 = solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 }); // [1, 3, 2]

    return 0;
}
#endif
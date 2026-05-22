#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int solution(std::vector<int> priorities, int location) {
    // 1. 실행 대기 큐와 우선순위 맵을 만든다
    std::queue<std::pair<int, size_t>> waitQueue;
    for (size_t i = 0; i < priorities.size(); ++i)
    {
        waitQueue.emplace(priorities[i], i);
    }

    // 2. 우선순위 정렬
    std::sort(priorities.begin(), priorities.end());

    // 3. 무한 반복 루프 시작
    int execCount = 0;
    while (true)
    {
        // 4. 대기 큐에서 프로세스 꺼낸다
        const auto [priority, index] = waitQueue.front();
        waitQueue.pop();

        // 5. 프로세스 우선순위가 가장 높지 않으면 다시 enqueue
        if (priority < priorities.back())
        {
            waitQueue.emplace(priority, index);
        }
        else
        {
            // 6. 가장 높다면 실행 카운트 증가 및 우선순위 pop_back
            ++execCount;
            priorities.pop_back();

            // 7. 해당 프로세스가 location index에 해당하는 프로세스면 카운트 반환
            if (index == location)
            {
                return execCount;
            }
        }    
    }
}

#ifdef LOCAL
int main()
{
    int answer1 = solution({ 2, 1, 3, 2 }, 2); // 1
    int answer2 = solution({ 1, 1, 9, 1, 1, 1 }, 0); // 5

    return 0;
}
#endif
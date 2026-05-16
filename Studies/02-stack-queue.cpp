// W01 5/15 — STL stack/queue drill (1회). 완료.
//
// 각 블록 헤더의 '다룰 API/항목'에 대해 변수 선언·호출·출력까지 구현 완료.

#include <cstddef>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // 콘솔 출력 코드페이지를 UTF-8로 (한글 깨짐 방지)
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // [블록 1] stack 생성·초기화
    // 다룰 항목: 빈 stack, underlying container 지정(stack<int, vector<int>>), 기존 컨테이너로 초기화
    std::cout << "[블록 1] stack 생성·초기화\n";

    {
        std::stack<int> stk1; // default container는 deque

        std::deque<int> dq = { 1, 2, 3, 4 }; // 여러 메모리 청크 + 청크 포인터 맵으로 구성된 자료구조 -> 동적 크기에 적합
        std::stack<int> stk2(dq);
        std::stack<int> stk3(std::move(dq));

        const std::size_t cap = 20;
        std::vector<int> vec; // 하나의 연속된 메모리 -> 크기를 미리 알 수 있을 때 적합
        vec.reserve(cap);
        vec.insert(vec.cend(), { 1, 2, 3, 4 });
        std::stack<int, std::vector<int>> stk4(vec);
        std::stack<int, std::vector<int>> stk5(std::move(vec));
    }

    // [블록 2] stack 연산·소비
    // 다룰 API: push, emplace, top, pop, size, empty / while(!empty) top→pop LIFO 추출
    std::cout << "[블록 2] stack 연산·소비\n";

    {
        std::stack<int> stk1;
        stk1.push(1);
        stk1.push(2);
        stk1.emplace(3);
        stk1.emplace(4); // emplace, push의 동작 차이는 vector의 emplace_back, push_back과 같음
        stk1.top() = 5;
        stk1.pop();
        std::size_t len = stk1.size();
        std::cout << "stk1 (size=" << len << "): ";

        const char* sep = "";
        while (!stk1.empty())
        {
            int x = stk1.top();
            stk1.pop(); // pop하지 않고 순회하는 방법은 없다

            std::cout << sep << x;
            sep = ", ";
        }
        std::cout << "\n";
    }

    // [블록 3] queue 생성·초기화
    // 다룰 항목: 빈 queue, 기존 컨테이너(deque)로 초기화
    std::cout << "[블록 3] queue 생성·초기화\n";

    {
        std::queue<char> q1; // default container는 deque

        std::deque<char> dq = { 'a', 'b', 'c' };
        std::queue<char> q2(dq);

        // vector<char> vec;
        // vec.reserve(20);
        // vec.insert(vec.cend(), {'a', 'b', 'c'});
        // queue<char, vector<char>> q3(vec);
        // vector는 pop_front() 제공하지 않는다 -> deque-backend, list-backend queue만 가능
    }

    // [블록 4] queue 연산·소비
    // 다룰 API: push, emplace, front, back, pop, size, empty / while(!empty) front→pop FIFO 추출
    std::cout << "[블록 4] queue 연산·소비\n";

    {
        std::queue<int> q1;
        q1.push(1);
        q1.push(2);
        q1.emplace(3); // emplace의 push 대비 장점은 stack의 경우와 같다
        q1.emplace(4);

        std::swap(q1.front(), q1.back());
        q1.pop();

        std::cout << "q1 (size=" << q1.size() << "): ";
        const char* sep = "";
        while (!q1.empty())
        {
            int x = q1.front();
            q1.pop(); // queue도 stack처럼 pop 없이 순회 불가

            std::cout << sep << x;
            sep = ", ";
        }
        std::cout << "\n";
    }

    return 0;
}

// W01 5/14 — STL vector drill (1회). 완료.
//
// 각 블록 헤더의 '다룰 API/항목'에 대해 변수 선언·호출·출력까지 구현 완료.

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

struct tracer
{
    int id;

    explicit tracer(int id) : id(id)
    {
        std::cout << "\tctor(" << id << ")\n";
    }

    tracer(const tracer& other) : id(other.id)
    {
        std::cout << "\tcopy(" << id << ")\n";
    }

    tracer(tracer&& other) noexcept : id(other.id)
    {
        std::cout << "\tmove(" << id << ")\n";
    }

    ~tracer()
    {
        std::cout << "\tdtor(" << id << ")\n";
    }
};

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // 콘솔 출력 코드페이지를 UTF-8로 (한글 깨짐 방지)
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // [블록 1] 생성·초기화
    // 다룰 항목: 빈 vector, vector(size, value), initializer_list, 범위 복사
    std::cout << "[블록 1] 생성·초기화\n";

    {
        std::vector<int> arr1;
        std::cout << "arr1: ";
        for (std::size_t i = 0; i < arr1.size(); ++i) // size_t type에 int로 연산하면 위험 (size() - 1)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << arr1[i];
        }
        std::cout << "\n";
    }

    {
        std::vector<int> arr2(10, 1);
        std::cout << "arr2: ";
        bool first = true;
        for (int x : arr2)
        {
            if (!first)
            {
                std::cout << ", ";
            }
            std::cout << x;
            first = false;
        }
        std::cout << "\n";
    }

    std::vector<int> arr3 = { 1, 2, 3, 4, 5 };
    {
        std::cout << "arr3: ";
        const char* sep = "";
        for (int i : arr3)
        {
            std::cout << sep << i;
            sep = ", ";
        }
        std::cout << "\n";
    }

    {
        std::vector<int> arr4(arr3.begin(), arr3.end());
        std::cout << "arr4: ";
        const char* sep = "";
        for (int i : arr4)
        {
            std::cout << sep << i;
            sep = ", ";
        }
        std::cout << "\n";
    }

    // [블록 2] 말단 추가·제거
    // 다룰 API: push_back, emplace_back, pop_back
    std::cout << "[블록 2] 말단 추가·제거\n";

    std::vector<tracer> tracers;
    tracers.reserve(10);

    {
        tracers.push_back(tracer(1)); // ctor(1) -> move(1) -> dtor(1)
        tracer t(2);                  // ctor(2)
        tracers.push_back(t);         // copy(2)
        // dtor(2)
    }

    {
        tracers.emplace_back(3);         // ctor(3)
        tracers.emplace_back(tracer(4)); // ctor(4) -> move(4) -> dtor(4)
        tracer t(5);                     // ctor(5)
        tracers.emplace_back(t);         // copy(5)
        // dtor(5)
    }

    {
        tracers.pop_back(); // dtor(5)
        tracers.pop_back(); // dtor(4)
    }

    tracers.clear(); // dtor(3) -> dtor(2) -> dtor(1)

    // [블록 3] 크기·용량
    // 다룰 API: size, empty, capacity, reserve, resize(n), resize(n, v), shrink_to_fit
    std::cout << "[블록 3] 크기·용량\n";

    {
        std::vector<int> arr1;
        std::cout << std::boolalpha << "arr1: size=" << arr1.size() << ", empty=" << arr1.empty()
            << ", capacity=" << arr1.capacity() << "\n";
    }

    {
        std::vector<int> arr2;
        arr2.reserve(10); // capacity 설정
        for (int i = 0; i < 5; ++i)
        {
            arr2.push_back(i);
        }
        arr2.reserve(13); // 다시 reserve 시도해도 원소 유지
        arr2.reserve(5);  // 더 작은 capacity로 설정 불가 -> 기존 capacity 유지
        std::cout << "arr2: size=" << arr2.size() << ", empty=" << arr2.empty() << ", capacity=" << arr2.capacity() << "\n";
    }

    {
        std::vector<int> arr3 = { 1, 2, 3, 4 };
        arr3.resize(20, 5);   // 원소 개수 20개로 늘림, 새로 추가되는 원소는 5로 초기화
        arr3.resize(25, 2);   // 20개 원소는 5, 그 뒤의 5개 원소는 2
        arr3.resize(10);      // 10개 원소로 줄이지만, capacity는 이전 상태 유지
        arr3.shrink_to_fit(); // capacity를 원소 개수와 같은 10으로 맞춤
        std::cout << "arr3: size=" << arr3.size() << ", empty=" << arr3.empty() << ", capacity=" << arr3.capacity() << "\n";
    }

    // [블록 4] 접근
    // 다룰 API: front, back, operator[], at  (at의 out_of_range는 주석으로만 메모)
    std::cout << "[블록 4] 접근\n";

    {
        std::vector<int> arr1 = { 1, 2, 3, 4, 5 };
        std::swap(arr1.front(), arr1.back()); // front, back은 참조
        std::cout << "arr1: front=" << arr1.front() << ", back=" << arr1.back() << "\n";
        arr1.clear();

        // cout << "arr1: front=" << arr1.front() << ", back=" << arr1.back() << "\n";
        // 표준상 UB, 현재 빌드 기준 Assertion '!this->empty()' failed.

        // cout << "arr1: arr1[arr1.size()]=" << arr1[arr1.size()];
        // 표준상 UB, 현재 빌드 기준 Assertion '__n < this->size()' failed.

        // cout << ", arr1.at(arr1.size())=" << arr1.at(arr1.size()) << "\n";
        // out_of_range exception 발생 (표준 동작)
    }

    // [블록 5] 순회
    // 방식: iterator(begin/end), range-for, indexed for
    std::cout << "[블록 5] 순회\n";

    {
        std::vector<int> arr1 = { 1, 2, 3, 4, 5, 6, 7 };

        {
            std::cout << "iterator(begin/end): ";
            const char* sep = "";
            for (auto iter = arr1.cbegin(); iter != arr1.cend(); ++iter) // 읽기 전용엔 const_iterator
            {
                std::cout << sep << *iter;
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            std::cout << "iterator(rbegin/rend): ";
            const char* sep = "";
            for (auto iter = arr1.crbegin(); iter != arr1.crend(); ++iter) // 거꾸로 순회 시 reverse_iterator
            {
                std::cout << sep << *iter;
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            std::cout << "range-for: ";
            const char* sep = "";
            for (auto x : arr1)
            {
                std::cout << sep << x;
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            std::cout << "indexed for: ";
            const char* sep = "";
            for (std::size_t i = 0; i < arr1.size(); ++i) // size_t type은 size_t type과만 연산해야 안전
            {
                std::cout << sep << arr1[i];
                sep = ", ";
            }
            std::cout << "\n";
        }
    }

    // [블록 6] 중간 삽입·삭제
    // 다룰 API: insert(pos, val), insert(pos, n, val), erase(pos), erase(first, last)
    std::cout << "[블록 6] 중간 삽입·삭제\n";

    {
        std::vector<int> arr1 = { 1, 2, 3, 4, 5 };

        {
            arr1.insert(arr1.cbegin() + 3, { 2, 1 }); // position에 삽입되고 그 자리에 있던 원소는 뒤로 밀림
            arr1.insert(arr1.cbegin() + 5, 3, 2);

            std::cout << "insert: ";
            const char* sep = "";
            for (int x : arr1)
            {
                std::cout << sep << x;
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            arr1.erase(arr1.cbegin() + 7);
            arr1.erase(arr1.cbegin() + 3, arr1.cbegin() + 7); // 제거 원소 범위 [first, last)

            std::cout << "erase: ";
            const char* sep = "";
            for (int x : arr1)
            {
                std::cout << sep << x;
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            arr1.erase(std::remove_if(arr1.begin(), arr1.end(), [](int x) { return (x % 2 == 0); }), arr1.cend());
            // remove_if: 제거 대상이 아닌 원소를 전부 앞으로 옮긴 후 제거 대상 시작 위치 iter 반환
            // remove_if는 swap으로 원소를 옮기므로 non-const iterator 요구

            std::cout << "erase(remove_if): ";
            const char* sep = "";
            for (int x : arr1)
            {
                std::cout << sep << x;
                sep = ", ";
            }
            std::cout << "\n";
        }
    }

    // [블록 7] 알고리즘 (<algorithm>)
    // 다룰 API: sort, reverse, find, lower_bound, upper_bound
    std::cout << "[블록 7] 알고리즘 (<algorithm>)\n";

    {
        std::vector<int> arr1 = { 6, 3, 2, 7, 5, 1, 4 };
        std::vector<std::pair<int, int>> arr2 = { {1, 2}, {3, 2}, {2, 4}, {2, 1}, {4, 3} };

        {
            std::sort(arr1.begin(), arr1.end());

            std::cout << "sort int: ";
            const char* sep = "";
            for (int x : arr1)
            {
                std::cout << sep << x;
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            std::sort(arr2.begin(), arr2.end(),
                [](const auto& p1, const auto& p2) { return std::tie(p1.second, p1.first) < std::tie(p2.second, p2.first); });
            // pair default 정렬 동작은 first 우선 정렬
            // 정렬 조건은 (p1.second != p2.second) ? (p1.second < p2.second) : (p1.first < p2.first)와 같다
            // comparator에서 <= 혹은 >= 비교 시 Strict Weak Ordering 위반 -> UB

            std::cout << "sort pair: ";
            const char* sep = "";
            for (const auto& p : arr2)
            {
                std::cout << sep << "{" << p.first << ", " << p.second << "}";
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            std::reverse(arr1.begin(), arr1.end());

            std::cout << "reverse int: ";
            const char* sep = "";
            for (int x : arr1)
            {
                std::cout << sep << x;
                sep = ", ";
            }
            std::cout << "\n";
        }

        {
            auto iter1 = std::find(arr1.cbegin(), arr1.cend(), 3);
            auto iter2 = std::find(arr1.cbegin(), arr1.cend(), -1);

            std::cout << "find(3): value=" << *iter1 << "\n";
            if (iter2 != arr1.cend()) // end iterator 역참조는 UB
            {
                std::cout << "find(-1): value=" << *iter2 << "\n";
            }
            else
            {
                std::cout << "find(-1): not found\n";
            }
        }

        {
            std::sort(arr1.begin(), arr1.end());
            auto iter1 = std::lower_bound(arr1.cbegin(), arr1.cend(), -1); // -1 이상 첫 위치, 모든 원소 < -1면 end()
            auto iter2 = std::upper_bound(arr1.cbegin(), arr1.cend(), 8);  // 8 초과 첫 위치, 모든 원소 <= 8이면 end()

            std::cout << "lower_bound(-1): " << *iter1 << "\n";
            if (iter2 != arr1.cend()) // end iterator 역참조는 UB
            {
                std::cout << "upper_bound(8): " << *iter2 << "\n";
            }
            else
            {
                std::cout << "upper_bound(8): not found\n";
            }

            arr1.insert(iter2, 8);
            std::cout << "insert 8: ";
            const char* sep = "";
            for (int x : arr1)
            {
                std::cout << sep << x;
                sep = ", ";
            }
            std::cout << "\n";
        }
    }

    // [블록 8] 2D
    // 다룰 항목: vector<vector<int>>(R, vector<int>(C, 0)), 인덱싱, 이중 순회
    std::cout << "[블록 8] 2D\n";

    {
        std::vector<std::vector<int>> dp(4, std::vector<int>(3, 0));

        int next_val = 1;

        std::cout << "dp: \n";
        for (std::vector<int>& row : dp)
        {
            const char* sep = "";
            for (int& x : row)
            {
                x = next_val;
                std::cout << sep << x;
                sep = ", ";
                ++next_val;
            }
            std::cout << "\n";
        }

        std::cout << "dp[2][2]: " << dp[2][2] << "\n";
        std::cout << "dp[0][3]: " << dp[0][2] << "\n";
    }

    return 0;
}

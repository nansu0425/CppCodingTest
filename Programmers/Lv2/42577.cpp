#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

// hash 풀이
//bool solution(std::vector<std::string> phone_book) {
//    // 어떤 번호가 다른 번호의 접두어인 경우 -> false
//
//    // 1. 번호 set을 만든다
//    // 2. prefix len set을 만든다
//    std::unordered_set<std::string> phoneSet;
//    std::unordered_set<size_t> prefixLenSet;
//    for (const std::string& phone : phone_book)
//    {
//        phoneSet.insert(phone);
//        prefixLenSet.insert(phone.size());
//    }
//
//    // 3. 모든 번호 순회
//    for (const std::string& phone : phone_book)
//    {
//        // 4. prefix len set 순회
//        for (size_t prefixLen : prefixLenSet)
//        {
//            // 5. 번호 길이 <= prefix len -> continue
//            if (phone.size() <= prefixLen)
//            {
//                continue;
//            }
//
//            // 6. phone의 prefix len substr이 번호 set에 있으면 false
//            std::string prefix = phone.substr(0, prefixLen);
//            if (phoneSet.count(prefix))
//            {
//                return false;
//            }
//        }
//    
//    }
//
//    return true;
//}

// 정렬 + 인접 비교 풀이
bool solution(std::vector<std::string> phone_book)
{
    // 사전순 정렬 -> 어떤 단어의 prefix인 단어가 존재하는 경우, prefix 단어는 그 단어 바로 앞으로 오게 된다

    std::sort(phone_book.begin(), phone_book.end());

    for (size_t i = 1; i < phone_book.size(); ++i)
    {
        const std::string& prev = phone_book[i - 1];
        const std::string& cur = phone_book[i];

        if (cur.compare(0, prev.size(), prev) == 0)
        {
            return false;
        }
    }

    return true;
}

#ifdef LOCAL
int main()
{
    bool answer1 = solution({ "119", "97674223", "1195524421" }); // false
    bool answer2 = solution({ "123","456","789" }); // true
    bool answer3 = solution({ "12","123","1235","567","88" }); // false

    return 0;
}
#endif
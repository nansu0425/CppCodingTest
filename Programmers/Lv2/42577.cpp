#include <string>
#include <vector>
#include <unordered_set>

bool solution(std::vector<std::string> phone_book) {
    // 1. phone set과 prefix count set을 만든다
    std::unordered_set<std::string> phoneSet;
    std::unordered_set<size_t> prefixCountSet;
    for (const auto& phone : phone_book)
    {
        phoneSet.insert(phone);
        prefixCountSet.insert(phone.size());
    }

    // 2. phone_book을 순회
    for (const std::string& phone : phone_book)
    {
        // 3. prefix count set 순회
        for (size_t prefixCount : prefixCountSet)
        {
            if (phone.size() <= prefixCount)
            {
                continue;
            }

            // 4. prefix가 phone set에 있는지 확인
            const std::string prefix = phone.substr(0, prefixCount);
            if (phoneSet.count(prefix))
            {
                return false;
            }
        }
    }
        
    return true;
}

#ifdef LOCAL
int main()
{
    bool answer1 = solution({ "119", "97674223", "1195524421" });

    return 0;
}
#endif
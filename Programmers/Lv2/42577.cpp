#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Hash 풀이
//bool solution(vector<string> phone_book) {
//    bool answer = true;
//
//    // 1. 모든 번호 및 번호 자릿수에 대한 set을 만든다
//    unordered_set<string> phoneSet;
//    set<size_t> prefixCount;
//    for (const string& phone : phone_book)
//    {
//        phoneSet.insert(phone);
//        prefixCount.insert(phone.size());
//    }
//
//    // 2. 각 번호에서 set에 있는 번호의 자릿수 만큼 앞에서 잘라서 그게 set에 있는지 확인
//    for (size_t count : prefixCount)
//    {
//        for (const string& phone : phone_book)
//        {
//            if (phone.size() <= count)
//            {
//                continue;
//            }
//            
//            string prefix = phone.substr(0, count); // substr(count)로 할 경우 앞에서 count만큼 잘린 string을 return
//            if (phoneSet.find(prefix) != phoneSet.end())
//            {
//                return false;
//            }
//        }
//    }
//
//    return answer;
//}

// 정렬 + 인접 비교 풀이
bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());

    for (size_t i = 1; i < phone_book.size(); ++i)
    {
        if (phone_book[i].compare(0, phone_book[i - 1].size(), phone_book[i - 1]) == 0)
        {
            return false;
        }
    }

    return true;
}

#ifdef LOCAL
int main()
{
    bool answer = solution({ "119", "97674223", "1195524421" });

    return 0;
}
#endif
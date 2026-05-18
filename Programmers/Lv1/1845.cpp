#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    // 1. 모든 종류에 대한 set을 만든다
    unordered_set<int> numSet(nums.cbegin(), nums.cend());
    
    // 2. 모든 종류 개수와 선택 가능한 수 중 최소
    answer = min(numSet.size(), nums.size() / 2);

    return answer;
}

#ifdef LOCAL
int main()
{
    int answer = solution({ 3,3,3,2,2,4 });

    return 0;
}
#endif
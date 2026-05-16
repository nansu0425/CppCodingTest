// W01 5/16 — STL map/unordered_map drill (1회). 손코딩용 빈 스켈레톤.
//
// 사용법: 각 블록의 // TODO를 직접 채워 가며 진행.
//   - 각 블록 헤더 아래의 '다룰 API/항목'을 보고 변수 선언·호출·출력까지 직접 작성.
// 필요한 표준 헤더는 블록을 채우며 직접 include. (bits/stdc++.h · using namespace std 미사용)

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // 콘솔 출력 코드페이지를 UTF-8로 (한글 깨짐 방지)
#endif
    // TODO: fastio 두 줄 (sync_with_stdio, cin.tie)

    // [블록 1] map 생성·초기화
    // 다룰 항목: 빈 map, initializer_list {{k,v},...}, 기존 범위 복사 map(first,last), copy 생성
    // TODO

    // [블록 2] map 삽입·조회
    // 다룰 API: insert, insert_or_assign, emplace, try_emplace, operator[], at, find, count  (operator[] 기본값 삽입 부수효과·at의 out_of_range는 주석으로만 메모 / contains는 C++20이라 제외, count로 존재 확인)
    // TODO

    // [블록 3] map 삭제·순회
    // 다룰 API: erase(key), erase(iter), erase(first,last), clear / 키 오름차순 순회, structured bindings auto& [k,v]
    // TODO

    // [블록 4] map 정렬 특성
    // 다룰 API: begin/rbegin(최소·최대 키), lower_bound, upper_bound, equal_range, map<K,V,greater<>> 커스텀 비교자
    // TODO

    // [블록 5] unordered_map 생성·초기화
    // 다룰 항목: 빈 unordered_map, initializer_list, 범위 복사, reserve(버킷 예약), max_load_factor
    // TODO

    // [블록 6] unordered_map 삽입·조회
    // 다룰 API: insert, emplace, try_emplace, operator[], at, find, count  (operator[] 기본값 삽입 주의는 map과 동일)
    // TODO

    // [블록 7] unordered_map 삭제·순회
    // 다룰 API: erase(key), erase(iter), clear / 순회 순서 보장 없음 확인, structured bindings
    // TODO

    // [블록 8] map vs unordered_map 비교
    // 다룰 항목: 정렬 vs 해시(복잡도 O(log n) vs 평균 O(1)), lower_bound는 map만, 버킷 API(bucket_count/load_factor), 선택 기준 메모
    // TODO

    return 0;
}

# CppCodingTest

C++ 코딩테스트 풀이 및 학습 코드 정리 repo

## 환경

- Windows + Visual Studio 2022, 플랫폼 도구 집합 v145
- 언어 표준: C++20 (`/std:c++20`)
- 전처리기 정의: `LOCAL` (로컬 테스트 코드 가드)

## 솔루션 구조

```
CppCodingTest.slnx                 솔루션 (VS 2022 .slnx)
Programmers/Programmers.vcxproj    Programmers 프로젝트
Programmers/<레벨>/<번호>.cpp      풀이 코드 (예: Programmers/Lv0/120804.cpp)
Studies/Studies.vcxproj            Studies 프로젝트 (STL 드릴)
Studies/<번호>-<주제>.cpp          드릴 코드 (예: Studies/01-vector.cpp)
```

## 풀이 워크플로우

- 각 `.cpp`는 자체 진입점을 가진다: 문제 풀이 코드 + `#ifdef LOCAL ... main()`.
- 한 번에 하나의 문제만 컴파일한다. 현재 푸는 `.cpp`만 프로젝트에 포함하고
  나머지는 Visual Studio에서 **프로젝트에서 제외(Exclude From Project)** 처리해
  단일 `main()`을 유지한다.
- 로컬 테스트 코드는 `#ifdef LOCAL` 가드 안에 둔다 (`LOCAL`은 프로젝트 설정에 정의됨).

## 코드 스타일

- `using namespace std;` 미사용 -> 이름 충돌 회피, 명확성 우선
- 필요한 표준 헤더만 명시 include

## Studies/

STL/개념 드릴 프로젝트. 각 `.cpp`는 독립 `int main()`이라 `LOCAL`이 필요 없다
(제출용 `solution`이 없음). Programmers와 동일하게 한 번에 하나의 `.cpp`만
프로젝트에 포함하고 나머지는 **프로젝트에서 제외**해 단일 `main()`을 유지한다.

## 이중 & 원형 연결리스트
[씹어먹는 스터디 week2: 이중 & 원형 연결리스트](https://www.eubug.space/ko/devouring-study/week2/)

- 이중 연결리스트와 원형 연결리스트 비교.
- 이중 연결리스트의 의사코드 살펴보기.
  + `insertFront()` : 리스트 처음에 노드를 추가
  + `insertBack()` : 리스트 끝에 노드를 추가 
  + `removeFront()` : 머리 노드 삭제 
  + `removeBack()` : 꼬리 노드 삭제
- 생각해볼 문제
  + 리스트 중간에 새로운 노드를 삽입하는 `insertAt(pos)` 함수 구현해보기.
  + 리스트 중간 노드를 삭제하는 `removeAt(pos)` 함수 구현해보기.
  + `removeBack()`과 `insertBack()` 함수 **O(1)**으로 구현해보기.
  + 이중 연결리스트 구현 후, 원형 이중 연결리스트 구현 해보기.
- 풀어볼 문제
  + 백준: 
    - [요세푸스 문제 (Silver V)](https://www.acmicpc.net/problem/1158)
    - [에디터 (Silver III)](https://www.acmicpc.net/problem/1406)
  + Leetcode:
    - [연결리스트 사이클 감지하기](https://leetcode.com/problems/linked-list-cycle/)
    - [서로 다른 두 연결리스트의 교차점 찾기](https://leetcode.com/problems/intersection-of-two-linked-lists/)
    - [연결리스트 팰린드롬](https://leetcode.com/problems/palindrome-linked-list/)

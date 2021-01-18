# 210119_2048_CWY

2048 문제

- search: 재귀적으로 dfs하는 함수
- _move: up, down, left, right 연산을 수행하는 함수
- _get: map을 비우고 queue에 넣는 함수
- _merge: queue와 map을 비교하면서 map에 값을 채우는 과정

search는 모든 방향에 대해서 _move함수를 호출하고 _move함수 내에서 _get과 _merge를 반복한다.

# Flowchart

![2048](https://user-images.githubusercontent.com/64261939/104895436-3badcd80-59b9-11eb-9112-bbfd17412151.jpg)
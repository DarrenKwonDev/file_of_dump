-- lua는 double precision floating point numbers만 지원한다.
-- 정수 그런거 없음.


-- exponentiation
a = 2 ^ 10;
print(a) -- 1024.0

b = 2 ^ -2;
print(b) -- 0.25

-- e 표기법
c = 2e3; -- 2 * 10 ^ 3
print(c) -- 2000.0

-- to num
print(tonumber("122") + 3)

--Coercion
print("123" + 123) -- 246 (숫자 덧셈은 강제 변환)
print("123" == 123) -- false (그러나 비교 연산자는 안 됨)
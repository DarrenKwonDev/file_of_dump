
-- multiple assignment
x, y = 1, "wow"
print(x, y)

-- swap
a, b = 1, 2
a, b = b, a
print(a, b) -- 2, 1

-- mismatch list sizes
i, j = 1, 2, 3, 4, 5, "asdf"
print(i, j) -- 나머지 값은 무시됨
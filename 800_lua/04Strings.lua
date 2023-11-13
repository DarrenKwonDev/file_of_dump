
-- string을 나타내는 다양한 방법
a = "hello"
b = 'hello'
c = [[hello]]

-- escapse
a = "hello \\ oh \""
print(a) -- hello \ oh "
b = [[hello \\ oh \"]] 
print(b) -- hello \\ oh \" 즉, 그냥 문자열 그대로 출력됨.

-- Concatenation
a = "hello" .. [["asdfijga\32/N!]]
print(a)

-- Coercion
a = "asdf" .. 3 .. 4
print(a)
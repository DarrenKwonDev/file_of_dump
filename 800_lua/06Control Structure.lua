
-- 0도 참이다.
if 0 then
    print(true)
elseif nil then
    print("nil")
else
    print(false)
end

-- while / do
a = 10
while a > 8 do
    a = a - 1
end

-- reapeat / until
a = 12
repeat
    print(a)
    a = a - 1
until a < 10

-- for
-- start, stop, step
for i = 1, 10, 2 do
    print(i)
end

-- for
-- ipars
t = {"a", "b"}
for index, value in ipairs(t) do
    print(index, value)
end
-- 타입이 몇 개 안됨.
-- type:
--     | "nil"
--     | "number"
--     | "string"
--     | "boolean"
--     | "table"
--     | "function"
--     | "thread"
--     | "userdata"


-- number
print(2 + 2)
print(3.14 + 5.2)
print(2 / 3)

-- string
-- + 연산 안 됨
print("lua user")
print("hello" .. "wow") -- .. is concat


-- boolean
print(true)
print(not true)
print(false)
print(true and false)
print(true or false)
print(1 == 0)

-- table
x = {"a", "b", "c"}
print(x[1]) -- a

-- function
foo = function (x, y)
    return x + y
end
print(foo(1, 2))

-- nil
print(nil)
print(nil or true)

-- userdata
-- c와의 연동할 때 살펴보자.

-- thread
-- 이라고 말하지만 보니까 coroutine임

print(type("123"))
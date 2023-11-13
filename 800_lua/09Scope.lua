
-- local 선언하지 않으면 모두 global
-- lua는 global by default다.

a = 3

function f()
    -- this is not local var. this is global var.
    a = 10
end
f()

print(a)

-- local
function f()
    local a = 100
    -- 해당 함수 호출 끝나면 사라짐
end
f()

print(a)
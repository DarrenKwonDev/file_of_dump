
-- table
t = {}
print(t) -- table: 0x7f8c2b402f00 
print(t[1]) -- nil
print(t[2]) -- nil

-- table insert
t[1] = 3
table.insert(t, "oh")
for index, value in ipairs(t) do
    print(index, value)
end

-- table are ref
t2 = t
print(t == t2) -- true (메모리 주소 같으므로)

-- table이 reference로 넘어 갔으므로 원본이 mutate 됨
function f(x) x[1] = 100 end
f(t2)
print(t[1]) -- 0
print(t2[1]) -- 0


-- table은 unordered 됨.
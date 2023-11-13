-- relational expressions
print(1 ~= 2) -- not equal

-- not, nil
print(not nil)

-- ternary operator
-- and has a higher precedence than or
a = 0 == nil and "a" or "b"
print(a)
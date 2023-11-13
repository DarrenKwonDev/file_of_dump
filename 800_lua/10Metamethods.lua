local x = {value = 5} -- creating local table x containing one key,value of value,5

-- 일단 5군.
print(x["value"])
print(x.value)

-- overload될 수 있는 metatable event
-- http://lua-users.org/wiki/MetatableEvents
local mt = {
  __add = function (lhs, rhs) -- "add" event handler
    return { 
        print("overloaded add call");
        value = lhs.value + rhs.value
    }
  end
}

setmetatable(x, mt) -- use "mt" as the metatable for "x"

-- __add overload된 걸로 실행됨.
local y = x + x

print(y.value) --> 10  -- Note: print(y) will just give us the table code i.e table: <some tablecode>

local z = y + y -- error, y doesn't have our metatable. this can be fixed by setting the metatable of the new object inside the metamethod

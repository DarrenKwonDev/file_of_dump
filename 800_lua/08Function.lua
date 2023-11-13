-- function
function f()
    print("oh")
end
f()

-- first class function (function as values)
foo = function (f)
    f()
end

bar = function ()
    print("bar")
end

foo(bar)

-- extra args
bar(1, 2, 3, 4) -- no error. ignored.

-- multiple return
function f()
    return 1, "a", [[oh]]
end
x, y, z = f()
print(x, y, z)

-- Variable number of arguments
f = function (x, ...)
    x(...)
end
f(print, 1, 2, [[asdf]])


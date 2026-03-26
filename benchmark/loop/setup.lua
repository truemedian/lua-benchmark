local function gen(_, i)
    if i > 1000 then return end
    return i + 1
end

local function tailcall(n)
    if n >= 1000 then return n end
    return tailcall(n + 1)
end
local fmod1 = math.fmod
local function fmod2(a, b)
	if (a < 0) == (b < 0) then
		return a % b
	end
	return (a % b) - b
end
local function fmod3(a, b)
	return (a % b) - (((a < 0) == (b < 0)) and 0 or b)
end
local function fmod4(a, b)
	return a - math.floor(a / b) * b
end
local fmod5
if _VERSION:match("%d.%d") >= "5.3" then
	fmod5 = load("return function(a, b) return a - a // b * b end")()
end

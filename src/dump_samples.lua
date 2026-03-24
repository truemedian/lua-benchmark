local fs = require("fs")

local tests = {}

local order = { "lua51", "lua52", "lua53", "lua54", "lua55", "luajit", "luajit_interpreter" }
local names = { "Lua 5.1", "Lua 5.2", "Lua 5.3", "Lua 5.4", "Lua 5.5", "LuaJIT", "LuaJIT (Interpreter)" }

for test in fs.scandirSync("results") do
	local meta = require("../benchmark/" .. test .. "/meta.lua")
	meta.code = {}
	meta.results = {}
	meta.setup = fs.readFileSync("benchmark/" .. test .. "/setup.lua")
	meta.setup_local = fs.readFileSync("benchmark/" .. test .. "/setup_local.lua")

	for file in fs.scandirSync("benchmark/" .. test) do
		local id = tonumber(file:sub(1, -5))
		if id then
			meta.code[id] = fs.readFileSync("benchmark/" .. test .. "/" .. file):gsub("%s+", " ")
		end
	end

	for env in fs.scandirSync("results/" .. test) do
		for result in fs.scandirSync("results/" .. test .. "/" .. env) do
			local id = tonumber(result:sub(1, -5))
			if id then
				local content = require("../results/" .. test .. "/" .. env .. "/" .. result)
				meta.results[env] = meta.results[env] or {}
				meta.results[env][id] = content
			end
		end
	end

	table.insert(tests, meta)
end

table.sort(tests, function(a, b)
	return a.name < b.name
end)

for _, test in ipairs(tests) do
	for i, env in ipairs(order) do
		if test.results[env] then
			for id = 1, #test.code do
				if test.results[env][id] then
					print(table.concat(test.results[env][id].samples, ","))
				end
			end
		end
	end
end

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

local lines = {}

local function format(time)
	if time < 1e3 then
		return string.format("%.3fns", time)
	elseif time < 1e6 then
		return string.format("%.3fµs", time / 1e3)
	elseif time < 1e9 then
		return string.format("%.3fms", time / 1e6)
	else
		return string.format("%.3fs", time / 1e9)
	end
end

for _, test in ipairs(tests) do
	table.insert(lines, "## " .. test.name)
	table.insert(lines, "")

	if test.setup then
		table.insert(lines, "#### One-Time Setup")
		table.insert(lines, "```lua")
		table.insert(lines, test.setup:match("^(.-)\n*$"))
		table.insert(lines, "```")
		table.insert(lines, "")
	end

	if test.setup_local then
		table.insert(lines, "#### Per Iteration Setup")
		table.insert(lines, "```lua")
		table.insert(lines, test.setup_local:match("^(.-)\n*$"))
		table.insert(lines, "```")
		table.insert(lines, "")
	end

	table.insert(lines, "| Test | Code |")
	table.insert(lines, "|------|------|")

	for id, code in ipairs(test.code) do
		table.insert(lines, "| `" .. test[id].id .. "` | `" .. code:match("^(.-)%s*$") .. "` |")
	end

	for i, env in ipairs(order) do
		if test.results[env] then
			table.insert(lines, "")
			table.insert(lines, "### " .. names[i])
			table.insert(lines, "")
			table.insert(lines, "| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |")
			table.insert(lines, "|------|-----|-----|--------|-----|-----|------|--------|------|")

			local fastest_median = math.huge
			for _, result in pairs(test.results[env]) do
				if result.median < fastest_median then
					fastest_median = result.median
				end
			end

			for id = 1, #test.code do
				local result = test.results[env][id]

				if result then
					local ratio = result.median / fastest_median

					table.insert(
						lines,
						string.format(
							"| `%s` | %s | %s | %s | %s | %s | %s | %s | %.2fx |",
							test[id].id,
							format(result.min),
							format(result.q25),
							format(result.median),
							format(result.q75),
							format(result.max),
							format(result.average),
							format(result.stddev),
							ratio
						)
					)
				else
					table.insert(lines, string.format("| `%s` | - | - | - | - | - | - | - | - |", test[id].id))
				end
			end
		end
	end

	table.insert(lines, "")
end

fs.writeFileSync("benchmark.md", table.concat(lines, "\n"))

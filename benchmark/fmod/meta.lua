return {
	name = "fmod",
	expected = function(n) return math.fmod(n, 10) end,
	{
		id = "fmod (global)",
	},
	{
		id = "fmod (local)",
	},
	{
		id = "branchy",
	},
	{
		id = "branchless",
	},
	{
		id = "definition (math.floor)",
	},
	{
		luajit = true,
		luajit_interpreter = true,
		lua51 = true,
		lua52 = true,
		id = "definition (floor division)",
	},
}

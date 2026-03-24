return {
	name = "table slice",
	expected = {},
	{
		id = "unpack",
	},
	{
		id = "from scratch",
	},
	{
		lua51 = true,
		lua52 = true,
		lua53 = true,
        lua54 = true,
		id = "table.new",
	},
    {
		luajit = true,
		luajit_interpreter = true,
		lua51 = true,
		lua52 = true,
		lua53 = true,
		id = "table.move",
	},
}

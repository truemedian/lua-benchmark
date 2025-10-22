local text = "Hello, this is an example text"
local char, sub, gsub, gmatch = string.char, string.sub, string.gsub, string.gmatch
local cstr = ffi and ffi.cast("const char*", text) or nil

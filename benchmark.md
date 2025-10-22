## character iteration

#### One-Time Setup
```lua
local text = "Hello, this is an example text"
local char, sub, gsub, gmatch = string.char, string.sub, string.gsub, string.gmatch
local cstr = ffi and ffi.cast("const char*", text) or nil
```

| Test | Code |
|------|------|
| `sub` | `for i = 1, #text do out = text:sub(i, i) end` |
| `gmatch` | `for c in gmatch(text, ".") do out = c end` |
| `gsub` | `gsub(text, ".", function(c) out = c end)` |
| `ffi cstr` | `for i = 0, #text - 1 do out = char(cstr[i]) end` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `sub` | 5.722µs | 6.570µs | 6.633µs | 6.689µs | 7.335µs | 6.630µs | 101.415ns | 1.00x |
| `gmatch` | 6.572µs | 6.744µs | 6.762µs | 6.784µs | 6.962µs | 6.765µs | 33.810ns | 1.02x |
| `gsub` | 7.824µs | 8.425µs | 8.443µs | 8.458µs | 8.685µs | 8.440µs | 44.071ns | 1.27x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `sub` | 5.635µs | 7.582µs | 7.623µs | 7.663µs | 7.970µs | 7.618µs | 102.459ns | 1.12x |
| `gmatch` | 5.599µs | 6.821µs | 6.833µs | 6.846µs | 10.329µs | 6.843µs | 142.422ns | 1.00x |
| `gsub` | 7.038µs | 8.706µs | 8.763µs | 8.812µs | 9.881µs | 8.752µs | 137.051ns | 1.28x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `sub` | 5.038µs | 7.297µs | 7.318µs | 7.340µs | 7.907µs | 7.313µs | 112.669ns | 1.49x |
| `gmatch` | 4.335µs | 4.880µs | 4.899µs | 4.915µs | 5.253µs | 4.898µs | 41.522ns | 1.00x |
| `gsub` | 7.826µs | 8.641µs | 8.698µs | 8.760µs | 10.021µs | 8.704µs | 129.772ns | 1.78x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `sub` | 5.442µs | 7.103µs | 7.127µs | 7.156µs | 7.549µs | 7.123µs | 108.895ns | 1.41x |
| `gmatch` | 4.974µs | 5.027µs | 5.038µs | 5.053µs | 5.272µs | 5.041µs | 27.486ns | 1.00x |
| `gsub` | 5.435µs | 5.937µs | 5.959µs | 5.982µs | 6.254µs | 5.961µs | 46.919ns | 1.18x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `sub` | 1.058µs | 1.156µs | 1.184µs | 1.211µs | 1.291µs | 1.183µs | 41.081ns | 1.00x |
| `gmatch` | 4.733µs | 5.138µs | 5.142µs | 5.147µs | 5.416µs | 5.144µs | 21.709ns | 4.34x |
| `gsub` | 7.025µs | 7.892µs | 7.927µs | 7.960µs | 8.658µs | 7.924µs | 80.411ns | 6.70x |
| `ffi cstr` | 1.149µs | 1.318µs | 1.356µs | 1.372µs | 3.453µs | 1.352µs | 83.943ns | 1.15x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `sub` | 3.086µs | 3.502µs | 3.540µs | 3.589µs | 3.864µs | 3.548µs | 70.361ns | 1.00x |
| `gmatch` | 3.506µs | 3.807µs | 3.823µs | 3.849µs | 3.989µs | 3.826µs | 35.012ns | 1.08x |
| `gsub` | 1.447µs | 7.638µs | 7.679µs | 7.717µs | 7.959µs | 7.666µs | 219.494ns | 2.17x |
| `ffi cstr` | 5.202µs | 5.888µs | 5.903µs | 5.915µs | 6.262µs | 5.899µs | 49.450ns | 1.67x |

## closure creation

#### One-Time Setup
```lua
local function f1(a, b, fn) return fn(a + b) end
local function f2(a) return a * 2 end
```

| Test | Code |
|------|------|
| `saved fn` | `out = f1(1, 2, f2)` |
| `new closure` | `out = f1(1, 2, function(a) return a * 2 end)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `saved fn` | 116.110ns | 176.449ns | 177.331ns | 178.389ns | 194.937ns | 177.409ns | 2.745ns | 1.00x |
| `new closure` | 226.562ns | 236.577ns | 238.992ns | 240.889ns | 273.646ns | 238.794ns | 3.460ns | 1.35x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `saved fn` | 212.737ns | 247.239ns | 248.797ns | 250.028ns | 267.178ns | 248.408ns | 3.557ns | 1.03x |
| `new closure` | 201.909ns | 240.908ns | 242.091ns | 243.305ns | 265.458ns | 241.965ns | 3.736ns | 1.00x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `saved fn` | 141.452ns | 171.911ns | 172.029ns | 172.125ns | 179.169ns | 171.788ns | 1.965ns | 1.00x |
| `new closure` | 163.622ns | 173.574ns | 173.712ns | 174.145ns | 188.544ns | 173.904ns | 1.107ns | 1.01x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `saved fn` | 74.850ns | 136.647ns | 137.377ns | 138.445ns | 589.703ns | 137.972ns | 14.627ns | 1.00x |
| `new closure` | 175.452ns | 197.032ns | 200.392ns | 202.906ns | 227.568ns | 200.137ns | 3.958ns | 1.46x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `saved fn` | 0.981ns | 1.006ns | 1.007ns | 1.008ns | 1.028ns | 1.007ns | 0.003ns | 1.00x |
| `new closure` | 106.168ns | 111.612ns | 112.122ns | 112.678ns | 118.578ns | 112.356ns | 1.164ns | 111.29x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `saved fn` | 66.380ns | 72.620ns | 72.834ns | 72.982ns | 76.310ns | 72.784ns | 0.390ns | 1.00x |
| `new closure` | 110.591ns | 114.454ns | 114.981ns | 115.742ns | 122.179ns | 115.158ns | 1.115ns | 1.58x |

## cube

#### One-Time Setup
```lua
local x, pow = 10, math.pow
```

| Test | Code |
|------|------|
| `math.pow (global)` | `out = math.pow(x, 2)` |
| `math.pow (local)` | `out = pow(x, 2)` |
| `multiply` | `out = x * x` |
| `exponent` | `out = x ^ 2` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 209.512ns | 227.900ns | 228.869ns | 229.880ns | 235.278ns | 228.802ns | 1.947ns | 5.98x |
| `math.pow (local)` | 155.322ns | 183.487ns | 183.722ns | 183.998ns | 190.431ns | 183.697ns | 1.382ns | 4.80x |
| `multiply` | 33.901ns | 38.230ns | 38.279ns | 38.296ns | 59.116ns | 38.282ns | 0.750ns | 1.00x |
| `exponent` | 68.741ns | 91.464ns | 91.546ns | 91.690ns | 101.206ns | 91.546ns | 1.094ns | 2.39x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 207.029ns | 251.785ns | 252.318ns | 252.805ns | 300.131ns | 252.204ns | 2.813ns | 5.33x |
| `math.pow (local)` | 69.867ns | 184.459ns | 185.251ns | 186.000ns | 263.464ns | 185.068ns | 6.396ns | 3.91x |
| `multiply` | 31.111ns | 47.270ns | 47.319ns | 47.352ns | 53.618ns | 47.280ns | 0.733ns | 1.00x |
| `exponent` | 78.522ns | 95.791ns | 95.894ns | 95.955ns | 111.910ns | 95.829ns | 1.127ns | 2.03x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 219.577ns | 246.128ns | 246.503ns | 246.849ns | 258.984ns | 246.414ns | 1.485ns | 7.01x |
| `math.pow (local)` | 187.805ns | 202.564ns | 202.976ns | 203.423ns | 211.787ns | 202.931ns | 1.125ns | 5.77x |
| `multiply` | 33.320ns | 35.055ns | 35.159ns | 35.174ns | 37.016ns | 35.127ns | 0.182ns | 1.00x |
| `exponent` | 85.835ns | 108.394ns | 108.536ns | 108.686ns | 114.247ns | 108.471ns | 1.176ns | 3.09x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 195.003ns | 227.820ns | 229.164ns | 230.703ns | 249.936ns | 229.188ns | 2.703ns | 8.43x |
| `math.pow (local)` | 167.962ns | 196.129ns | 196.800ns | 197.549ns | 220.619ns | 196.754ns | 2.031ns | 7.24x |
| `multiply` | 30.703ns | 35.160ns | 35.276ns | 35.294ns | 37.293ns | 35.267ns | 0.437ns | 1.30x |
| `exponent` | 8.737ns | 27.177ns | 27.186ns | 27.241ns | 89.680ns | 27.226ns | 2.093ns | 1.00x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 7.136ns | 7.384ns | 7.390ns | 7.402ns | 7.634ns | 7.388ns | 0.042ns | 7.34x |
| `math.pow (local)` | 0.981ns | 1.005ns | 1.007ns | 1.008ns | 1.060ns | 1.007ns | 0.004ns | 1.00x |
| `multiply` | 0.979ns | 1.006ns | 1.008ns | 1.008ns | 1.056ns | 1.007ns | 0.003ns | 1.00x |
| `exponent` | 0.984ns | 1.006ns | 1.007ns | 1.008ns | 1.051ns | 1.007ns | 0.003ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 95.051ns | 109.099ns | 109.149ns | 109.207ns | 117.024ns | 109.138ns | 0.772ns | 5.52x |
| `math.pow (local)` | 86.956ns | 97.264ns | 97.392ns | 97.498ns | 101.236ns | 97.326ns | 0.760ns | 4.93x |
| `multiply` | 18.314ns | 19.725ns | 19.771ns | 19.812ns | 118.956ns | 19.970ns | 3.558ns | 1.00x |
| `exponent` | 69.894ns | 79.749ns | 79.796ns | 79.889ns | 82.907ns | 79.717ns | 0.569ns | 4.04x |

## default

#### One-Time Setup
```lua
local x = false
```

| Test | Code |
|------|------|
| `if-else` | `if not x then out = 1 else out = x end` |
| `or` | `out = x or 1` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `if-else` | 32.173ns | 38.656ns | 38.699ns | 38.721ns | 126.337ns | 38.785ns | 2.800ns | 1.14x |
| `or` | 30.061ns | 33.260ns | 33.893ns | 34.393ns | 36.678ns | 33.839ns | 0.811ns | 1.00x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `if-else` | 41.193ns | 52.318ns | 52.346ns | 52.361ns | 55.227ns | 52.239ns | 0.834ns | 1.21x |
| `or` | 35.767ns | 43.088ns | 43.384ns | 44.408ns | 47.169ns | 43.639ns | 1.111ns | 1.00x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `if-else` | 10.510ns | 41.082ns | 41.107ns | 41.160ns | 47.139ns | 41.073ns | 1.027ns | 1.23x |
| `or` | 29.023ns | 33.264ns | 33.347ns | 33.371ns | 36.131ns | 33.316ns | 0.257ns | 1.00x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `if-else` | 23.217ns | 29.556ns | 29.599ns | 29.646ns | 31.934ns | 29.566ns | 0.384ns | 1.01x |
| `or` | 0.220ns | 29.184ns | 29.192ns | 29.241ns | 59.979ns | 29.227ns | 1.682ns | 1.00x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `if-else` | 0.931ns | 1.006ns | 1.007ns | 1.008ns | 1.058ns | 1.007ns | 0.004ns | 1.00x |
| `or` | 0.969ns | 1.005ns | 1.007ns | 1.008ns | 1.026ns | 1.007ns | 0.003ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `if-else` | 13.349ns | 25.198ns | 25.371ns | 25.539ns | 47.913ns | 25.375ns | 0.892ns | 1.51x |
| `or` | 12.074ns | 16.727ns | 16.784ns | 16.882ns | 17.876ns | 16.789ns | 0.220ns | 1.00x |

## empty string

#### One-Time Setup
```lua
local str = ""
local cstr = ffi and ffi.cast("const char*", str) or nil
```

| Test | Code |
|------|------|
| `length` | `out = #str == 0` |
| `value` | `out = str == ""` |
| `ffi cstr` | `out = cstr[0] == 0` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `length` | 47.513ns | 54.901ns | 56.760ns | 58.589ns | 63.797ns | 56.656ns | 2.581ns | 1.26x |
| `value` | 35.965ns | 43.649ns | 45.002ns | 46.516ns | 49.864ns | 44.999ns | 1.988ns | 1.00x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `length` | 65.325ns | 73.963ns | 74.079ns | 74.167ns | 232.108ns | 74.207ns | 5.022ns | 1.30x |
| `value` | 18.028ns | 56.783ns | 56.839ns | 56.919ns | 63.060ns | 56.768ns | 1.489ns | 1.00x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `length` | 59.711ns | 72.743ns | 72.900ns | 73.079ns | 78.346ns | 72.833ns | 0.851ns | 1.23x |
| `value` | 49.537ns | 59.083ns | 59.143ns | 59.220ns | 60.842ns | 59.101ns | 0.601ns | 1.00x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `length` | 40.331ns | 47.260ns | 47.390ns | 47.542ns | 48.925ns | 47.346ns | 0.621ns | 1.34x |
| `value` | 28.702ns | 35.211ns | 35.471ns | 36.245ns | 37.693ns | 35.653ns | 0.731ns | 1.00x |
| `ffi cstr` | - | - | - | - | - | - | - | - |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `length` | 0.992ns | 1.005ns | 1.007ns | 1.008ns | 1.051ns | 1.007ns | 0.003ns | 1.00x |
| `value` | 0.987ns | 1.006ns | 1.007ns | 1.008ns | 1.026ns | 1.007ns | 0.003ns | 1.00x |
| `ffi cstr` | 0.973ns | 1.006ns | 1.007ns | 1.008ns | 1.055ns | 1.007ns | 0.004ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `length` | 7.202ns | 30.980ns | 31.014ns | 31.057ns | 155.491ns | 31.109ns | 4.017ns | 1.28x |
| `value` | 21.071ns | 24.215ns | 24.240ns | 24.251ns | 56.787ns | 24.263ns | 1.041ns | 1.00x |
| `ffi cstr` | 131.350ns | 144.634ns | 145.487ns | 146.399ns | 160.609ns | 145.571ns | 1.671ns | 6.00x |

## fmod

#### One-Time Setup
```lua
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
```

| Test | Code |
|------|------|
| `fmod (global)` | `out = math.fmod(__i, 10)` |
| `fmod (local)` | `out = fmod1(__i, 10)` |
| `branchy` | `out = fmod2(__i, 10)` |
| `branchless` | `out = fmod3(__i, 10)` |
| `definition (math.floor)` | `out = fmod4(__i, 10)` |
| `definition (floor division)` | `out = fmod5(__i, 10)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `fmod (global)` | 52.110ns | 177.278ns | 179.366ns | 181.547ns | 195.990ns | 179.194ns | 5.799ns | 1.36x |
| `fmod (local)` | 113.658ns | 130.543ns | 131.624ns | 132.573ns | 412.560ns | 131.800ns | 9.066ns | 1.00x |
| `branchy` | 156.394ns | 176.703ns | 177.765ns | 179.322ns | 186.908ns | 177.927ns | 2.333ns | 1.35x |
| `branchless` | 158.227ns | 212.138ns | 213.812ns | 215.516ns | 229.458ns | 213.757ns | 3.915ns | 1.62x |
| `definition (math.floor)` | 197.839ns | 256.303ns | 258.720ns | 261.431ns | 274.651ns | 258.817ns | 4.894ns | 1.97x |
| `definition (floor division)` | - | - | - | - | - | - | - | - |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `fmod (global)` | 142.977ns | 205.548ns | 205.782ns | 206.023ns | 213.922ns | 205.699ns | 2.403ns | 1.45x |
| `fmod (local)` | 115.870ns | 141.024ns | 141.598ns | 142.191ns | 151.392ns | 141.575ns | 1.276ns | 1.00x |
| `branchy` | 202.902ns | 231.127ns | 233.473ns | 234.714ns | 244.611ns | 232.582ns | 3.794ns | 1.65x |
| `branchless` | 237.511ns | 269.394ns | 271.351ns | 273.656ns | 288.000ns | 271.513ns | 3.540ns | 1.92x |
| `definition (math.floor)` | 264.876ns | 297.095ns | 298.168ns | 299.187ns | 308.089ns | 298.100ns | 2.283ns | 2.11x |
| `definition (floor division)` | - | - | - | - | - | - | - | - |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `fmod (global)` | 118.676ns | 189.605ns | 189.811ns | 190.025ns | 616.629ns | 190.080ns | 14.311ns | 1.32x |
| `fmod (local)` | 124.272ns | 143.867ns | 144.125ns | 144.317ns | 148.626ns | 144.035ns | 1.338ns | 1.00x |
| `branchy` | 105.442ns | 214.486ns | 214.746ns | 215.056ns | 945.189ns | 216.353ns | 31.427ns | 1.49x |
| `branchless` | 188.422ns | 244.617ns | 245.036ns | 245.429ns | 267.831ns | 244.655ns | 4.401ns | 1.70x |
| `definition (math.floor)` | 241.724ns | 271.562ns | 272.864ns | 274.070ns | 282.351ns | 272.689ns | 2.641ns | 1.89x |
| `definition (floor division)` | 140.196ns | 155.959ns | 156.118ns | 156.231ns | 697.677ns | 156.683ns | 17.176ns | 1.08x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `fmod (global)` | 126.063ns | 151.733ns | 153.887ns | 155.942ns | 549.966ns | 154.208ns | 13.447ns | 1.17x |
| `fmod (local)` | 121.882ns | 129.990ns | 131.783ns | 133.463ns | 141.988ns | 131.790ns | 2.902ns | 1.00x |
| `branchy` | 127.358ns | 150.559ns | 150.750ns | 150.913ns | 169.097ns | 150.619ns | 1.707ns | 1.14x |
| `branchless` | 152.865ns | 178.962ns | 179.152ns | 179.487ns | 893.956ns | 180.616ns | 31.081ns | 1.36x |
| `definition (math.floor)` | 187.320ns | 214.337ns | 214.770ns | 215.238ns | 311.587ns | 214.813ns | 3.525ns | 1.63x |
| `definition (floor division)` | 106.398ns | 130.907ns | 132.262ns | 132.820ns | 138.702ns | 131.839ns | 1.936ns | 1.00x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `fmod (global)` | 94.536ns | 109.023ns | 109.556ns | 110.054ns | 118.738ns | 109.499ns | 1.197ns | 24.52x |
| `fmod (local)` | 89.282ns | 100.409ns | 101.195ns | 101.842ns | 147.963ns | 101.204ns | 2.004ns | 22.65x |
| `branchy` | 11.459ns | 12.073ns | 12.084ns | 12.087ns | 20.007ns | 12.093ns | 0.260ns | 2.70x |
| `branchless` | 10.099ns | 10.707ns | 10.926ns | 11.071ns | 13.106ns | 10.898ns | 0.268ns | 2.45x |
| `definition (math.floor)` | 4.385ns | 4.459ns | 4.468ns | 4.469ns | 6.853ns | 4.468ns | 0.077ns | 1.00x |
| `definition (floor division)` | - | - | - | - | - | - | - | - |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `fmod (global)` | 86.075ns | 98.174ns | 98.427ns | 98.670ns | 195.629ns | 98.513ns | 3.251ns | 1.16x |
| `fmod (local)` | 73.922ns | 84.367ns | 84.612ns | 84.871ns | 89.226ns | 84.595ns | 0.635ns | 1.00x |
| `branchy` | 93.371ns | 96.260ns | 96.339ns | 96.423ns | 99.934ns | 96.341ns | 0.304ns | 1.14x |
| `branchless` | 114.984ns | 122.978ns | 123.257ns | 123.743ns | 131.455ns | 123.421ns | 0.778ns | 1.46x |
| `definition (math.floor)` | 94.403ns | 99.933ns | 100.006ns | 100.078ns | 107.415ns | 99.974ns | 0.450ns | 1.18x |
| `definition (floor division)` | - | - | - | - | - | - | - | - |

## ipairs iteration

#### One-Time Setup
```lua
local nxt = next
local len = 100
local a = { n = len, [0] = len }
for i = 1, len do
	a[i] = i
end
```

| Test | Code |
|------|------|
| `ipairs` | `for k, v in ipairs(a) do out = v end` |
| `pairs` | `for k, v in pairs(a) do out = v end` |
| `next (global)` | `for k, v in next, a do out = v end` |
| `next (local)` | `for k, v in nxt, a do out = v end` |
| `local len` | `for i = 1, len do out = a[i] end` |
| `table.n` | `for i = 1, a.n do out = a[i] end` |
| `table[0]` | `for i = 1, a[0] do out = a[i] end` |
| `#table` | `for i = 1, #a do out = a[i] end` |
| `constant` | `for i = 1, 100 do out = a[i] end` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `ipairs` | 5.874µs | 13.315µs | 13.372µs | 13.428µs | 33.900µs | 13.395µs | 776.283ns | 2.79x |
| `pairs` | 10.631µs | 11.900µs | 11.913µs | 11.930µs | 13.509µs | 11.922µs | 123.340ns | 2.48x |
| `next (global)` | 10.861µs | 11.657µs | 11.668µs | 11.683µs | 12.960µs | 11.673µs | 91.423ns | 2.43x |
| `next (local)` | 10.271µs | 11.631µs | 11.641µs | 11.660µs | 12.043µs | 11.639µs | 89.694ns | 2.43x |
| `local len` | 4.252µs | 4.722µs | 4.796µs | 4.873µs | 5.955µs | 4.799µs | 114.021ns | 1.00x |
| `table.n` | 4.553µs | 4.796µs | 4.850µs | 4.890µs | 5.157µs | 4.842µs | 78.962ns | 1.01x |
| `table[0]` | 4.101µs | 4.766µs | 4.866µs | 4.942µs | 14.506µs | 4.863µs | 383.605ns | 1.01x |
| `#table` | 4.107µs | 4.761µs | 4.832µs | 4.883µs | 5.055µs | 4.820µs | 93.396ns | 1.01x |
| `constant` | 4.227µs | 4.721µs | 4.800µs | 4.881µs | 5.157µs | 4.799µs | 110.849ns | 1.00x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `ipairs` | 9.455µs | 13.440µs | 13.495µs | 13.549µs | 48.004µs | 13.566µs | 1.599µs | 2.59x |
| `pairs` | 7.653µs | 12.016µs | 12.029µs | 12.045µs | 13.956µs | 12.023µs | 174.508ns | 2.31x |
| `next (global)` | 10.000µs | 11.919µs | 11.934µs | 11.952µs | 12.186µs | 11.918µs | 148.951ns | 2.29x |
| `next (local)` | 10.141µs | 11.895µs | 11.912µs | 11.933µs | 12.352µs | 11.903µs | 122.744ns | 2.29x |
| `local len` | 4.580µs | 5.212µs | 5.306µs | 5.408µs | 5.617µs | 5.306µs | 136.952ns | 1.02x |
| `table.n` | 4.860µs | 5.203µs | 5.210µs | 5.217µs | 5.340µs | 5.210µs | 24.554ns | 1.00x |
| `table[0]` | 4.801µs | 5.226µs | 5.230µs | 5.237µs | 5.439µs | 5.232µs | 21.870ns | 1.00x |
| `#table` | 1.537µs | 5.250µs | 5.348µs | 5.440µs | 10.093µs | 5.348µs | 235.671ns | 1.03x |
| `constant` | 4.561µs | 5.208µs | 5.307µs | 5.403µs | 5.634µs | 5.303µs | 140.038ns | 1.02x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `ipairs` | 4.930µs | 10.331µs | 10.340µs | 10.349µs | 11.245µs | 10.332µs | 193.494ns | 2.91x |
| `pairs` | 8.967µs | 10.551µs | 10.564µs | 10.583µs | 11.165µs | 10.566µs | 88.201ns | 2.97x |
| `next (global)` | 9.417µs | 10.451µs | 10.468µs | 10.487µs | 11.690µs | 10.470µs | 72.863ns | 2.95x |
| `next (local)` | 9.100µs | 10.449µs | 10.466µs | 10.485µs | 11.209µs | 10.468µs | 65.022ns | 2.95x |
| `local len` | 2.592µs | 3.553µs | 3.555µs | 3.558µs | 8.250µs | 3.564µs | 187.620ns | 1.00x |
| `table.n` | 294.449ns | 3.568µs | 3.570µs | 3.573µs | 11.278µs | 3.566µs | 294.461ns | 1.00x |
| `table[0]` | 2.851µs | 3.580µs | 3.582µs | 3.584µs | 3.729µs | 3.581µs | 32.173ns | 1.01x |
| `#table` | 2.774µs | 3.599µs | 3.602µs | 3.606µs | 3.696µs | 3.600µs | 36.885ns | 1.01x |
| `constant` | 2.792µs | 3.553µs | 3.554µs | 3.555µs | 3.643µs | 3.551µs | 37.684ns | 1.00x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `ipairs` | 7.454µs | 9.587µs | 9.602µs | 9.615µs | 10.226µs | 9.593µs | 124.873ns | 2.97x |
| `pairs` | 9.004µs | 10.549µs | 10.615µs | 10.696µs | 11.054µs | 10.620µs | 136.593ns | 3.29x |
| `next (global)` | 8.789µs | 10.489µs | 10.600µs | 10.716µs | 14.583µs | 10.612µs | 241.082ns | 3.28x |
| `next (local)` | 4.891µs | 10.516µs | 10.621µs | 10.726µs | 11.070µs | 10.617µs | 241.694ns | 3.29x |
| `local len` | 2.982µs | 3.232µs | 3.233µs | 3.234µs | 5.264µs | 3.235µs | 69.082ns | 1.00x |
| `table.n` | 2.777µs | 3.243µs | 3.245µs | 3.246µs | 4.297µs | 3.244µs | 42.350ns | 1.00x |
| `table[0]` | 374.831ns | 3.261µs | 3.265µs | 3.271µs | 3.662µs | 3.263µs | 96.787ns | 1.01x |
| `#table` | 2.702µs | 3.255µs | 3.257µs | 3.259µs | 11.001µs | 3.272µs | 305.090ns | 1.01x |
| `constant` | 2.804µs | 3.229µs | 3.230µs | 3.231µs | 3.380µs | 3.230µs | 27.495ns | 1.00x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `ipairs` | 451.946ns | 459.922ns | 460.047ns | 460.677ns | 471.437ns | 460.234ns | 1.218ns | 1.92x |
| `pairs` | 489.110ns | 1.148µs | 1.150µs | 1.151µs | 2.270µs | 1.153µs | 51.299ns | 4.81x |
| `next (global)` | 782.393ns | 1.240µs | 1.242µs | 1.244µs | 1.336µs | 1.241µs | 15.720ns | 5.19x |
| `next (local)` | 2.898µs | 3.096µs | 3.101µs | 3.105µs | 3.151µs | 3.100µs | 13.325ns | 12.96x |
| `local len` | 253.387ns | 260.294ns | 261.191ns | 261.880ns | 267.146ns | 261.099ns | 1.101ns | 1.09x |
| `table.n` | 244.114ns | 250.943ns | 251.310ns | 251.674ns | 257.899ns | 251.295ns | 0.798ns | 1.05x |
| `table[0]` | 190.301ns | 251.787ns | 252.226ns | 252.652ns | 420.356ns | 252.346ns | 5.749ns | 1.05x |
| `#table` | 270.192ns | 277.166ns | 277.591ns | 278.069ns | 293.853ns | 277.635ns | 0.982ns | 1.16x |
| `constant` | 231.748ns | 238.866ns | 239.356ns | 239.687ns | 243.933ns | 239.233ns | 0.828ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `ipairs` | 3.289µs | 3.964µs | 3.971µs | 3.978µs | 4.051µs | 3.968µs | 37.668ns | 2.78x |
| `pairs` | 989.898ns | 1.446µs | 1.451µs | 1.456µs | 3.817µs | 1.454µs | 93.283ns | 1.02x |
| `next (global)` | 1.236µs | 1.423µs | 1.428µs | 1.433µs | 1.498µs | 1.427µs | 14.551ns | 1.00x |
| `next (local)` | 4.216µs | 4.675µs | 4.683µs | 4.686µs | 7.239µs | 4.684µs | 85.367ns | 3.28x |
| `local len` | 1.755µs | 2.054µs | 2.058µs | 2.062µs | 3.394µs | 2.059µs | 45.308ns | 1.44x |
| `table.n` | 1.726µs | 2.063µs | 2.071µs | 2.084µs | 2.195µs | 2.072µs | 28.183ns | 1.45x |
| `table[0]` | 592.442ns | 2.062µs | 2.066µs | 2.071µs | 2.203µs | 2.062µs | 53.846ns | 1.45x |
| `#table` | 1.024µs | 2.083µs | 2.089µs | 2.095µs | 3.961µs | 2.087µs | 74.680ns | 1.46x |
| `constant` | 1.571µs | 2.054µs | 2.059µs | 2.063µs | 2.551µs | 2.055µs | 32.160ns | 1.44x |

## local vs global index

#### One-Time Setup
```lua
local s = math.sin
```

| Test | Code |
|------|------|
| `local` | `out = s(3.14)` |
| `global` | `out = math.sin(3.14)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 102.931ns | 122.488ns | 122.594ns | 122.799ns | 266.087ns | 122.784ns | 5.419ns | 1.00x |
| `global` | 148.947ns | 167.267ns | 168.094ns | 168.927ns | 176.524ns | 168.118ns | 2.095ns | 1.37x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 113.647ns | 132.244ns | 132.499ns | 132.740ns | 152.731ns | 132.481ns | 1.553ns | 1.00x |
| `global` | 173.320ns | 192.422ns | 192.984ns | 193.551ns | 205.114ns | 192.919ns | 1.616ns | 1.46x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 102.407ns | 125.509ns | 126.955ns | 127.818ns | 132.765ns | 126.546ns | 2.259ns | 1.00x |
| `global` | 103.362ns | 169.409ns | 169.828ns | 170.268ns | 188.658ns | 169.746ns | 2.529ns | 1.34x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 98.867ns | 111.012ns | 111.704ns | 112.723ns | 122.470ns | 111.992ns | 2.090ns | 1.00x |
| `global` | 124.118ns | 139.733ns | 140.231ns | 140.712ns | 160.196ns | 140.218ns | 1.418ns | 1.26x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 0.967ns | 1.005ns | 1.007ns | 1.008ns | 1.026ns | 1.007ns | 0.003ns | 1.00x |
| `global` | 0.945ns | 1.005ns | 1.007ns | 1.008ns | 1.055ns | 1.007ns | 0.005ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 43.624ns | 54.158ns | 54.212ns | 54.269ns | 55.910ns | 54.158ns | 0.530ns | 1.00x |
| `global` | 41.050ns | 67.290ns | 67.476ns | 67.542ns | 181.457ns | 67.491ns | 3.751ns | 1.24x |

## local vs global vs upvalue

#### One-Time Setup
```lua
local t_upvalue = type
```

#### Per Iteration Setup
```lua
local t_local = type
```

| Test | Code |
|------|------|
| `local` | `out = t_local(3)` |
| `upvalue` | `out = t_upvalue(3)` |
| `global` | `out = type(3)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 132.341ns | 153.599ns | 153.856ns | 154.124ns | 174.844ns | 153.871ns | 1.372ns | 1.00x |
| `upvalue` | 141.509ns | 153.890ns | 154.242ns | 154.526ns | 162.523ns | 154.257ns | 1.002ns | 1.00x |
| `global` | 161.707ns | 174.733ns | 175.448ns | 176.076ns | 188.951ns | 175.393ns | 1.445ns | 1.14x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 150.085ns | 165.648ns | 165.916ns | 166.197ns | 170.013ns | 165.913ns | 0.837ns | 1.00x |
| `upvalue` | 152.173ns | 166.954ns | 167.147ns | 167.404ns | 170.882ns | 167.167ns | 0.701ns | 1.01x |
| `global` | 183.831ns | 197.558ns | 197.909ns | 198.286ns | 204.186ns | 197.861ns | 1.001ns | 1.19x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 85.249ns | 118.334ns | 118.477ns | 118.640ns | 126.085ns | 118.337ns | 1.637ns | 1.01x |
| `upvalue` | 107.441ns | 117.559ns | 117.691ns | 117.842ns | 124.465ns | 117.612ns | 0.832ns | 1.00x |
| `global` | 112.589ns | 134.420ns | 134.697ns | 134.987ns | 141.861ns | 134.637ns | 1.175ns | 1.14x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 21.021ns | 102.522ns | 102.587ns | 102.657ns | 190.578ns | 102.474ns | 4.218ns | 1.00x |
| `upvalue` | 88.071ns | 102.758ns | 102.904ns | 103.040ns | 106.999ns | 102.864ns | 0.828ns | 1.00x |
| `global` | 87.933ns | 115.433ns | 115.629ns | 115.810ns | 133.649ns | 115.535ns | 1.513ns | 1.13x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 0.989ns | 1.005ns | 1.007ns | 1.008ns | 2.164ns | 1.008ns | 0.037ns | 1.00x |
| `upvalue` | 0.969ns | 1.005ns | 1.007ns | 1.008ns | 1.027ns | 1.007ns | 0.003ns | 1.00x |
| `global` | 0.962ns | 1.006ns | 1.007ns | 1.008ns | 1.056ns | 1.007ns | 0.004ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `local` | 37.272ns | 39.068ns | 39.103ns | 39.135ns | 138.432ns | 39.306ns | 4.042ns | 1.01x |
| `upvalue` | 35.292ns | 38.787ns | 38.822ns | 38.854ns | 40.632ns | 38.815ns | 0.180ns | 1.00x |
| `global` | 39.698ns | 40.563ns | 40.590ns | 40.633ns | 41.701ns | 40.608ns | 0.138ns | 1.05x |

## localized method

#### One-Time Setup
```lua
local class = {
	test = function(self) return 1 end,
}
local ltest = class.test
```

| Test | Code |
|------|------|
| `none` | `out = class:test(); out = class:test(); out = class:test()` |
| `inside loop` | `local test = class.test; out = test(class); out = test(class); out = test(class)` |
| `outside loop` | `out = ltest(class); out = ltest(class); out = ltest(class)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `none` | 278.752ns | 372.145ns | 372.725ns | 373.340ns | 869.685ns | 373.603ns | 21.334ns | 1.23x |
| `inside loop` | 318.607ns | 331.350ns | 332.131ns | 332.928ns | 394.044ns | 332.211ns | 2.645ns | 1.09x |
| `outside loop` | 59.500ns | 303.423ns | 303.799ns | 304.201ns | 315.939ns | 303.333ns | 8.840ns | 1.00x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `none` | 405.406ns | 451.462ns | 455.956ns | 459.905ns | 495.713ns | 455.694ns | 8.866ns | 1.18x |
| `inside loop` | 355.178ns | 400.303ns | 408.107ns | 414.177ns | 443.229ns | 405.834ns | 12.761ns | 1.05x |
| `outside loop` | 321.347ns | 380.268ns | 387.701ns | 393.495ns | 427.663ns | 387.197ns | 10.365ns | 1.00x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `none` | 296.208ns | 383.857ns | 388.093ns | 391.205ns | 711.640ns | 387.602ns | 12.868ns | 1.17x |
| `inside loop` | 325.398ns | 354.426ns | 357.381ns | 359.695ns | 384.379ns | 356.847ns | 5.557ns | 1.08x |
| `outside loop` | 288.571ns | 329.929ns | 331.702ns | 333.299ns | 358.429ns | 331.228ns | 4.841ns | 1.00x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `none` | 315.014ns | 332.725ns | 333.789ns | 334.736ns | 347.151ns | 333.641ns | 1.999ns | 1.16x |
| `inside loop` | 243.342ns | 293.555ns | 294.434ns | 295.272ns | 1.062µs | 295.050ns | 24.430ns | 1.02x |
| `outside loop` | 230.758ns | 287.375ns | 288.245ns | 289.177ns | 333.743ns | 288.234ns | 4.227ns | 1.00x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `none` | 0.852ns | 1.006ns | 1.007ns | 1.008ns | 1.115ns | 1.007ns | 0.010ns | 1.00x |
| `inside loop` | 0.972ns | 1.006ns | 1.007ns | 1.008ns | 1.074ns | 1.007ns | 0.004ns | 1.00x |
| `outside loop` | 0.988ns | 1.006ns | 1.007ns | 1.008ns | 1.044ns | 1.007ns | 0.003ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `none` | 74.145ns | 141.393ns | 141.729ns | 141.855ns | 186.823ns | 141.612ns | 2.749ns | 1.20x |
| `inside loop` | 83.901ns | 120.480ns | 120.661ns | 120.823ns | 152.493ns | 120.589ns | 2.215ns | 1.02x |
| `outside loop` | 97.186ns | 118.230ns | 118.422ns | 118.634ns | 122.062ns | 118.396ns | 0.868ns | 1.00x |

## math.max

#### One-Time Setup
```lua
local max, x, y = math.max, 1, 100
```

| Test | Code |
|------|------|
| `math.max (global)` | `out = math.max(x, y)` |
| `math.max (local)` | `out = max(x, y)` |
| `if-else` | `if x > y then out = x else out = y end` |
| `branchless` | `out = x > y and x or y` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 154.027ns | 166.182ns | 166.770ns | 167.623ns | 173.804ns | 166.880ns | 1.298ns | 3.09x |
| `math.max (local)` | 108.857ns | 118.950ns | 119.595ns | 120.271ns | 285.390ns | 119.780ns | 5.384ns | 2.22x |
| `if-else` | 49.218ns | 53.412ns | 53.925ns | 54.433ns | 57.657ns | 53.792ns | 1.132ns | 1.00x |
| `branchless` | 43.276ns | 53.594ns | 53.927ns | 54.456ns | 56.977ns | 53.828ns | 1.231ns | 1.00x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 159.581ns | 192.415ns | 192.854ns | 193.253ns | 199.678ns | 192.615ns | 2.523ns | 2.66x |
| `math.max (local)` | 90.044ns | 128.671ns | 129.552ns | 129.910ns | 137.733ns | 129.256ns | 1.865ns | 1.78x |
| `if-else` | 56.281ns | 69.650ns | 72.697ns | 75.991ns | 90.097ns | 72.977ns | 5.083ns | 1.00x |
| `branchless` | 59.580ns | 69.907ns | 72.578ns | 76.018ns | 89.264ns | 72.971ns | 4.608ns | 1.00x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 129.607ns | 156.591ns | 156.739ns | 156.888ns | 161.155ns | 156.683ns | 1.354ns | 2.59x |
| `math.max (local)` | 87.235ns | 111.215ns | 111.273ns | 111.347ns | 126.668ns | 111.230ns | 1.278ns | 1.84x |
| `if-else` | 45.204ns | 60.355ns | 60.429ns | 60.517ns | 64.280ns | 60.400ns | 0.647ns | 1.00x |
| `branchless` | 46.670ns | 60.341ns | 60.419ns | 60.511ns | 61.929ns | 60.304ns | 0.959ns | 1.00x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 99.902ns | 129.491ns | 130.371ns | 131.966ns | 141.730ns | 130.566ns | 2.756ns | 3.08x |
| `math.max (local)` | 83.817ns | 106.273ns | 108.651ns | 110.908ns | 128.494ns | 108.619ns | 3.783ns | 2.57x |
| `if-else` | 38.435ns | 42.252ns | 42.267ns | 42.369ns | 120.302ns | 42.484ns | 3.141ns | 1.00x |
| `branchless` | 35.580ns | 42.251ns | 42.263ns | 42.366ns | 44.460ns | 42.289ns | 0.287ns | 1.00x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 9.990ns | 10.060ns | 10.066ns | 10.077ns | 10.380ns | 10.071ns | 0.022ns | 10.00x |
| `math.max (local)` | 0.945ns | 1.005ns | 1.007ns | 1.008ns | 1.025ns | 1.007ns | 0.004ns | 1.00x |
| `if-else` | 0.975ns | 1.006ns | 1.008ns | 1.008ns | 1.050ns | 1.007ns | 0.004ns | 1.00x |
| `branchless` | 0.973ns | 1.006ns | 1.007ns | 1.008ns | 1.027ns | 1.007ns | 0.003ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 46.225ns | 51.087ns | 51.109ns | 51.138ns | 53.902ns | 51.115ns | 0.273ns | 1.93x |
| `math.max (local)` | 36.208ns | 40.828ns | 40.944ns | 41.115ns | 43.153ns | 40.964ns | 0.312ns | 1.54x |
| `if-else` | 3.631ns | 26.487ns | 26.512ns | 26.530ns | 32.690ns | 26.484ns | 0.846ns | 1.00x |
| `branchless` | 21.619ns | 26.484ns | 26.513ns | 26.529ns | 184.069ns | 26.704ns | 5.016ns | 1.00x |

## math.max of 3 numbers

#### One-Time Setup
```lua
local max, x, y, z = math.max, 1, 100, 55
```

| Test | Code |
|------|------|
| `math.max (global)` | `out = math.max(x, y, z)` |
| `math.max (local)` | `out = max(x, y, z)` |
| `if-else` | `if x > y and x > z then out = x elseif y > z and y > x then out = y else out = z end` |
| `branchless` | `out = (x > y and x > z and x) or (y > z and y > x and y) or (z)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 166.792ns | 186.818ns | 187.555ns | 188.304ns | 195.652ns | 187.553ns | 1.575ns | 1.45x |
| `math.max (local)` | 122.867ns | 140.497ns | 141.294ns | 142.049ns | 152.817ns | 141.228ns | 1.526ns | 1.09x |
| `if-else` | 80.505ns | 128.518ns | 129.055ns | 129.555ns | 332.932ns | 129.086ns | 6.849ns | 1.00x |
| `branchless` | 68.520ns | 134.535ns | 135.063ns | 136.128ns | 157.137ns | 135.087ns | 2.818ns | 1.05x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 166.720ns | 217.894ns | 218.819ns | 219.802ns | 240.852ns | 218.654ns | 3.385ns | 1.42x |
| `math.max (local)` | 133.719ns | 153.186ns | 153.983ns | 154.435ns | 449.314ns | 154.077ns | 9.466ns | 1.00x |
| `if-else` | 138.833ns | 162.755ns | 165.406ns | 169.018ns | 201.565ns | 166.587ns | 7.169ns | 1.07x |
| `branchless` | 134.526ns | 171.868ns | 174.754ns | 177.275ns | 205.753ns | 174.642ns | 5.058ns | 1.13x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 159.438ns | 182.491ns | 182.800ns | 183.131ns | 190.854ns | 182.748ns | 1.385ns | 1.34x |
| `math.max (local)` | 45.359ns | 136.466ns | 136.862ns | 137.046ns | 517.239ns | 137.167ns | 12.431ns | 1.00x |
| `if-else` | 115.069ns | 137.034ns | 137.445ns | 137.515ns | 151.361ns | 137.260ns | 1.169ns | 1.00x |
| `branchless` | 97.621ns | 142.040ns | 142.427ns | 142.508ns | 826.287ns | 143.680ns | 27.113ns | 1.04x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 138.288ns | 166.247ns | 167.143ns | 167.876ns | 173.262ns | 166.993ns | 1.867ns | 1.76x |
| `math.max (local)` | 130.133ns | 141.961ns | 143.096ns | 144.244ns | 185.652ns | 142.678ns | 3.466ns | 1.51x |
| `if-else` | 81.769ns | 94.636ns | 94.763ns | 94.907ns | 101.584ns | 94.780ns | 0.824ns | 1.00x |
| `branchless` | 57.813ns | 102.679ns | 102.711ns | 102.736ns | 184.717ns | 102.737ns | 3.333ns | 1.08x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 8.777ns | 9.054ns | 9.070ns | 9.073ns | 9.469ns | 9.066ns | 0.037ns | 9.01x |
| `math.max (local)` | 0.987ns | 1.006ns | 1.007ns | 1.008ns | 1.051ns | 1.007ns | 0.003ns | 1.00x |
| `if-else` | 0.982ns | 1.006ns | 1.008ns | 1.008ns | 1.091ns | 1.008ns | 0.005ns | 1.00x |
| `branchless` | 0.984ns | 1.006ns | 1.007ns | 1.008ns | 1.051ns | 1.007ns | 0.003ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.max (global)` | 47.037ns | 56.387ns | 56.413ns | 56.456ns | 60.605ns | 56.395ns | 0.497ns | 1.30x |
| `math.max (local)` | 40.041ns | 43.369ns | 43.429ns | 43.508ns | 109.081ns | 43.493ns | 2.090ns | 1.00x |
| `if-else` | 46.243ns | 59.014ns | 59.095ns | 59.174ns | 421.534ns | 61.227ns | 27.411ns | 1.36x |
| `branchless` | 44.952ns | 57.546ns | 57.609ns | 57.687ns | 70.484ns | 57.647ns | 0.832ns | 1.33x |

## select

#### One-Time Setup
```lua
local function fn()
	return 1, 2, 3, 4
end
local sel = select
```

| Test | Code |
|------|------|
| `argument expanision` | `local _; _, _, _, out = fn()` |
| `select (global)` | `out = select(4, fn())` |
| `select (local)` | `out = sel(4, fn())` |
| `table` | `out = ({ fn() })[4]` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 120.156ns | 144.571ns | 145.153ns | 145.858ns | 152.194ns | 145.125ns | 1.758ns | 1.00x |
| `select (global)` | 197.023ns | 226.510ns | 227.747ns | 228.753ns | 235.213ns | 227.547ns | 2.331ns | 1.57x |
| `select (local)` | 197.556ns | 204.279ns | 205.917ns | 207.196ns | 214.140ns | 205.702ns | 2.256ns | 1.42x |
| `table` | 407.167ns | 421.444ns | 435.679ns | 448.752ns | 514.539ns | 434.855ns | 15.271ns | 3.00x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 175.242ns | 198.115ns | 199.377ns | 201.337ns | 243.073ns | 199.894ns | 4.547ns | 1.00x |
| `select (global)` | 218.632ns | 261.289ns | 262.021ns | 262.665ns | 290.505ns | 261.806ns | 2.792ns | 1.31x |
| `select (local)` | 236.925ns | 252.310ns | 254.976ns | 258.855ns | 279.634ns | 255.187ns | 5.435ns | 1.28x |
| `table` | 389.493ns | 409.698ns | 417.978ns | 427.589ns | 516.492ns | 419.713ns | 12.712ns | 2.10x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 114.848ns | 140.750ns | 141.054ns | 141.184ns | 206.388ns | 140.971ns | 2.492ns | 1.00x |
| `select (global)` | 193.690ns | 220.929ns | 221.345ns | 222.222ns | 231.049ns | 221.600ns | 1.823ns | 1.57x |
| `select (local)` | 181.307ns | 202.846ns | 203.235ns | 204.118ns | 208.103ns | 203.419ns | 1.713ns | 1.44x |
| `table` | 395.311ns | 431.122ns | 435.959ns | 440.635ns | 530.096ns | 436.006ns | 10.413ns | 3.09x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 106.700ns | 133.172ns | 134.268ns | 135.341ns | 147.523ns | 134.140ns | 2.570ns | 1.00x |
| `select (global)` | 140.379ns | 186.116ns | 188.314ns | 190.180ns | 503.212ns | 188.416ns | 10.629ns | 1.40x |
| `select (local)` | 150.596ns | 180.526ns | 181.872ns | 183.419ns | 191.460ns | 181.965ns | 3.062ns | 1.35x |
| `table` | 242.717ns | 370.502ns | 378.402ns | 389.959ns | 813.607ns | 389.067ns | 44.697ns | 2.82x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 0.852ns | 1.006ns | 1.007ns | 1.008ns | 2.252ns | 1.008ns | 0.040ns | 1.00x |
| `select (global)` | 5.777ns | 7.045ns | 7.047ns | 7.053ns | 9.662ns | 7.051ns | 0.093ns | 7.00x |
| `select (local)` | 0.967ns | 1.006ns | 1.007ns | 1.008ns | 1.055ns | 1.007ns | 0.004ns | 1.00x |
| `table` | 247.656ns | 23.442µs | 23.541µs | 23.658µs | 44.951µs | 23.586µs | 1.055µs | 23376.10x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 51.486ns | 68.650ns | 68.851ns | 68.897ns | 81.024ns | 68.807ns | 0.976ns | 1.00x |
| `select (global)` | 84.648ns | 102.946ns | 103.062ns | 103.189ns | 274.472ns | 103.257ns | 5.998ns | 1.50x |
| `select (local)` | 90.010ns | 99.551ns | 99.654ns | 99.838ns | 234.457ns | 99.799ns | 4.319ns | 1.45x |
| `table` | 158.498ns | 197.581ns | 199.990ns | 209.035ns | 444.831ns | 238.572ns | 79.796ns | 2.90x |

## square

#### One-Time Setup
```lua
local x, pow = 10, math.pow
```

| Test | Code |
|------|------|
| `math.pow (global)` | `out = math.pow(x, 3)` |
| `math.pow (local)` | `out = pow(x, 3)` |
| `multiply` | `out = x * x * x` |
| `exponent` | `out = x ^ 3` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 132.584ns | 228.039ns | 228.980ns | 229.953ns | 252.893ns | 228.924ns | 3.950ns | 3.86x |
| `math.pow (local)` | 157.691ns | 183.702ns | 183.928ns | 184.165ns | 191.749ns | 183.881ns | 1.394ns | 3.10x |
| `multiply` | 45.985ns | 59.352ns | 59.395ns | 59.499ns | 63.469ns | 59.352ns | 0.730ns | 1.00x |
| `exponent` | 29.662ns | 91.463ns | 91.556ns | 91.698ns | 118.596ns | 91.420ns | 2.876ns | 1.54x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 170.803ns | 257.687ns | 258.279ns | 258.757ns | 1.162µs | 259.010ns | 28.763ns | 3.09x |
| `math.pow (local)` | 162.722ns | 187.891ns | 188.314ns | 188.703ns | 195.140ns | 188.014ns | 2.326ns | 2.26x |
| `multiply` | 72.558ns | 82.904ns | 83.493ns | 84.042ns | 94.918ns | 83.436ns | 0.999ns | 1.00x |
| `exponent` | 14.536ns | 95.802ns | 95.900ns | 95.961ns | 153.476ns | 95.912ns | 3.980ns | 1.15x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 117.663ns | 249.466ns | 249.894ns | 250.264ns | 256.385ns | 249.542ns | 4.957ns | 4.71x |
| `math.pow (local)` | 194.777ns | 202.566ns | 202.976ns | 203.294ns | 209.858ns | 202.929ns | 0.845ns | 3.82x |
| `multiply` | 43.901ns | 53.052ns | 53.075ns | 53.099ns | 56.387ns | 53.045ns | 0.543ns | 1.00x |
| `exponent` | 87.993ns | 108.273ns | 108.440ns | 108.704ns | 119.112ns | 108.413ns | 0.952ns | 2.04x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 203.205ns | 226.916ns | 228.270ns | 229.687ns | 243.800ns | 228.251ns | 2.583ns | 4.20x |
| `math.pow (local)` | 177.991ns | 196.146ns | 196.816ns | 197.625ns | 216.167ns | 196.899ns | 1.751ns | 3.62x |
| `multiply` | 40.212ns | 54.164ns | 54.359ns | 54.505ns | 56.758ns | 54.343ns | 0.720ns | 1.00x |
| `exponent` | 83.303ns | 89.111ns | 89.385ns | 89.645ns | 93.212ns | 89.277ns | 0.734ns | 1.64x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 8.611ns | 9.054ns | 9.070ns | 9.072ns | 18.681ns | 9.095ns | 0.337ns | 9.01x |
| `math.pow (local)` | 0.970ns | 1.006ns | 1.007ns | 1.008ns | 1.056ns | 1.007ns | 0.004ns | 1.00x |
| `multiply` | 0.946ns | 1.006ns | 1.008ns | 1.008ns | 1.138ns | 1.008ns | 0.007ns | 1.00x |
| `exponent` | 0.989ns | 1.005ns | 1.007ns | 1.008ns | 1.091ns | 1.007ns | 0.005ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `math.pow (global)` | 96.222ns | 109.099ns | 109.145ns | 109.195ns | 112.600ns | 109.090ns | 0.673ns | 3.73x |
| `math.pow (local)` | 88.868ns | 98.548ns | 98.639ns | 98.725ns | 103.963ns | 98.615ns | 0.535ns | 3.37x |
| `multiply` | 22.241ns | 29.259ns | 29.293ns | 29.330ns | 31.453ns | 29.285ns | 0.354ns | 1.00x |
| `exponent` | 68.480ns | 77.930ns | 78.009ns | 78.060ns | 88.758ns | 77.963ns | 0.566ns | 2.66x |

## string concatenation

#### One-Time Setup
```lua
local bs = string.rep("---------", 127)
local t = { bs, bs, bs, bs, bs, bs, bs, bs, bs, bs }
local concat, format = table.concat, string.format
```

| Test | Code |
|------|------|
| `all-in-one` | `out = bs .. bs .. bs .. bs .. bs .. bs .. bs .. bs .. bs .. bs` |
| `separated` | `out = bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs;` |
| `loop` | `out = bs; for i = 1, 9 do out = out .. bs end` |
| `format` | `out = format("%s%s%s%s%s%s%s%s%s%s", bs, bs, bs, bs, bs, bs, bs, bs, bs, bs)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `all-in-one` | 924.271ns | 1.407µs | 1.418µs | 1.431µs | 1.490µs | 1.418µs | 23.909ns | 1.00x |
| `separated` | 9.234µs | 10.168µs | 10.197µs | 10.230µs | 12.043µs | 10.202µs | 97.599ns | 7.19x |
| `loop` | 10.028µs | 10.223µs | 10.252µs | 10.283µs | 10.554µs | 10.255µs | 49.021ns | 7.23x |
| `format` | 3.871µs | 5.266µs | 5.295µs | 5.325µs | 5.807µs | 5.294µs | 76.469ns | 3.73x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `all-in-one` | 14.636µs | 23.443µs | 24.431µs | 28.530µs | 32.540µs | 25.137µs | 3.587µs | 2.38x |
| `separated` | 18.939µs | 22.590µs | 23.384µs | 24.369µs | 32.458µs | 23.688µs | 1.628µs | 2.27x |
| `loop` | 17.283µs | 22.519µs | 23.337µs | 24.345µs | 33.599µs | 23.619µs | 1.728µs | 2.27x |
| `format` | 6.201µs | 9.587µs | 10.283µs | 11.484µs | 16.415µs | 10.484µs | 1.113µs | 1.00x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `all-in-one` | 4.511µs | 7.221µs | 7.469µs | 8.043µs | 12.429µs | 7.710µs | 1.005µs | 1.24x |
| `separated` | 21.664µs | 26.287µs | 27.146µs | 27.765µs | 38.038µs | 27.201µs | 1.713µs | 4.52x |
| `loop` | 21.664µs | 26.490µs | 27.277µs | 27.952µs | 39.986µs | 27.362µs | 1.600µs | 4.54x |
| `format` | 3.899µs | 5.834µs | 6.007µs | 6.305µs | 8.078µs | 6.056µs | 378.987ns | 1.00x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `all-in-one` | 10.841µs | 20.958µs | 21.768µs | 25.389µs | 30.653µs | 22.387µs | 3.610µs | 3.25x |
| `separated` | 21.423µs | 25.663µs | 26.850µs | 27.458µs | 38.252µs | 26.762µs | 1.678µs | 4.01x |
| `loop` | 19.913µs | 25.237µs | 26.425µs | 27.144µs | 39.660µs | 26.356µs | 1.690µs | 3.95x |
| `format` | 5.517µs | 6.489µs | 6.689µs | 6.953µs | 8.116µs | 6.723µs | 319.286ns | 1.00x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `all-in-one` | 0.969ns | 1.005ns | 1.007ns | 1.008ns | 1.046ns | 1.007ns | 0.004ns | 1.00x |
| `separated` | 0.969ns | 1.006ns | 1.008ns | 1.008ns | 1.038ns | 1.007ns | 0.003ns | 1.00x |
| `loop` | 5.610µs | 5.892µs | 5.906µs | 5.921µs | 6.612µs | 5.909µs | 46.003ns | 5864.36x |
| `format` | 0.929ns | 1.006ns | 1.008ns | 1.009ns | 1.123ns | 1.008ns | 0.007ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `all-in-one` | 1.013µs | 1.109µs | 1.115µs | 1.123µs | 1.185µs | 1.117µs | 13.423ns | 1.00x |
| `separated` | 8.414µs | 8.513µs | 8.544µs | 8.574µs | 8.885µs | 8.546µs | 50.925ns | 7.67x |
| `loop` | 7.476µs | 8.535µs | 8.562µs | 8.589µs | 12.616µs | 8.574µs | 183.428ns | 7.68x |
| `format` | 1.560µs | 1.637µs | 1.646µs | 1.657µs | 1.698µs | 1.647µs | 16.036ns | 1.48x |

## table insert

#### One-Time Setup
```lua
local tinsert = table.insert
```

#### Per Iteration Setup
```lua
out = { [0] = 0, n = 0 }
local count = 1
```

| Test | Code |
|------|------|
| `table.insert` | `tinsert(out, __i)` |
| `loop parameter` | `out[__i] = __i` |
| `#table+1` | `out[#out + 1] = __i` |
| `table.n` | `out.n = out.n + 1; out[out.n] = __i` |
| `table[0]` | `out[0] = out[0] + 1; out[out[0]] = __i` |
| `lockstep parameter` | `out[count] = __i; count = count + 1` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `table.insert` | 292.529ns | 296.907ns | 297.735ns | 298.458ns | 305.749ns | 297.711ns | 1.342ns | 4.96x |
| `loop parameter` | 53.631ns | 59.204ns | 60.062ns | 61.058ns | 67.554ns | 60.148ns | 1.453ns | 1.00x |
| `#table+1` | 230.768ns | 250.995ns | 251.902ns | 252.920ns | 260.018ns | 251.979ns | 1.964ns | 4.19x |
| `table.n` | 147.864ns | 167.052ns | 167.437ns | 167.860ns | 174.327ns | 167.438ns | 1.318ns | 2.79x |
| `table[0]` | 150.849ns | 171.969ns | 172.621ns | 173.241ns | 184.309ns | 172.632ns | 1.604ns | 2.87x |
| `lockstep parameter` | 52.963ns | 70.984ns | 72.304ns | 73.786ns | 311.111ns | 72.796ns | 9.213ns | 1.20x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `table.insert` | 273.289ns | 331.123ns | 332.428ns | 333.794ns | 374.052ns | 332.429ns | 3.380ns | 5.78x |
| `loop parameter` | 0.043ns | 57.338ns | 57.488ns | 57.698ns | 66.719ns | 57.466ns | 2.392ns | 1.00x |
| `#table+1` | 230.926ns | 257.099ns | 258.394ns | 259.738ns | 265.641ns | 258.275ns | 2.473ns | 4.49x |
| `table.n` | 165.655ns | 173.612ns | 173.998ns | 174.496ns | 181.761ns | 174.089ns | 0.933ns | 3.03x |
| `table[0]` | 126.801ns | 242.218ns | 242.656ns | 243.069ns | 302.831ns | 242.535ns | 6.115ns | 4.22x |
| `lockstep parameter` | 67.075ns | 70.655ns | 71.123ns | 71.632ns | 78.495ns | 71.208ns | 0.840ns | 1.24x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `table.insert` | 287.978ns | 314.858ns | 315.591ns | 316.354ns | 328.222ns | 315.538ns | 2.123ns | 5.03x |
| `loop parameter` | 49.550ns | 62.394ns | 62.695ns | 62.983ns | 67.675ns | 62.668ns | 0.866ns | 1.00x |
| `#table+1` | 240.573ns | 256.278ns | 257.844ns | 259.401ns | 310.064ns | 257.885ns | 2.932ns | 4.11x |
| `table.n` | 103.300ns | 137.268ns | 137.964ns | 138.769ns | 365.069ns | 138.142ns | 7.560ns | 2.20x |
| `table[0]` | 64.243ns | 164.310ns | 164.809ns | 165.282ns | 293.743ns | 164.895ns | 5.425ns | 2.63x |
| `lockstep parameter` | 63.199ns | 73.436ns | 73.969ns | 74.446ns | 91.104ns | 73.945ns | 1.145ns | 1.18x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `table.insert` | 82.444ns | 163.784ns | 165.019ns | 166.090ns | 180.717ns | 164.822ns | 3.488ns | 3.81x |
| `loop parameter` | 35.952ns | 42.306ns | 43.365ns | 43.891ns | 50.513ns | 43.218ns | 1.211ns | 1.00x |
| `#table+1` | 65.348ns | 77.367ns | 78.354ns | 79.318ns | 86.115ns | 78.413ns | 1.667ns | 1.81x |
| `table.n` | 20.650ns | 98.937ns | 99.178ns | 99.478ns | 344.013ns | 99.747ns | 11.288ns | 2.29x |
| `table[0]` | 96.132ns | 115.454ns | 116.377ns | 117.625ns | 123.218ns | 116.533ns | 1.652ns | 2.68x |
| `lockstep parameter` | 40.130ns | 50.193ns | 52.117ns | 53.225ns | 60.096ns | 51.891ns | 1.780ns | 1.20x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `table.insert` | 36.277ns | 37.363ns | 37.469ns | 37.598ns | 40.829ns | 37.509ns | 0.269ns | 1.18x |
| `loop parameter` | 31.142ns | 31.654ns | 31.778ns | 31.911ns | 42.487ns | 31.811ns | 0.420ns | 1.00x |
| `#table+1` | 32.309ns | 37.762ns | 37.927ns | 38.130ns | 81.068ns | 37.978ns | 1.402ns | 1.19x |
| `table.n` | 33.838ns | 34.676ns | 34.784ns | 34.916ns | 35.878ns | 34.805ns | 0.205ns | 1.09x |
| `table[0]` | 39.135ns | 39.644ns | 39.774ns | 39.913ns | 41.098ns | 39.787ns | 0.211ns | 1.25x |
| `lockstep parameter` | 34.108ns | 34.662ns | 34.772ns | 34.904ns | 35.878ns | 34.793ns | 0.203ns | 1.09x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `table.insert` | 132.288ns | 214.649ns | 215.618ns | 216.594ns | 364.381ns | 215.786ns | 6.830ns | 8.31x |
| `loop parameter` | 46.184ns | 48.275ns | 48.362ns | 48.447ns | 50.087ns | 48.372ns | 0.213ns | 1.86x |
| `#table+1` | 184.781ns | 196.952ns | 197.617ns | 198.412ns | 208.122ns | 197.617ns | 1.422ns | 7.62x |
| `table.n` | 24.394ns | 54.824ns | 55.888ns | 56.479ns | 122.896ns | 55.703ns | 2.611ns | 2.15x |
| `table[0]` | 35.439ns | 47.334ns | 47.414ns | 47.513ns | 49.484ns | 47.382ns | 0.532ns | 1.83x |
| `lockstep parameter` | 19.627ns | 25.885ns | 25.938ns | 26.030ns | 29.629ns | 25.952ns | 0.416ns | 1.00x |

## table slice

#### One-Time Setup
```lua
local unpack = unpack or table.unpack
local a = {}
for i = 1, 2000 do
	a[i] = i
end
local x, y = 500, 1500
local tnew = table.new
```

| Test | Code |
|------|------|
| `unpack` | `out = {unpack(a, x, y)}` |
| `from scratch` | `out = {}; for i = x, y do out[i - x + 1] = a[i] end` |
| `allocated` | `out = table.new(y - x, 0); for i = x, y do out[i - x + 1] = a[i] end` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `unpack` | 32.091µs | 33.646µs | 33.946µs | 34.218µs | 36.644µs | 33.961µs | 497.186ns | 1.00x |
| `from scratch` | 137.485µs | 139.224µs | 139.471µs | 139.727µs | 185.816µs | 139.542µs | 1.786µs | 4.11x |
| `allocated` | - | - | - | - | - | - | - | - |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `unpack` | 34.085µs | 35.571µs | 38.101µs | 38.752µs | 40.329µs | 37.471µs | 1.645µs | 1.00x |
| `from scratch` | 117.744µs | 137.227µs | 137.393µs | 137.525µs | 140.538µs | 137.322µs | 795.410ns | 3.61x |
| `allocated` | - | - | - | - | - | - | - | - |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `unpack` | 31.210µs | 33.946µs | 34.094µs | 34.253µs | 36.344µs | 34.138µs | 334.782ns | 1.00x |
| `from scratch` | 115.169µs | 116.853µs | 117.011µs | 117.161µs | 135.052µs | 117.024µs | 670.997ns | 3.43x |
| `allocated` | - | - | - | - | - | - | - | - |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `unpack` | 22.087µs | 28.592µs | 28.678µs | 28.785µs | 87.577µs | 28.795µs | 2.037µs | 1.00x |
| `from scratch` | 44.135µs | 96.014µs | 96.135µs | 96.257µs | 227.693µs | 96.259µs | 4.643µs | 3.35x |
| `allocated` | - | - | - | - | - | - | - | - |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `unpack` | 9.142µs | 9.721µs | 10.087µs | 17.308µs | 32.176µs | 13.442µs | 3.860µs | 1.14x |
| `from scratch` | 9.933µs | 10.334µs | 10.472µs | 10.604µs | 12.097µs | 10.481µs | 226.812ns | 1.19x |
| `allocated` | 7.765µs | 8.595µs | 8.816µs | 9.122µs | 12.004µs | 8.860µs | 374.440ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `unpack` | 9.193µs | 9.654µs | 13.772µs | 30.721µs | 37.327µs | 18.511µs | 10.178µs | 1.00x |
| `from scratch` | 53.407µs | 54.714µs | 66.209µs | 69.731µs | 72.706µs | 62.249µs | 7.549µs | 4.81x |
| `allocated` | 49.754µs | 50.994µs | 51.155µs | 51.311µs | 201.109µs | 51.452µs | 5.124µs | 3.71x |

## table unpack

#### One-Time Setup
```lua
local a = { 9, 121, 131, 1787 }
local unpack = unpack or table.unpack
local function unpack4(a)
	return a[1], a[2], a[3], a[4]
end
```

| Test | Code |
|------|------|
| `argument expanision` | `local a1, a2, a3, a4 = a[1], a[2], a[3], a[4]` |
| `unpack` | `local a1, a2, a3, a4 = unpack(a)` |
| `function` | `local a1, a2, a3, a4 = unpack4(a)` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 165.280ns | 181.460ns | 188.078ns | 190.359ns | 202.985ns | 186.229ns | 5.935ns | 1.00x |
| `unpack` | 35.247ns | 203.615ns | 204.971ns | 206.438ns | 453.607ns | 205.142ns | 9.900ns | 1.09x |
| `function` | 222.198ns | 235.027ns | 236.438ns | 237.498ns | 251.405ns | 236.289ns | 2.261ns | 1.26x |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 105.520ns | 207.163ns | 210.110ns | 214.261ns | 225.170ns | 210.467ns | 6.171ns | 1.00x |
| `unpack` | 195.031ns | 238.389ns | 240.455ns | 242.416ns | 259.314ns | 240.441ns | 3.389ns | 1.14x |
| `function` | 327.438ns | 348.032ns | 348.832ns | 349.839ns | 367.315ns | 348.917ns | 2.227ns | 1.66x |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 86.936ns | 99.354ns | 99.396ns | 99.425ns | 100.895ns | 99.330ns | 0.769ns | 1.00x |
| `unpack` | 166.185ns | 221.416ns | 222.421ns | 223.398ns | 228.873ns | 222.062ns | 3.436ns | 2.24x |
| `function` | 120.521ns | 169.779ns | 169.990ns | 170.224ns | 472.288ns | 170.342ns | 10.163ns | 1.71x |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 71.676ns | 81.492ns | 81.519ns | 81.625ns | 85.497ns | 81.544ns | 0.578ns | 1.00x |
| `unpack` | 57.677ns | 209.829ns | 212.733ns | 215.564ns | 252.845ns | 212.157ns | 7.862ns | 2.61x |
| `function` | 118.123ns | 131.316ns | 132.735ns | 133.990ns | 138.126ns | 132.641ns | 2.160ns | 1.63x |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 0.956ns | 1.006ns | 1.007ns | 1.008ns | 1.037ns | 1.007ns | 0.004ns | 1.00x |
| `unpack` | 95.420ns | 103.103ns | 103.264ns | 103.400ns | 112.340ns | 103.241ns | 0.586ns | 102.52x |
| `function` | 0.967ns | 1.006ns | 1.008ns | 1.008ns | 1.210ns | 1.008ns | 0.008ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `argument expanision` | 40.670ns | 47.319ns | 47.366ns | 47.434ns | 49.642ns | 47.340ns | 0.539ns | 1.00x |
| `unpack` | 63.036ns | 77.664ns | 77.808ns | 78.092ns | 85.667ns | 77.888ns | 1.260ns | 1.64x |
| `function` | 63.025ns | 74.132ns | 74.249ns | 74.291ns | 80.005ns | 74.215ns | 0.790ns | 1.57x |

## table.new

| Test | Code |
|------|------|
| `literal` | `out = {1, 2, 3}` |
| `start empty` | `out = {}; out[1] = 1; out[2] = 2; out[3] = 3` |
| `start false` | `out = {false, false, false}; out[1] = 1; out[2] = 2; out[3] = 3` |
| `preallocate` | `out = table.new(3, 0); out[1] = 1; out[2] = 2; out[3] = 3` |
| `ffi fill` | `out = ffi.new("int[3]", 1, 2, 3)` |
| `ffi individual` | `out = ffi.new("int[3]"); out[0] = 1; out[1] = 2; out[2] = 3` |

### Lua 5.1

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `literal` | 234.786ns | 245.954ns | 259.680ns | 269.272ns | 368.339ns | 259.080ns | 14.708ns | 1.00x |
| `start empty` | 856.099ns | 955.001ns | 961.343ns | 967.730ns | 1.097µs | 962.219ns | 12.916ns | 3.70x |
| `start false` | 386.505ns | 433.539ns | 443.248ns | 454.370ns | 759.155ns | 445.567ns | 24.029ns | 1.71x |
| `preallocate` | - | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - | - |

### Lua 5.2

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `literal` | 239.990ns | 254.394ns | 278.265ns | 304.228ns | 373.201ns | 279.444ns | 25.932ns | 1.00x |
| `start empty` | 777.484ns | 926.910ns | 931.203ns | 937.577ns | 997.774ns | 931.844ns | 9.921ns | 3.35x |
| `start false` | 382.274ns | 441.551ns | 446.321ns | 450.186ns | 508.268ns | 445.608ns | 8.153ns | 1.60x |
| `preallocate` | - | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - | - |

### Lua 5.3

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `literal` | 82.439ns | 309.629ns | 319.505ns | 326.341ns | 408.815ns | 317.657ns | 18.087ns | 1.00x |
| `start empty` | 732.469ns | 901.586ns | 905.422ns | 912.717ns | 1.158µs | 907.019ns | 13.117ns | 2.83x |
| `start false` | 324.057ns | 358.032ns | 363.816ns | 368.273ns | 1.659µs | 363.361ns | 43.205ns | 1.14x |
| `preallocate` | - | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - | - |

### Lua 5.4

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `literal` | 70.814ns | 240.317ns | 251.965ns | 265.843ns | 969.166ns | 252.328ns | 30.820ns | 1.01x |
| `start empty` | 709.981ns | 852.455ns | 859.215ns | 864.774ns | 1.022µs | 858.762ns | 13.910ns | 3.45x |
| `start false` | 233.318ns | 243.017ns | 249.137ns | 256.953ns | 349.820ns | 250.164ns | 8.857ns | 1.00x |
| `preallocate` | - | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - | - |

### LuaJIT

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `literal` | 0.968ns | 1.005ns | 1.007ns | 1.008ns | 1.046ns | 1.007ns | 0.004ns | 1.00x |
| `start empty` | 349.445ns | 363.403ns | 364.531ns | 365.704ns | 379.320ns | 364.642ns | 2.158ns | 362.04x |
| `start false` | 0.990ns | 1.005ns | 1.007ns | 1.008ns | 1.031ns | 1.007ns | 0.003ns | 1.00x |
| `preallocate` | 0.987ns | 1.005ns | 1.007ns | 1.008ns | 1.102ns | 1.007ns | 0.004ns | 1.00x |
| `ffi fill` | 0.986ns | 1.006ns | 1.007ns | 1.008ns | 1.055ns | 1.007ns | 0.003ns | 1.00x |
| `ffi individual` | 0.987ns | 1.006ns | 1.007ns | 1.008ns | 1.061ns | 1.007ns | 0.003ns | 1.00x |

### LuaJIT (Interpreter)

| Test | Min | Q25 | Median | Q75 | Max | Mean | Stddev | Cost |
|------|-----|-----|--------|-----|-----|------|--------|------|
| `literal` | 69.421ns | 75.768ns | 76.809ns | 77.972ns | 161.574ns | 77.233ns | 4.186ns | 1.00x |
| `start empty` | 457.079ns | 474.316ns | 474.940ns | 475.642ns | 503.384ns | 475.002ns | 2.177ns | 6.18x |
| `start false` | 86.147ns | 94.743ns | 95.487ns | 96.144ns | 104.513ns | 95.444ns | 1.421ns | 1.24x |
| `preallocate` | 159.977ns | 165.953ns | 167.212ns | 168.420ns | 197.462ns | 167.227ns | 1.953ns | 2.18x |
| `ffi fill` | 714.489ns | 853.579ns | 854.085ns | 854.686ns | 2.980µs | 862.023ns | 101.961ns | 11.12x |
| `ffi individual` | 1.145µs | 1.179µs | 1.181µs | 1.211µs | 1.261µs | 1.190µs | 16.485ns | 15.38x |

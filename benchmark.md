## arithmetic operations

#### One-Time Setup

```lua
local exp, log = math.exp, math.log
local a = -12345.0
local b = 522
```

| Test | Code |
| ----:| ---- |
| `negate` | `out = -a` |
| `add` | `out = a + b` |
| `sub` | `out = a - b` |
| `mul` | `out = a * b` |
| `div` | `out = a / b` |
| `mod` | `out = a % b` |
| `exp` | `out = a ^ b` |
| `math.exp` | `out = exp(b)` |
| `math.log` | `out = log(b)` |
| `bor` | `out = a \| b` |
| `band` | `out = a & b` |
| `bxor` | `out = a ~ b` |
| `bnot` | `out = ~a` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `negate` | 3.039ns | 6.054ns | 30.911ns | 6.082ns | 0.616ns | 1.00x | 55 (1.1%) |
| `add` | 2.051ns | 10.518ns | 15.796ns | 10.571ns | 0.822ns | 1.74x | 102 (2.0%) |
| `sub` | 6.747ns | 10.507ns | 17.527ns | 10.537ns | 0.656ns | 1.74x | 77 (1.5%) |
| `mul` | 6.210ns | 10.103ns | 16.119ns | 10.268ns | 0.891ns | 1.67x | 91 (1.8%) |
| `div` | 5.480ns | 10.221ns | 63.692ns | 10.417ns | 1.374ns | 1.69x | 20 (0.4%) |
| `mod` | 6.379ns | 10.937ns | 16.119ns | 10.955ns | 0.794ns | 1.81x | 67 (1.3%) |
| `exp` | 12.558ns | 22.667ns | 35.258ns | 22.983ns | 2.126ns | 3.74x | 94 (1.9%) |
| `math.exp` | 20.023ns | 30.671ns | 46.446ns | 31.108ns | 2.988ns | 5.07x | 89 (1.8%) |
| `math.log` | 5.920ns | 28.836ns | 80.538ns | 29.215ns | 2.585ns | 4.76x | 71 (1.4%) |
| `bor` | - | - | - | - | - | - | - |
| `band` | - | - | - | - | - | - | - |
| `bxor` | - | - | - | - | - | - | - |
| `bnot` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `negate` | 3.388ns | 7.863ns | 53.490ns | 7.961ns | 1.771ns | 1.00x | 12 (0.2%) |
| `add` | 2.507ns | 11.129ns | 19.741ns | 11.171ns | 1.401ns | 1.42x | 38 (0.8%) |
| `sub` | 1.675ns | 11.115ns | 19.979ns | 11.205ns | 1.425ns | 1.41x | 55 (1.1%) |
| `mul` | 0.955ns | 11.479ns | 19.214ns | 11.486ns | 1.494ns | 1.46x | 49 (1.0%) |
| `div` | 5.256ns | 11.157ns | 18.336ns | 11.213ns | 1.330ns | 1.42x | 44 (0.9%) |
| `mod` | 1.039ns | 13.187ns | 118.803ns | 13.263ns | 2.584ns | 1.68x | 9 (0.2%) |
| `exp` | 5.796ns | 22.598ns | 35.355ns | 22.703ns | 2.742ns | 2.87x | 47 (0.9%) |
| `math.exp` | 14.628ns | 30.343ns | 49.683ns | 30.522ns | 3.770ns | 3.86x | 51 (1.0%) |
| `math.log` | 2.217ns | 30.919ns | 49.667ns | 31.070ns | 3.932ns | 3.93x | 47 (0.9%) |
| `bor` | - | - | - | - | - | - | - |
| `band` | - | - | - | - | - | - | - |
| `bxor` | - | - | - | - | - | - | - |
| `bnot` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `negate` | 0.718ns | 6.576ns | 10.878ns | 6.695ns | 0.929ns | 1.00x | 40 (0.8%) |
| `add` | 5.900ns | 13.786ns | 24.706ns | 13.947ns | 1.610ns | 2.10x | 45 (0.9%) |
| `sub` | 3.305ns | 12.808ns | 77.097ns | 13.027ns | 2.256ns | 1.95x | 29 (0.6%) |
| `mul` | 2.526ns | 12.534ns | 22.163ns | 12.809ns | 1.895ns | 1.91x | 56 (1.1%) |
| `div` | 0.511ns | 15.113ns | 21.142ns | 14.813ns | 2.308ns | 2.30x | 19 (0.4%) |
| `mod` | 8.988ns | 17.278ns | 31.892ns | 17.390ns | 2.233ns | 2.63x | 53 (1.1%) |
| `exp` | 8.954ns | 29.389ns | 107.929ns | 29.104ns | 4.764ns | 4.47x | 11 (0.2%) |
| `math.exp` | 1.552ns | 32.678ns | 226.581ns | 33.353ns | 6.445ns | 4.97x | 16 (0.3%) |
| `math.log` | 3.789ns | 32.507ns | 57.504ns | 33.014ns | 4.914ns | 4.94x | 44 (0.9%) |
| `bor` | 1.210ns | 18.465ns | 106.634ns | 18.341ns | 4.806ns | 2.81x | 26 (0.5%) |
| `band` | \* | 17.847ns | 118.864ns | 17.821ns | 4.607ns | 2.71x | 25 (0.5%) |
| `bxor` | 4.671ns | 14.266ns | 27.906ns | 14.441ns | 1.991ns | 2.17x | 65 (1.3%) |
| `bnot` | 1.807ns | 13.933ns | 23.965ns | 14.137ns | 2.007ns | 2.12x | 51 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `negate` | 1.023ns | 5.806ns | 31.747ns | 5.862ns | 1.011ns | 1.00x | 13 (0.3%) |
| `add` | \* | 8.158ns | 13.488ns | 8.190ns | 1.178ns | 1.40x | 41 (0.8%) |
| `sub` | 1.654ns | 7.590ns | 37.551ns | 7.683ns | 1.132ns | 1.31x | 38 (0.8%) |
| `mul` | 2.697ns | 8.070ns | 14.410ns | 8.148ns | 1.041ns | 1.39x | 58 (1.2%) |
| `div` | 1.621ns | 7.993ns | 13.242ns | 8.070ns | 1.096ns | 1.38x | 43 (0.9%) |
| `mod` | \* | 13.640ns | 25.262ns | 13.751ns | 1.676ns | 2.35x | 45 (0.9%) |
| `exp` | 12.683ns | 21.181ns | 122.363ns | 21.387ns | 3.087ns | 3.65x | 34 (0.7%) |
| `math.exp` | 0.483ns | 28.407ns | 51.046ns | 28.622ns | 3.720ns | 4.89x | 64 (1.3%) |
| `math.log` | 16.503ns | 28.404ns | 71.194ns | 28.655ns | 3.576ns | 4.89x | 54 (1.1%) |
| `bor` | 3.090ns | 9.706ns | 17.245ns | 9.751ns | 1.176ns | 1.67x | 53 (1.1%) |
| `band` | 4.402ns | 10.196ns | 42.635ns | 10.267ns | 1.456ns | 1.76x | 33 (0.7%) |
| `bxor` | 2.267ns | 11.741ns | 99.596ns | 11.681ns | 2.398ns | 2.02x | 10 (0.2%) |
| `bnot` | 2.434ns | 8.073ns | 13.664ns | 8.125ns | 1.077ns | 1.39x | 57 (1.1%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `negate` | 2.199ns | 5.122ns | 8.422ns | 5.154ns | 0.631ns | 1.00x | 43 (0.9%) |
| `add` | 4.266ns | 7.124ns | 11.379ns | 7.199ns | 0.938ns | 1.39x | 48 (1.0%) |
| `sub` | 1.213ns | 7.047ns | 54.389ns | 7.148ns | 1.508ns | 1.38x | 9 (0.2%) |
| `mul` | 3.862ns | 7.696ns | 12.470ns | 7.715ns | 0.949ns | 1.50x | 44 (0.9%) |
| `div` | 1.852ns | 6.803ns | 11.719ns | 6.850ns | 0.848ns | 1.33x | 60 (1.2%) |
| `mod` | 7.515ns | 13.364ns | 22.211ns | 13.471ns | 1.627ns | 2.61x | 64 (1.3%) |
| `exp` | 8.529ns | 19.527ns | 35.418ns | 19.688ns | 2.482ns | 3.81x | 49 (1.0%) |
| `math.exp` | 13.462ns | 26.790ns | 142.057ns | 27.096ns | 3.923ns | 5.23x | 34 (0.7%) |
| `math.log` | 1.075ns | 27.607ns | 73.740ns | 28.065ns | 4.163ns | 5.39x | 44 (0.9%) |
| `bor` | 1.352ns | 9.415ns | 40.564ns | 9.695ns | 1.668ns | 1.84x | 15 (0.3%) |
| `band` | 6.205ns | 10.483ns | 20.110ns | 10.725ns | 1.817ns | 2.05x | 4 (0.1%) |
| `bxor` | 0.362ns | 10.134ns | 80.752ns | 10.355ns | 2.031ns | 1.98x | 10 (0.2%) |
| `bnot` | 3.650ns | 8.545ns | 25.938ns | 8.813ns | 1.454ns | 1.67x | 5 (0.1%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `negate` | \* | \* | 0.436ns | \* | 0.025ns | 1.02x | 78 (1.6%) |
| `add` | \* | \* | 0.475ns | \* | 0.029ns | 1.03x | 66 (1.3%) |
| `sub` | \* | \* | 0.426ns | \* | 0.028ns | 1.04x | 68 (1.4%) |
| `mul` | \* | \* | 0.432ns | \* | 0.023ns | 1.03x | 83 (1.7%) |
| `div` | \* | \* | 0.421ns | \* | 0.020ns | 1.03x | 85 (1.7%) |
| `mod` | \* | \* | 0.408ns | \* | 0.025ns | 1.00x | 113 (2.3%) |
| `exp` | \* | \* | 0.454ns | \* | 0.024ns | 1.03x | 84 (1.7%) |
| `math.exp` | \* | \* | 0.413ns | \* | 0.021ns | 1.03x | 103 (2.1%) |
| `math.log` | \* | \* | 0.422ns | \* | 0.022ns | 1.03x | 90 (1.8%) |
| `bor` | - | - | - | - | - | - | - |
| `band` | - | - | - | - | - | - | - |
| `bxor` | - | - | - | - | - | - | - |
| `bnot` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `negate` | 1.088ns | 3.776ns | 7.223ns | 3.804ns | 0.440ns | 1.00x | 43 (0.9%) |
| `add` | 3.223ns | 5.180ns | 67.123ns | 5.237ns | 1.124ns | 1.37x | 3 (0.1%) |
| `sub` | 0.491ns | 5.231ns | 7.907ns | 5.264ns | 0.613ns | 1.39x | 46 (0.9%) |
| `mul` | 0.392ns | 5.294ns | 8.192ns | 5.341ns | 0.623ns | 1.40x | 47 (0.9%) |
| `div` | 2.504ns | 5.131ns | 7.899ns | 5.160ns | 0.595ns | 1.36x | 55 (1.1%) |
| `mod` | 1.189ns | 7.345ns | 27.370ns | 7.386ns | 0.902ns | 1.94x | 34 (0.7%) |
| `exp` | 5.061ns | 19.384ns | 31.485ns | 19.473ns | 2.160ns | 5.13x | 47 (0.9%) |
| `math.exp` | 1.149ns | 14.202ns | 22.079ns | 14.298ns | 1.656ns | 3.76x | 47 (0.9%) |
| `math.log` | 4.079ns | 12.788ns | 19.824ns | 12.868ns | 1.415ns | 3.39x | 40 (0.8%) |
| `bor` | - | - | - | - | - | - | - |
| `band` | - | - | - | - | - | - | - |
| `bxor` | - | - | - | - | - | - | - |
| `bnot` | - | - | - | - | - | - | - |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `negate` |  **6.054ns**  |  **7.863ns**  |  **6.576ns**  |  **5.806ns**  |  **5.122ns**  |  **\***  |  **3.776ns**  |
| `add` |  10.518ns  |  11.129ns  |  13.786ns  |  8.158ns  |  7.124ns  |  **\***  |  5.180ns  |
| `sub` |  10.507ns  |  11.115ns  |  12.808ns  |  7.590ns  |  7.047ns  |  **\***  |  5.231ns  |
| `mul` |  10.103ns  |  11.479ns  |  12.534ns  |  8.070ns  |  7.696ns  |  **\***  |  5.294ns  |
| `div` |  10.221ns  |  11.157ns  |  15.113ns  |  7.993ns  |  6.803ns  |  **\***  |  5.131ns  |
| `mod` |  10.937ns  |  13.187ns  |  17.278ns  |  13.640ns  |  13.364ns  |  **\***  |  7.345ns  |
| `exp` |  22.667ns  |  22.598ns  |  29.389ns  |  21.181ns  |  19.527ns  |  **\***  |  19.384ns  |
| `math.exp` |  30.671ns  |  30.343ns  |  32.678ns  |  28.407ns  |  26.790ns  |  **\***  |  14.202ns  |
| `math.log` |  28.836ns  |  30.919ns  |  32.507ns  |  28.404ns  |  27.607ns  |  **\***  |  12.788ns  |
| `bor` |  -  |  -  |  18.465ns  |  9.706ns  |  9.415ns  |  -  |  -  |
| `band` |  -  |  -  |  17.847ns  |  10.196ns  |  10.483ns  |  -  |  -  |
| `bxor` |  -  |  -  |  14.266ns  |  11.741ns  |  10.134ns  |  -  |  -  |
| `bnot` |  -  |  -  |  13.933ns  |  8.073ns  |  8.545ns  |  -  |  -  |

## assert

#### One-Time Setup

```lua
local function good() return true end
local function bad() return false end
```

| Test | Code |
| ----:| ---- |
| `assert positive` | `pcall(function() assert(good(), "thing") end)` |
| `assert negative` | `pcall(function() assert(bad(), "thing") end)` |
| `short-circuit positive` | `pcall(function() local _ = good() or error("thing") end)` |
| `short-circuit negative` | `pcall(function() local _ = bad() or error("thing") end)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `assert positive` | 74.663ns | 152.083ns | 494.466ns | 154.135ns | 16.778ns | 1.16x | 58 (1.2%) |
| `assert negative` | 151.128ns | 788.398ns | 1.915µs | 793.028ns | 96.805ns | 5.99x | 54 (1.1%) |
| `short-circuit positive` | 83.141ns | 131.567ns | 212.797ns | 135.348ns | 16.397ns | 1.00x | 33 (0.7%) |
| `short-circuit negative` | 198.885ns | 903.383ns | 1.752µs | 892.079ns | 126.443ns | 6.87x | 18 (0.4%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `assert positive` | 5.153ns | 120.182ns | 202.586ns | 124.304ns | 19.662ns | 1.15x | 18 (0.4%) |
| `assert negative` | 30.809ns | 707.902ns | 1.252µs | 717.936ns | 100.218ns | 6.75x | 24 (0.5%) |
| `short-circuit positive` | 14.186ns | 104.881ns | 177.031ns | 108.013ns | 18.067ns | 1.00x | 11 (0.2%) |
| `short-circuit negative` | 371.073ns | 635.747ns | 1.609µs | 638.330ns | 77.401ns | 6.06x | 44 (0.9%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `assert positive` | 13.400ns | 96.995ns | 184.698ns | 97.756ns | 11.848ns | 1.22x | 60 (1.2%) |
| `assert negative` | 316.557ns | 503.020ns | 866.637ns | 508.414ns | 53.683ns | 6.32x | 59 (1.2%) |
| `short-circuit positive` | 22.154ns | 79.643ns | 441.748ns | 80.388ns | 11.349ns | 1.00x | 29 (0.6%) |
| `short-circuit negative` | 319.218ns | 482.244ns | 803.874ns | 487.106ns | 49.957ns | 6.06x | 54 (1.1%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `assert positive` | 54.482ns | 111.427ns | 364.267ns | 114.441ns | 13.630ns | 1.13x | 47 (0.9%) |
| `assert negative` | 120.866ns | 449.372ns | 703.756ns | 462.090ns | 57.105ns | 4.55x | 24 (0.5%) |
| `short-circuit positive` | 53.138ns | 98.786ns | 265.774ns | 101.617ns | 13.957ns | 1.00x | 22 (0.4%) |
| `short-circuit negative` | 73.805ns | 410.844ns | 1.817µs | 420.553ns | 52.903ns | 4.16x | 49 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `assert positive` | 75.845ns | 113.576ns | 174.183ns | 115.111ns | 10.238ns | 1.18x | 84 (1.7%) |
| `assert negative` | 152.359ns | 446.832ns | 841.896ns | 454.489ns | 47.203ns | 4.65x | 67 (1.3%) |
| `short-circuit positive` | 52.503ns | 96.175ns | 151.778ns | 97.561ns | 9.462ns | 1.00x | 69 (1.4%) |
| `short-circuit negative` | 262.015ns | 421.494ns | 671.903ns | 428.219ns | 42.289ns | 4.38x | 78 (1.6%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `assert positive` | 29.450ns | 49.263ns | 73.948ns | 50.375ns | 4.788ns | 1.21x | 44 (0.9%) |
| `assert negative` | 1.196µs | 1.760µs | 6.815µs | 1.772µs | 153.387ns | 43.35x | 50 (1.0%) |
| `short-circuit positive` | 24.669ns | 40.603ns | 65.044ns | 40.787ns | 3.034ns | 1.00x | 103 (2.1%) |
| `short-circuit negative` | 1.058µs | 1.576µs | 2.787µs | 1.586µs | 117.759ns | 38.81x | 106 (2.1%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `assert positive` | 28.994ns | 60.316ns | 136.249ns | 63.971ns | 19.809ns | 1.47x | 3 (0.1%) |
| `assert negative` | 266.962ns | 1.740µs | 5.693µs | 1.767µs | 223.334ns | 42.42x | 42 (0.8%) |
| `short-circuit positive` | 4.147ns | 41.010ns | 218.603ns | 42.267ns | 6.258ns | 1.00x | 4 (0.1%) |
| `short-circuit negative` | 626.083ns | 1.486µs | 2.369µs | 1.498µs | 173.685ns | 36.24x | 65 (1.3%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `assert positive` |  152.083ns  |  120.182ns  |  96.995ns  |  111.427ns  |  113.576ns  |  49.263ns  |  60.316ns  |
| `assert negative` |  788.398ns  |  707.902ns  |  503.020ns  |  449.372ns  |  446.832ns  |  1.760µs  |  1.740µs  |
| `short-circuit positive` |  **131.567ns**  |  **104.881ns**  |  **79.643ns**  |  **98.786ns**  |  **96.175ns**  |  **40.603ns**  |  **41.010ns**  |
| `short-circuit negative` |  903.383ns  |  635.747ns  |  482.244ns  |  410.844ns  |  421.494ns  |  1.576µs  |  1.486µs  |

## character iteration

#### One-Time Setup

```lua
local text = "Hello, this is an example text"
local char, sub, gsub, gmatch = string.char, string.sub, string.gsub, string.gmatch
local cstr = ffi and ffi.cast("const char*", text) or nil
```

| Test | Code |
| ----:| ---- |
| `sub` | `for i = 1, #text do out = text:sub(i, i) end` |
| `gmatch` | `for c in gmatch(text, ".") do out = c end` |
| `gsub` | `gsub(text, ".", function(c) out = c end)` |
| `ffi cstr` | `for i = 0, #text - 1 do out = char(cstr[i]) end` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `sub` | 1.178µs | 1.803µs | 2.876µs | 1.825µs | 157.083ns | 1.00x | 88 (1.8%) |
| `gmatch` | 1.125µs | 1.861µs | 7.905µs | 1.880µs | 173.060ns | 1.03x | 48 (1.0%) |
| `gsub` | 1.125µs | 2.328µs | 3.916µs | 2.337µs | 184.839ns | 1.29x | 72 (1.4%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `sub` | 135.574ns | 1.849µs | 3.387µs | 1.864µs | 244.489ns | 1.08x | 65 (1.3%) |
| `gmatch` | 345.882ns | 1.716µs | 3.211µs | 1.734µs | 228.221ns | 1.00x | 68 (1.4%) |
| `gsub` | 675.610ns | 2.087µs | 3.842µs | 2.098µs | 259.860ns | 1.22x | 47 (0.9%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `sub` | 358.885ns | 2.170µs | 3.385µs | 2.136µs | 329.329ns | 1.36x | 10 (0.2%) |
| `gmatch` | 26.237ns | 1.601µs | 5.252µs | 1.585µs | 209.035ns | 1.00x | 28 (0.6%) |
| `gsub` | 306.143ns | 2.379µs | 3.670µs | 2.383µs | 399.516ns | 1.49x | 7 (0.1%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `sub` | 679.375ns | 1.652µs | 4.696µs | 1.672µs | 227.375ns | 1.28x | 57 (1.1%) |
| `gmatch` | 464.254ns | 1.290µs | 2.842µs | 1.305µs | 166.336ns | 1.00x | 53 (1.1%) |
| `gsub` | 409.550ns | 1.494µs | 4.143µs | 1.502µs | 189.729ns | 1.16x | 60 (1.2%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `sub` | 801.563ns | 1.663µs | 2.481µs | 1.667µs | 130.262ns | 1.21x | 88 (1.8%) |
| `gmatch` | 843.574ns | 1.375µs | 2.450µs | 1.392µs | 111.927ns | 1.00x | 94 (1.9%) |
| `gsub` | 961.040ns | 1.566µs | 2.389µs | 1.569µs | 102.956ns | 1.14x | 80 (1.6%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `sub` | 182.210ns | 300.857ns | 498.880ns | 303.378ns | 22.903ns | 1.00x | 105 (2.1%) |
| `gmatch` | 927.521ns | 1.412µs | 5.026µs | 1.421µs | 122.403ns | 4.69x | 58 (1.2%) |
| `gsub` | 1.302µs | 2.126µs | 3.385µs | 2.147µs | 175.223ns | 7.07x | 91 (1.8%) |
| `ffi cstr` | 149.484ns | 327.752ns | 493.052ns | 332.618ns | 27.911ns | 1.09x | 102 (2.0%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `sub` | 656.694ns | 993.123ns | 1.720µs | 1.022µs | 112.663ns | 1.00x | 65 (1.3%) |
| `gmatch` | 265.831ns | 1.013µs | 1.667µs | 1.021µs | 118.524ns | 1.02x | 52 (1.0%) |
| `gsub` | 242.936ns | 1.897µs | 7.965µs | 1.908µs | 235.468ns | 1.91x | 26 (0.5%) |
| `ffi cstr` | 804.059ns | 1.602µs | 2.524µs | 1.616µs | 180.932ns | 1.61x | 45 (0.9%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `sub` |  **1.803µs**  |  **1.849µs**  |  2.170µs  |  1.652µs  |  1.663µs  |  **300.857ns**  |  **993.123ns**  |
| `gmatch` |  **1.861µs**  |  **1.716µs**  |  **1.601µs**  |  **1.290µs**  |  **1.375µs**  |  1.412µs  |  **1.013µs**  |
| `gsub` |  2.328µs  |  2.087µs  |  2.379µs  |  1.494µs  |  1.566µs  |  2.126µs  |  1.897µs  |
| `ffi cstr` |  -  |  -  |  -  |  -  |  -  |  **327.752ns**  |  1.602µs  |

## closure creation

#### One-Time Setup

```lua
local function f1(a, b, fn) return fn(a + b) end
local function f2(a) return a * 2 end
```

| Test | Code |
| ----:| ---- |
| `saved fn` | `out = f1(1, 2, f2)` |
| `new closure` | `out = f1(1, 2, function(a) return a * 2 end)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `saved fn` | 31.191ns | 47.071ns | 75.068ns | 47.682ns | 4.360ns | 1.00x | 107 (2.1%) |
| `new closure` | 41.687ns | 71.521ns | 327.585ns | 73.278ns | 9.935ns | 1.52x | 27 (0.5%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `saved fn` | 1.797ns | 61.108ns | 310.282ns | 61.394ns | 8.903ns | 1.01x | 39 (0.8%) |
| `new closure` | 30.097ns | 60.630ns | 102.606ns | 61.111ns | 7.848ns | 1.00x | 65 (1.3%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `saved fn` | 15.161ns | 41.758ns | 75.165ns | 42.012ns | 5.334ns | 1.00x | 54 (1.1%) |
| `new closure` | 17.731ns | 43.313ns | 71.636ns | 43.784ns | 5.657ns | 1.04x | 58 (1.2%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `saved fn` | 2.627ns | 33.571ns | 63.663ns | 34.025ns | 4.899ns | 1.00x | 69 (1.4%) |
| `new closure` | 35.395ns | 58.739ns | 94.366ns | 60.065ns | 6.969ns | 1.75x | 58 (1.2%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `saved fn` | 26.501ns | 35.315ns | 55.787ns | 35.760ns | 3.461ns | 1.00x | 71 (1.4%) |
| `new closure` | 33.360ns | 56.337ns | 93.455ns | 57.034ns | 4.374ns | 1.60x | 84 (1.7%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `saved fn` | \* | \* | 0.440ns | \* | 0.025ns | 1.00x | 73 (1.5%) |
| `new closure` | 20.040ns | 30.842ns | 47.701ns | 31.656ns | 3.515ns | 113.74x | 22 (0.4%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `saved fn` | \* | 19.922ns | 31.073ns | 20.262ns | 2.917ns | 1.00x | 32 (0.6%) |
| `new closure` | 17.459ns | 36.421ns | 333.261ns | 36.221ns | 6.598ns | 1.83x | 2 (0.0%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `saved fn` |  **47.071ns**  |  **61.108ns**  |  **41.758ns**  |  **33.571ns**  |  **35.315ns**  |  **\***  |  **19.922ns**  |
| `new closure` |  71.521ns  |  **60.630ns**  |  **43.313ns**  |  58.739ns  |  56.337ns  |  30.842ns  |  36.421ns  |

## cube

#### One-Time Setup

```lua
local x, pow = 10, math.pow
```

| Test | Code |
| ----:| ---- |
| `math.pow (global)` | `out = math.pow(x, 2)` |
| `math.pow (local)` | `out = pow(x, 2)` |
| `multiply` | `out = x * x` |
| `exponent` | `out = x ^ 2` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 41.627ns | 61.433ns | 93.313ns | 62.654ns | 6.032ns | 5.95x | 50 (1.0%) |
| `math.pow (local)` | 31.248ns | 47.639ns | 274.826ns | 48.760ns | 6.183ns | 4.62x | 27 (0.5%) |
| `multiply` | 5.919ns | 10.321ns | 17.383ns | 10.582ns | 1.217ns | 1.00x | 26 (0.5%) |
| `exponent` | 10.058ns | 23.507ns | 33.727ns | 23.630ns | 1.819ns | 2.28x | 97 (1.9%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 13.770ns | 61.851ns | 111.920ns | 62.177ns | 7.516ns | 5.42x | 44 (0.9%) |
| `math.pow (local)` | 11.437ns | 46.835ns | 78.071ns | 47.046ns | 5.955ns | 4.11x | 46 (0.9%) |
| `multiply` | 4.299ns | 11.406ns | 57.763ns | 11.475ns | 1.596ns | 1.00x | 35 (0.7%) |
| `exponent` | 3.559ns | 24.326ns | 45.431ns | 24.590ns | 3.150ns | 2.13x | 66 (1.3%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 9.178ns | 60.755ns | 107.403ns | 61.825ns | 7.925ns | 6.58x | 61 (1.2%) |
| `math.pow (local)` | 0.516ns | 53.882ns | 121.260ns | 55.192ns | 9.588ns | 5.84x | 14 (0.3%) |
| `multiply` | 1.221ns | 9.232ns | 61.921ns | 9.482ns | 2.236ns | 1.00x | 9 (0.2%) |
| `exponent` | 7.418ns | 34.506ns | 157.430ns | 34.108ns | 5.187ns | 3.74x | 23 (0.5%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 1.606ns | 52.431ns | 336.984ns | 52.907ns | 9.177ns | 7.43x | 11 (0.2%) |
| `math.pow (local)` | 5.695ns | 45.559ns | 78.205ns | 45.863ns | 5.898ns | 6.46x | 58 (1.2%) |
| `multiply` | \* | 8.009ns | 15.942ns | 8.076ns | 1.039ns | 1.14x | 50 (1.0%) |
| `exponent` | 3.432ns | 7.052ns | 71.693ns | 7.134ns | 1.339ns | 1.00x | 9 (0.2%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | - | - | - | - | - | - | - |
| `math.pow (local)` | - | - | - | - | - | - | - |
| `multiply` | 0.964ns | 6.884ns | 49.642ns | 6.967ns | 1.214ns | 1.03x | 25 (0.5%) |
| `exponent` | 3.517ns | 6.669ns | 15.511ns | 6.840ns | 1.026ns | 1.00x | 24 (0.5%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 1.464ns | 2.438ns | 3.720ns | 2.458ns | 0.218ns | 9.03x | 76 (1.5%) |
| `math.pow (local)` | \* | \* | 0.626ns | \* | 0.027ns | 1.00x | 67 (1.3%) |
| `multiply` | \* | \* | 0.450ns | \* | 0.026ns | 1.02x | 50 (1.0%) |
| `exponent` | \* | \* | 0.425ns | \* | 0.021ns | 1.01x | 68 (1.4%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 5.976ns | 28.365ns | 49.469ns | 28.459ns | 3.476ns | 5.44x | 40 (0.8%) |
| `math.pow (local)` | 8.632ns | 25.308ns | 41.097ns | 25.397ns | 2.784ns | 4.85x | 53 (1.1%) |
| `multiply` | 2.925ns | 5.218ns | 8.357ns | 5.255ns | 0.593ns | 1.00x | 44 (0.9%) |
| `exponent` | 10.636ns | 20.592ns | 36.892ns | 20.755ns | 2.242ns | 3.95x | 48 (1.0%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `math.pow (global)` |  61.433ns  |  61.851ns  |  60.755ns  |  52.431ns  |  -  |  2.438ns  |  28.365ns  |
| `math.pow (local)` |  47.639ns  |  46.835ns  |  53.882ns  |  45.559ns  |  -  |  **\***  |  25.308ns  |
| `multiply` |  **10.321ns**  |  **11.406ns**  |  **9.232ns**  |  8.009ns  |  **6.884ns**  |  **\***  |  **5.218ns**  |
| `exponent` |  23.507ns  |  24.326ns  |  34.506ns  |  **7.052ns**  |  **6.669ns**  |  **\***  |  20.592ns  |

## default

#### One-Time Setup

```lua
local x = false
```

| Test | Code |
| ----:| ---- |
| `if-else` | `if not x then out = 1 else out = x end` |
| `or` | `out = x or 1` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `if-else` | 5.201ns | 10.232ns | 16.110ns | 10.285ns | 0.836ns | 1.15x | 92 (1.8%) |
| `or` | 4.379ns | 8.936ns | 26.847ns | 9.218ns | 1.098ns | 1.00x | 42 (0.8%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `if-else` | 0.544ns | 12.490ns | 57.621ns | 12.561ns | 1.711ns | 1.21x | 34 (0.7%) |
| `or` | 2.268ns | 10.361ns | 19.485ns | 10.418ns | 1.324ns | 1.00x | 55 (1.1%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `if-else` | 1.272ns | 10.282ns | 41.657ns | 10.518ns | 1.728ns | 1.01x | 23 (0.5%) |
| `or` | 0.378ns | 10.215ns | 63.275ns | 10.135ns | 1.648ns | 1.00x | 27 (0.5%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `if-else` | 0.449ns | 7.216ns | 40.489ns | 7.255ns | 1.057ns | 1.00x | 39 (0.8%) |
| `or` | 0.478ns | 7.241ns | 72.156ns | 7.460ns | 1.657ns | 1.00x | 5 (0.1%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `if-else` | 0.488ns | 8.276ns | 15.310ns | 8.357ns | 1.387ns | 1.20x | 21 (0.4%) |
| `or` | 2.158ns | 6.896ns | 12.411ns | 6.935ns | 0.887ns | 1.00x | 53 (1.1%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `if-else` | \* | \* | 0.405ns | \* | 0.025ns | 1.00x | 85 (1.7%) |
| `or` | \* | \* | 0.424ns | \* | 0.033ns | 1.02x | 20 (0.4%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `if-else` | 2.592ns | 6.663ns | 11.788ns | 6.691ns | 0.788ns | 1.51x | 31 (0.6%) |
| `or` | 0.715ns | 4.426ns | 6.998ns | 4.458ns | 0.524ns | 1.00x | 44 (0.9%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `if-else` |  10.232ns  |  12.490ns  |  **10.282ns**  |  **7.216ns**  |  8.276ns  |  **\***  |  6.663ns  |
| `or` |  **8.936ns**  |  **10.361ns**  |  **10.215ns**  |  **7.241ns**  |  **6.896ns**  |  **\***  |  **4.426ns**  |

## empty string

#### One-Time Setup

```lua
local str = ""
local cstr = ffi and ffi.cast("const char*", str) or nil
```

| Test | Code |
| ----:| ---- |
| `length` | `out = #str == 0` |
| `value` | `out = str == ""` |
| `ffi cstr` | `out = cstr[0] == 0` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `length` | 7.146ns | 14.779ns | 25.311ns | 14.931ns | 1.402ns | 1.24x | 93 (1.9%) |
| `value` | 4.365ns | 11.881ns | 17.637ns | 11.936ns | 0.966ns | 1.00x | 97 (1.9%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `length` | 0.372ns | 17.854ns | 31.022ns | 17.955ns | 2.275ns | 1.28x | 57 (1.1%) |
| `value` | 4.872ns | 13.938ns | 88.136ns | 14.122ns | 1.960ns | 1.00x | 27 (0.5%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `length` | 0.826ns | 17.395ns | 88.690ns | 17.472ns | 2.467ns | 1.22x | 20 (0.4%) |
| `value` | 4.259ns | 14.242ns | 26.715ns | 14.361ns | 1.787ns | 1.00x | 52 (1.0%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `length` | \* | 10.304ns | 37.451ns | 10.416ns | 1.432ns | 1.23x | 50 (1.0%) |
| `value` | 2.529ns | 8.374ns | 14.171ns | 8.439ns | 1.075ns | 1.00x | 56 (1.1%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `length` | 6.439ns | 11.415ns | 20.341ns | 11.552ns | 1.028ns | 1.24x | 121 (2.4%) |
| `value` | 5.919ns | 9.210ns | 15.855ns | 9.299ns | 0.862ns | 1.00x | 82 (1.6%) |
| `ffi cstr` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `length` | \* | \* | 0.402ns | \* | 0.023ns | 1.00x | 98 (2.0%) |
| `value` | \* | \* | 0.405ns | \* | 0.024ns | 1.01x | 95 (1.9%) |
| `ffi cstr` | \* | \* | 0.417ns | \* | 0.025ns | 1.01x | 89 (1.8%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `length` | 1.217ns | 8.192ns | 13.633ns | 8.277ns | 1.026ns | 1.30x | 45 (0.9%) |
| `value` | 1.307ns | 6.289ns | 65.748ns | 6.382ns | 1.180ns | 1.00x | 5 (0.1%) |
| `ffi cstr` | 9.584ns | 40.347ns | 167.253ns | 41.402ns | 6.530ns | 6.42x | 12 (0.2%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `length` |  14.779ns  |  17.854ns  |  17.395ns  |  10.304ns  |  11.415ns  |  **\***  |  8.192ns  |
| `value` |  **11.881ns**  |  **13.938ns**  |  **14.242ns**  |  **8.374ns**  |  **9.210ns**  |  **\***  |  **6.289ns**  |
| `ffi cstr` |  -  |  -  |  -  |  -  |  -  |  **\***  |  40.347ns  |

## fmod

#### One-Time Setup

```lua
local fmod1, floor = math.fmod, math.floor
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
	return a - floor(a / b) * b
end
local fmod5
if _VERSION:match("%d.%d") >= "5.3" then
	fmod5 = load("return function(a, b) return a - a // b * b end")()
end
```

| Test | Code |
| ----:| ---- |
| `fmod (global)` | `out = math.fmod(__i, 10)` |
| `fmod (local)` | `out = fmod1(__i, 10)` |
| `branchy` | `out = fmod2(__i, 10)` |
| `branchless` | `out = fmod3(__i, 10)` |
| `definition (math.floor)` | `out = fmod4(__i, 10)` |
| `definition (floor division)` | `out = fmod5(__i, 10)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `fmod (global)` | 18.252ns | 47.982ns | 77.888ns | 48.557ns | 4.324ns | 1.39x | 84 (1.7%) |
| `fmod (local)` | 23.503ns | 34.598ns | 59.792ns | 35.127ns | 3.482ns | 1.00x | 41 (0.8%) |
| `branchy` | 30.505ns | 47.724ns | 71.619ns | 48.408ns | 4.398ns | 1.38x | 88 (1.8%) |
| `branchless` | 17.785ns | 57.776ns | 385.966ns | 58.915ns | 8.924ns | 1.67x | 8 (0.2%) |
| `definition (math.floor)` | 37.017ns | 56.289ns | 177.762ns | 56.773ns | 4.614ns | 1.63x | 54 (1.1%) |
| `definition (floor division)` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `fmod (global)` | 9.188ns | 51.576ns | 88.377ns | 51.906ns | 6.514ns | 1.50x | 47 (0.9%) |
| `fmod (local)` | 21.521ns | 34.475ns | 185.269ns | 34.675ns | 5.097ns | 1.00x | 27 (0.5%) |
| `branchy` | 28.276ns | 58.773ns | 98.123ns | 59.479ns | 7.109ns | 1.70x | 64 (1.3%) |
| `branchless` | 12.951ns | 69.236ns | 120.773ns | 70.064ns | 8.310ns | 2.01x | 54 (1.1%) |
| `definition (math.floor)` | 12.454ns | 65.934ns | 112.592ns | 66.250ns | 8.259ns | 1.91x | 48 (1.0%) |
| `definition (floor division)` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `fmod (global)` | 16.623ns | 46.573ns | 82.496ns | 46.822ns | 6.049ns | 1.36x | 58 (1.2%) |
| `fmod (local)` | 7.606ns | 34.272ns | 215.412ns | 34.660ns | 5.204ns | 1.00x | 29 (0.6%) |
| `branchy` | 17.805ns | 50.445ns | 98.651ns | 50.738ns | 6.113ns | 1.47x | 54 (1.1%) |
| `branchless` | 1.031ns | 60.234ns | 97.260ns | 60.617ns | 7.431ns | 1.76x | 59 (1.2%) |
| `definition (math.floor)` | 3.773ns | 56.211ns | 107.854ns | 56.715ns | 7.652ns | 1.64x | 63 (1.3%) |
| `definition (floor division)` | 11.249ns | 38.438ns | 145.910ns | 39.245ns | 6.193ns | 1.12x | 33 (0.7%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `fmod (global)` | 14.362ns | 36.679ns | 64.832ns | 36.968ns | 4.731ns | 1.18x | 45 (0.9%) |
| `fmod (local)` | 13.101ns | 31.968ns | 56.477ns | 32.074ns | 4.243ns | 1.03x | 50 (1.0%) |
| `branchy` | 2.191ns | 35.878ns | 62.464ns | 36.093ns | 4.480ns | 1.15x | 50 (1.0%) |
| `branchless` | 26.156ns | 44.098ns | 73.399ns | 44.315ns | 5.385ns | 1.41x | 59 (1.2%) |
| `definition (math.floor)` | 25.486ns | 42.082ns | 130.504ns | 42.398ns | 5.475ns | 1.35x | 40 (0.8%) |
| `definition (floor division)` | 14.959ns | 31.188ns | 53.709ns | 31.393ns | 3.996ns | 1.00x | 44 (0.9%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `fmod (global)` | 24.992ns | 40.776ns | 69.013ns | 41.542ns | 5.090ns | 1.27x | 39 (0.8%) |
| `fmod (local)` | 19.372ns | 32.103ns | 190.079ns | 32.285ns | 3.673ns | 1.00x | 16 (0.3%) |
| `branchy` | 22.196ns | 40.618ns | 103.190ns | 40.953ns | 3.816ns | 1.27x | 75 (1.5%) |
| `branchless` | 27.822ns | 47.203ns | 78.286ns | 47.485ns | 4.295ns | 1.47x | 83 (1.7%) |
| `definition (math.floor)` | 28.112ns | 44.312ns | 66.794ns | 44.673ns | 3.711ns | 1.38x | 110 (2.2%) |
| `definition (floor division)` | 5.723ns | 32.977ns | 171.132ns | 33.144ns | 3.265ns | 1.03x | 22 (0.4%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `fmod (global)` | 20.938ns | 28.658ns | 45.566ns | 29.252ns | 2.757ns | 23.69x | 57 (1.1%) |
| `fmod (local)` | 16.082ns | 27.464ns | 41.075ns | 27.797ns | 2.220ns | 22.70x | 99 (2.0%) |
| `branchy` | 1.636ns | 2.938ns | 4.700ns | 2.989ns | 0.268ns | 2.43x | 103 (2.1%) |
| `branchless` | 1.778ns | 2.975ns | 4.531ns | 3.029ns | 0.265ns | 2.46x | 90 (1.8%) |
| `definition (math.floor)` | 0.814ns | 1.210ns | 1.887ns | 1.226ns | 0.102ns | 1.00x | 89 (1.8%) |
| `definition (floor division)` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `fmod (global)` | 5.713ns | 25.519ns | 39.530ns | 25.767ns | 2.703ns | 1.14x | 58 (1.2%) |
| `fmod (local)` | 4.595ns | 22.483ns | 37.499ns | 22.759ns | 2.849ns | 1.00x | 46 (0.9%) |
| `branchy` | 3.450ns | 25.194ns | 244.338ns | 25.558ns | 4.796ns | 1.12x | 8 (0.2%) |
| `branchless` | 7.918ns | 32.200ns | 49.795ns | 32.919ns | 4.959ns | 1.43x | 25 (0.5%) |
| `definition (math.floor)` | 6.667ns | 25.985ns | 348.969ns | 26.650ns | 6.222ns | 1.16x | 4 (0.1%) |
| `definition (floor division)` | - | - | - | - | - | - | - |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `fmod (global)` |  47.982ns  |  51.576ns  |  46.573ns  |  36.679ns  |  40.776ns  |  28.658ns  |  25.519ns  |
| `fmod (local)` |  **34.598ns**  |  **34.475ns**  |  **34.272ns**  |  **31.968ns**  |  **32.103ns**  |  27.464ns  |  **22.483ns**  |
| `branchy` |  47.724ns  |  58.773ns  |  50.445ns  |  35.878ns  |  40.618ns  |  2.938ns  |  25.194ns  |
| `branchless` |  57.776ns  |  69.236ns  |  60.234ns  |  44.098ns  |  47.203ns  |  2.975ns  |  32.200ns  |
| `definition (math.floor)` |  56.289ns  |  65.934ns  |  56.211ns  |  42.082ns  |  44.312ns  |  **1.210ns**  |  25.985ns  |
| `definition (floor division)` |  -  |  -  |  38.438ns  |  **31.188ns**  |  **32.977ns**  |  -  |  -  |

## ipairs iteration

#### One-Time Setup

```lua
local nxt, lipairs, lpairs = next, ipairs, pairs
local len = 100
local a = { n = len, [0] = len }
for i = 1, len do
	a[i] = i
end
```

| Test | Code |
| ----:| ---- |
| `ipairs (global)` | `for k, v in ipairs(a) do out = v end` |
| `ipairs (local)` | `for k, v in lipairs(a) do out = v end` |
| `pairs (global)` | `for k, v in pairs(a) do out = v end` |
| `pairs (local)` | `for k, v in lpairs(a) do out = v end` |
| `next (global)` | `for k, v in next, a do out = v end` |
| `next (local)` | `for k, v in nxt, a do out = v end` |
| `local len` | `for i = 1, len do out = a[i] end` |
| `table.n` | `for i = 1, a.n do out = a[i] end` |
| `table[0]` | `for i = 1, a[0] do out = a[i] end` |
| `#table` | `for i = 1, #a do out = a[i] end` |
| `constant` | `for i = 1, 100 do out = a[i] end` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `ipairs (global)` | 36.448ns | 2.950µs | 6.040µs | 2.973µs | 382.579ns | 2.49x | 53 (1.1%) |
| `ipairs (local)` | 400.977ns | 2.972µs | 26.180µs | 2.997µs | 535.262ns | 2.51x | 10 (0.2%) |
| `pairs (global)` | 1.220µs | 2.819µs | 5.455µs | 2.841µs | 327.156ns | 2.38x | 58 (1.2%) |
| `pairs (local)` | 921.494ns | 2.841µs | 17.374µs | 2.864µs | 416.777ns | 2.40x | 26 (0.5%) |
| `next (global)` | 87.200ns | 2.809µs | 5.049µs | 2.824µs | 330.974ns | 2.37x | 47 (0.9%) |
| `next (local)` | 1.428µs | 2.805µs | 5.179µs | 2.823µs | 341.570ns | 2.37x | 62 (1.2%) |
| `local len` | 388.779ns | 1.185µs | 1.981µs | 1.191µs | 147.033ns | 1.00x | 44 (0.9%) |
| `table.n` | 620.852ns | 1.215µs | 6.914µs | 1.227µs | 193.622ns | 1.03x | 26 (0.5%) |
| `table[0]` | 76.565ns | 1.188µs | 2.170µs | 1.199µs | 156.248ns | 1.00x | 44 (0.9%) |
| `#table` | 770.364ns | 1.209µs | 2.046µs | 1.248µs | 162.479ns | 1.02x | 40 (0.8%) |
| `constant` | 609.047ns | 1.278µs | 2.509µs | 1.287µs | 103.686ns | 1.08x | 76 (1.5%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `ipairs (global)` | 53.335ns | 3.313µs | 5.953µs | 3.331µs | 411.285ns | 2.53x | 37 (0.7%) |
| `ipairs (local)` | 1.332µs | 3.321µs | 5.386µs | 3.348µs | 429.684ns | 2.54x | 48 (1.0%) |
| `pairs (global)` | 24.443ns | 2.962µs | 4.959µs | 2.982µs | 372.367ns | 2.27x | 43 (0.9%) |
| `pairs (local)` | 388.767ns | 2.973µs | 15.479µs | 2.998µs | 445.583ns | 2.27x | 18 (0.4%) |
| `next (global)` | 586.977ns | 2.965µs | 4.920µs | 2.981µs | 376.569ns | 2.27x | 48 (1.0%) |
| `next (local)` | 387.952ns | 2.977µs | 5.032µs | 2.994µs | 365.043ns | 2.28x | 57 (1.1%) |
| `local len` | 76.180ns | 1.307µs | 2.322µs | 1.317µs | 169.732ns | 1.00x | 56 (1.1%) |
| `table.n` | 37.138ns | 1.312µs | 4.876µs | 1.317µs | 168.069ns | 1.00x | 43 (0.9%) |
| `table[0]` | 102.919ns | 1.389µs | 2.332µs | 1.405µs | 170.935ns | 1.06x | 44 (0.9%) |
| `#table` | 246.675ns | 1.332µs | 2.709µs | 1.340µs | 171.907ns | 1.02x | 41 (0.8%) |
| `constant` | 195.552ns | 1.326µs | 2.548µs | 1.329µs | 174.598ns | 1.01x | 41 (0.8%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `ipairs (global)` | 149.569ns | 2.699µs | 5.763µs | 2.739µs | 418.054ns | 3.09x | 40 (0.8%) |
| `ipairs (local)` | 691.582ns | 2.594µs | 10.990µs | 2.634µs | 379.765ns | 2.97x | 37 (0.7%) |
| `pairs (global)` | 481.529ns | 2.627µs | 4.677µs | 2.672µs | 408.219ns | 3.01x | 49 (1.0%) |
| `pairs (local)` | 305.189ns | 2.588µs | 4.592µs | 2.629µs | 384.046ns | 2.96x | 62 (1.2%) |
| `next (global)` | 301.120ns | 2.635µs | 4.493µs | 2.665µs | 414.239ns | 3.02x | 34 (0.7%) |
| `next (local)` | 405.598ns | 2.642µs | 19.038µs | 2.685µs | 474.498ns | 3.03x | 13 (0.3%) |
| `local len` | 92.969ns | 876.034ns | 1.524µs | 895.682ns | 138.624ns | 1.00x | 48 (1.0%) |
| `table.n` | 186.986ns | 873.512ns | 1.889µs | 885.850ns | 126.706ns | 1.00x | 52 (1.0%) |
| `table[0]` | 134.822ns | 889.507ns | 1.814µs | 901.796ns | 129.386ns | 1.02x | 56 (1.1%) |
| `#table` | 163.652ns | 891.744ns | 4.399µs | 913.162ns | 156.482ns | 1.02x | 21 (0.4%) |
| `constant` | 120.632ns | 950.615ns | 1.472µs | 960.796ns | 152.430ns | 1.09x | 12 (0.2%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `ipairs (global)` | 288.731ns | 2.424µs | 16.708µs | 2.458µs | 390.873ns | 3.43x | 29 (0.6%) |
| `ipairs (local)` | 290.915ns | 2.406µs | 4.299µs | 2.430µs | 317.023ns | 3.41x | 47 (0.9%) |
| `pairs (global)` | 647.540ns | 2.626µs | 6.053µs | 2.648µs | 325.963ns | 3.72x | 48 (1.0%) |
| `pairs (local)` | 1.208µs | 2.607µs | 4.875µs | 2.632µs | 318.400ns | 3.69x | 66 (1.3%) |
| `next (global)` | 270.780ns | 2.577µs | 11.120µs | 2.603µs | 348.788ns | 3.65x | 41 (0.8%) |
| `next (local)` | 421.235ns | 2.572µs | 4.550µs | 2.593µs | 335.311ns | 3.64x | 57 (1.1%) |
| `local len` | 179.102ns | 705.754ns | 1.229µs | 713.041ns | 92.128ns | 1.00x | 51 (1.0%) |
| `table.n` | 222.434ns | 716.336ns | 1.253µs | 721.258ns | 88.299ns | 1.01x | 51 (1.0%) |
| `table[0]` | 271.192ns | 714.373ns | 2.656µs | 721.663ns | 104.357ns | 1.01x | 31 (0.6%) |
| `#table` | 388.891ns | 717.988ns | 5.096µs | 730.719ns | 129.786ns | 1.02x | 13 (0.3%) |
| `constant` | 331.084ns | 713.529ns | 3.883µs | 722.518ns | 114.091ns | 1.01x | 22 (0.4%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `ipairs (global)` | 212.318ns | 2.436µs | 4.115µs | 2.453µs | 327.256ns | 4.00x | 58 (1.2%) |
| `ipairs (local)` | 492.407ns | 2.427µs | 12.152µs | 2.442µs | 334.451ns | 3.99x | 31 (0.6%) |
| `pairs (global)` | 853.071ns | 2.495µs | 4.243µs | 2.512µs | 316.965ns | 4.10x | 58 (1.2%) |
| `pairs (local)` | 484.242ns | 2.458µs | 4.273µs | 2.489µs | 321.464ns | 4.04x | 57 (1.1%) |
| `next (global)` | 674.302ns | 2.478µs | 6.836µs | 2.496µs | 317.742ns | 4.07x | 55 (1.1%) |
| `next (local)` | 135.578ns | 2.465µs | 14.112µs | 2.487µs | 373.485ns | 4.05x | 31 (0.6%) |
| `local len` | 101.962ns | 611.150ns | 1.235µs | 615.093ns | 79.609ns | 1.00x | 62 (1.2%) |
| `table.n` | 101.188ns | 612.968ns | 1.010µs | 617.620ns | 74.607ns | 1.01x | 51 (1.0%) |
| `table[0]` | 45.550ns | 623.184ns | 1.571µs | 630.871ns | 88.027ns | 1.02x | 60 (1.2%) |
| `#table` | 223.926ns | 616.796ns | 4.304µs | 620.172ns | 106.454ns | 1.01x | 15 (0.3%) |
| `constant` | 116.395ns | 608.854ns | 1.187µs | 611.965ns | 78.439ns | 1.00x | 37 (0.7%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `ipairs (global)` | 32.885ns | 123.520ns | 227.573ns | 124.357ns | 9.586ns | 1.94x | 73 (1.5%) |
| `ipairs (local)` | 81.043ns | 123.231ns | 185.269ns | 125.172ns | 11.229ns | 1.93x | 84 (1.7%) |
| `pairs (global)` | 114.238ns | 295.249ns | 781.068ns | 299.514ns | 32.136ns | 4.63x | 28 (0.6%) |
| `pairs (local)` | 548.267ns | 851.795ns | 1.372µs | 869.016ns | 88.266ns | 13.37x | 55 (1.1%) |
| `next (global)` | 192.052ns | 288.011ns | 984.610ns | 292.027ns | 33.498ns | 4.52x | 37 (0.7%) |
| `next (local)` | 546.730ns | 837.096ns | 1.326µs | 848.715ns | 72.686ns | 13.14x | 83 (1.7%) |
| `local len` | 46.760ns | 69.441ns | 117.018ns | 70.361ns | 6.242ns | 1.09x | 78 (1.6%) |
| `table.n` | 47.214ns | 69.075ns | 116.051ns | 70.490ns | 6.681ns | 1.08x | 82 (1.6%) |
| `table[0]` | 44.416ns | 67.539ns | 107.518ns | 67.941ns | 4.612ns | 1.06x | 114 (2.3%) |
| `#table` | 40.080ns | 74.852ns | 136.698ns | 75.329ns | 5.592ns | 1.17x | 102 (2.0%) |
| `constant` | 41.390ns | 63.728ns | 102.794ns | 64.169ns | 4.881ns | 1.00x | 87 (1.7%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `ipairs (global)` | 577.739ns | 1.044µs | 1.630µs | 1.051µs | 115.154ns | 2.81x | 46 (0.9%) |
| `ipairs (local)` | 648.884ns | 1.028µs | 4.231µs | 1.037µs | 125.095ns | 2.77x | 28 (0.6%) |
| `pairs (global)` | 129.641ns | 371.855ns | 765.997ns | 373.010ns | 41.106ns | 1.00x | 40 (0.8%) |
| `pairs (local)` | 299.712ns | 1.260µs | 2.349µs | 1.266µs | 137.765ns | 3.39x | 51 (1.0%) |
| `next (global)` | 105.415ns | 378.569ns | 663.014ns | 380.800ns | 43.223ns | 1.02x | 48 (1.0%) |
| `next (local)` | 283.362ns | 1.274µs | 2.001µs | 1.282µs | 140.356ns | 3.43x | 42 (0.8%) |
| `local len` | 126.261ns | 543.769ns | 870.802ns | 546.357ns | 63.395ns | 1.46x | 38 (0.8%) |
| `table.n` | 119.034ns | 539.712ns | 1.226µs | 541.089ns | 61.480ns | 1.45x | 54 (1.1%) |
| `table[0]` | 197.567ns | 543.882ns | 2.455µs | 548.090ns | 70.388ns | 1.46x | 21 (0.4%) |
| `#table` | 36.486ns | 537.234ns | 867.745ns | 540.368ns | 60.713ns | 1.44x | 50 (1.0%) |
| `constant` | 171.613ns | 542.202ns | 811.289ns | 545.789ns | 61.681ns | 1.46x | 39 (0.8%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `ipairs (global)` |  2.950µs  |  3.313µs  |  2.699µs  |  2.424µs  |  2.436µs  |  123.520ns  |  1.044µs  |
| `ipairs (local)` |  2.972µs  |  3.321µs  |  2.594µs  |  2.406µs  |  2.427µs  |  123.231ns  |  1.028µs  |
| `pairs (global)` |  2.819µs  |  2.962µs  |  2.627µs  |  2.626µs  |  2.495µs  |  295.249ns  |  **371.855ns**  |
| `pairs (local)` |  2.841µs  |  2.973µs  |  2.588µs  |  2.607µs  |  2.458µs  |  851.795ns  |  1.260µs  |
| `next (global)` |  2.809µs  |  2.965µs  |  2.635µs  |  2.577µs  |  2.478µs  |  288.011ns  |  **378.569ns**  |
| `next (local)` |  2.805µs  |  2.977µs  |  2.642µs  |  2.572µs  |  2.465µs  |  837.096ns  |  1.274µs  |
| `local len` |  **1.185µs**  |  **1.307µs**  |  **876.034ns**  |  **705.754ns**  |  **611.150ns**  |  **69.441ns**  |  543.769ns  |
| `table.n` |  **1.215µs**  |  **1.312µs**  |  **873.512ns**  |  **716.336ns**  |  **612.968ns**  |  **69.075ns**  |  539.712ns  |
| `table[0]` |  **1.188µs**  |  **1.389µs**  |  **889.507ns**  |  **714.373ns**  |  **623.184ns**  |  **67.539ns**  |  543.882ns  |
| `#table` |  **1.209µs**  |  **1.332µs**  |  **891.744ns**  |  **717.988ns**  |  **616.796ns**  |  74.852ns  |  537.234ns  |
| `constant` |  **1.278µs**  |  **1.326µs**  |  **950.615ns**  |  **713.529ns**  |  **608.854ns**  |  **63.728ns**  |  542.202ns  |

## local vs global index

#### One-Time Setup

```lua
local s = math.sin
```

| Test | Code |
| ----:| ---- |
| `local` | `out = s(3.14)` |
| `global` | `out = math.sin(3.14)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 15.284ns | 32.799ns | 58.388ns | 33.467ns | 3.580ns | 1.00x | 48 (1.0%) |
| `global` | 14.867ns | 44.849ns | 297.935ns | 45.757ns | 5.856ns | 1.37x | 25 (0.5%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 11.695ns | 32.266ns | 71.494ns | 32.409ns | 4.241ns | 1.00x | 55 (1.1%) |
| `global` | 6.429ns | 47.582ns | 80.856ns | 47.904ns | 5.937ns | 1.47x | 49 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 10.948ns | 30.514ns | 52.304ns | 30.912ns | 4.486ns | 1.00x | 64 (1.3%) |
| `global` | 1.616ns | 52.406ns | 173.268ns | 51.749ns | 8.919ns | 1.72x | 24 (0.5%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 8.733ns | 28.230ns | 48.007ns | 28.462ns | 3.610ns | 1.00x | 55 (1.1%) |
| `global` | 1.215ns | 34.939ns | 263.568ns | 35.182ns | 5.633ns | 1.24x | 20 (0.4%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 19.942ns | 27.995ns | 45.458ns | 28.551ns | 3.116ns | 1.00x | 86 (1.7%) |
| `global` | 19.848ns | 37.262ns | 61.343ns | 37.426ns | 3.053ns | 1.33x | 102 (2.0%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | \* | \* | 0.427ns | \* | 0.020ns | 1.01x | 92 (1.8%) |
| `global` | \* | \* | 0.435ns | \* | 0.022ns | 1.00x | 107 (2.1%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 6.473ns | 14.171ns | 23.621ns | 14.219ns | 1.606ns | 1.00x | 51 (1.0%) |
| `global` | 8.290ns | 17.409ns | 78.129ns | 17.529ns | 2.256ns | 1.23x | 15 (0.3%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `local` |  **32.799ns**  |  **32.266ns**  |  **30.514ns**  |  **28.230ns**  |  **27.995ns**  |  **\***  |  **14.171ns**  |
| `global` |  44.849ns  |  47.582ns  |  52.406ns  |  34.939ns  |  37.262ns  |  **\***  |  17.409ns  |

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
| ----:| ---- |
| `local` | `out = t_local(3)` |
| `upvalue` | `out = t_upvalue(3)` |
| `global` | `out = type(3)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 23.833ns | 42.673ns | 76.228ns | 42.958ns | 3.298ns | 1.00x | 96 (1.9%) |
| `upvalue` | 26.568ns | 42.785ns | 67.277ns | 43.556ns | 3.846ns | 1.00x | 71 (1.4%) |
| `global` | 19.059ns | 48.079ns | 76.207ns | 48.757ns | 4.465ns | 1.13x | 80 (1.6%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 19.491ns | 41.391ns | 69.213ns | 41.654ns | 5.093ns | 1.00x | 43 (0.9%) |
| `upvalue` | 4.531ns | 41.805ns | 71.295ns | 42.013ns | 5.228ns | 1.01x | 53 (1.1%) |
| `global` | 10.106ns | 48.500ns | 330.065ns | 49.176ns | 7.650ns | 1.17x | 24 (0.5%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 12.770ns | 28.620ns | 48.529ns | 28.863ns | 3.798ns | 1.00x | 65 (1.3%) |
| `upvalue` | 0.619ns | 29.564ns | 56.028ns | 29.936ns | 4.291ns | 1.03x | 53 (1.1%) |
| `global` | 3.369ns | 39.458ns | 189.208ns | 40.212ns | 8.149ns | 1.38x | 16 (0.3%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 4.887ns | 27.772ns | 222.939ns | 28.024ns | 5.025ns | 1.00x | 16 (0.3%) |
| `upvalue` | 1.461ns | 27.998ns | 47.381ns | 28.341ns | 3.838ns | 1.01x | 66 (1.3%) |
| `global` | 16.024ns | 29.910ns | 53.079ns | 30.257ns | 3.723ns | 1.08x | 71 (1.4%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 11.217ns | 26.478ns | 47.919ns | 26.915ns | 2.681ns | 1.00x | 90 (1.8%) |
| `upvalue` | 13.716ns | 26.827ns | 47.960ns | 27.285ns | 2.807ns | 1.01x | 82 (1.6%) |
| `global` | 20.174ns | 31.226ns | 208.753ns | 31.487ns | 4.107ns | 1.18x | 18 (0.4%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | \* | \* | 0.409ns | \* | 0.027ns | 1.00x | 75 (1.5%) |
| `upvalue` | \* | \* | 0.432ns | \* | 0.026ns | 1.00x | 91 (1.8%) |
| `global` | \* | \* | 0.419ns | \* | 0.025ns | 1.00x | 66 (1.3%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `local` | 5.891ns | 10.333ns | 17.372ns | 10.358ns | 1.365ns | 1.00x | 16 (0.3%) |
| `upvalue` | 5.378ns | 10.304ns | 61.948ns | 10.367ns | 1.736ns | 1.00x | 10 (0.2%) |
| `global` | 5.698ns | 10.831ns | 17.479ns | 10.862ns | 0.756ns | 1.05x | 91 (1.8%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `local` |  **42.673ns**  |  **41.391ns**  |  **28.620ns**  |  **27.772ns**  |  **26.478ns**  |  **\***  |  **10.333ns**  |
| `upvalue` |  **42.785ns**  |  **41.805ns**  |  **29.564ns**  |  **27.998ns**  |  **26.827ns**  |  **\***  |  **10.304ns**  |
| `global` |  48.079ns  |  48.500ns  |  39.458ns  |  **29.910ns**  |  31.226ns  |  **\***  |  **10.831ns**  |

## localized method

#### One-Time Setup

```lua
local class = {
	test = function(self) return 1 end,
}
local ltest = class.test
```

| Test | Code |
| ----:| ---- |
| `none` | `out = class:test(); out = class:test(); out = class:test()` |
| `inside loop` | `local test = class.test; out = test(class); out = test(class); out = test(class)` |
| `outside loop` | `out = ltest(class); out = ltest(class); out = ltest(class)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `none` | 15.098ns | 99.251ns | 280.233ns | 100.882ns | 10.440ns | 1.23x | 26 (0.5%) |
| `inside loop` | 61.057ns | 86.501ns | 275.442ns | 87.210ns | 7.678ns | 1.08x | 65 (1.3%) |
| `outside loop` | 51.105ns | 80.403ns | 125.632ns | 81.243ns | 7.504ns | 1.00x | 80 (1.6%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `none` | 23.131ns | 116.773ns | 198.970ns | 118.151ns | 14.119ns | 1.13x | 49 (1.0%) |
| `inside loop` | 34.819ns | 111.146ns | 182.189ns | 111.647ns | 13.662ns | 1.08x | 47 (0.9%) |
| `outside loop` | 2.173ns | 103.030ns | 182.644ns | 104.128ns | 13.675ns | 1.00x | 56 (1.1%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `none` | 3.717ns | 95.061ns | 167.375ns | 95.706ns | 11.136ns | 1.19x | 44 (0.9%) |
| `inside loop` | 0.890ns | 91.704ns | 153.541ns | 91.969ns | 11.213ns | 1.15x | 39 (0.8%) |
| `outside loop` | 27.128ns | 79.699ns | 418.554ns | 80.037ns | 10.489ns | 1.00x | 29 (0.6%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `none` | 10.943ns | 81.967ns | 144.859ns | 83.925ns | 13.421ns | 1.18x | 28 (0.6%) |
| `inside loop` | 15.309ns | 71.404ns | 135.869ns | 72.696ns | 11.238ns | 1.02x | 61 (1.2%) |
| `outside loop` | 4.414ns | 69.727ns | 243.400ns | 70.908ns | 10.569ns | 1.00x | 39 (0.8%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `none` | 59.492ns | 85.609ns | 124.986ns | 88.030ns | 9.636ns | 1.22x | 34 (0.7%) |
| `inside loop` | 41.555ns | 76.173ns | 251.143ns | 76.413ns | 7.120ns | 1.08x | 33 (0.7%) |
| `outside loop` | 45.843ns | 70.235ns | 121.810ns | 71.230ns | 7.146ns | 1.00x | 76 (1.5%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `none` | \* | \* | 0.460ns | \* | 0.017ns | 1.01x | 68 (1.4%) |
| `inside loop` | \* | \* | 0.465ns | \* | 0.024ns | 1.00x | 95 (1.9%) |
| `outside loop` | \* | \* | 0.891ns | \* | 0.029ns | 1.03x | 62 (1.2%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `none` | 7.155ns | 37.787ns | 124.801ns | 38.399ns | 5.203ns | 1.12x | 33 (0.7%) |
| `inside loop` | 1.269ns | 33.642ns | 65.185ns | 34.160ns | 4.720ns | 1.00x | 22 (0.4%) |
| `outside loop` | 3.534ns | 34.310ns | 133.607ns | 34.977ns | 5.165ns | 1.02x | 23 (0.5%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `none` |  99.251ns  |  116.773ns  |  95.061ns  |  81.967ns  |  85.609ns  |  **\***  |  37.787ns  |
| `inside loop` |  **86.501ns**  |  **111.146ns**  |  91.704ns  |  **71.404ns**  |  **76.173ns**  |  **\***  |  **33.642ns**  |
| `outside loop` |  **80.403ns**  |  **103.030ns**  |  **79.699ns**  |  **69.727ns**  |  **70.235ns**  |  **\***  |  **34.310ns**  |

## math.max

#### One-Time Setup

```lua
local max, x, y = math.max, 1, 100
```

| Test | Code |
| ----:| ---- |
| `math.max (global)` | `out = math.max(x, y)` |
| `math.max (local)` | `out = max(x, y)` |
| `if-else` | `if x > y then out = x else out = y end` |
| `branchless` | `out = x > y and x or y` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 1.506ns | 40.855ns | 81.312ns | 40.996ns | 5.048ns | 3.12x | 45 (0.9%) |
| `math.max (local)` | 9.671ns | 29.191ns | 52.165ns | 29.326ns | 3.570ns | 2.23x | 51 (1.0%) |
| `if-else` | 7.706ns | 13.076ns | 85.430ns | 13.210ns | 1.974ns | 1.00x | 16 (0.3%) |
| `branchless` | 5.091ns | 13.113ns | 21.698ns | 13.171ns | 1.666ns | 1.00x | 48 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 11.367ns | 48.543ns | 83.800ns | 49.076ns | 5.831ns | 2.72x | 52 (1.0%) |
| `math.max (local)` | 10.645ns | 32.282ns | 55.829ns | 32.417ns | 4.496ns | 1.81x | 54 (1.1%) |
| `if-else` | 5.053ns | 17.940ns | 28.565ns | 18.036ns | 2.269ns | 1.01x | 41 (0.8%) |
| `branchless` | 6.533ns | 17.842ns | 80.297ns | 17.965ns | 2.614ns | 1.00x | 35 (0.7%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 6.039ns | 46.448ns | 216.342ns | 46.344ns | 10.580ns | 3.05x | 30 (0.6%) |
| `math.max (local)` | 12.547ns | 28.796ns | 169.343ns | 29.493ns | 5.274ns | 1.89x | 8 (0.2%) |
| `if-else` | 1.925ns | 16.216ns | 25.262ns | 16.271ns | 2.634ns | 1.06x | 41 (0.8%) |
| `branchless` | 1.469ns | 15.229ns | 26.383ns | 15.612ns | 2.492ns | 1.00x | 34 (0.7%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 15.248ns | 30.219ns | 212.862ns | 30.603ns | 4.660ns | 3.07x | 25 (0.5%) |
| `math.max (local)` | 4.546ns | 25.540ns | 47.708ns | 25.804ns | 3.536ns | 2.60x | 41 (0.8%) |
| `if-else` | 2.149ns | 9.829ns | 17.327ns | 9.886ns | 1.176ns | 1.00x | 42 (0.8%) |
| `branchless` | 3.240ns | 9.928ns | 16.605ns | 10.011ns | 1.235ns | 1.01x | 56 (1.1%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 1.932ns | 31.644ns | 51.640ns | 31.874ns | 4.210ns | 3.52x | 59 (1.2%) |
| `math.max (local)` | 3.145ns | 23.585ns | 39.697ns | 23.716ns | 2.996ns | 2.62x | 46 (0.9%) |
| `if-else` | 2.112ns | 8.990ns | 25.325ns | 9.074ns | 1.193ns | 1.00x | 45 (0.9%) |
| `branchless` | 3.060ns | 8.994ns | 15.388ns | 9.048ns | 1.152ns | 1.00x | 44 (0.9%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 1.550ns | 2.436ns | 3.797ns | 2.470ns | 0.220ns | 9.13x | 60 (1.2%) |
| `math.max (local)` | \* | \* | 0.437ns | \* | 0.028ns | 1.01x | 50 (1.0%) |
| `if-else` | \* | \* | 0.512ns | \* | 0.020ns | 1.00x | 80 (1.6%) |
| `branchless` | \* | \* | 0.502ns | \* | 0.021ns | 1.02x | 95 (1.9%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 8.191ns | 13.371ns | 20.364ns | 13.390ns | 1.442ns | 1.95x | 42 (0.8%) |
| `math.max (local)` | 5.839ns | 10.211ns | 67.776ns | 10.285ns | 1.481ns | 1.49x | 15 (0.3%) |
| `if-else` | 3.582ns | 7.009ns | 11.033ns | 7.048ns | 0.761ns | 1.02x | 42 (0.8%) |
| `branchless` | 3.061ns | 6.872ns | 11.232ns | 6.919ns | 0.788ns | 1.00x | 51 (1.0%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `math.max (global)` |  40.855ns  |  48.543ns  |  46.448ns  |  30.219ns  |  31.644ns  |  2.436ns  |  13.371ns  |
| `math.max (local)` |  29.191ns  |  32.282ns  |  28.796ns  |  25.540ns  |  23.585ns  |  **\***  |  10.211ns  |
| `if-else` |  **13.076ns**  |  **17.940ns**  |  **16.216ns**  |  **9.829ns**  |  **8.990ns**  |  **\***  |  **7.009ns**  |
| `branchless` |  **13.113ns**  |  **17.842ns**  |  **15.229ns**  |  **9.928ns**  |  **8.994ns**  |  **\***  |  **6.872ns**  |

## math.max of 3 numbers

#### One-Time Setup

```lua
local max, x, y, z = math.max, 1, 100, 55
```

| Test | Code |
| ----:| ---- |
| `math.max (global)` | `out = math.max(x, y, z)` |
| `math.max (local)` | `out = max(x, y, z)` |
| `if-else` | `if x > y and x > z then out = x elseif y > z and y > x then out = y else out = z end` |
| `branchless` | `out = (x > y and x > z and x) or (y > z and y > x and y) or (z)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 24.832ns | 48.642ns | 81.268ns | 49.886ns | 5.448ns | 1.43x | 68 (1.4%) |
| `math.max (local)` | 21.543ns | 36.520ns | 63.480ns | 36.910ns | 3.199ns | 1.08x | 71 (1.4%) |
| `if-else` | 22.594ns | 33.904ns | 55.795ns | 34.390ns | 3.129ns | 1.00x | 98 (2.0%) |
| `branchless` | 13.314ns | 36.184ns | 69.434ns | 36.605ns | 3.468ns | 1.07x | 82 (1.6%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 14.871ns | 53.839ns | 247.897ns | 54.450ns | 7.666ns | 1.42x | 36 (0.7%) |
| `math.max (local)` | 4.488ns | 37.808ns | 61.753ns | 38.143ns | 4.822ns | 1.00x | 52 (1.0%) |
| `if-else` | 12.613ns | 41.537ns | 72.469ns | 41.852ns | 5.460ns | 1.10x | 56 (1.1%) |
| `branchless` | 4.257ns | 44.360ns | 74.852ns | 44.220ns | 6.081ns | 1.17x | 27 (0.5%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 6.322ns | 48.482ns | 80.802ns | 49.312ns | 7.733ns | 1.46x | 21 (0.4%) |
| `math.max (local)` | 1.528ns | 35.793ns | 151.339ns | 36.750ns | 6.593ns | 1.08x | 8 (0.2%) |
| `if-else` | 6.151ns | 33.222ns | 52.388ns | 33.511ns | 4.211ns | 1.00x | 53 (1.1%) |
| `branchless` | 3.898ns | 34.408ns | 60.148ns | 34.678ns | 4.062ns | 1.04x | 58 (1.2%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 13.741ns | 38.729ns | 71.902ns | 39.042ns | 5.050ns | 1.68x | 46 (0.9%) |
| `math.max (local)` | 5.284ns | 33.507ns | 56.617ns | 33.505ns | 4.667ns | 1.45x | 48 (1.0%) |
| `if-else` | 3.838ns | 23.065ns | 256.299ns | 23.764ns | 5.759ns | 1.00x | 4 (0.1%) |
| `branchless` | 5.409ns | 24.763ns | 52.653ns | 25.413ns | 4.198ns | 1.07x | 29 (0.6%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 24.473ns | 44.341ns | 212.418ns | 44.804ns | 4.359ns | 2.08x | 65 (1.3%) |
| `math.max (local)` | 21.227ns | 32.463ns | 51.599ns | 32.814ns | 2.945ns | 1.52x | 73 (1.5%) |
| `if-else` | 9.519ns | 21.311ns | 34.395ns | 21.890ns | 2.691ns | 1.00x | 29 (0.6%) |
| `branchless` | 14.242ns | 22.374ns | 35.899ns | 22.530ns | 1.842ns | 1.05x | 97 (1.9%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | 1.256ns | 2.471ns | 3.879ns | 2.505ns | 0.247ns | 9.16x | 51 (1.0%) |
| `math.max (local)` | \* | \* | 0.406ns | \* | 0.024ns | 1.00x | 104 (2.1%) |
| `if-else` | \* | \* | 0.456ns | \* | 0.021ns | 1.00x | 68 (1.4%) |
| `branchless` | \* | \* | 0.416ns | \* | 0.020ns | 1.01x | 112 (2.2%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.max (global)` | \* | 15.192ns | 22.470ns | 15.242ns | 1.601ns | 1.32x | 36 (0.7%) |
| `math.max (local)` | 6.518ns | 11.501ns | 34.393ns | 11.604ns | 1.351ns | 1.00x | 45 (0.9%) |
| `if-else` | 2.239ns | 15.227ns | 23.406ns | 15.291ns | 1.648ns | 1.32x | 43 (0.9%) |
| `branchless` | 1.467ns | 14.918ns | 62.692ns | 14.997ns | 1.883ns | 1.30x | 35 (0.7%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `math.max (global)` |  48.642ns  |  53.839ns  |  48.482ns  |  38.729ns  |  44.341ns  |  2.471ns  |  15.192ns  |
| `math.max (local)` |  **36.520ns**  |  **37.808ns**  |  **35.793ns**  |  33.507ns  |  32.463ns  |  **\***  |  **11.501ns**  |
| `if-else` |  **33.904ns**  |  **41.537ns**  |  **33.222ns**  |  **23.065ns**  |  **21.311ns**  |  **\***  |  15.227ns  |
| `branchless` |  **36.184ns**  |  44.360ns  |  **34.408ns**  |  **24.763ns**  |  **22.374ns**  |  **\***  |  14.918ns  |

## select

#### One-Time Setup

```lua
local function fn()
	return 1, 2, 3, 4
end
local sel = select
```

| Test | Code |
| ----:| ---- |
| `argument expanision` | `local _; _, _, _, out = fn()` |
| `select (global)` | `out = select(4, fn())` |
| `select (local)` | `out = sel(4, fn())` |
| `table` | `out = ({ fn() })[4]` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 8.018ns | 35.547ns | 62.120ns | 35.886ns | 4.174ns | 1.00x | 60 (1.2%) |
| `select (global)` | 12.478ns | 55.641ns | 90.977ns | 56.075ns | 6.890ns | 1.57x | 50 (1.0%) |
| `select (local)` | 5.763ns | 49.684ns | 81.832ns | 50.007ns | 5.978ns | 1.40x | 44 (0.9%) |
| `table` | 59.499ns | 115.698ns | 487.291ns | 118.044ns | 13.496ns | 3.25x | 40 (0.8%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 7.180ns | 55.036ns | 95.683ns | 56.351ns | 9.707ns | 1.00x | 12 (0.2%) |
| `select (global)` | 34.830ns | 78.290ns | 123.838ns | 80.430ns | 13.540ns | 1.42x | 5 (0.1%) |
| `select (local)` | 11.726ns | 72.593ns | 116.659ns | 73.999ns | 11.575ns | 1.32x | 17 (0.3%) |
| `table` | 67.069ns | 113.114ns | 315.647ns | 115.705ns | 12.658ns | 2.06x | 39 (0.8%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 6.832ns | 40.192ns | 63.688ns | 40.600ns | 6.718ns | 1.00x | 10 (0.2%) |
| `select (global)` | 6.257ns | 58.485ns | 93.460ns | 59.667ns | 10.211ns | 1.46x | 10 (0.2%) |
| `select (local)` | 16.825ns | 52.852ns | 285.070ns | 54.161ns | 11.164ns | 1.31x | 16 (0.3%) |
| `table` | 62.792ns | 107.893ns | 172.071ns | 111.084ns | 14.220ns | 2.68x | 20 (0.4%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 7.771ns | 32.838ns | 58.463ns | 33.037ns | 4.303ns | 1.00x | 46 (0.9%) |
| `select (global)` | 3.992ns | 45.661ns | 82.910ns | 45.900ns | 5.992ns | 1.39x | 42 (0.8%) |
| `select (local)` | 4.114ns | 43.714ns | 73.691ns | 43.928ns | 5.583ns | 1.33x | 47 (0.9%) |
| `table` | 54.473ns | 85.744ns | 142.967ns | 87.123ns | 9.008ns | 2.61x | 77 (1.5%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 4.297ns | 30.569ns | 51.461ns | 30.865ns | 3.988ns | 1.00x | 53 (1.1%) |
| `select (global)` | 17.621ns | 43.792ns | 251.713ns | 44.388ns | 7.600ns | 1.43x | 20 (0.4%) |
| `select (local)` | 0.379ns | 41.428ns | 124.324ns | 41.516ns | 5.409ns | 1.36x | 37 (0.7%) |
| `table` | 47.660ns | 81.735ns | 135.100ns | 82.884ns | 9.498ns | 2.67x | 60 (1.2%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | \* | \* | 0.402ns | \* | 0.022ns | 1.01x | 87 (1.7%) |
| `select (global)` | 0.904ns | 1.337ns | 2.113ns | 1.355ns | 0.114ns | 5.00x | 94 (1.9%) |
| `select (local)` | \* | \* | 0.432ns | \* | 0.024ns | 1.00x | 107 (2.1%) |
| `table` | 1.669µs | 6.881µs | 15.194µs | 7.019µs | 668.715ns | 25755.60x | 53 (1.1%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 1.550ns | 17.936ns | 30.221ns | 18.005ns | 2.010ns | 1.00x | 50 (1.0%) |
| `select (global)` | 14.244ns | 27.337ns | 46.983ns | 27.541ns | 3.276ns | 1.52x | 48 (1.0%) |
| `select (local)` | 5.845ns | 25.918ns | 41.622ns | 26.033ns | 2.871ns | 1.45x | 43 (0.9%) |
| `table` | 35.768ns | 58.246ns | 91.781ns | 59.089ns | 6.157ns | 3.25x | 78 (1.6%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `argument expanision` |  **35.547ns**  |  **55.036ns**  |  **40.192ns**  |  **32.838ns**  |  **30.569ns**  |  **\***  |  **17.936ns**  |
| `select (global)` |  55.641ns  |  78.290ns  |  58.485ns  |  45.661ns  |  43.792ns  |  1.337ns  |  27.337ns  |
| `select (local)` |  49.684ns  |  72.593ns  |  52.852ns  |  43.714ns  |  41.428ns  |  **\***  |  25.918ns  |
| `table` |  115.698ns  |  113.114ns  |  107.893ns  |  85.744ns  |  81.735ns  |  6.881µs  |  58.246ns  |

## sqrt

#### One-Time Setup

```lua
local x, sqrt = 10, math.sqrt
```

| Test | Code |
| ----:| ---- |
| `math.sqrt (global)` | `out = math.sqrt(x)` |
| `math.sqrt (local)` | `out = sqrt(x)` |
| `exponent` | `out = x ^ 0.5` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.sqrt (global)` | 21.278ns | 36.883ns | 58.780ns | 37.748ns | 4.233ns | 1.58x | 35 (0.7%) |
| `math.sqrt (local)` | 12.950ns | 24.767ns | 38.998ns | 25.384ns | 2.722ns | 1.06x | 40 (0.8%) |
| `exponent` | 5.114ns | 23.297ns | 77.310ns | 23.446ns | 1.875ns | 1.00x | 64 (1.3%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.sqrt (global)` | 2.347ns | 42.360ns | 174.598ns | 42.812ns | 6.016ns | 1.75x | 37 (0.7%) |
| `math.sqrt (local)` | 1.146ns | 25.237ns | 43.419ns | 25.433ns | 3.188ns | 1.04x | 54 (1.1%) |
| `exponent` | 4.170ns | 24.217ns | 45.340ns | 24.454ns | 3.119ns | 1.00x | 52 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.sqrt (global)` | 8.615ns | 36.847ns | 148.078ns | 37.105ns | 5.061ns | 1.50x | 38 (0.8%) |
| `math.sqrt (local)` | 13.064ns | 26.538ns | 45.364ns | 26.707ns | 3.328ns | 1.08x | 62 (1.2%) |
| `exponent` | 8.725ns | 24.534ns | 40.033ns | 24.686ns | 3.070ns | 1.00x | 63 (1.3%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.sqrt (global)` | 17.525ns | 28.097ns | 48.828ns | 28.290ns | 3.499ns | 1.34x | 52 (1.0%) |
| `math.sqrt (local)` | 9.315ns | 22.875ns | 36.937ns | 23.038ns | 2.984ns | 1.09x | 47 (0.9%) |
| `exponent` | 4.388ns | 21.046ns | 36.234ns | 21.137ns | 2.645ns | 1.00x | 53 (1.1%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.sqrt (global)` | 22.764ns | 32.315ns | 190.050ns | 33.194ns | 4.407ns | 1.43x | 9 (0.2%) |
| `math.sqrt (local)` | 11.913ns | 23.642ns | 37.689ns | 23.944ns | 2.288ns | 1.05x | 84 (1.7%) |
| `exponent` | 14.631ns | 22.530ns | 40.962ns | 22.730ns | 1.766ns | 1.00x | 104 (2.1%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.sqrt (global)` | 1.470ns | 2.411ns | 4.066ns | 2.437ns | 0.193ns | 9.16x | 128 (2.6%) |
| `math.sqrt (local)` | \* | \* | 0.426ns | \* | 0.029ns | 1.00x | 47 (0.9%) |
| `exponent` | \* | \* | 0.427ns | \* | 0.025ns | 1.01x | 87 (1.7%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.sqrt (global)` | 4.812ns | 14.330ns | 21.526ns | 14.373ns | 1.468ns | 1.46x | 41 (0.8%) |
| `math.sqrt (local)` | 0.888ns | 9.844ns | 15.379ns | 9.896ns | 1.091ns | 1.00x | 38 (0.8%) |
| `exponent` | \* | 22.857ns | 33.157ns | 22.930ns | 3.459ns | 2.32x | 20 (0.4%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `math.sqrt (global)` |  36.883ns  |  42.360ns  |  36.847ns  |  28.097ns  |  32.315ns  |  2.411ns  |  14.330ns  |
| `math.sqrt (local)` |  **24.767ns**  |  **25.237ns**  |  **26.538ns**  |  **22.875ns**  |  **23.642ns**  |  **\***  |  **9.844ns**  |
| `exponent` |  **23.297ns**  |  **24.217ns**  |  **24.534ns**  |  **21.046ns**  |  **22.530ns**  |  **\***  |  22.857ns  |

## square

#### One-Time Setup

```lua
local x, pow = 10, math.pow
```

| Test | Code |
| ----:| ---- |
| `math.pow (global)` | `out = math.pow(x, 3)` |
| `math.pow (local)` | `out = pow(x, 3)` |
| `multiply` | `out = x * x * x` |
| `exponent` | `out = x ^ 3` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | \* | 59.249ns | 216.923ns | 61.250ns | 10.682ns | 4.05x | 19 (0.4%) |
| `math.pow (local)` | 9.287ns | 45.336ns | 259.673ns | 46.141ns | 8.076ns | 3.10x | 30 (0.6%) |
| `multiply` | 4.964ns | 14.634ns | 26.444ns | 14.754ns | 1.798ns | 1.00x | 48 (1.0%) |
| `exponent` | 3.074ns | 21.392ns | 124.132ns | 21.630ns | 3.050ns | 1.46x | 44 (0.9%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 18.462ns | 61.690ns | 114.329ns | 62.003ns | 7.858ns | 3.56x | 45 (0.9%) |
| `math.pow (local)` | 1.751ns | 45.156ns | 176.951ns | 45.670ns | 6.613ns | 2.60x | 52 (1.0%) |
| `multiply` | 0.558ns | 17.341ns | 48.202ns | 17.470ns | 2.314ns | 1.00x | 41 (0.8%) |
| `exponent` | 4.176ns | 24.824ns | 88.220ns | 24.971ns | 3.390ns | 1.43x | 37 (0.7%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 11.638ns | 59.161ns | 115.830ns | 59.586ns | 7.315ns | 4.64x | 40 (0.8%) |
| `math.pow (local)` | 3.910ns | 49.138ns | 95.099ns | 49.578ns | 6.205ns | 3.86x | 54 (1.1%) |
| `multiply` | 0.479ns | 12.738ns | 116.084ns | 12.930ns | 2.429ns | 1.00x | 15 (0.3%) |
| `exponent` | 14.999ns | 26.371ns | 45.630ns | 26.812ns | 3.658ns | 2.07x | 59 (1.2%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 2.754ns | 53.384ns | 201.860ns | 54.358ns | 8.740ns | 4.26x | 51 (1.0%) |
| `math.pow (local)` | 27.209ns | 46.203ns | 189.983ns | 46.761ns | 7.041ns | 3.68x | 40 (0.8%) |
| `multiply` | 2.644ns | 12.541ns | 85.877ns | 12.741ns | 2.098ns | 1.00x | 19 (0.4%) |
| `exponent` | 8.330ns | 21.687ns | 73.610ns | 21.991ns | 3.216ns | 1.73x | 50 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | - | - | - | - | - | - | - |
| `math.pow (local)` | - | - | - | - | - | - | - |
| `multiply` | 0.777ns | 10.204ns | 17.450ns | 10.223ns | 1.314ns | 1.00x | 54 (1.1%) |
| `exponent` | 0.391ns | 21.340ns | 33.509ns | 21.675ns | 3.059ns | 2.09x | 49 (1.0%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 1.343ns | 2.446ns | 3.637ns | 2.464ns | 0.193ns | 9.11x | 67 (1.3%) |
| `math.pow (local)` | \* | \* | 0.407ns | \* | 0.029ns | 1.02x | 52 (1.0%) |
| `multiply` | \* | \* | 0.525ns | \* | 0.023ns | 1.00x | 87 (1.7%) |
| `exponent` | \* | \* | 0.418ns | \* | 0.018ns | 1.01x | 90 (1.8%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `math.pow (global)` | 11.822ns | 28.903ns | 128.228ns | 29.057ns | 3.734ns | 3.76x | 30 (0.6%) |
| `math.pow (local)` | 10.226ns | 25.538ns | 41.103ns | 25.649ns | 2.822ns | 3.32x | 45 (0.9%) |
| `multiply` | 3.771ns | 7.688ns | 13.930ns | 7.735ns | 0.896ns | 1.00x | 42 (0.8%) |
| `exponent` | 8.149ns | 20.472ns | 31.200ns | 20.591ns | 2.281ns | 2.66x | 44 (0.9%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `math.pow (global)` |  59.249ns  |  61.690ns  |  59.161ns  |  53.384ns  |  -  |  2.446ns  |  28.903ns  |
| `math.pow (local)` |  45.336ns  |  45.156ns  |  49.138ns  |  46.203ns  |  -  |  **\***  |  25.538ns  |
| `multiply` |  **14.634ns**  |  **17.341ns**  |  **12.738ns**  |  **12.541ns**  |  **10.204ns**  |  **\***  |  **7.688ns**  |
| `exponent` |  21.392ns  |  24.824ns  |  26.371ns  |  21.687ns  |  21.340ns  |  **\***  |  20.472ns  |

## string concatenation

#### One-Time Setup

```lua
local bs = string.rep("---------", 127)
local t = { bs, bs, bs, bs, bs, bs, bs, bs, bs, bs }
local concat, format = table.concat, string.format
```

| Test | Code |
| ----:| ---- |
| `all-in-one` | `out = bs .. bs .. bs .. bs .. bs .. bs .. bs .. bs .. bs .. bs` |
| `separated` | `out = bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs; out = out .. bs;` |
| `loop` | `out = bs; for i = 1, 9 do out = out .. bs end` |
| `format` | `out = format("%s%s%s%s%s%s%s%s%s%s", bs, bs, bs, bs, bs, bs, bs, bs, bs, bs)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `all-in-one` | 118.739ns | 330.613ns | 1.161µs | 336.790ns | 61.244ns | 1.00x | 31 (0.6%) |
| `separated` | 1.592µs | 2.598µs | 4.711µs | 2.619µs | 323.650ns | 7.86x | 68 (1.4%) |
| `loop` | 1.698µs | 2.623µs | 4.576µs | 2.636µs | 319.300ns | 7.93x | 43 (0.9%) |
| `format` | 233.241ns | 1.329µs | 2.367µs | 1.340µs | 167.335ns | 4.02x | 65 (1.3%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `all-in-one` | 1.665ns | 439.234ns | 1.525µs | 434.676ns | 200.727ns | 1.00x | 30 (0.6%) |
| `separated` | 94.109ns | 4.780µs | 20.275µs | 5.093µs | 2.098µs | 10.88x | 130 (2.6%) |
| `loop` | 92.482ns | 4.743µs | 18.078µs | 5.041µs | 1.986µs | 10.80x | 119 (2.4%) |
| `format` | 8.244ns | 1.080µs | 5.251µs | 1.121µs | 554.357ns | 2.46x | 69 (1.4%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `all-in-one` | 0.645ns | 417.756ns | 1.685µs | 422.038ns | 192.454ns | 1.00x | 48 (1.0%) |
| `separated` | 137.564ns | 4.699µs | 18.705µs | 5.034µs | 2.017µs | 11.25x | 137 (2.7%) |
| `loop` | 31.930ns | 5.224µs | 18.031µs | 5.977µs | 2.646µs | 12.50x | 49 (1.0%) |
| `format` | 474.222ns | 1.845µs | 3.268µs | 1.836µs | 401.354ns | 4.42x | 7 (0.1%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `all-in-one` | \* | 330.194ns | 3.197µs | 384.888ns | 279.935ns | 1.00x | 98 (2.0%) |
| `separated` | 199.200ns | 4.791µs | 19.847µs | 5.373µs | 2.436µs | 14.51x | 112 (2.2%) |
| `loop` | 516.820ns | 4.806µs | 17.601µs | 5.397µs | 2.414µs | 14.56x | 115 (2.3%) |
| `format` | 21.509ns | 1.658µs | 5.933µs | 1.706µs | 420.464ns | 5.02x | 88 (1.8%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `all-in-one` | 5.796ns | 2.235µs | 4.806µs | 2.111µs | 892.010ns | 1.00x | 1 (0.0%) |
| `separated` | 185.469ns | 11.174µs | 22.321µs | 10.356µs | 4.876µs | 5.00x | 0 (0.0%) |
| `loop` | 199.871ns | 4.781µs | 22.097µs | 5.178µs | 2.177µs | 2.14x | 135 (2.7%) |
| `format` | 102.697ns | 2.315µs | 4.160µs | 2.340µs | 320.148ns | 1.04x | 56 (1.1%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `all-in-one` | \* | \* | 0.444ns | \* | 0.022ns | 1.01x | 77 (1.5%) |
| `separated` | \* | \* | 0.422ns | \* | 0.021ns | 1.00x | 70 (1.4%) |
| `loop` | 1.070µs | 1.786µs | 2.965µs | 1.823µs | 180.701ns | 6634.82x | 92 (1.8%) |
| `format` | \* | \* | 0.427ns | \* | 0.025ns | 1.01x | 82 (1.6%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `all-in-one` | 188.856ns | 324.898ns | 693.221ns | 328.280ns | 36.777ns | 1.00x | 60 (1.2%) |
| `separated` | 1.053µs | 2.317µs | 3.670µs | 2.327µs | 264.050ns | 7.13x | 40 (0.8%) |
| `loop` | 1.465µs | 2.423µs | 4.094µs | 2.438µs | 279.118ns | 7.46x | 55 (1.1%) |
| `format` | 222.108ns | 421.866ns | 681.450ns | 424.890ns | 49.739ns | 1.30x | 51 (1.0%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `all-in-one` |  **330.613ns**  |  **439.234ns**  |  **417.756ns**  |  **330.194ns**  |  **2.235µs**  |  **\***  |  **324.898ns**  |
| `separated` |  2.598µs  |  4.780µs  |  4.699µs  |  4.791µs  |  11.174µs  |  **\***  |  2.317µs  |
| `loop` |  2.623µs  |  4.743µs  |  5.224µs  |  4.806µs  |  4.781µs  |  1.786µs  |  2.423µs  |
| `format` |  1.329µs  |  1.080µs  |  1.845µs  |  1.658µs  |  **2.315µs**  |  **\***  |  421.866ns  |

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
| ----:| ---- |
| `table.insert (global)` | `table.insert(out, __i)` |
| `table.insert (local)` | `tinsert(out, __i)` |
| `loop parameter` | `out[__i] = __i` |
| `#table+1` | `out[#out + 1] = __i` |
| `table.n` | `out.n = out.n + 1; out[out.n] = __i` |
| `table[0]` | `out[0] = out[0] + 1; out[out[0]] = __i` |
| `lockstep parameter` | `out[count] = __i; count = count + 1` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `table.insert (global)` | 59.510ns | 86.575ns | 157.171ns | 88.061ns | 8.749ns | 5.65x | 71 (1.4%) |
| `table.insert (local)` | 53.836ns | 81.292ns | 131.368ns | 82.016ns | 6.165ns | 5.30x | 78 (1.6%) |
| `loop parameter` | 9.093ns | 15.331ns | 26.251ns | 15.385ns | 1.400ns | 1.00x | 68 (1.4%) |
| `#table+1` | 45.299ns | 68.231ns | 151.660ns | 68.539ns | 5.380ns | 4.45x | 64 (1.3%) |
| `table.n` | 29.290ns | 46.542ns | 69.703ns | 47.104ns | 4.327ns | 3.04x | 60 (1.2%) |
| `table[0]` | 28.463ns | 47.238ns | 76.872ns | 48.296ns | 4.555ns | 3.08x | 112 (2.2%) |
| `lockstep parameter` | 12.090ns | 19.157ns | 30.832ns | 19.489ns | 1.916ns | 1.25x | 61 (1.2%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `table.insert (global)` | 4.879ns | 93.137ns | 261.021ns | 93.903ns | 12.421ns | 6.50x | 55 (1.1%) |
| `table.insert (local)` | 5.426ns | 81.772ns | 138.121ns | 82.606ns | 10.856ns | 5.71x | 60 (1.2%) |
| `loop parameter` | 3.939ns | 14.318ns | 37.312ns | 14.570ns | 2.156ns | 1.00x | 83 (1.7%) |
| `#table+1` | 24.366ns | 65.924ns | 105.732ns | 66.655ns | 8.172ns | 4.60x | 67 (1.3%) |
| `table.n` | 3.876ns | 45.421ns | 75.689ns | 45.813ns | 5.992ns | 3.17x | 63 (1.3%) |
| `table[0]` | 3.674ns | 64.578ns | 161.817ns | 65.361ns | 8.398ns | 4.51x | 53 (1.1%) |
| `lockstep parameter` | 3.545ns | 18.134ns | 36.013ns | 18.432ns | 2.727ns | 1.27x | 65 (1.3%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `table.insert (global)` | 7.690ns | 83.888ns | 143.169ns | 84.540ns | 11.088ns | 5.57x | 60 (1.2%) |
| `table.insert (local)` | 4.181ns | 85.096ns | 145.309ns | 87.108ns | 14.509ns | 5.65x | 32 (0.6%) |
| `loop parameter` | \* | 15.053ns | 51.079ns | 15.089ns | 2.788ns | 1.00x | 16 (0.3%) |
| `#table+1` | 28.860ns | 79.362ns | 197.721ns | 78.771ns | 12.269ns | 5.27x | 33 (0.7%) |
| `table.n` | 13.456ns | 35.053ns | 67.116ns | 35.849ns | 7.334ns | 2.33x | 37 (0.7%) |
| `table[0]` | 1.851ns | 44.972ns | 156.681ns | 44.240ns | 7.760ns | 2.99x | 10 (0.2%) |
| `lockstep parameter` | 3.473ns | 16.674ns | 30.507ns | 17.311ns | 3.305ns | 1.11x | 49 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `table.insert (global)` | 0.323ns | 50.882ns | 292.888ns | 52.833ns | 11.405ns | 5.46x | 11 (0.2%) |
| `table.insert (local)` | 2.604ns | 49.090ns | 75.855ns | 49.097ns | 9.885ns | 5.27x | 6 (0.1%) |
| `loop parameter` | 1.045ns | 9.322ns | 36.382ns | 9.764ns | 2.118ns | 1.00x | 52 (1.0%) |
| `#table+1` | 1.898ns | 24.169ns | 43.149ns | 23.796ns | 5.203ns | 2.59x | 4 (0.1%) |
| `table.n` | 8.913ns | 23.905ns | 71.956ns | 24.503ns | 4.104ns | 2.56x | 60 (1.2%) |
| `table[0]` | 0.705ns | 39.978ns | 61.856ns | 39.081ns | 7.133ns | 4.29x | 11 (0.2%) |
| `lockstep parameter` | 1.335ns | 11.601ns | 61.064ns | 11.873ns | 2.187ns | 1.24x | 51 (1.0%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `table.insert (global)` | 28.597ns | 46.591ns | 191.669ns | 47.579ns | 5.600ns | 7.05x | 49 (1.0%) |
| `table.insert (local)` | 19.992ns | 38.390ns | 55.683ns | 38.828ns | 3.963ns | 5.81x | 68 (1.4%) |
| `loop parameter` | 3.407ns | 6.604ns | 12.143ns | 6.632ns | 0.805ns | 1.00x | 62 (1.2%) |
| `#table+1` | 6.613ns | 15.519ns | 25.361ns | 15.814ns | 1.568ns | 2.35x | 94 (1.9%) |
| `table.n` | 0.653ns | 25.763ns | 90.528ns | 26.160ns | 2.889ns | 3.90x | 48 (1.0%) |
| `table[0]` | 20.353ns | 30.344ns | 45.573ns | 30.424ns | 2.462ns | 4.59x | 58 (1.2%) |
| `lockstep parameter` | 5.336ns | 8.668ns | 15.526ns | 8.723ns | 0.910ns | 1.31x | 41 (0.8%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `table.insert (global)` | 1.758ns | 3.813ns | 7.067ns | 3.847ns | 0.353ns | 1.94x | 85 (1.7%) |
| `table.insert (local)` | 2.253ns | 3.941ns | 7.820ns | 4.002ns | 0.415ns | 2.01x | 52 (1.0%) |
| `loop parameter` | 0.408ns | 1.962ns | 3.656ns | 1.999ns | 0.249ns | 1.00x | 61 (1.2%) |
| `#table+1` | 2.044ns | 3.903ns | 9.043ns | 3.942ns | 0.405ns | 1.99x | 61 (1.2%) |
| `table.n` | 1.956ns | 2.831ns | 5.202ns | 2.870ns | 0.313ns | 1.44x | 44 (0.9%) |
| `table[0]` | 2.835ns | 4.792ns | 8.138ns | 4.857ns | 0.467ns | 2.44x | 66 (1.3%) |
| `lockstep parameter` | 1.716ns | 2.831ns | 5.194ns | 2.885ns | 0.331ns | 1.44x | 55 (1.1%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `table.insert (global)` | 19.900ns | 58.453ns | 96.422ns | 58.701ns | 6.291ns | 5.10x | 39 (0.8%) |
| `table.insert (local)` | 4.714ns | 54.250ns | 89.622ns | 54.748ns | 6.349ns | 4.73x | 45 (0.9%) |
| `loop parameter` | 1.263ns | 11.458ns | 19.959ns | 11.676ns | 1.259ns | 1.00x | 45 (0.9%) |
| `#table+1` | 26.987ns | 49.325ns | 112.139ns | 49.684ns | 5.639ns | 4.30x | 44 (0.9%) |
| `table.n` | 7.843ns | 28.167ns | 44.590ns | 28.701ns | 2.851ns | 2.46x | 43 (0.9%) |
| `table[0]` | 1.886ns | 26.387ns | 42.092ns | 26.610ns | 2.666ns | 2.30x | 55 (1.1%) |
| `lockstep parameter` | 2.506ns | 14.293ns | 22.267ns | 14.557ns | 2.054ns | 1.25x | 19 (0.4%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `table.insert (global)` |  86.575ns  |  93.137ns  |  83.888ns  |  50.882ns  |  46.591ns  |  3.813ns  |  58.453ns  |
| `table.insert (local)` |  81.292ns  |  81.772ns  |  85.096ns  |  49.090ns  |  38.390ns  |  3.941ns  |  54.250ns  |
| `loop parameter` |  **15.331ns**  |  **14.318ns**  |  **15.053ns**  |  **9.322ns**  |  **6.604ns**  |  **1.962ns**  |  **11.458ns**  |
| `#table+1` |  68.231ns  |  65.924ns  |  79.362ns  |  24.169ns  |  15.519ns  |  3.903ns  |  49.325ns  |
| `table.n` |  46.542ns  |  45.421ns  |  35.053ns  |  23.905ns  |  25.763ns  |  2.831ns  |  28.167ns  |
| `table[0]` |  47.238ns  |  64.578ns  |  44.972ns  |  39.978ns  |  30.344ns  |  4.792ns  |  26.387ns  |
| `lockstep parameter` |  19.157ns  |  18.134ns  |  16.674ns  |  11.601ns  |  8.668ns  |  2.831ns  |  14.293ns  |

## table slice

#### One-Time Setup

```lua
local unpack = unpack or table.unpack
local a = {}
for i = 1, 2000 do
	a[i] = i
end
local x, y = 500, 1500
local tnew = table.new or table.create
```

| Test | Code |
| ----:| ---- |
| `unpack` | `out = {unpack(a, x, y)}` |
| `from scratch` | `out = {}; for i = x, y do out[i - x + 1] = a[i] end` |
| `table.new` | `out = tnew(y - x, 0); for i = x, y do out[i - x + 1] = a[i] end` |
| `table.move` | `out = {}; table.move(a, x, y, 1, out)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `unpack` | 71.397ns | 7.533µs | 13.638µs | 7.706µs | 1.112µs | 1.00x | 67 (1.3%) |
| `from scratch` | 20.014µs | 38.547µs | 154.647µs | 39.292µs | 3.969µs | 5.12x | 53 (1.1%) |
| `table.new` | - | - | - | - | - | - | - |
| `table.move` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `unpack` | 1.911µs | 8.039µs | 14.677µs | 8.161µs | 1.175µs | 1.00x | 61 (1.2%) |
| `from scratch` | 10.886µs | 38.487µs | 60.035µs | 39.068µs | 3.449µs | 4.79x | 97 (1.9%) |
| `table.new` | - | - | - | - | - | - | - |
| `table.move` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `unpack` | 805.391ns | 8.442µs | 30.267µs | 8.819µs | 1.752µs | 1.00x | 16 (0.3%) |
| `from scratch` | 14.513µs | 33.087µs | 51.076µs | 33.794µs | 4.504µs | 3.92x | 17 (0.3%) |
| `table.new` | - | - | - | - | - | - | - |
| `table.move` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `unpack` | 213.444ns | 6.365µs | 14.871µs | 6.629µs | 1.259µs | 1.00x | 75 (1.5%) |
| `from scratch` | 10.491µs | 22.297µs | 45.562µs | 22.771µs | 3.058µs | 3.50x | 101 (2.0%) |
| `table.new` | - | - | - | - | - | - | - |
| `table.move` | 2.204µs | 13.793µs | 71.109µs | 13.983µs | 2.135µs | 2.17x | 43 (0.9%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `unpack` | 24.159ns | 5.914µs | 19.991µs | 6.008µs | 841.474ns | 1.00x | 65 (1.3%) |
| `from scratch` | 615.542ns | 18.491µs | 40.724µs | 18.767µs | 2.091µs | 3.13x | 67 (1.3%) |
| `table.new` | 5.896µs | 17.888µs | 33.321µs | 18.104µs | 1.948µs | 3.02x | 43 (0.9%) |
| `table.move` | 879.820ns | 10.251µs | 21.107µs | 10.388µs | 1.353µs | 1.73x | 61 (1.2%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `unpack` | 1.566µs | 2.749µs | 4.822µs | 2.792µs | 256.552ns | 1.05x | 75 (1.5%) |
| `from scratch` | 1.628µs | 2.811µs | 4.818µs | 2.847µs | 275.805ns | 1.07x | 73 (1.5%) |
| `table.new` | 1.445µs | 2.624µs | 4.836µs | 2.710µs | 403.234ns | 1.00x | 32 (0.6%) |
| `table.move` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `unpack` | 1.739µs | 2.776µs | 4.691µs | 2.842µs | 387.873ns | 1.00x | 32 (0.6%) |
| `from scratch` | 3.661µs | 16.040µs | 26.761µs | 16.264µs | 1.850µs | 5.78x | 34 (0.7%) |
| `table.new` | 4.212µs | 13.603µs | 22.777µs | 13.746µs | 1.674µs | 4.90x | 40 (0.8%) |
| `table.move` | - | - | - | - | - | - | - |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `unpack` |  **7.533µs**  |  **8.039µs**  |  **8.442µs**  |  **6.365µs**  |  **5.914µs**  |  **2.749µs**  |  **2.776µs**  |
| `from scratch` |  38.547µs  |  38.487µs  |  33.087µs  |  22.297µs  |  18.491µs  |  **2.811µs**  |  16.040µs  |
| `table.new` |  -  |  -  |  -  |  -  |  17.888µs  |  **2.624µs**  |  13.603µs  |
| `table.move` |  -  |  -  |  -  |  13.793µs  |  10.251µs  |  -  |  -  |

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
| ----:| ---- |
| `argument expanision` | `local a1, a2, a3, a4 = a[1], a[2], a[3], a[4]` |
| `unpack` | `local a1, a2, a3, a4 = unpack(a)` |
| `function` | `local a1, a2, a3, a4 = unpack4(a)` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 5.194ns | 46.359ns | 81.248ns | 46.781ns | 5.905ns | 1.00x | 52 (1.0%) |
| `unpack` | 5.561ns | 50.558ns | 212.664ns | 50.943ns | 7.122ns | 1.09x | 42 (0.8%) |
| `function` | 29.611ns | 58.092ns | 101.799ns | 58.601ns | 7.276ns | 1.25x | 62 (1.2%) |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 10.840ns | 53.089ns | 88.486ns | 53.484ns | 6.933ns | 1.00x | 47 (0.9%) |
| `unpack` | 9.393ns | 58.630ns | 98.725ns | 58.908ns | 8.132ns | 1.10x | 53 (1.1%) |
| `function` | 12.211ns | 88.481ns | 242.066ns | 89.821ns | 12.973ns | 1.67x | 40 (0.8%) |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 4.498ns | 25.962ns | 42.195ns | 26.438ns | 4.424ns | 1.00x | 9 (0.2%) |
| `unpack` | 25.727ns | 54.838ns | 340.570ns | 56.529ns | 10.271ns | 2.11x | 8 (0.2%) |
| `function` | 6.578ns | 41.962ns | 72.080ns | 42.844ns | 6.662ns | 1.62x | 32 (0.6%) |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 0.329ns | 18.641ns | 67.185ns | 18.828ns | 2.677ns | 1.00x | 45 (0.9%) |
| `unpack` | 16.974ns | 49.689ns | 83.964ns | 50.222ns | 6.694ns | 2.67x | 63 (1.3%) |
| `function` | \* | 31.148ns | 51.552ns | 31.289ns | 3.726ns | 1.67x | 61 (1.2%) |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 5.906ns | 16.648ns | 122.484ns | 16.813ns | 2.555ns | 1.00x | 22 (0.4%) |
| `unpack` | 19.203ns | 50.253ns | 130.063ns | 50.672ns | 6.572ns | 3.02x | 50 (1.0%) |
| `function` | 3.130ns | 31.400ns | 52.795ns | 31.666ns | 4.137ns | 1.89x | 50 (1.0%) |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | \* | \* | 0.459ns | \* | 0.021ns | 1.00x | 106 (2.1%) |
| `unpack` | 16.944ns | 27.970ns | 47.342ns | 28.053ns | 1.980ns | 105.50x | 86 (1.7%) |
| `function` | \* | \* | 0.458ns | \* | 0.024ns | 1.00x | 113 (2.3%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `argument expanision` | 1.508ns | 12.523ns | 45.272ns | 12.661ns | 1.661ns | 1.00x | 35 (0.7%) |
| `unpack` | 5.606ns | 20.528ns | 97.007ns | 20.704ns | 2.727ns | 1.64x | 18 (0.4%) |
| `function` | 7.968ns | 19.359ns | 32.196ns | 19.440ns | 2.199ns | 1.55x | 51 (1.0%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `argument expanision` |  **46.359ns**  |  **53.089ns**  |  **25.962ns**  |  **18.641ns**  |  **16.648ns**  |  **\***  |  **12.523ns**  |
| `unpack` |  **50.558ns**  |  58.630ns  |  54.838ns  |  49.689ns  |  50.253ns  |  27.970ns  |  20.528ns  |
| `function` |  58.092ns  |  88.481ns  |  41.962ns  |  31.148ns  |  31.400ns  |  **\***  |  19.359ns  |

## table.new

#### One-Time Setup

```lua
local tnew = table.new or table.create
```

| Test | Code |
| ----:| ---- |
| `literal` | `out = {1, 2, 3}` |
| `start empty` | `out = {}; out[1] = 1; out[2] = 2; out[3] = 3` |
| `start false` | `out = {false, false, false}; out[1] = 1; out[2] = 2; out[3] = 3` |
| `preallocate` | `out = tnew(3, 0); out[1] = 1; out[2] = 2; out[3] = 3` |
| `ffi fill` | `out = ffi.new("int[3]", 1, 2, 3)` |
| `ffi individual` | `out = ffi.new("int[3]"); out[0] = 1; out[1] = 2; out[2] = 3` |
<details>
<summary>
<b>Lua 5.1</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `literal` | 3.734ns | 70.010ns | 392.217ns | 73.448ns | 14.873ns | 1.00x | 27 (0.5%) |
| `start empty` | 185.188ns | 284.816ns | 468.452ns | 290.196ns | 32.104ns | 4.07x | 64 (1.3%) |
| `start false` | 75.510ns | 136.332ns | 258.622ns | 138.819ns | 17.352ns | 1.95x | 15 (0.3%) |
| `preallocate` | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.2</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `literal` | 37.454ns | 70.923ns | 119.858ns | 72.740ns | 9.156ns | 1.00x | 53 (1.1%) |
| `start empty` | 167.600ns | 280.024ns | 471.529ns | 283.444ns | 28.529ns | 3.95x | 60 (1.2%) |
| `start false` | 80.986ns | 134.003ns | 227.561ns | 136.895ns | 14.319ns | 1.89x | 56 (1.1%) |
| `preallocate` | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.3</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `literal` | 39.707ns | 73.665ns | 268.089ns | 75.615ns | 10.463ns | 1.00x | 31 (0.6%) |
| `start empty` | 146.447ns | 280.911ns | 453.629ns | 288.359ns | 36.455ns | 3.81x | 32 (0.6%) |
| `start false` | 62.163ns | 98.765ns | 167.186ns | 101.705ns | 13.028ns | 1.34x | 28 (0.6%) |
| `preallocate` | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.4</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `literal` | 32.385ns | 60.034ns | 103.114ns | 61.097ns | 7.842ns | 1.00x | 71 (1.4%) |
| `start empty` | 45.150ns | 256.476ns | 542.390ns | 259.228ns | 31.188ns | 4.27x | 53 (1.1%) |
| `start false` | 39.149ns | 69.976ns | 113.879ns | 71.890ns | 8.710ns | 1.17x | 51 (1.0%) |
| `preallocate` | - | - | - | - | - | - | - |
| `ffi fill` | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>Lua 5.5</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `literal` | 7.293ns | 59.550ns | 219.597ns | 60.627ns | 5.931ns | 1.00x | 46 (0.9%) |
| `start empty` | 95.018ns | 231.929ns | 803.850ns | 239.120ns | 26.452ns | 3.89x | 45 (0.9%) |
| `start false` | 47.929ns | 71.668ns | 200.070ns | 73.160ns | 7.354ns | 1.20x | 41 (0.8%) |
| `preallocate` | 49.344ns | 88.285ns | 130.019ns | 90.587ns | 9.892ns | 1.48x | 22 (0.4%) |
| `ffi fill` | - | - | - | - | - | - | - |
| `ffi individual` | - | - | - | - | - | - | - |

</details>
<details>
<summary>
<b>LuaJIT</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `literal` | \* | \* | 0.423ns | \* | 0.021ns | 1.02x | 72 (1.4%) |
| `start empty` | 21.106ns | 108.463ns | 165.632ns | 111.152ns | 10.768ns | 406.32x | 74 (1.5%) |
| `start false` | \* | \* | 0.469ns | \* | 0.039ns | 1.09x | 32 (0.6%) |
| `preallocate` | \* | \* | 0.918ns | 0.304ns | 0.053ns | 1.11x | 51 (1.0%) |
| `ffi fill` | \* | \* | 0.951ns | \* | 0.030ns | 1.00x | 73 (1.5%) |
| `ffi individual` | \* | \* | 0.554ns | \* | 0.028ns | 1.01x | 67 (1.3%) |

</details>
<details>
<summary>
<b>LuaJIT (Interpreter)</b>
</summary>

| Test | Min | Median | Max | Mean | Stddev | Cost | Outliers |
| ----:|:---:|:------:|:---:|:----:|:------:|:----:|:--------:|
| `literal` | 10.864ns | 26.159ns | 58.175ns | 26.596ns | 3.829ns | 1.00x | 51 (1.0%) |
| `start empty` | 92.598ns | 153.926ns | 242.229ns | 155.963ns | 19.626ns | 5.88x | 13 (0.3%) |
| `start false` | 15.444ns | 30.413ns | 93.222ns | 31.758ns | 5.185ns | 1.16x | 36 (0.7%) |
| `preallocate` | 19.947ns | 40.266ns | 81.215ns | 41.793ns | 5.804ns | 1.54x | 28 (0.6%) |
| `ffi fill` | 28.567ns | 246.024ns | 684.983ns | 250.357ns | 34.619ns | 9.41x | 18 (0.4%) |
| `ffi individual` | 28.645ns | 337.080ns | 576.303ns | 343.818ns | 42.563ns | 12.89x | 25 (0.5%) |

</details>

#### Median Time

| Test | Lua 5.1 | Lua 5.2 | Lua 5.3 | Lua 5.4 | Lua 5.5 | LuaJIT | LuaJIT (Interpreter) |
| - | - | - | - | - | - | - | - |
| `literal` |  **70.010ns**  |  **70.923ns**  |  **73.665ns**  |  **60.034ns**  |  **59.550ns**  |  **\***  |  **26.159ns**  |
| `start empty` |  284.816ns  |  280.024ns  |  280.911ns  |  256.476ns  |  231.929ns  |  108.463ns  |  153.926ns  |
| `start false` |  136.332ns  |  134.003ns  |  98.765ns  |  69.976ns  |  71.668ns  |  **\***  |  30.413ns  |
| `preallocate` |  -  |  -  |  -  |  -  |  88.285ns  |  \*  |  40.266ns  |
| `ffi fill` |  -  |  -  |  -  |  -  |  -  |  **\***  |  246.024ns  |
| `ffi individual` |  -  |  -  |  -  |  -  |  -  |  **\***  |  337.080ns  |

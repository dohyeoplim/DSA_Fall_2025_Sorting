### DSA Fall 2025

Sorting

---

```plaintext
.
├── bench.sh        # generate benchmarks for all algorithms and sizes
├── build.sh        # build the C sources
├── plot/           # Python scripts for plotting benchmark results
├── report/         # LaTeX report
├── src/            # C source code: sort.c, util.c, main.c, headers
└── report.pdf
```

#### Build
```bash
./build.sh
```

#### Run Benchmarks
```bash
./bench.sh > bench/bench_result_base.csv
```

#### Plot Results
```bash
uv run plot/main.py
```

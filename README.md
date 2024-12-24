# libpq

Statically compiled `libpq` target for bazel to be used with [llvm_toolchain](https://github.com/bazel-contrib/toolchains_llvm) for 64-bit platforms.


### For rules_rust (typically pq-sys for diesel) (Bazel 8):
```
crate.annotation(
    build_script_env = {
        "PQ_LIB_STATIC": "1",
    },
    compile_data = ["@@libpq+//:libpq"],
    crate = "pq-sys",
    rustc_flags = [
        "-L",
        "$(BINDIR)/external/libpq+",
    ],
)
```
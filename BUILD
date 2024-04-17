exports_files(
    glob(["**"]),
    visibility = ["//visibility:public"],
)

genrule(
    name = "pg_config",
    srcs = [
        "@postgres//:pg_config.linux.h",
        "@postgres//:pg_config.macos.h",
    ],
    outs = ["pg_config.h"],
    cmd = select({
        "@platforms//os:osx": "cp $(location @postgres//:pg_config.macos.h) $@",
        "@platforms//os:linux": "cp $(location @postgres//:pg_config.linux.h) $@",
        "//conditions:default": "@platforms//:incompatible",
    }),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "headers",
    srcs = glob([
        "src/include/**/*.h",
        "src/interfaces/libpq/*.h",
    ]) + ["src/port/pg_config_paths.h"],
    includes = [
        "src/include",
        "src/interfaces/libpq",
        "src/port",
    ],
    visibility = ["//visibility:public"],
)

alias(
    name = "libpq",
    actual = ":pq",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "pq",
    srcs = [
        ":pg_config",
        "@postgres//:src/interfaces/libpq/fe-auth.c",
        "@postgres//:src/interfaces/libpq/fe-auth-scram.c",
        "@postgres//:src/interfaces/libpq/fe-connect.c",
        "@postgres//:src/interfaces/libpq/fe-exec.c",
        "@postgres//:src/interfaces/libpq/fe-lobj.c",
        "@postgres//:src/interfaces/libpq/fe-misc.c",
        "@postgres//:src/interfaces/libpq/fe-print.c",
        "@postgres//:src/interfaces/libpq/fe-protocol3.c",
        "@postgres//:src/interfaces/libpq/fe-secure.c",
        "@postgres//:src/interfaces/libpq/fe-secure-common.c",
        "@postgres//:src/interfaces/libpq/fe-trace.c",
        "@postgres//:src/interfaces/libpq/legacy-pqsignal.c",
        "@postgres//:src/interfaces/libpq/libpq-events.c",
        "@postgres//:src/interfaces/libpq/pqexpbuffer.c",
    ],
    hdrs = ["@postgres//:src/interfaces/libpq/libpq-fe.h"],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = ["@postgres//:headers"],
)

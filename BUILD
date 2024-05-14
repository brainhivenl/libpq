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
        "src/common/**/*.h",
        "src/include/**/*.h",
        "src/interfaces/libpq/*.h",
    ]) + ["src/port/pg_config_paths.h"],
    includes = [
        "src/common",
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
        "@postgres//:src/common/base64.c",
        "@postgres//:src/common/cryptohash.c",
        "@postgres//:src/common/encnames.c",
        "@postgres//:src/common/hmac.c",
        "@postgres//:src/common/ip.c",
        "@postgres//:src/common/link-canary.c",
        "@postgres//:src/common/md5.c",
        "@postgres//:src/common/md5_common.c",
        "@postgres//:src/common/pg_prng.c",
        "@postgres//:src/common/saslprep.c",
        "@postgres//:src/common/scram-common.c",
        "@postgres//:src/common/sha1.c",
        "@postgres//:src/common/sha2.c",
        "@postgres//:src/common/string.c",
        "@postgres//:src/common/unicode_norm.c",
        "@postgres//:src/common/wchar.c",
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
        "@postgres//:src/port/chklocale.c",
        "@postgres//:src/port/explicit_bzero.c",
        "@postgres//:src/port/inet_net_ntop.c",
        "@postgres//:src/port/noblock.c",
        "@postgres//:src/port/pg_strong_random.c",
        "@postgres//:src/port/pgstrcasecmp.c",
        "@postgres//:src/port/snprintf.c",
        "@postgres//:src/port/strerror.c",
        "@postgres//:src/port/thread.c",
    ] + select({
        "@platforms//os:linux": [
            "@libpq//:getpeereid.linux.c",
            "@postgres//:src/port/strlcat.c",
            "@postgres//:src/port/strlcpy.c",
        ],
        "//conditions:default": [],
    }),
    defines = [
        "FRONTEND",
        "HAVE_STRERROR_R",
        "STRERROR_R_INT",
    ],
    hdrs = ["@postgres//:src/interfaces/libpq/libpq-fe.h"],
    linkstatic = True,
    visibility = ["//visibility:public"],
    deps = ["@postgres//:headers"],
)

load("//bazel:rules.bzl", "pme_cc_binary", "pme_cc_library")

exports_files(
    [".clang-tidy"],
    visibility = ["//:__subpackages__"],
)

load(
    "@local_config//:defs.bzl",
    "PROJECT_DEFAULT_COPTS",
)

filegroup(
    name = "headers",
    srcs = [
        "src/person.hpp",
        "src/resource.hpp",
        "src/job.hpp",
        "src/location.hpp",
    ],
    visibility = ["@mcss//:__pkg__"],
)


pme_cc_library(
    name = "pme_lib",
    hdrs = [":headers"],
    visibility = ["//visibility:public"],
)

pme_cc_binary(
    name = "pme",
    srcs = ["src/main.cpp"],
    deps = [":pme_lib",],
    visibility = ["//visibility:public"],
)

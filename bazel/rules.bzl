load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load(
    "@local_config//:defs.bzl",
    "PROJECT_DEFAULT_COPTS",
)

def pme_cc_binary(**kwargs):
    cc_binary(
        **kwargs
    )

def pme_cc_library(**kwargs):
    cc_library(
        copts = PROJECT_DEFAULT_COPTS,
        **kwargs
    )

def pme_cc_test(name, **kwargs):
    full_deps = [
        "//:pme",
        "@ut",
    ]

    if "deps" in kwargs:
        full_deps = full_deps + kwargs.deps

    if "srcs" in kwargs:
        test_srcs = kwargs.srcs
    else:
        test_srcs = [name + "_test.cpp"]

    cc_test(
        name = name,
        srcs = test_srcs,
        copts = PROJECT_DEFAULT_COPTS,
        deps = full_deps,
        **kwargs
    )


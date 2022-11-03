load("@pip_requirements//:requirements.bzl", "requirement")
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")

package(default_visibility = ["//visibility:public"])

py_library(
    name = "slowdown",
    srcs = ["__init__.py"],
    data = [":slowdown_envpool.so"],
    deps = ["//envpool/python:api"],
)

py_library(
    name = "slowdown_registration",
    srcs = ["registration.py"],
    deps = ["//envpool:registration"],
)

pybind_extension(
    name = "slowdown_envpool",
    srcs = ["slowdown_envpool.cc", "slowdown_envpool.h"],
    linkopts = ["-ldl"],
    deps = [
        "//envpool/core:async_envpool",
        "//envpool/core:env",
        "//envpool/core:env_spec",
        "//envpool/core:py_envpool",
    ],
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

gtest_version = "release-1.11.0"

# Fetch gtest
# see https://google.github.io/googletest/quickstart-bazel.html
http_archive(
  name = "com_google_googletest",
  urls = [
      "https://github.com/google/googletest/archive/" + gtest_version + ".zip"],
  strip_prefix = "googletest-" + gtest_version,
)

# Bazel needs a dependency on rules_cc repo (enrlov: isn't this built in?)
# see https://google.github.io/googletest/quickstart-bazel.html
http_archive(
  name = "rules_cc",
  urls = ["https://github.com/bazelbuild/rules_cc/archive/40548a2974f1aea06215272d9c2b47a14a24e556.zip"],
  strip_prefix = "rules_cc-40548a2974f1aea06215272d9c2b47a14a24e556",
)

http_archive(
    name = "sfml",
    urls = [
        "https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz",
    ],
    sha256 = "34ad106e4592d2ec03245db5e8ad8fbf85c256d6ef9e337e8cf5c4345dc583dd",
    build_file = "BUILD.sfml",
)
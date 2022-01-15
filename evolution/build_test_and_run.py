#!/usr/bin/env python3
import click
import subprocess


@click.command()
@click.option(
    "--tout/--no-tout",
    #type=click.Bool,
    required=False,
    help="Shot test output"
)

def run(tout):

    test_cmd = ["bazel", "test", "//..."]
    if tout:
        test_cmd += ["--test_output=all"]
    cmds = [
        ["clear"],
        ["bazel", "build", "//..."],
        test_cmd,
        ["./bazel-bin/evolution"]
    ]

    for cmd in cmds:
        process = subprocess.call(cmd)
        if process != 0:
            break

if __name__ == "__main__":
    run()


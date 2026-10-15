#!/usr/bin/env bash
export JAVA_HOME="$HOME/.local/jdk21"
exec /opt/ghidra/ghidraRun "$@"

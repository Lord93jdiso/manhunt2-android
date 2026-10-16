#!/usr/bin/env bash
# Запуск GhidraMCP headless-сервера (автоанализ без GUI) на 127.0.0.1:8089
# Класс-путь по образцу docker/entrypoint.sh из ghidra-mcp
set -e
export JAVA_HOME="$HOME/.local/jdk21"
GH="${GHIDRA_INSTALL_DIR:-/opt/ghidra}"
HERE="$(cd "$(dirname "$0")" && pwd)"

JAR=""
for j in "$HERE"/ghidra-mcp/build/libs/GhidraMCP-*.jar "$HERE"/ghidra-mcp/target/GhidraMCP-*.jar; do
  case "$j" in *sources*|*javadoc*|*tests*) continue;; esac
  if [ -f "$j" ]; then JAR="$j"; break; fi
done
if [ -z "$JAR" ]; then
  echo "НЕ найден GhidraMCP jar — сначала соберите расширение:"
  echo "  cd $HERE/ghidra-mcp && JAVA_HOME=\$HOME/.local/jdk21 \\"
  echo "    ./gradlew buildExtension -PGHIDRA_INSTALL_DIR=$GH"
  exit 1
fi

CP="$JAR"
for d in "$GH"/Ghidra/Framework/*/lib "$GH"/Ghidra/Features/*/lib "$GH"/Ghidra/Processors/*/lib; do
  for jar in "$d"/*.jar; do [ -f "$jar" ] && CP="$CP:$jar"; done
done
for jar in "$HERE"/ghidra-mcp/target/lib/*.jar "$HERE"/ghidra-mcp/lib/*.jar; do
  [ -f "$jar" ] && CP="$CP:$jar"
done

echo "GhidraMCP headless → http://127.0.0.1:8089 (jar: $JAR)"
exec "$JAVA_HOME/bin/java" -Xmx3g \
  -Dghidra.home="$GH" -Dapplication.name=GhidraMCP \
  -classpath "$CP" \
  com.xebyte.headless.GhidraMCPHeadlessServer --bind 127.0.0.1 --port 8089 "$@"

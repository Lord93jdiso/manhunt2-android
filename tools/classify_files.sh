#!/usr/bin/env bash
# Классификация файлов игры по магическим байтам.
# usage: classify_files.sh [<dir>]
# По-умолчанию — каталог распакованных PC-файлов Manhunt 2.
ROOT="${1:-/home/artemiy/manhunt2-port/pc/Manhunt_2_Win_Files_EN/Game Files}"

declare -A S
while IFS= read -r -d '' f; do
  e="${f##*.}"; e="$(echo "$e" | tr 'A-Z' 'a-z')"
  if [ -z "${S[$e]+set}" ]; then S[$e]="$f"; fi
done < <(find "$ROOT" -type f -print0 2>/dev/null)

for e in $(printf '%s\n' "${!S[@]}" | sort); do
  f="${S[$e]}"
  printf '\n===== .%s  [%s]\n' "$e" "${f#"$ROOT"/}"
  file -b "$f" | head -1
  if command -v xxd >/dev/null 2>&1; then
    head -c 96 "$f" | xxd -g 1 | head -6
  else
    head -c 96 "$f" | hexdump -C | head -6
  fi
done

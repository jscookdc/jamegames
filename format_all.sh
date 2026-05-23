#!/usr/bin/env bash
# I had Claude generate this one, idk
# Format all C/C++ source files tracked by git using clang-format.

set -euo pipefail

# Pin the version to match the Dockerfile / CI.
CLANG_FORMAT="${CLANG_FORMAT:-clang-format-18}"

# Verify the tool is available.
if ! command -v "$CLANG_FORMAT" >/dev/null 2>&1; then
  echo "Error: $CLANG_FORMAT not found in PATH" >&2
  exit 1
fi

# Run from the repo root so git ls-files works correctly regardless of CWD.
cd "$(git rev-parse --show-toplevel)"

# Collect tracked C/C++ files.
mapfile -t FILES < <(git ls-files '*.cpp' '*.h' '*.hpp' '*.cc' '*.cxx' '*.c')

if [[ ${#FILES[@]} -eq 0 ]]; then
  echo "No C/C++ files found."
  exit 0
fi

# Optional flags: --check for dry-run, --verbose for file-by-file output.
MODE="format"
VERBOSE=0
for arg in "$@"; do
  case "$arg" in
    --check)   MODE="check" ;;
    --verbose) VERBOSE=1 ;;
    -h|--help)
      echo "Usage: $0 [--check] [--verbose]"
      echo "  --check    Don't modify files; exit non-zero if any would change."
      echo "  --verbose  Print each file as it's processed."
      exit 0
      ;;
    *) echo "Unknown option: $arg" >&2; exit 1 ;;
  esac
done

if [[ "$MODE" == "check" ]]; then
  echo "Checking ${#FILES[@]} files with $CLANG_FORMAT..."
  "$CLANG_FORMAT" --dry-run --Werror "${FILES[@]}"
  echo "All files are properly formatted."
else
  echo "Formatting ${#FILES[@]} files with $CLANG_FORMAT..."
  if [[ "$VERBOSE" -eq 1 ]]; then
    for f in "${FILES[@]}"; do
      echo "  $f"
      "$CLANG_FORMAT" -i "$f"
    done
  else
    "$CLANG_FORMAT" -i "${FILES[@]}"
  fi
  echo "Done."
fi
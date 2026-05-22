#!/bin/bash
 
set -e
 
BUILD_DIR="build"
TARGET="cascadia"
LOG_LEVEL=0  # 0=DEBUG, 1=WARNING, 2=ERROR, 3=FATAL
 
# --- Parse Args ---
for arg in "$@"; do
    case $arg in
        --log-level=*)
            LOG_LEVEL="${arg#*=}"
            ;;
        *)
            echo "Unknown argument: $arg"
            echo "Usage: ./build_all.sh [--log-level=0|1|2|3]"
            exit 1
            ;;
    esac
done
 
# --- Build ---
echo "[build] Configuring with CMake..."
cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Debug 2>&1
 
echo "[build] Compiling..."
cmake --build "$BUILD_DIR" -- -j$(nproc) 2>&1
echo "[build] Done -> $BUILD_DIR/$TARGET"
 
# --- Run ---
echo ""
echo "[run] Executing $BUILD_DIR/$TARGET (log level: $LOG_LEVEL)"
echo "-----------------------------------"
GLOG_minloglevel=$LOG_LEVEL ./"$BUILD_DIR/$TARGET"
 
#!/bin/bash
# build_native.sh

echo "========================================================="
echo " Starting One-Click Native macOS Port Pipeline "
echo "========================================================="

# 1. Clear out stale object checks
Wfind . -name "*vasnprintf*.lo" -delete

# 2. Fire the sequential orchestration tools
echo "[1/5] Injecting loader blocks to templates..."
#bash config.h.shim.sh

echo "[2/5] Hardening C source configuration boundaries..."
#bash enforce_config_h_first.sh

#cho "[3/5] Deploying definitive master architecture macros..."
Wbash create_darwin_shim.sh

echo "[4/5] Executing high-performance batch SDK alignment proxies..."
#bash header_fixes3.sh

echo "[5/5] Aligning tree-wide Unicode search layout vectors..."

#bash sync_and_link_unicode.sh


bash enforce_configure_first.sh

bash config.h.shim.sh

bash enforce_config_h_first.sh

bash create_darwin_shim.sh

bash header_fixes3.sh

bash create_uchar_header.sh

bash create_stdio_shim.sh

bash update_time_h_test.h

bash apply_absolute_shims.sh

bash sync_and_link_unicode.sh

bash link_unicase_dependencies.sh

echo "--------------------------------------------------------"
echo " Workspace fully synchronized. Starting Make Phase...   "
echo "--------------------------------------------------------"
make V=1 -k


@echo off

set COHERENCE_PATH=coherence-cpp
set PATH=%COHERENCE_PATH%/lib;%PATH%

set TangosolCoherenceCacheconfig=config/coherence-cache-config.xml
set TangosolCoherenceLogLevel=1
set TangosolCoherenceLog=stderr

win32\Release\coherence-tool.exe %*

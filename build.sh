COHERENCE_PATH="coherence-cpp"
ARCH=64

CC="g++"
CC_OPTIONS="-Wall -ansi -m${ARCH}"
LIBRARY_PATH=$COHERENCE_PATH/lib
INCLUDE_PATH=$COHERENCE_PATH/include
LIBRARY_OPTIONS="-lcoherence -L${LIBRARY_PATH}"
INCLUDE_OPTIONS="-I${INCLUDE_PATH}"

$CC $CC_OPTIONS $LIBRARY_OPTIONS $INCLUDE_OPTIONS src/coherence-tool.cpp -o bin/coherence-tool

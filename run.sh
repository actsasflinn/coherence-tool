#!/bin/bash

COHERENCE_PATH="/usr/local/libcoherence"
LIBRARY_PATH=$COHERENCE_PATH/lib/

OS=$(uname -s)
if [[ $OS == "Darwin" ]] ; then
  DYLD_LIBRARY_PATH=$LIBRARY_PATH:$DYLD_LIBRARY_PATH
elif [[ $OS == "Linux" ]] ; then
  LD_LIBRARY_PATH=$LIBRARY_PATH:$LD_LIBRARY_PATH
elif [[ $OS == "Sun" ]] ; then
  LD_LIBRARY_PATH=$LIBRARY_PATH:$LD_LIBRARY_PATH
else
  echo "unsupported platform"
fi

TangosolCoherenceLogLevel=1
TangosolCoherenceLog=stderr

./coherence-tool $*

#!/bin/bash

export COHERENCE_PATH="/usr/local/libcoherence"
export LIBRARY_PATH=$COHERENCE_PATH/lib/

export OS=$(uname -s)
if [[ $OS == "Darwin" ]] ; then
  export DYLD_LIBRARY_PATH=$LIBRARY_PATH:$DYLD_LIBRARY_PATH
elif [[ $OS == "Linux" ]] ; then
  export LD_LIBRARY_PATH=$LIBRARY_PATH:$LD_LIBRARY_PATH
elif [[ $OS == "Sun" ]] ; then
  export LD_LIBRARY_PATH=$LIBRARY_PATH:$LD_LIBRARY_PATH
else
  echo "unsupported platform"
fi

export TangosolCoherenceCacheconfig=config/coherence-cache-config.xml
export TangosolCoherenceLogLevel=1
export TangosolCoherenceLog=stderr

bin/coherence-tool $*

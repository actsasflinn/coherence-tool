#!/bin/bash

COHERENCE_PATH="coherence-cpp"
LIBRARY_PATH=$COHERENCE_PATH/lib/

OS=$(uname -s)
if [[ $OS == "Darwin" ]] ; then
  export DYLD_LIBRARY_PATH=$LIBRARY_PATH:$DYLD_LIBRARY_PATH
elif [[ $OS == "Linux" ]] ; then
  export LD_LIBRARY_PATH=$LIBRARY_PATH:$LD_LIBRARY_PATH
elif [[ $OS == "Sun" ]] ; then
  export LD_LIBRARY_PATH=$LIBRARY_PATH:$LD_LIBRARY_PATH
else
  echo "unsupported platform"
fi

export TangosolCoherenceLogLevel=1
export TangosolCoherenceLog=stderr

# There is likely a better way to do this.
args=($@)
if [[ $1 == "-c" ]] ; then
  CONFIG=$2
  args=(${args[@]:2})
else
  CONFIG=config/coherence-cache-config.xml
fi
export TangosolCoherenceCacheconfig=$CONFIG

bin/coherence-tool ${args[*]}

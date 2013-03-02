coherence-tool
==============

A command line utility for debugging and managing Oracle Coherence cache

At the moment the client doesn't have good tests, docs or Makefile.

Use at your own risk.

Setup
-----

Download the Oracle Coherence C++ libraries from OTN
untar/unzip to your preferred location (mine is /usr/local/libcoherence)

1. Edit the build.sh file and specify your COHERENCE_PATH variable to where ever you untarred/unzipped the OTN libraries and specify your ARCH variable as 32 or 64
2. Edit the run.sh file and specify your COHERENCE_PATH variable to where ever you untarred/unzipped the OTN libraries
3. ./build.sh
4. Configure your coherence-cache-config.xml file for your environment

Usage
-----

    ./run.sh <cache-name> get <key1> [key2] ...
    ./run.sh <cache-name> mget
    ./run.sh <cache-name> put <key> <value>
    ./run.sh <cache-name> mput <key1> <value1> [<key2> <value2>] ...
    ./run.sh <cache-name> delete <key> [key2] ...
    ./run.sh <cache-name> size
    ./run.sh <cache-name> keys
    ./run.sh <cache-name> values
    ./run.sh <cache-name> key_exists <key>
    ./run.sh <cache-name> value_exists <value>
    ./run.sh <cache-name> clear

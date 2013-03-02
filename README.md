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

    coherence-tool <cache-name> get <key1> [key2] ...
    coherence-tool <cache-name> mget
    coherence-tool <cache-name> put <key> <value>
    coherence-tool <cache-name> mput <key1> <value1> [<key2> <value2>] ...
    coherence-tool <cache-name> delete <key> [key2] ...
    coherence-tool <cache-name> size
    coherence-tool <cache-name> keys
    coherence-tool <cache-name> values
    coherence-tool <cache-name> key_exists <key>
    coherence-tool <cache-name> value_exists <value>
    coherence-tool <cache-name> clear

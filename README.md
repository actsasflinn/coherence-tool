coherence-tool
==============

A command line utility for debugging and managing Oracle Coherence cache

At the moment the client doesn't have good tests, docs or Makefile.

Use at your own risk.

Linux/Solaris/Mac OS X Setup
----------------------------

Download the Oracle Coherence C++ libraries from OTN
untar/unzip to your preferred location (mine is /usr/local/libcoherence)

1. Edit the build.sh file and specify your COHERENCE_PATH variable to where ever you untarred/unzipped the OTN libraries and specify your ARCH variable as 32 or 64
2. Edit the run.sh file and specify your COHERENCE_PATH variable to where ever you untarred/unzipped the OTN libraries
3. ./build.sh
4. Configure your config/coherence-cache-config.xml file for your environment
5. See usage

Windows Setup
-------------

Download the Oracle Coherence C++ libraries from OTN
unzip and copy the coherence-cpp directory into the project folder

1. Open the solution file and update the VC++ directories to point to your coherence-cpp directories
2. Build the solution
3. Configure your config/coherence-cache-config.xml file for your environment
4. See usage

Usage
-----

    ./run.sh [-c <config-file>] <cache-name> get <key1> [key2] ...
    ./run.sh [-c <config-file>] <cache-name> mget
    ./run.sh [-c <config-file>] <cache-name> put <key> <value>
    ./run.sh [-c <config-file>] <cache-name> mput <key1> <value1> [<key2> <value2>] ...
    ./run.sh [-c <config-file>] <cache-name> delete <key> [key2] ...
    ./run.sh [-c <config-file>] <cache-name> size
    ./run.sh [-c <config-file>] <cache-name> keys
    ./run.sh [-c <config-file>] <cache-name> values
    ./run.sh [-c <config-file>] <cache-name> key_exists <key>
    ./run.sh [-c <config-file>] <cache-name> value_exists <value>
    ./run.sh [-c <config-file>] <cache-name> clear

Examples
--------

    # Use a config file at config/dev.xml
    ./run.sh -c config/dev.xml dist-example put foo bar
    # NULL

    # Using the default config file at config/coherence-cache-config.xml
    ./run.sh dist-example put foo bar
    # NULL

    ./run.sh dist-example get foo
    # bar

    ./run.sh dist-example put foo baz
    # bar

    ./run.sh dist-example put foo bat
    # baz

    ./run.sh dist-example put bar baz
    # NULL

    ./run.sh dist-example put baz bat
    # NULL

    ./run.sh dist-example get foo bar
    # bat
    # bat

    ./run.sh dist-example mget
    # foo:bat
    # baz:bat
    # bar:baz

    ./run.sh dist-example mput baz bax bax ban ban bak

    ./run.sh dist-example mget
    # foo:bat
    # ban:bak
    # baz:bax
    # bar:baz
    # bax:ban

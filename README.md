coherence-tool
==============

A command line utility for debugging and managing Oracle Coherence cache

At the moment the client doesn't have good tests, docs or Makefile.

Use at your own risk.

Linux/Solaris/Mac OS X Setup
----------------------------

Download the Oracle Coherence C++ libraries from OTN
untar/unzip and copy the "coherence-cpp" into this directory

1. Edit the build.sh file and specify your ARCH variable as "32" if needed (default is set to 64)
2. ./build.sh
3. Configure your config/coherence-cache-config.xml file for your environment
4. See usage

Windows Setup
-------------

Download the Oracle Coherence C++ libraries from OTN
unzip and copy the "coherence-cpp" directory into this directory

1. Open the solution file and update the VC++ directories to point to the "coherence-cpp" directory
2. Build the solution
3. Configure your config/coherence-cache-config.xml file for your environment
4. See usage

Usage
-----

    ./run.sh [-c <config-file>] [-s service-name] <cache-name> get <key1> [key2] ...
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> mget
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> put <key> <value>
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> mput <key1> <value1> [<key2> <value2>] ...
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> delete <key> [key2] ...
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> size
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> keys
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> values
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> key_exists <key>
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> value_exists <value>
    ./run.sh [-c <config-file>] [-s service-name] <cache-name> clear

Examples
--------

    # Using the default config file at config/coherence-cache-config.xml
    ./run.sh dist-example get foo
    # <result>

    # Use a specific config file at config/testing.xml (Unix only at the moment)
    ./run.sh -c config/testing.xml dist-example get foo
    # <result>

    # Use a specific service (production)
    # This allows you to enter multiple cache clusters in one config
    ./run.sh -s production dist-example put foo bar
    # <result>

    # Use a specific service (development)
    # This allows you to enter multiple cache clusters in one config
    ./run.sh -s development dist-example get foo
    # <result>

    # Clear the cache
    ./run.sh dist-example clear

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

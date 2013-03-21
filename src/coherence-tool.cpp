#include "coherence/lang.ns"
#include "coherence/util.ns"
#include "coherence/net.ns"
#include "coherence/net/cache.ns"

using namespace coherence::lang;
using namespace coherence::util;
using namespace coherence::net;
using namespace coherence::net::cache;

void usage() {
  std::cerr << "usage:" << std::endl <<
    "coherence-tool <cache-name> get <key1> [key2] [key3]" << std::endl <<
    "coherence-tool <cache-name> mget" << std::endl <<
    "coherence-tool <cache-name> put <key> <value>" << std::endl <<
    "coherence-tool <cache-name> mput <key1> <value1>" <<
      "[<key2> <value2>] [<key3> <value3>]" << std::endl <<
    "coherence-tool <cache-name> delete <key> [key2] [key3]" << std::endl <<
    "coherence-tool <cache-name> size" << std::endl <<
    "coherence-tool <cache-name> keys" << std::endl <<
    "coherence-tool <cache-name> values" << std::endl <<
    "coherence-tool <cache-name> key_exists <key>" << std::endl <<
    "coherence-tool <cache-name> value_exists <value>" << std::endl <<
    "coherence-tool <cache-name> clear" << std::endl
  << std::endl;
}

int main(int argc, char** argv) {
  int res = 0;

  try {
    if (argc > 2) {
      String::View vsCacheName;
      NamedCache::Handle hCache;
      std::string cmd;
      int startArg = 3;

      if ("-s" == (std::string) argv[1]) {
        // Get the service
        String::View vsServiceName = argv[2];
        coherence::net::CacheService::Handle svc = cast<coherence::net::CacheService::Handle>(CacheFactory::getService(vsServiceName));

        // Get the named cache
        vsCacheName = argv[3];
        hCache = svc->ensureCache(vsCacheName);

        // process the command...
        cmd = argv[4];

        startArg = 5;
      } else {
        // Get the named cache
        vsCacheName = argv[1];
        hCache = CacheFactory::getCache(vsCacheName);

        // process the command...
        cmd = argv[2];
      }

      // Get
      if (cmd == "get") {
        for(int i = startArg;i < argc;i++) {
          String::View vsKey = argv[i];
          String::View vsValue = cast<String::View>(hCache->get(vsKey));
          std::cout << vsValue << std::endl;
        }

      // Get All
      } else if (cmd == "mget") {
        for (Iterator::Handle hIter = hCache->entrySet()->iterator();
          hIter->hasNext();) {
          Map::Entry::View vEntry = cast<Map::Entry::View>(hIter->next());
          String::View vsKey = cast<String::View>(vEntry->getKey());
          String::View vsValue = cast<String::View>(vEntry->getValue());
          std::cout << vsKey << ":" << vsValue << std::endl;
        }

      // Put
      } else if (cmd == "put") {
        String::View vsKey = argv[startArg];
        String::View vsValue = argv[startArg+1];
        std::cout << hCache->put(vsKey, vsValue) << std::endl;

      // Put All
      } else if (cmd == "mput") {
        typedef TypedCollections::TypedMap<String::View,
          String::View> StringStringMap;
        StringStringMap::Handle hMap =
          StringStringMap::create(HashMap::create());

        for(int i = startArg;i<argc;i+=2) {
          String::View vsKey = argv[i];
          String::View vsValue = argv[i+1];
          hMap->put(vsKey, vsValue);
        }
        hCache->putAll(hMap);

      // Delete
      } else if (cmd == "delete") {
        for(int i = startArg;i < argc;i++) {
          String::View vsKey = argv[i];
          String::View vsValue = cast<String::View>(hCache->remove(vsKey));
          std::cout << vsValue << std::endl;
        }

      // Size
      } else if (cmd == "size") {
        std::cout << hCache->size() << std::endl;

      // Keys
      } else if (cmd == "keys") {
        for (Iterator::Handle hIter = hCache->keySet()->iterator();
          hIter->hasNext();) {
          String::View vsKey = cast<String::View>(hIter->next());
          std::cout << vsKey << std::endl;
        }

      // Values
      } else if (cmd == "values") {
        for (Iterator::Handle hIter = hCache->entrySet()->iterator();
          hIter->hasNext();) {
          Map::Entry::View vEntry = cast<Map::Entry::View>(hIter->next());
          String::View vsValue = cast<String::View>(vEntry->getValue());
          std::cout << vsValue << std::endl;
        }

      // Keys
      } else if (cmd == "key_exists") {
        String::View vsKey = argv[startArg];
        res = hCache->containsKey(vsKey);
        std::cout << res << std::endl;

      // Value
      } else if (cmd == "value_exists") {
        String::View vsValue = argv[startArg];
        res = hCache->containsValue(vsValue);
        std::cout << res << std::endl;

      // Clear
      } else if (cmd == "clear") {
        hCache->clear();
      // Usage
      } else {
        usage();
        res = 1;
      }
    } else {
      usage();
      res = 1;
    }
  } catch (const std::exception& e) {
    std::cerr << "error: " << e.what() << std::endl;
    res = 1;
  }
  return res;
}

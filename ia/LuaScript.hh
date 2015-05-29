#ifndef LUASCRIPT_HH
#define LUASCRIPT_HH
 
#include <string>
#include <vector>
#include <iostream>
 
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}
 
class LuaScript {
public:
    LuaScript(const std::string& filename);
    ~LuaScript();
    void printError(const std::string& variableName, const std::string& reason);
 
    template<typename T>
    T get(const std::string& variableName) {

    }
    bool lua_gettostack(const std::string& variableName) {

    }
 
    // Generic get
    template<typename T>
    T lua_get(const std::string& variableName) {
      return 0;
    }
 
    // Generic default get
    template<typename T>
    T lua_getdefault(const std::string& variableName) {
      return 0;
    }
private:
    lua_State* L;
};
 
#endif
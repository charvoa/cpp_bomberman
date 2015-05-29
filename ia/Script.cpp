#include <LuaBridge.h>
#include <iostream>

extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}
 
using namespace luabridge;
int main() {
    lua_State* L = luaL_newstate();
    luaL_dofile(L, "script.lua");
    luaL_openlibs(L);
    lua_pcall(L, 0, 0, 0);
    LuaRef s = getGlobal(L, "testString");
    LuaRef n = getGlobal(L, "number");
    std::string luaString = s.cast<std::string>();
    int answer = n.cast<int>();
    std::cout << luaString << std::endl;
    std::cout << "And here's our number:" << answer << std::endl;
}


LuaScript::LuaScript(const std::string& filename) {
    L = luaL_newstate();
    if (luaL_loadfile(L, filename.c_str()) || lua_pcall(L, 0, 0, 0)) {
        std::cout<<"Error: script not loaded ("<<filename<<")"<<std::endl;
        L = 0;
    }
}

LuaScript::~LuaScript() {
    if(L) lua_close(L);
}
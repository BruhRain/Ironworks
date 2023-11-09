#ifndef LUALIBRARY_HPP
#define LUALIBRARY_HPP

#include "../LuaU/VM/include/lua.h"
#include "../LuaU/VM/include/lualib.h"
#include "../LuaU/Compiler/include/luacode.h"

#include <functional>
#include <vector>
#include <string>

class CLuaLibrary
{
protected:
    lua_State* LuaState = nullptr;
public:
    std::vector<std::string> Scripts = {};
public:
    void Init();
    void Destroy();
    lua_State* GetLuaState();

    int ExecuteScript(std::string script);

    void CreateLibrary(const char* name, const std::function<void()>& functions);
    void RegisterFunction(const char* name, lua_CFunction function, int index = -10002);

    std::vector<std::string> GetScriptList();
};

inline CLuaLibrary* LuaLibrary = new CLuaLibrary();

namespace LuaAPI
{
    int DebugPrint(lua_State* L);
    int ChangeConsoleTitle(lua_State* L);

    int DebugGetLastScript(lua_State* L);

    int IsKeyDown(lua_State* L);
    int IsKeyPressed(lua_State* L);
    int GetMousePosition(lua_State* L);

    int Vector2New(lua_State* L);
}
#endif
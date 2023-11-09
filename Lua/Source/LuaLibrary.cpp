#include "LuaLibrary.hpp"

#include <format>
#include <iostream>

void CLuaLibrary::Init()
{
    this->LuaState = luaL_newstate();
    luaL_openlibs(this->LuaState);
}

void CLuaLibrary::Destroy()
{
    lua_close(this->LuaState);
    free(this->LuaState);
}

lua_State* CLuaLibrary::GetLuaState()
{
    return this->LuaState;
}

void CLuaLibrary::CreateLibrary(const char* name, const std::function<void()>& functions)
{
    lua_newtable(this->LuaState);
    {
        functions();
    }
    lua_setfield(this->LuaState, -10002, name);
}

void CLuaLibrary::RegisterFunction(const char* name, lua_CFunction function, int index)
{
    lua_pushcfunction(this->LuaState, function, name);
    lua_setfield(this->LuaState, index, name);
}

int CLuaLibrary::ExecuteScript(std::string script)
{
    this->Scripts.push_back(script);
    size_t bytecodeSize = 0;

    char* bytecode = luau_compile(script.c_str(), script.length(), NULL, &bytecodeSize);
    int res = luau_load(this->LuaState, "main", bytecode, bytecodeSize, 0);

    if (res == 0)
    {
        int call = lua_pcall(this->LuaState, 0, 0, 0);
        if (call != LUA_OK) std::cout << std::format("[ERROR]: {}\n", lua_tostring(this->LuaState, -1));
    }
    free(bytecode);
    return 0;
}

std::vector<std::string> CLuaLibrary::GetScriptList()
{
    return this->Scripts;
}

int LuaAPI::DebugGetLastScript(lua_State* L)
{
    int ScriptCount = LuaLibrary->GetScriptList().size();

    lua_pushstring(L, LuaLibrary->GetScriptList()[ScriptCount - 1].c_str());
    if (lua_isnil(L, -1)) return 0;

    return 1;
}

int LuaAPI::DebugPrint(lua_State* L)
{
    if (lua_isnil(L, 1))
    {
        lua_pushboolean(L, false);
        lua_pushstring(L, "Arg 1 expects string.");
    }
    const char* print_message = lua_tostring(L, 1);
    
    std::cout << std::format("[DEBUG]: {}\n", print_message);
    lua_pushboolean(L, true);
    return 1;
}

int LuaAPI::ChangeConsoleTitle(lua_State* L)
{
    if (lua_isnil(L, 1))
    {
        lua_pushboolean(L, false);
        lua_pushstring(L, "Arg 1 expects string.");
    }
    if(!lua_isstring(L, 1))
    {
        lua_pushboolean(L, false);
        lua_pushstring(L, "Type provided is not string.");
    }
    const char* title = lua_tostring(L, 1);
    // provide string esc.
    return 1;
}

int LuaAPI::IsKeyDown(lua_State* L)
{
    
}

int LuaAPI::IsKeyPressed(lua_State* L)
{return 1;}

int LuaAPI::GetMousePosition(lua_State* L)
{return 1;}

int LuaAPI::Vector2New(lua_State* L)
{return 1;}
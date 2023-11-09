#include "LuaLibrary.hpp"

CLuaLibrary::CLuaLibrary()
{
    this->LuaState = luaL_newstate();
    luaL_openlibs(this->LuaState);
}

CLuaLibrary::~CLuaLibrary()
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

int LuaAPI::DebugPrint(lua_State* L)
{return 1;}

int LuaAPI::ChangeConsoleTitle(lua_State* L)
{return 1;}

int LuaAPI::IsKeyDown(lua_State* L)
{return 1;}

int LuaAPI::IsKeyPressed(lua_State* L)
{return 1;}

int LuaAPI::GetMousePosition(lua_State* L)
{return 1;}

int LuaAPI::Vector2New(lua_State* L)
{return 1;}
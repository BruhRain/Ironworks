#include "LuaLibrary.hpp"

int main(void)
{
    CLuaLibrary* LuaLibrary = new CLuaLibrary();

    LuaLibrary->CreateLibrary("Debug", [&LuaLibrary]()
    {
        LuaLibrary->RegisterFunction("Print", LuaAPI::DebugPrint);
        LuaLibrary->RegisterFunction("ChangeConsoleTitle", LuaAPI::ChangeConsoleTitle);
    });

    LuaLibrary->CreateLibrary("Input", [&LuaLibrary]()
    {
        LuaLibrary->RegisterFunction("IsKeyDown", LuaAPI::IsKeyDown);
        LuaLibrary->RegisterFunction("IsKeyPressed", LuaAPI::IsKeyPressed);
        LuaLibrary->RegisterFunction("GetMousePosition", LuaAPI::GetMousePosition);
    });

    LuaLibrary->CreateLibrary("Vector2", [&LuaLibrary]()
    {
        LuaLibrary->RegisterFunction("New", LuaAPI::Vector2New);
    });
    
    return 0;
}
#include "LuaLibrary.hpp"

#include <iostream>
#include <thread>
#include <windows.h>

void LuaThread()
{
    LuaLibrary->CreateLibrary("debug", [&]()
    {
        LuaLibrary->RegisterFunction("print", LuaAPI::DebugPrint, -2);
        LuaLibrary->RegisterFunction("change_console_title", LuaAPI::ChangeConsoleTitle, -2);
        LuaLibrary->RegisterFunction("get_last_script", LuaAPI::DebugGetLastScript, -2);
    });

    LuaLibrary->CreateLibrary("input", [&]()
    {
        LuaLibrary->RegisterFunction("is_key_down", LuaAPI::IsKeyDown, -2);
        LuaLibrary->RegisterFunction("is_key_pressed", LuaAPI::IsKeyPressed, -2);
        LuaLibrary->RegisterFunction("get_mouse_position", LuaAPI::GetMousePosition, -2);
    });

    LuaLibrary->CreateLibrary("vector2", [&]()
    {
        LuaLibrary->RegisterFunction("new", LuaAPI::Vector2New, -2);
    });

    std::string script = "";

    while(true)
    {
        Sleep(250);
        std::cout << "> ";
        std::getline(std::cin, script);
        LuaLibrary->ExecuteScript(script);
    }
}

int main(void)
{
    std::thread(LuaThread).detach();

    return 0;
}
#include <array>
#include "Vector.hpp"

#ifndef INPUT_HPP
#define INPUT_HPP

class CInputSystem
{
protected:
    Vector2 MousePosition = {};
    std::array<bool, 256> KeyStates = {};
    std::array<bool, 256> OldKeyStates = {};
public:
    const Vector2& GetMousePosition();
    bool KeyDown(int key_code);
    bool KeyReleased(int key_code);
    bool KeyPressed(int key_code);
    bool CursorInRegion(Vector2 Position, Vector2 Size);
    void Update();
};

#endif
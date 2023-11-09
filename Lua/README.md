# Lua Implementation of Ironworks

Feel free to copy the project as a boilerplate for your project.

Custom functions can be found in `Source/LuaLibrary.cpp` and `Source/LuaLibrary.hpp`

---

## Example Usage
```lua
local uilib = ui.library("theme_name")
local main_window = uilib:create_window("name", {400, 600}, {0,0})
local new_tab = main_window:create_tab("tab name")
```

There are more functions other than the library, more documentation can be found in the [Wiki](https://github.com/BruhRain/<FRAMEWORK_NAME>/wiki) page.

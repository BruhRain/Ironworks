#include <string>
#include <deque>

#include "Utilities/Vector.hpp"

#ifndef IELEMENT_HPP
#define IELEMENT_HPP

enum ElementType
{
    WINDOW,
    TAB,
    CONTAINER,
    BUTTON,
    TEXTBOX,
    LABEL,
    IMAGE,
    CHECKBOX,
    COLORPICKER,
    SLIDER,
    PROGRESSBAR,
    COMBOBOX,
    LISTBOX
};

class IElement
{
public:
    std::string ElementName;
    ElementType Type;

    Vector2 Position;
    Vector2 Size;

    bool Hovered;
    bool Selected;

    IElement* ParentElement;
    std::deque<IElement*> ChildElements = {};
};

#endif
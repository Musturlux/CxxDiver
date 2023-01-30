/**
 * @file main.cpp
 * @author Musturlux
 * @brief This is the main for the project, Game of Life
 * @version not define
 * @date 2023-01
 *
 * @copyright Copyright (c) 2023
 */

#include <memory> // for shared_ptr, __shared_ptr_access
#include <string> // for operator+, to_string

#include "ftxui/component/captured_mouse.hpp"     // for ftxui
#include "ftxui/component/component.hpp"          // for Button, Horizontal, Renderer
#include "ftxui/component/component_base.hpp"     // for ComponentBase
#include "ftxui/component/screen_interactive.hpp" // for ScreenInteractive
#include "ftxui/dom/elements.hpp"                 // for separator, gauge, text, Element, operator|, vbox, border

using namespace ftxui;

#define NEED_CELL_PARENT 3

struct cell
{
    bool alive{false};

    bool is_alive()
    {
        return this->alive;
    }

    void birth()
    {
        this->alive = true;
    }

    void die()
    {
        this->alive = false;
    }

    void step(int nb_parent)
    {
        if (nb_parent >= NEED_CELL_PARENT)
            this->birth();
        else
            this->die();
    }
};

int main(int argc, const char *argv[])
{
    int value = 50;

    // The tree of components. This defines how to navigate using the keyboard.
    auto buttons = Container::Horizontal({
        Button("Decrease", [&]
               { value--; }),
        Button("Increase", [&]
               { value++; }),
    });

    // Modify the way to render them on screen:
    auto component = Renderer(buttons, [&]
                              { return vbox({
                                           text("value = " + std::to_string(value)),
                                           separator(),
                                           gauge(value * 0.01f),
                                           separator(),
                                           buttons->Render(),
                                       }) |
                                       border; });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(component);
    return 0;
}
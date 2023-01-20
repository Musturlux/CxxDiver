/**
 * @file main.cpp
 * @author Musturlux
 * @brief This is the main for the project, Game of Life
 * @version not define
 * @date 2023-01
 *
 * @copyright Copyright (c) 2023
 */

#include <iostream>

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

int main()
{
}
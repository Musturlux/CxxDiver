/**
 * @file Wall.hpp
 * @author Musturlux
 * @brief This class is the Wall.hpp implementation. Wall.hpp is interface.
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class Wall
{
    private:
        bool isPassable;

    public:
        virtual ~Wall() {}
        virtual bool getIsPassable() = 0;
        virtual void setIsPassable(bool franchiseable) = 0;
        virtual std::string getDescription() = 0;
        virtual std::string bombTheWall() = 0;
};
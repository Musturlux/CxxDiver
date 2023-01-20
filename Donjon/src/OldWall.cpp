/**
 * @file Wall.cpp
 * @author Musturlux
 * @brief This class is the Wall.hpp implementation. Wall.hpp is interface.
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/Wall.hpp"


/**
 * SimpleWall is a Class who implement Wall, is not destructible or Franchiseable.
 */
class SimpleWall : public Wall
{
    private:
        bool isPassable = false;

    public:
        bool getIsPassable() override{
            return isPassable;
        }
        void setIsPassable(bool franchiseable) override{
            this->isPassable = franchiseable;
        }
        std::string getDescription() override{
            return "C'est juste un mur tkt.";
        }
        virtual std::string bombTheWall() override{
            return "BOOOOOM ! A bin non il c'est rien passé.";
        }
};


/**
 * Door is a Class who implement Wall, is destructible and Franchiseable.
 */
class Door : public Wall
{
    private:
        bool isPassable = true;

    public:
        bool getIsPassable() override{
            return isPassable;
        }

        void setIsPassable(bool franchiseable) override{
            this->isPassable = franchiseable;
        }

        std::string getDescription() override{
            return "C'est une porte qui n'est pas vérrouillé, pas très prudent.";
        }

        virtual std::string bombTheWall() override{
            return "BOOOOOM ! La porte DÉJÀ OUVERTE vole en mille éclat !";
        }
};


/**
 * BreakeableWall is a Class who implement Wall, is destructible and Franchiseable is the player use a bomb.
 */
class BreakeableWall : public Wall
{
    private:
        bool isPassable = false;

    public:
        bool getIsPassable() override{
            return isPassable;
        }

        void setIsPassable(bool franchiseable) override{
            this->isPassable = franchiseable;
        }

        std::string getDescription() override{
            return "C'est un mur qui semble fragile.";
        }

        virtual std::string bombTheWall() override{
            this->isPassable = true;
            return "BOOOOOM ! Le mur est ouvert, j'espère qu'il n'estais pas porteur ...";
        }
};
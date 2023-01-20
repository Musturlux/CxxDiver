/**
 * @file Wall.cpp
 * @author Musturlux
 * @brief This code is a implementation alternative for wall with less POO.
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 */
#include <iostream>
#include <stdint.h>

struct Wall{
    enum Type {
        UNDEFINED, DOOR, LDOOR, WALL, BREAKWALL
    } type { UNDEFINED };

    bool is_passable {false};

    const std::string description {};

    static Wall new_door(){
        return{
            Type::DOOR,
            true,
            "This is a door."
        };
    }

    static Wall new_lockedDoor(){
        return{
            Type::LDOOR,
            false,
            "This is a door."
        };
    }

    static Wall new_wall(){
        return{
            Type::WALL,
            false,
            "This a wall."
        };
    }

    static Wall new_BreakWall(){
        return{
            Type::BREAKWALL,
            false,
            "This a wall."
        };
    }

    void bomb(){
        switch (type){
        case DOOR:
            std::cout <<"BOOM ! The door is open, but this one was already open."<< std::endl;
            break;
        
        case LDOOR:
            std::cout <<"BOOM ! The door is open congrat, nice play."<< std::endl;
            is_passable = true;
            break;

        case BREAKWALL:
            std::cout <<"BOOM ! The wall explode in a lot of piece ! I ... I hope this wall was not important."<< std::endl;
            is_passable = true;
            break;

        default:
            std::cout <<"BOOM ! Nothing change sorry."<< std::endl;
            break;
        }
    }

    void lookCloser(){
        switch (type){
            case DOOR:
                std::cout<<"The door seems open."<<std::endl;
                break;
            case LDOOR:
                std::cout<<"The door seems close."<<std::endl;
            case BREAKWALL:
                std::cout<<"Yes, i see what you mean this wall seems fragile."<<std::endl;
                break;
            default :
                std::cout<<"Nothing more : "+this->description<<std::endl;       
        }
    }
};

int main (){
    auto breakwall = Wall::new_BreakWall();
    auto wall      = Wall::new_wall(); 
    
    std::cout << breakwall.description << std::endl;
    breakwall.lookCloser();
    breakwall.bomb();

    std::cout << wall.description << std::endl;
    wall.lookCloser();
    wall.bomb();

    return 0;
}
/**
 * @author Rajan Pande, Doug Summerlin, Prasanna Raghavan
 * @brief RWA2_group3 node cpp file to execute methods pertaining to node class
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */


//import libraries
#include <iostream>
#include <algorithm>
#include "../include/node/node.h"
#include "../include/util/util.h"
#include "../include/mouse/mouse.h"
#include "../include/api/api.h"

void rwa2::Node::get_wall_direction(int curr_orient){
    
    if (curr_orient == 0)  //if facing global north
    {
        this->char1 = 'n';     //char1 = north
        this->char2 = 'w';     //char2 = west
        this->char3 = 'e';     //char3 = east
    }
    else if (curr_orient == 90){  //if facing global east
        this->char1 = 'e';     //char1 = east
        this->char2 = 'n';     //char2 = north
        this->char3 = 's';     //char2 = south
    }
    else if (curr_orient == -90){  //if facing global west
        this->char1 = 'w';     //char1 = west
        this->char2 = 's';     //char2 = south
        this->char3 = 'n';     //char3 = north
    }
    else {                     //if facing global south
        this->char1 = 's';     //char1 = south
        this->char2 = 'e';     //char2 = east
        this->char3 = 'w';     //char3 = west

    }
}
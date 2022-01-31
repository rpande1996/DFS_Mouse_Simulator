/**
 * @file main.cpp
 * @author Rajan Pande, Doug Summerlin, Prasanna Raghavan
 * @brief RWA2_group3 main cpp file to execute functionality define in classes
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//import libraries and header files
#include <iostream>
#include "../include/node/node.h"
#include "../include/util/util.h"
#include "../include/mouse/mouse.h"
#include "../include/api/api.h"

int main(){
    rwa2::Mouse mouse; //create Mouse object named mouse
    std::pair<int, int> goal{8, 7}; //define coordinate pair of goal node to be 8,7 G3
    std::stack<std::pair<int, int>> path = mouse.find_path(goal);  //define path vector of pairs to be loaded with output of Mouse DFS method
    mouse.print_stack_pair(path); //print the path of coordinate pairs to the simulator
}
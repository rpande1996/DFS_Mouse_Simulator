/**
 * @file util.cpp
 * @author Rajan Pande, Doug Summerlin, Prasanna Raghavan
 * @brief RWA2_group3 util cpp class to define utliities 
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

std::string rwa2::Util::location_text(std::pair<int, int> loc){

    std::string string_1 = std::to_string(loc.first);    //take first element of location pair amd comvert to string
    std::string string_2 = std::to_string(loc.second);   //take second element of location pair and convert to string
    std::string text = (string_1+","+string_2);          //combine strings1&2 into a single string
    return text;                                         //return combined string to pass to maze as text

}
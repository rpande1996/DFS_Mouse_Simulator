#ifndef NODE_H
# define NODE_H

#include <vector>

namespace rwa2{
    /**
     * @brief Class to represent a node with multiple walls
     * 
     */
    class Node{

    public:    
    char char1, char2, char3;

    /**
     * @brief Get the node wall direction based on the current orientation of the mouse
     * 
     * @param curr_orient 
     */
    void get_wall_direction(int curr_orient);

    /**
     * @brief Get the char1 attribute
     * 
     * @return char 
     */
    char get_char1(){
        return this->char1;
    }
    /**
     * @brief Get the char2 attribute
     * 
     * @return char 
     */
    char get_char2(){
        return this->char2;
    }
    /**
     * @brief Get the char3 attribute
     * 
     * @return char 
     */
    char get_char3(){
        return this->char3;
    }
    };
}

#endif
#ifndef MOUSE_H
#define MOUSE_H

#include "../node/node.h"
#include "../api/api.h"
#include "../util/util.h"

namespace rwa2{
    
    /**
     * @brief A class defining the mouse object, its DFS path, its location/orientation, and its movement
     * 
     */
    class Mouse{

    public:

    std::stack<std::string> valid_moves;
    std::array<std::array<int, 16>, 16> orientation {0};
    std::stack<std::pair<int, int>> path;
    std::vector<std::pair<int, int>> visited_nodes;
    std::pair<int, int> location {0,0};
    std::vector<int> null_vector {0,0,0};
    int current_orientation = 0;


    /**
     * @brief Method carrying out depth first search algorithm
     * 
     * @param goal x,y coordinate of node defined to be the goal for the mouse to reach
     * @return std::stack<std::pair<int, int>> return stack of pairs defining path for mouse to travel
     */
    std::stack<std::pair<int, int>> find_path(std::pair<int, int> goal);

    /**
     * @brief Method to return second most recent value in stack of nodes
     * 
     * @return std::pair<int, int> returns coordinate pair of node location
     */
    std::pair<int, int> find_previous_node();

    /**
     * @brief Method utilizing API.wallfront/left/right() to check walls at location and fill logic vector accordingly
     * 
     * @return std::vector<int> return 3 element vector corresponding to boolean values of walls in each direction U,L,R, where no wall in direction is TRUE, otherwise FALSE
     */
    std::vector<int> check_walls();

    /**
     * @brief Method for determining if a certain pair exists in a vector of pairs
     * 
     * @param vector_pair pass node location to be checked in vector
     * @return true if pair is present in vector
     * @return false if pair is not present in vector
     */
    bool find_node(std::vector<std::pair<int, int>> vector_pair);

    /**
     * @brief uses API functionality to rotate mouse 90deg CCW and correct orientation
     * 
     * @param move_bot boolean value initialized at true in method definiton
     */
    void turn_left(bool move_bot = true);

    /**
     * @brief uses API functionality to rotate mouse 90deg CW and correct orientation
     * 
     * @param move_bot boolean value initialized at true in method definiton
     */
    void turn_right(bool move_bot = true);

    /**
     * @brief uses API functionality to move mouse bot 1 unit in commanded direction and reorient
     * 
     * @param move_bot boolean value initialized at true in method definition
     * @param change_orientation boolean value initialized at true in method definition
     */
    void move_forward(bool move_bot = true, bool change_orientation = true);

    /**
     * @brief Method used to rotate mouse bot to reset its orientation
     * 
     */
    void reset_orientation();

    /**
     * @brief This method is used for backtracking functionality
     * 
     * @param path Feed stack path to backtracking function so it can pop off invalid entries
     */
    void go_to_previous (std::stack<std::pair<int, int>>& path);

    /**
     * @brief This position assesseses
     * 
     * @param move Pass string U, L, R value to check legal position in any direction
     * @return true Return true if position is in visitedNodes list
     * @return false Return false if current position is not in visited node list
     */
    bool legal_position(std::string move);

    /**
     * @brief Method to create stack of valid moves as strings, by using boolean vector input
     * 
     * @param valid_moves passes stack of valid moves of type string, U is front, R is right, L is left
     * @param walls Vector of integers containing 1 or not 1, determining validity of "ith" wall corresponding to "ith" vector entry
     * @return std::stack<std::string> return updated stack of valid moves after analyzing wall validity vector
     */
    std::stack<std::string> legal_moves (std::stack<std::string>& valid_moves, std::vector<int> walls);
    
    /**
     * @brief Method reads input string from top of stack, and calls the movement function to move the mouse bot accordingly
     * 
     */
    void carry_out_move();

    /**
     * @brief This method takes the stack of pairs corresponding to the DFS solution and colors the path 
     * 
     * @param stack_pair Pass the stack of pairs that comprise the solution path
     */
    void print_stack_pair(std::stack<std::pair<int, int>> stack_pair);

    };
}

#endif
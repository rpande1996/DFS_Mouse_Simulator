/**
 * @file mouse.cpp
 * @author Rajan Pande, Doug Summerlin, Prasanna Raghavan
 * @brief RWA2_group3 mouse cpp file to execute mouse class methods pertaining to the mousebot and its movement
 * @version 0.1
 * @date 2021-11-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//Import libraries and headers
#include <iostream>
#include <algorithm>
#include "../include/node/node.h"
#include "../include/util/util.h"
#include "../include/mouse/mouse.h"
#include "../include/api/api.h"

//find path method is main DFS algorithm
std::stack<std::pair<int, int>> rwa2::Mouse::find_path(
        std::pair<int, int> goal
){
    path.push(this->location); //push current mouse location to stack of location pairs
    if (this->location.first == goal.first && this->location.second == goal.second){
        return path;    // if location pair is identical to goal pair, return path solution
    }
    else{
        visited_nodes.push_back(this->location);   //add location pair to visited Node vector
        API::setColor(this->location.first, this->location.second, 'R');  //set color of current node to red
        rwa2::Util Util;
        std::string text = Util.location_text(location); //convert int location to string using util locationtext method
        std::cerr<<text<<'\n';  //print text to simulator UI
        API::setText(this->location.first, this->location.second, text); //set string location on current node with API method
        rwa2::Node Node;           
        std::vector<int> walls = check_walls(); // define wall vector to hold boolean wall values
        if(walls == null_vector){  // if the wall vector is null, meaning completely surrounded by walls

            while (walls == null_vector) { // if the mouse is still surrounded by walls on three sides
                visited_nodes.push_back(this->location); // make sure current node is in visited node stack
                go_to_previous(path);  // use pushback function with current path stack
                walls = check_walls(); // check next node and fill wall vector to repeat loop
            }
            rwa2::Mouse::carry_out_move(); // move mousebot accordingly
            path = rwa2::Mouse::find_path(goal);  //call function recursively with goal node location
        }
        else{
            valid_moves = rwa2::Mouse::legal_moves(valid_moves, walls);  // if wall vector not null, check wall vector directions for valid moves
            rwa2::Mouse::carry_out_move(); // move mouse according to valid move set
            API::setColor(this->location.first, this->location.second, 'R');    // if mouse has ever traversed node location, set node color to red                
            std::string text = Util.location_text(location); // convert location to string to print text
            API::setText(this->location.first, this->location.second, text); //if mouse has ever traversed node, print location to node
            std::cerr<<text<<'\n'; // print path text string in simulator 
            visited_nodes.push_back(this->location);  //add current location to visited node vector
            path = rwa2::Mouse::find_path(goal); // call function recursively with goal node location
        }
    }
    return path; // return path stack of pairs
}

void rwa2::Mouse::turn_left(
    bool move_bot
){
    if (move_bot){ //if passed boolean is true
        API::turnLeft();   //use the API function to turn left
    }
    this->current_orientation -= 90;        //subtract 90deg from current mouse orientation
    if (this->current_orientation == 270){  //if mouse orientation is 270 deg
        this->current_orientation = -90;    //reset to -90 deg for orientation calculation consistency
    }
    if (this->current_orientation == -180){ //if mouse orientation is at -180 deg
        this->current_orientation = 180;    //reset to 180 deg for orientation calculation consistency
    }
    if (this->current_orientation == 360){  //if mouse orientation is at 360 deg
        this->current_orientation = 0;      //reset to 0 deg for orientation calculation consistency
    }
    return;  //return void
}

void rwa2::Mouse::turn_right(
    bool move_bot
){
    if(move_bot){  //if passed boolean is true
        API::turnRight();  //use the API function to turn right
    }
    this->current_orientation += 90;    //add 90deg from current mouse orientation
    if (this->current_orientation == 270){  //if mouse orientation is 270 deg
        this->current_orientation = -90;    //reset to -90 deg for orientation calculation consistency
    }
    if (this->current_orientation == -180){ //if mouse orientation is at -180 deg
        this->current_orientation = 180;    //reset to 180 deg for orientation calculation consistency
    }
    if (this->current_orientation == 360){  //if mouse orientation is at 360 deg
        this->current_orientation = 0;      //reset to 0 deg for orientation calculation consistency
    }
    return; //return void
}

void rwa2::Mouse::move_forward(
    bool move_bot,
    bool change_orientation
){
    if (move_bot) {    //if passed boolean is true
        API::moveForward();  //use the API function to move forward
    }
    if (this->current_orientation == 0){  // if bot is facing north
        this->location.second += 1;      // add one to y coordinate
    }
    else if (this->current_orientation == -90){  // if bot is facing west
        this->location.first -= 1;               //subtract one from x coordinate
    }
    else if (this->current_orientation == 90){   // if bot is facing east
        this->location.first += 1;                // add one to x coordinate
    }
    else{
        this->location.second -= 1;    // if bot is facing south subtract one from y coordinate
    }
    if (change_orientation) {                //if second passed boolean is true
        orientation[15-this->location.second][this->location.first] = this->current_orientation; //change orientation to match current mouse bot orienation
    }
    return;
}

void rwa2::Mouse::reset_orientation(){
    int target = orientation[15 - this->location.second][this->location.first]; //define target orientation relative to bots current orientation
    while (this->current_orientation!= target) {  //while current orientation is not equal to the target orientation
        rwa2::Mouse::turn_left();  //rotate until target orientation is reached
    }
    return;
}

void rwa2::Mouse::go_to_previous(
    std::stack<std::pair<int, int>>& path
){
    visited_nodes.push_back(this->location);  //add mouse location to visited node vector
    path.pop();                //remove top element from path stack
    rwa2::Mouse::turn_left();  //rotate left 90deg
    rwa2::Mouse::turn_left();   //rotate left 90 deg to complete U turn
    rwa2::Mouse::move_forward(true, false);  //move forward once but dont update orientation
    rwa2::Mouse::reset_orientation();  //now rotate until target angle is reached to reset orientation

    return;
}

bool rwa2::Mouse::legal_position(
    std::string move
){
    std::pair<int, int> old_location = this->location;  //load current mouse position into old location pair
    int old_orientation = this->current_orientation;   //load current mouse orientation into old orientation int
    if (move == "U"){    // if passed value is string "U"
        rwa2::Mouse::move_forward(false, false); // reorient robot
    }
    else if (move == "L"){  //if passed value is string "L"
        rwa2::Mouse::turn_left(false); 
        rwa2::Mouse::move_forward(false, false);   //reorient robot

    }
    else if (move == "R"){  //if passed value is string "R"
        rwa2::Mouse::turn_right(false);
        rwa2::Mouse::move_forward(false, false);   //reorient robot
    }

    bool ret_val; //define boolean return value
    // if mouse not at 0,0 and the current location is in the visited nodes vector
    if (!rwa2::Mouse::find_node(visited_nodes) && this->location.first >= 0 && this->location.second >= 0) {
        ret_val = true; //return true if locaiton in visited Nodes
    } else {
        ret_val =  false;  //return false if location not in visited nodes
    }
    this->location = old_location;  // reset location to stored old location
    this->current_orientation = old_orientation; //reset orientation to stored old orientation

    return ret_val;  //return true if location in visited nodes, false otherwise
}

std::stack<std::string> rwa2::Mouse::legal_moves (
    std::stack<std::string>& valid_moves,  //pass stack of strings of valid moves
    std::vector<int> walls    // pass vector of ints denoting walls
){    
    if (walls.at(2)==1){       // if theres no wall on the right, push R to valid move stack
        valid_moves.push("R");
    }
    if (walls.at(1) == 1){
        valid_moves.push("L");  // if there is no wall on the left, push L to valid move stack
    }
    if (walls.at(0) == 1){
        valid_moves.push("U"); // if there is no wall in front, push U to valid move stack
    }
    return valid_moves;  //return stack of valid move strings RLU
}

 void rwa2::Mouse::carry_out_move(
){
    std::string move = this->valid_moves.top();  //initialize string with the top valid from the Mouses valid move stack
    if (move == "U"){   // if the value of the string is U, call move forward method to move forward
        move_forward();
    }
    else if (move == "L"){  // if the value of the string is L, call move left method to move left, then move forward
        turn_left();
        move_forward();

    }
    else if (move == "R"){  // if the value of the string is R, call move right method to move left, then move forward
        turn_right();
        move_forward();
    }
    this->valid_moves.pop();  // pop the top valid move from the top of the stack
    return;  // return void
}

bool rwa2::Mouse::find_node(
    std::vector<std::pair<int, int>> vector_pair
){
    bool ret_val;  //define boolean return value
    std::vector<std::pair<int, int>>::iterator i;  //define iterator of vectored pair type
    i = std::find (vector_pair.begin(), vector_pair.end(), this->location); //find location of vector pair in passed vector
    if (i!=vector_pair.end()){ //compare iterator result of std::find to pair.end()
        ret_val = true; //if logical statemenr returns true, pair is in passed vector
    }
    else{
        ret_val = false; //if logical statement returns false, pair is not in passed vector
    }
    return ret_val; //return boolean indicating status of pair presence in vector
}
std::pair<int, int> rwa2::Mouse::find_previous_node(){
    path.pop();  //remove the top node from the stack of node locations
    std::pair<int, int> second = path.top(); //fill a pair with the value of the next node location
    return second; //return the what is the second node in the stack before the first pop
}

std::vector<int> rwa2::Mouse::check_walls() {
    rwa2::Node Node;  //declare Node object to do work with if necessary
    std::vector<int> walls {0,0,0};  //set 3 integer vector to hold wall values for walls surrounding mouse
    Node.get_wall_direction(current_orientation); //get directions of walls relative to mouse location
    if (!API::wallFront()){  //if there is not a wall in front of the mouse
        if (rwa2::Mouse::legal_position("U")) { //pass "U" string to legal pos. method 
            walls.at(0)=1;  // fill the first element of the wall vector with a 1, signifying no wall present
        }
    }
    else{
        API::setWall(this->location.first, this->location.second, Node.get_char1()); // set a wall in the simulator in the front of the bot
    }
    if (!API::wallLeft()){     // if there is not a wall to the left of the mouse
        if (rwa2::Mouse::legal_position("L")) { //pass "L" string to legal pos. method
            walls.at(1)=1;   // fill the second element of the wall vector  with a 1, signifying no wall present
        }
    }
    else{
        Node.get_wall_direction(current_orientation);  //get the direction of the wall using the mouse bots current orientation
        API::setWall(this->location.first, this->location.second, Node.get_char2());  // set a wall in the simulator on the left of the bot
    }
    if (!API::wallRight()){     // if there is not a wall to the right of the mouse
        if (rwa2::Mouse::legal_position("R")) {  // pass "R" string to legal pos. method
            walls.at(2)=1;    // fill the third element of the wall vector with a 1, signifying no wall present
        }
    }
    else{
        Node.get_wall_direction(current_orientation);   //get the direction of the wall using the mouse bots current orientation
        API::setWall(this->location.first, this->location.second, Node.get_char3());  // set a wall in the simulator on the right of the bot
    }
    return walls; // return the vector of U L R wall checks to do work with
}

void rwa2::Mouse::print_stack_pair(
    std::stack<std::pair<int, int>> stack_pair
){
    std::stack<std::pair<int, int>> stack_temp;  //create temporary stack of pairs
    while (!stack_pair.empty()){             //if the passed stair of pairs is not empty
        std::pair<int, int> pair_temp = stack_pair.top();    //load the top element into a temporary pair
        int a = pair_temp.first;       // disect the pair into ints
        int b = pair_temp.second;
        API::setColor(a, b, 'G');      // set color of coordinate ints to green
        stack_temp.push(pair_temp);   //push the temporary pair into the temporary stack
        stack_pair.pop();            //pop off the top element of the passed stack of pairs
    }
    while (!stack_temp.empty()){          // while the temporary stack is not empty
        std::pair<int,int> pairTemp_2 = stack_temp.top();   //load the top element into another temporary pair
        stack_pair.push(pairTemp_2);  //psuh that temporary pair into the passed stack
        stack_temp.pop();   //pop off the top element of the temporary stack
    }
}
#ifndef UTIL_H
#define UTIL_H

#include <stack>
#include <array>
#include <string>


namespace rwa2{
    /**
     * @brief Utilities class for performing basic operations
     * 
     */
    class Util{

    public:
    /**
     * @brief method for converting node coordinate pair into string to pass to maze
     * 
     * @param loc location of coordinate pair
     * @return std::string combined string form of coordinate pair
     */
    std::string location_text(std::pair<int, int> loc);
    };
}


#endif
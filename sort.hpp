#ifndef __SORT_HPP__
#define __SORT_HPP__

#include <cstdlib>
#include <iostream>

class Sort {
    public:
        Sort() {}
        virtual ~Sort() = default;
        virtual void reorder(Moviedatabase* movies, std::vector<std::vector<std::string>> recommendations) = 0;
};


#endif //__SORT_HPP__

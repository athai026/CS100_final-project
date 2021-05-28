#ifndef __SORT_HPP__
#define __SORT_HPP__

#include <cstdlib>
#include <iostream>

class Sort {
    public:
        Sort() {}
        ~Sort() {}
        void reorder(Moviedatabase& movies, int column_num) {
            std::vector<std::vector<std::string>> r = movies.get_recommendations();
            int i;
            int j;
            for (i = 1; i < r.size(); ++i) {
                j = i;
                while (j > 0) {
                    double curr = std::stod(r.at(j).at(column_num));
                    double prev = std::stod(r.at(j - 1).at(column_num));
                    if (curr > prev) {
                        swap(r.at(j), r.at(j - 1));
                    }
                    --j;
                }
            }
            movies.set_recommendations(r);
        }
};


#endif //__SORT_HPP__

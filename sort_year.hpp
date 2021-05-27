#ifndef __SORT_YEAR_HPP__
#define __SORT_YEAR_HPP__

#include "sort.hpp"

class Sort_Year : public Sort {
    private:
        int column_num;
    public:
        Sort_Year() {}
        void reorder(Moviedatabase* movies, std::vector<std::vector<std::string>> recommendations) {
            column_num = movies->get_column_by_keyword("Year");
            int i;
            int j;
            for (i = 1; i < recommendations.size(); ++i) {
                j = i;
                while (j > 0) {
                    double curr = std::stod(recommendations.at(j).at(column_num));
                    double prev = std::stod(recommendations.at(j-1).at(column_num));
                    if (curr > prev) {
                        swap(recommendations.at(j), recommendations.at(j-1));
                        //temp = recommendations.at(j);
                        //recommendations.at(j) = recommendations.at(j-1);
                        //recommendations.at(j-1) = temp;
                    }
                    --j;
                }
            }
        }
};

#endif // __SORT_YEAR_HPP__

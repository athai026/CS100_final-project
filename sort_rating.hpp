#ifndef __SORT_RATING_HPP__
#define __SORT_RATING_HPP__

#include "sort.hpp"

class Sort_Rating : public Sort {
    private:
        int column_num;
    public:
        Sort_Rating() {}
        void reorder(Moviedatabase* movies, std::vector<std::vector<std::string>> recommendations) {
            column_num = movies->get_column_by_keyword("Rate");
            int i;
            int j;
            for (i = 1; i < recommendations.size(); ++i) {
                j = i;
                while (j > 0) {
                    double curr = std::stod(recommendations.at(j).at(column_num));
                    double prev = std::stod(recommendations.at(j-1).at(column_num));
                    if (curr > prev) {
                        swap(recommendations.at(j), recommendations.at(j-1));
                    }
                    --j;
                }
            }
            movies->recommendations = recommendations;
            movies->print_recommendation(std::cout);
        }
};

#endif // __SORT_RATING_HPP__

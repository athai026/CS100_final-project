#ifndef __SORT_RATING_HPP__
#define __SORT_RATING_HPP__

#include "sort.hpp"

class Sort_Rating : public Sort {
    private:
        int column_num;
    public:
        void reorder(Moviedatabase* movies, std::vector<std::vector<std::string>>> recommendations) {
            column_num = get_column_by_keyword("Rate");
            int i;
            int j;
            std::vector<std::<string>> temp;
            for (i = 1; i < recommendations.size(); ++i) {
                j = i;
                while (j > 0 && recommendations.at(j).at(column_num) > recommendations.at(j-1).at(column_num)) {
                    swap(recommendations.at(j), recommendations.at(j-1));
                    --j;
                }
            }
        }
};

#endif // __SORT_RATING_HPP__

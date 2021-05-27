#ifndef __SORT_RATING_HPP__
#define __SORT_RATING_HPP__

#include "sort.hpp"

class Sort_Rating : public Sort {
    private:
        int column_num;
    public:
        Sort_Rating() {}
        void reorder(Moviedatabase* movies, std::vector<std::vector<std::string>> recommendations) {
            std::cout << "In reorder function" << std::endl;
            column_num = movies->get_column_by_keyword("Rate");
            std::cout << "Got column number: " << column_num << std::endl;
            std::cout << "size of rec vector: " << recommendations.size() << std::endl;
            int i;
            int j;
            std::vector<std::string> temp;
            for (i = 1; i < recommendations.size(); ++i) {
std::cout << "index: " << i << std::endl;
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
            std::cout << "Done reordering" << std::endl;
        }
};

#endif // __SORT_RATING_HPP__

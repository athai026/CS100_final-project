#ifndef __MOVIEDATABASE_HPP__
#define __MOVIEDATABASE_HPP__

#include <string>
#include <initializer_list>
#include <vector>
#include <iosfwd>

class Search;

class Sort;

class Moviedatabase
{
protected:
    std::vector<std::string> column_keywords;
    std::vector<std::vector<std::string>> data;
    std::vector<std::vector<std::string>> recommendations;
    Search* search = nullptr;
    

public:
    Moviedatabase();
    ~Moviedatabase();

    const std::string& cell_data(int row, int column) const;
    std::string& cell_data(int row, int column);

    void set_search(Search* new_search);
//    void set_sort(Sort* new_sort);
    void print_recommendation(std::ostream& out) const;
    void save_recommendation();
    void clear();
    void set_column_keywords(const std::vector<std::string>& keywords);
    void add_row(const std::vector<std::string>& row_data);
    int get_column_by_keyword(const std::string& keyword) const;
    void read_file();
    std::vector<std::vector<std::string>> get_recommendations();
    void set_recommendations(std::vector<std::vector<std::string>>);
    void read_file();
};

#endif //__MOVIEDATABASE_HPP__


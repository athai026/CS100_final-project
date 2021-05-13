#ifndef __MOVIEDATABASE_HPP__
#define __MOVIEDATABASE_HPP__

#include <string>
#include <initializer_list>
#include <vector>
#include <iosfwd>

class Search;

class Moviedatabase
{
    std::vector<std::string> column_keywords;
    std::vector<std::vector<std::string> > data;
    Search* search = nullptr;
    

public:
    ~Moviedatabase();

    const std::string& cell_data(int row, int column) const
    {
        return data.at(row).at(column);
    }

    std::string& cell_data(int row, int column)
    {
        return data.at(row).at(column);
    }

    void set_search(Search* new_search);


    void print_recommendation(std::ostream& out) const;

    void clear();
    void set_column_keywords(const std::vector<std::string>& keywords);
    void add_row(const std::vector<std::string>& row_data);
    void remove_row(Search* new_search);
    int get_column_by_keyword(const std::string& keyword) const;
    void save_to_file();
};

#endif //__MOVIEDATABASE_HPP__


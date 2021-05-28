#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <cstring>

class Search
{
public:
    virtual ~Search() {}

    virtual bool search(const Moviedatabase* movie, int row) const = 0;
};

class Search_Column: public Search
{
protected:
    int column;
public:
    ~Search_Column() {}
    Search_Column(const Moviedatabase* movie, const std::string& keyword)
    {
        column = movie->get_column_by_keyword(keyword);
    }

    virtual bool search(const Moviedatabase* movie, int row) const
    {
        return search(movie->cell_data(row, column));
    }


    virtual bool search(const std::string& s) const = 0;
};
class Search_Contains: public Search_Column
{
    std::string query;
public:
    ~Search_Contains() {}
    Search_Contains(const Moviedatabase* movie, const std::string& column, const std::string& query) : Search_Column(movie, column)
    {
        this->query = query;
    }
    bool search(const std::string& s) const
    {
        size_t found = s.find(query);
        if (found != std::string::npos)
        {
            return true;
        }
        return false;
    }
};


class Search_And: public Search
{
    Search* search_one = nullptr;
    Search* search_two = nullptr;
public:
    ~Search_And() {}
    Search_And(Search* search_one, Search* search_two)
    {
        this->search_one = search_one;
        this->search_two = search_two;
    }
    
    bool search(const Moviedatabase* movie, int row) const
    {
        return search_one->search(movie, row) && search_two->search(movie, row);
    }
};

class Search_Or: public Search
{
    Search* search_one = nullptr;
    Search* search_two = nullptr;
public:
    ~Search_Or() {}
    Search_Or(Search* search_one, Search* search_two)
    {
        this->search_one = search_one;
        this->search_two = search_two;
    }

    bool search(const Moviedatabase* movie, int row) const
    {
        return search_one->search(movie, row)|| search_two->search(movie, row);
    }
};

#endif //__SEARCH_HPP__
#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <cstring>

class Search
{
public:
    virtual ~Search() = default;

    virtual bool search(const Moviedatabase* movie, int row) const = 0;
};

class Search_Column: public Search
{
protected:
    int column;
public:
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

#endif //__SEARCH_HPP__


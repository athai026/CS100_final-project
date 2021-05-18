#include "moviedatabase.hpp"
#include "search.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
Moviedatabase::~Moviedatabase()
{
    delete search;
}

void Moviedatabase::set_search(Search* new_search)
{
    delete search;
    search = new_search;
}

void Moviedatabase::clear()
{
    column_keywords.clear();
    data.clear();
    delete search;
    search = nullptr;
}

void Moviedatabase::set_column_keywords(const std::vector<std::string>& keywords)
{
    column_keywords=keywords;
}

void Moviedatabase::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}
void Moviedatabase::remove_row(Search* new_search)
{
    for (int i=0; i<data.size(); i++) {
        if (search->search(this, i))
        {
            data.at(i).clear();
        }
    }
}

int Moviedatabase::get_column_by_keyword(const std::string& keyword) const
{
    for(int i=0; i<column_keywords.size(); i++)
        if(column_keywords.at(i) == keyword)
            return i;
    return -1;
}
void Moviedatabase::print_recommendation(std::ostream &out) const
{
    if (search == nullptr) {
        for (int i=0; i<data.size(); i++) {
            
                for (int j=0; j<data.at(i).size(); j++) {
                    out<<data.at(i).at(j)<<' ';
                }
                out<<'\n';
            
        }
    }
    else
    for (int i=0; i<data.size(); i++) {
        if (search->search(this, i))
        {
            for (int j=0; j<data.at(i).size(); j++) {
                out<<data.at(i).at(j)<<' ';
            }
            out<<'\n';
        }
    }
}
void Moviedatabase::save_recommendation() {
    for (int i = 0; i < data.size(); i++) {
        if (search->search(this, i)) {
            recommendations.push_back(data.at(i));
        }
    }
}
void Moviedatabase::save_to_file()
 {
    std::ofstream fs;
    fs.open("movies.txt", std::ios::out);
    fs.write((char *) & data, sizeof(data));
    fs.close();
}


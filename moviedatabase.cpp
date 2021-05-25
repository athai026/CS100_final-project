#include "moviedatabase.hpp"
#include "search.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <cstring>
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

int Moviedatabase::get_column_by_keyword(const std::string& keyword) const
{
    for(int i=0; i<column_keywords.size(); i++)
        if(column_keywords.at(i) == keyword)
            return i;
    return -1;
}
void Moviedatabase::print_recommendation(std::ostream &out) const
{
    if (search != nullptr)
    {
        out<<"Title/ Genre/ Director/ Actress/ Rate/ Year/ "<<std::endl;;
    for (int i=0; i<data.size(); i++) {
        if (search->search(this, i))
        {
            for (int j=0; j<data.at(i).size(); j++) {
                out<<data.at(i).at(j)<<"/ ";
            }
            out<<'\n';
        }
    }
    }
    else{out<<"No result";}
}
void Moviedatabase::read_file()
{
    std::fstream infile;
    infile.open("moviedata.txt");
    while(infile)
    {
      std::string s;
        if (!getline( infile, s )) break;

      std::istringstream ss( s );
      std::vector <std::string> record;
        
      while (ss)
      {
        std::string s;
        if (!getline( ss, s, ';' )) break;
        record.push_back( s );
      }

      data.push_back( record );
        
    }
    
    if (!infile.is_open())
    {
      std::cerr << "File can't open";
    }
    infile.close();
}

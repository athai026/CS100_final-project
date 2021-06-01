#include "moviedatabase.hpp"
#include "search.hpp"
#include "sort.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>

Moviedatabase::Moviedatabase() 
{
    search = nullptr;
}

Moviedatabase::~Moviedatabase()
{
    if (search != nullptr) {
        delete search;
        search = nullptr;
    }
}

const std::string& Moviedatabase::cell_data(int row, int column) const
{
    return data.at(row).at(column);
}

std::string& Moviedatabase::cell_data(int row, int column)
{
    return data.at(row).at(column);
}

void Moviedatabase::set_search(Search* new_search)
{
    if (search != nullptr) {
        delete search;
        search = nullptr;
    }
    search = new_search;
}


void Moviedatabase::clear()
{
    column_keywords.clear();
    data.clear();
    if (search != nullptr) {
        delete search;
        search = nullptr;
    }
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

    if (recommendations.empty()) {
        std::cout << "empty vector" << std::endl;
    }
    for (int i=0; i<recommendations.size(); i++) {
            for (int j=0; j<recommendations.at(i).size(); j++) {
                switch(j){
                    case 0:
                        out<<"Title: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 1:
                        out<<"Genre(s): "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 2:
                        out<<"Director(s): "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 3:
                        out<<"Starring: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 4:
                        out<<"Rating: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 5:
                        out<<"Release Year: "<<recommendations.at(i).at(j)<<std::endl;

                        break;
                    default:
                        break;
                }
            }
            out<<'\n';
    }
}
void Moviedatabase::save_recommendation() {
    recommendations.clear();
    if (search != nullptr) {
        for (int i = 0; i < data.size(); i++) {
            if (search->search(this, i)) {
                recommendations.push_back(data.at(i));
            }
        }
    }
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


std::vector<std::vector<std::string>> Moviedatabase::get_recommendations() {
    return recommendations;
}

void Moviedatabase::set_recommendations(std::vector<std::vector<std::string>> r) {
    recommendations = r;
}
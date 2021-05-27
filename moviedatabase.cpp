#include "moviedatabase.hpp"
#include "search.hpp"
#include "sort.hpp"
#include "sort_rating.hpp"
#include "sort_year.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
Moviedatabase::~Moviedatabase()
{
    delete search;
}

void Moviedatabase::set_search(Search* new_search)
{
    delete search;
    search = new_search;
}

void Moviedatabase::set_sort(Sort* new_sort) {
    sort = new_sort;
    sort->reorder(this, get_recommendations());
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
    std::cout << "In print recommendation function" << std::endl;
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
                        out<<"Genre: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 2:
                        out<<"Director: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 3:
                        out<<"Actor: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 4:
                        out<<"Rate: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    case 5:
                        out<<"Year: "<<recommendations.at(i).at(j)<<std::endl;
                        break;
                    default:
                        break;
                }
            }
            out<<'\n';
    }
    std::cout << "Done printing" << std::endl;
}
void Moviedatabase::save_recommendation() {
    if (search != nullptr) {
        for (int i = 0; i < data.size(); i++) {
            if (search->search(this, i)) {
                recommendations.push_back(data.at(i));
            }
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

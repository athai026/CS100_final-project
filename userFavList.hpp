#ifndef __USER_FAV_LIST_HPP__
#define __USER_FAV_LIST_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "moviedatabase.hpp"

using namespace std;

class UserFavList : public Moviedatabase {
    private:
        vector<vector<string>> favorites;
        int numAction, numAdventure, numAnimation, numBiography, numComedy, numCrime, numDrama, numFantasy, numHorror, numMusical, numMystery, numScifi, numThriller;
        string favGenre;
    
    public:
        UserFavList();
        ~UserFavList();
        void readList();
        void saveList();
        bool doesFileExist(string filename);
        int check(string movieTitle);
        void add_movie(string movieTitle);
        void delete_movie(string movieTitle);
        void clearList();
        bool exists(string movieTitle);
        string find_fav_genre();
        void print_favList(ostream &out);
};


#endif //__USER_FAV_LIST_HPP__

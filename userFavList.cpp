#include "userFavList.hpp"

UserFavList::UserFavList() {
    numAction = numAdventure = numAnimation = numBiography = numComedy = numCrime = numDrama = numFantasy = numHorror = numMusical = numMystery = numRomance = numScifi = numThriller = 0;
    string favGenre = "";

}

UserFavList::~UserFavList() {}

void UserFavList::readList() {
    ifstream inFS;
    if (doesFileExist("favList.txt")) {
        inFS.open("favList.txt");
        if (!inFS.is_open()) {
            cout << "Could not open favList.txt" << endl;
        }
        while(inFS) {
            string s;
            if (!getline( inFS, s )) break;

            istringstream ss( s );
            vector <string> record;
        
            while (ss) {
                string s;
                if (!getline( ss, s, ';' )) break;
                record.push_back( s );
            }

            favorites.push_back( record );
        }
        inFS.close();
    }
}

void UserFavList::saveList() {
    ofstream outFS;
    outFS.open("favList.txt");
    if (!outFS.is_open()) {
        cout << "Could not open favList.txt" << endl;
        return;
    }
    
    for (int i = 0; i < favorites.size(); ++i) {
        outFS << favorites.at(i).at(0) << ";";
        outFS << favorites.at(i).at(1) << ";";
        outFS << favorites.at(i).at(2) << ";";
        outFS << favorites.at(i).at(3) << ";";
        outFS << favorites.at(i).at(4) << ";";
        outFS << favorites.at(i).at(5) << endl;
    }
    
    outFS.close();
}

bool UserFavList::doesFileExist(string filename) {
    ifstream infile(filename);
    return infile.good();
}

int UserFavList::check(string movieTitle) {
    read_file();
    for (int i = 0; i < data.size(); ++i) {
        if (movieTitle == data.at(i).at(0)) {
            return i;
        }
    }
    cout << "Invalid movie title" << endl;
    return -1;
}

void UserFavList::add_movie(string movieTitle) {
    int index = check(movieTitle);
    if (index != -1) {
        if (!exists(movieTitle)) {
            favorites.push_back(data.at(index));
        }
        else {
            cout << "Movie already added to favorites list" << endl;
        }
    }
}

void UserFavList::delete_movie(string movieTitle) {
    if (!exists(movieTitle)) {
        cout << "Movie is not in favorites list" << endl;
    }
    else {
        vector<vector<string>>::iterator it = favorites.begin();
        for (int i = 0; i < favorites.size(); ++i) {
            if (favorites.at(i).at(0) == movieTitle) {
                favorites.erase(it);
                break;
            }
            ++it;
        }
    }
}

bool UserFavList::exists(string movieTitle) {
    for (int i = 0; i < favorites.size(); ++i) {
        if (favorites.at(i).at(0) == movieTitle) {
            return true;
        }
    }
    return false;
}

void UserFavList::clearList() {
    favorites.clear();
}

void UserFavList::print_favList(ostream &out) {
    if (favorites.empty()) {
        std::cout << "empty vector" << std::endl;
    }
    for (int i=0; i<favorites.size(); i++) {
            for (int j=0; j<favorites.at(i).size(); j++) {
                switch(j){
                    case 0:
                        out<<"Title: "<<favorites.at(i).at(j)<<std::endl;
                        break;
                    case 1:
                        out<<"Genre(s): "<<favorites.at(i).at(j)<<std::endl;
                        break;
                    case 2:
                        out<<"Director(s): "<<favorites.at(i).at(j)<<std::endl;
                        break;
                    case 3:
                        out<<"Starring: "<<favorites.at(i).at(j)<<std::endl;
                        break;
                    case 4:
                        out<<"Rating: "<<favorites.at(i).at(j)<<std::endl;
                        break;
                    case 5:
                        out<<"Release Year: "<<favorites.at(i).at(j)<<std::endl;
                        break;
                    default:
                        break;
                }
            }
            out<<'\n';
    }
}

string UserFavList::find_fav_genre() {
    int max;

    for (int i = 0; i < favorites.size(); ++i) {
        size_t found = favorites.at(i).at(1).find("action");
        if (found != string::npos) {
            ++numAction;
        }

        found = favorites.at(i).at(1).find("adventure");
        if (found != string::npos) {
            ++numAdventure;
        }

        found = favorites.at(i).at(1).find("animation");
        if (found != string::npos) {
            ++numAnimation;
        }

        found = favorites.at(i).at(1).find("biography");
        if (found != string::npos) {
            ++numBiography;
        }

        found = favorites.at(i).at(1).find("comedy");
        if (found != string::npos) {
            ++numComedy;
        }

        found = favorites.at(i).at(1).find("crime");
        if (found != string::npos) {
            ++numCrime;
        }

        found = favorites.at(i).at(1).find("drama");
        if (found != string::npos) {
            ++numDrama;
        }

        found = favorites.at(i).at(1).find("fantasy");
        if (found != string::npos) {
            ++numFantasy;
        }

        found = favorites.at(i).at(1).find("horror");
        if (found != string::npos) {
            ++numHorror;
        }

        found = favorites.at(i).at(1).find("musical");
        if (found != string::npos) {
            ++numMusical;
        }

        found = favorites.at(i).at(1).find("mystery");
        if (found != string::npos) {
            ++numMystery;
        }

        found = favorites.at(i).at(1).find("romance");
        if (found != string::npos) {
            ++numRomance;
        }

        found = favorites.at(i).at(1).find("sci-fi");
        if (found != string::npos) {
            ++numScifi;
        }

        found = favorites.at(i).at(1).find("thriller");
        if (found != string::npos) {
            ++numThriller;
        }
    }
    
    if (numAction > numAdventure) {
        max = numAction;
        favGenre = "action";
    }
    else {
        max = numAdventure;
        favGenre = "adventure";
    }
    if (max < numAnimation) {
        max = numAnimation;
        favGenre = "animation";
    }
    if (max < numBiography) {
        max = numBiography;
        favGenre = "biography";
    }
    if (max < numComedy) {
        max = numComedy;
        favGenre = "comedy";
    }
    if (max < numCrime) {
        max = numCrime;
        favGenre = "crime";
    }
    if (max < numDrama) {
        max = numDrama;
        favGenre = "drama";
    }
    if (max < numFantasy) {
        max = numFantasy;
        favGenre = "fantasy";
    }
    if (max < numHorror) {
        max = numHorror;
        favGenre = "horror";
    }
    if (max < numMusical) {
        max = numMusical;
        favGenre = "musical";
    }
    if (max < numMystery) {
        max = numMystery;
        favGenre = "mystery";
    }
    if (max < numRomance) {
        max = numRomance;
        favGenre = "romance";
    }
    if (max < numScifi) {
        max = numScifi;
        favGenre = "sci-fi";
    }
    if (max < numThriller) {
        max = numThriller;
        favGenre = "thriller";
    }

    return favGenre;       
}

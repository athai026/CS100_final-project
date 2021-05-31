#include "moviedatabase.hpp"
#include "sort.hpp"
#include "search.hpp"

#include <string>
#include <initializer_list>
#include <vector>
#include <iosfwd>
#include <sstream>
#include <iostream>

using namespace std;

void searching(Moviedatabase& movie);
void sorting(Moviedatabase& movie);

int main(int argc, char* argv[])
{
    char select;
    bool loop = true;
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actor","Rate","Year"});
    movie.read_file();    
    cout << "Welcome to our movie recommender!" << endl;

    while(loop)
    {
        cout << endl << "Please read the menu below and choose an option" << endl;
        cout << "__________________________________________________" << endl;
        cout << endl << "S - search for a movie" << endl;
        //cout << "V - view favorite movie list" << endl;
        //cout << "R - remove a movie from favorite movie list" << endl;
        cout << "Q - quit and exit program" << endl;
        cout << endl << "Enter selection: ";
        cin >> select;
        cout << endl;

        switch(select)
        {
            case 'S':
    	    case 's': 
            {
	        searching(movie);
            } break;
            case 'Q':
            case 'q': 
            {
	        cout << "Thank you! Goodbye :)" << endl;
		loop = false;
	        return 0;
            } break;
            default: cout << "Invalid selection, please try again" << endl;
        }
        
        cout << "Would you like to make another selection? (Y for yes or any other key for no)" << endl;
        char c;
        cin >> c;

        if(c == 'y' || c == 'Y') 
	{ 
	    continue; 
	} 
        else 
        { 
            loop = false; 
	    cout << endl << endl << "Thank you! Goodbye :)" << endl;
	}
    } 

    return 0; 
}

void sorting(Moviedatabase& movie)
{
    Sort s;
    string user_ans1;
    string user_ans2;
    cout << "Would you like your recommendation to be sorted? (yes/no)" << endl;
    cin >> user_ans1;
    cout << endl;

    if (user_ans1 == "yes" || user_ans1 == "y" || user_ans1 == "Y" || user_ans1 == "Yes") {
        cout << "How would you like it sorted? By rating or by release year?" << endl;
        cin >> user_ans2;
        cout << endl;

        if (user_ans2 == "rating" || user_ans2 == "r") {
            s.reorder(movie, 4);
        }
        else if (user_ans2 == "year" || user_ans2 == "y") {
            s.reorder(movie, 5);
        }
        else {
            cout << "Sorry invalid input" << endl;
        }
    }
    else {
        cout << "Not sorted:" << endl << endl;
    }
}

void searching(Moviedatabase& movie)
{
    string user_input1;
    string user_input2;
    string user_input3;
    cout<<"Choose your search option" << endl << "_________________________" << endl;
    cout<<"1.Actor "<< endl;
    cout<<"2.Genre"<< endl;
    cout<<"3.Genre & Genre "<< endl;
    cout<<"4.Genre/Genre "<< endl;
    cout<<"5.Genre & Actor "<< endl;
    cout<<"6.Genre & Director"<< endl;
    cout << endl << "Search by option #";
    cin >> user_input1;
    cout << endl;
 
    stringstream to_Int1(user_input1);
    int input1 = 0;
    to_Int1>>input1;
    switch (input1) {
        case 1:
            cout <<"Enter name of the actress: ";
            cin.ignore();
            getline(cin, user_input2);
	    cout << endl;
            movie.set_search(new Search_Contains(&movie,"Actor",user_input2));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 2:
            cout <<"Enter genre of movie: ";
            cin.ignore();
            getline(cin, user_input2);
	    cout << endl;
            movie.set_search(new Search_Contains(&movie,"Genre",user_input2));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 3:
            cout <<"Enter your first genre: ";
            cin.ignore();
            getline(cin, user_input2);
	    cout << endl;
            cout <<"Enter your second genre: ";
            cin.ignore();
            getline(cin, user_input3);
	    cout << endl;
            movie.set_search(new Search_And(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Genre",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 4:
            cout <<"Enter your first genre: ";
            cin.ignore();
            getline(cin, user_input2);
	    cout << endl;
            cout <<"Enter your second genre: ";
            cin.ignore();
            getline(cin, user_input3);
	    cout << endl;
            movie.set_search(new Search_Or(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Genre",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 5:
            cout <<"Enter your genre: ";
            cin.ignore();
            getline(cin, user_input2);
	    cout << endl;
            cout <<"Enter your actor: ";
            cin.ignore();
            getline(cin, user_input3);
	    cout << endl;
            movie.set_search(new Search_And(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Actor",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 6:
            cout <<"Enter your genre: ";
            cin.ignore();
            getline(cin, user_input2);
	    cout << endl;
            cout <<"Enter your director: ";
            cin.ignore();
            getline(cin, user_input3);
	    cout << endl;
            movie.set_search(new Search_And(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Director",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        default:
            break;
    }
}

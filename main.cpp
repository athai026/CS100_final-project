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
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actor","Rate","Year"});
    movie.read_file();


    searching(movie);
    cout << "Thank you" << endl;
    return 0;
}

void sorting(Moviedatabase& movie)
{
    Sort s;
    string user_ans1;
    string user_ans2;
    cout << "Would you like your recommendation to be sorted? (yes/no)" << endl;
    cin >> user_ans1;

    if (user_ans1 == "yes") {
        cout << "How would you like it sorted? By rating or by release year?" << endl;
        cin >> user_ans2;

        if (user_ans2 == "rating") {
            s.reorder(movie, 4);
        }
        else if (user_ans2 == "year") {
            s.reorder(movie, 5);
        }
        else {
            cout << "Sorry invalid input" << endl;
        }
    }
    else {
        cout << "No sorting:" << endl;
    }
}

void searching(Moviedatabase& movie)
{
    string user_input1;
    string user_input2;
    string user_input3;
    cout<<"Choose your search option:"<< endl;
    cout<<"1.Actor "<< endl;
    cout<<"2.Genre"<< endl;
    cout<<"3.Genre&Genre "<< endl;
    cout<<"4.Genre/Genre "<< endl;
    cout<<"5.Genre&Actor "<< endl;
    cout<<"6.Genre&Director"<< endl;
    cin >> user_input1;

    stringstream to_Int1(user_input1);
    int input1 =0;
    to_Int1>>input1;
    switch (input1) {
        case 1:
            cout <<"Enter name of the actress :"<< endl;
            cin.ignore();
            getline(cin, user_input2);
            movie.set_search(new Search_Contains(&movie,"Actor",user_input2));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 2:
            cout <<"Enter genre of movie :"<< endl;
            cin.ignore();
            getline(cin, user_input2);
            movie.set_search(new Search_Contains(&movie,"Genre",user_input2));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 3:
            cout <<"Enter your first genre :"<< endl;
            cin.ignore();
            getline(cin, user_input2);
            cout <<"Enter your second genre :"<< endl;
            cin.ignore();
            getline(cin, user_input3);
            movie.set_search(new Search_And(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Genre",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 4:
            cout <<"Enter your first genre :"<< endl;
            cin.ignore();
            getline(cin, user_input2);
            cout <<"Enter your second genre :"<< endl;
            cin.ignore();
            getline(cin, user_input3);
            movie.set_search(new Search_Or(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Genre",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 5:
            cout <<"Enter your genre :"<< endl;
            cin.ignore();
            getline(cin, user_input2);
            cout <<"Enter your actor :"<< endl;
            cin.ignore();
            getline(cin, user_input3);
            movie.set_search(new Search_And(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Actor",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        case 6:
            cout <<"Enter your genre :"<< endl;
            cin.ignore();
            getline(cin, user_input2);
            cout <<"Enter your director :"<< endl;
            cin.ignore();
            getline(cin, user_input3);
            movie.set_search(new Search_And(new Search_Contains(&movie,"Genre",user_input2),new Search_Contains(&movie,"Director",user_input3)));
            movie.save_recommendation();
            sorting(movie);
            movie.print_recommendation(std::cout);
            break;
        default:
            break;
    }
}


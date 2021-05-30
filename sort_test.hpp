#ifndef __SORT_TEST_HPP__
#define __SORT_TEST_HPP__

#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "moviedatabase.cpp"
#include "search.hpp"
#include "sort.hpp" 

TEST(SortFunction, SortByRating_romantic) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Contains(&movie,"Genre","romantic"));
    movie.save_recommendation();
    Sort s;
    s.reorder(movie, 4);
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(), "Title: The Help\nGenre(s): romantic,historical\nDirector(s): Tate Taylor\nStarring: Emma Stone\nRating: 8\nRelease Year: 2011\n\nTitle: Titanic\nGenre(s): romantic,drama\nDirector(s): James Cameron\nStarring: Leonardo DiCaprio and Kate Winslet\nRating: 7.8\nRelease Year: 1997\n\n");
}

TEST(SortFunction, SortByYear_romantic) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Contains(&movie,"Genre","romantic"));
    movie.save_recommendation();
    Sort s;
    s.reorder(movie, 5);
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(), "Title: The Help\nGenre(s): romantic,historical\nDirector(s): Tate Taylor\nStarring: Emma Stone\nRating: 8\nRelease Year: 2011\n\nTitle: Titanic\nGenre(s): romantic,drama\nDirector(s): James Cameron\nStarring: Leonardo DiCaprio and Kate Winslet\nRating: 7.8\nRelease Year: 1997\n\n");
}

#endif //__SORT_TEST_HPP__

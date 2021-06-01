#ifndef __SEARCH_TEST_HPP__
#define __SEARCH_TEST_HPP__

#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "moviedatabase.cpp"
#include "search.hpp"
 

TEST(SearchFunction, Search_Contains_AGenre) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Contains(&movie,"Genre","romantic"));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: Titanic\nGenre(s): romantic,drama\nDirector(s): James Cameron\nStarring: Leonardo DiCaprio and Kate Winslet\nRating: 7.8\nRelease Year: 1997\n\nTitle: The Help\nGenre(s): romantic,historical\nDirector(s): Tate Taylor\nStarring: Emma Stone\nRating: 8\nRelease Year: 2011\n\n");
}
TEST(SearchFunction, Search_Contains_NameOfStarring) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Contains(&movie,"Actress","Emma Stone"));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: The Help\nGenre(s): romantic,historical\nDirector(s): Tate Taylor\nStarring: Emma Stone\nRating: 8\nRelease Year: 2011\n\n");
}
TEST(SearchFunction, Search_Contains_MovieFromAyear) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Contains(&movie,"Year","2018"));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: Skyscraper\nGenre(s): action,thriller\nDirector(s): Rawson Marshall Thurber\nStarring: Dwayne Johnson\nRating: 6\nRelease Year: 2018\n\nTitle: Deadpool 2\nGenre(s): action,adventure,sci-fi\nDirector(s): David Leitch\nStarring: Ryan Reynolds\nRating: 8\nRelease Year: 2018\n\n");
}
TEST(SearchFunction, Search_And_GenreAndDirector) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_And(new Search_Contains(&movie,"Genre","romantic"),new Search_Contains(&movie,"Director","James Cameron")));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: Titanic\nGenre(s): romantic,drama\nDirector(s): James Cameron\nStarring: Leonardo DiCaprio and Kate Winslet\nRating: 7.8\nRelease Year: 1997\n\n");
}
TEST(SearchFunction, Search_And_GenreAndStarring) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_And(new Search_Contains(&movie,"Genre","thriller"),new Search_Contains(&movie,"Actress","Rose Byrne")));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: Insidious\nGenre(s): horror,thriller\nDirector(s): James Wan\nStarring: Patrick Wilson and Rose Byrne\nRating: 7\nRelease Year: 2010\n\n");
}
TEST(SearchFunction, Search_And_TwoGenres) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_And(new Search_Contains(&movie,"Genre","adventure"),new Search_Contains(&movie,"Genre","fantasy")));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: Maleficent\nGenre(s): fantasy,adventure\nDirector(s): Robert Stromberg\nStarring: Angelina Jolie\nRating: 7\nRelease Year: 2014\n\n");
}
TEST(SearchFunction, Search_Or_NamesOfStarrings) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Or(new Search_Contains(&movie,"Actress","Angelina Jolie"),new Search_Contains(&movie,"Actress","Tom Cruise")));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: The Mummy\nGenre(s): action,thriller\nDirector(s): Alex Kurtzman\nStarring: Tom Cruise\nRating: 7\nRelease Year: 2017\n\nTitle: Maleficent\nGenre(s): fantasy,adventure\nDirector(s): Robert Stromberg\nStarring: Angelina Jolie\nRating: 7\nRelease Year: 2014\n\n");
}
TEST(SearchFunction, Search_Or_FromTwoDifferentYears) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos Lopez Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Or(new Search_Contains(&movie,"Year","2013"),new Search_Contains(&movie,"Year","2021")));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: Raya and The Last Dragon\nGenre(s): animation,action,adventure\nDirector(s): Don Hall, Carlos Lopez Estrada\nStarring: Kelly Marie Tran and Awkwafina\nRating: 7.4\nRelease Year: 2021\n\nTitle: Frozen\nGenre(s): animation\nDirector(s): Chris Buck and Jennifer Lee\nStarring: Kristen Bell, Idina Menzel and Jonathan Groff\nRating: 7\nRelease Year: 2013\n\n");
}
TEST(SearchFunction, Search_Or_TwoGenres) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos Lopez Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_Or(new Search_Contains(&movie,"Genre","animation"),new Search_Contains(&movie,"Genre","adventure")));
    movie.save_recommendation();
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"Title: Raya and The Last Dragon\nGenre(s): animation,action,adventure\nDirector(s): Don Hall, Carlos Lopez Estrada\nStarring: Kelly Marie Tran and Awkwafina\nRating: 7.4\nRelease Year: 2021\n\nTitle: Deadpool 2\nGenre(s): action,adventure,sci-fi\nDirector(s): David Leitch\nStarring: Ryan Reynolds\nRating: 8\nRelease Year: 2018\n\nTitle: Maleficent\nGenre(s): fantasy,adventure\nDirector(s): Robert Stromberg\nStarring: Angelina Jolie\nRating: 7\nRelease Year: 2014\n\nTitle: Frozen\nGenre(s): animation\nDirector(s): Chris Buck and Jennifer Lee\nStarring: Kristen Bell, Idina Menzel and Jonathan Groff\nRating: 7\nRelease Year: 2013\n\n");
}

TEST(SearchFunction, Search_And_Genre_NotGenre) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_And(new Search_Contains(&movie,"Genre","action"),new Search_Not(new Search_Contains(&movie,"Genre","thriller"))));
    movie.save_recommendation();
    Sort s;
    s.reorder(movie, 5);
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(), "Title: Raya and The Last Dragon\nGenre(s): animation,action,adventure\nDirector(s): Don Hall, Carlos Lopez Estrada\nStarring: Kelly Marie Tran and Awkwafina\nRating: 7.4\nRelease Year: 2021\n\nTitle: Deadpool 2\nGenre(s): action,adventure,sci-fi\nDirector(s): David Leitch\nStarring: Ryan Reynolds\nRating: 6\nRelease Year: 2018\n\n");
}

TEST(SearchFunction, Search_And_Genre_NotDirector) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    movie.add_row({"Titanic","romantic,drama","James Cameron","Leonardo DiCaprio and Kate Winslet","7.8","1997"});
    movie.add_row({"Raya and The Last Dragon","animation,action,adventure","Don Hall, Carlos López Estrada","Kelly Marie Tran and Awkwafina","7.4","2021"});
    movie.add_row({"The Mummy","action,thriller","Alex Kurtzman","Tom Cruise","7","2017"});
    movie.add_row({"Skyscraper","action,thriller","Rawson Marshall Thurber","Dwayne Johnson","6","2018"});
    movie.add_row({"Deadpool 2","action,adventure,sci-fi","David Leitch","Ryan Reynolds","8","2018"});
    movie.add_row({"Maleficent","fantasy,adventure","Robert Stromberg","Angelina Jolie","7","2014"});
    movie.add_row({"The Help","romantic,historical","Tate Taylor","Emma Stone","8","2011"});
    movie.add_row({"Insidious","horror,thriller","James Wan","Patrick Wilson and Rose Byrne","7","2010"});
    movie.add_row({"Frozen","animation","Chris Buck and Jennifer Lee","Kristen Bell, Idina Menzel and Jonathan Groff","7","2013"});
    movie.set_search(new Search_And(new Search_Contains(&movie,"Genre","horror"), new Search_Not(new Search_Contains(&movie,"Director","James Wan"))));
    movie.save_recommendation();
    Sort s;
    s.reorder(movie, 5);
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(), "");
}

#endif //__SEARCH_TEST_HPP__

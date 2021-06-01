#ifndef __USER_FAV_LIST_TEST_HPP__
#define __USER_FAV_LIST_TEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "userFavList.hpp"

TEST(UserFavList_FindFavGenre, animation) {
    UserFavList fav;
    fav.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    fav.add_movie("Raya and The Last Dragon");
    fav.add_movie("Frozen");
    fav.add_movie("The Lion King");
    fav.add_movie("My Neighbor Totoro");
    fav.add_movie("Inside Out");
    std::string genre = fav.find_fav_genre();
    EXPECT_EQ(genre, "animation");
}

TEST(UserFavList_FindFavGenre, action) {
    UserFavList fav;
    fav.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    fav.add_movie("Titanic");
    fav.add_movie("Raya and The Last Dragon");
    fav.add_movie("Skyscraper");
    fav.add_movie("Deadpool 2");
    fav.add_movie("Maleficent");
    std::string genre = fav.find_fav_genre();
    EXPECT_EQ(genre, "action");
}

TEST(UserFavList_FindFavGenre, drama) {
    UserFavList fav;
    fav.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    fav.add_movie("Metropolis");
    fav.add_movie("Memento");
    fav.add_movie("Alien");
    fav.add_movie("Interstellar");
    fav.add_movie("Good Will Hunting");
    std::string genre = fav.find_fav_genre();
    EXPECT_EQ(genre, "drama");
}

TEST(UserFavList_FindFavGenre, comedy) {
    UserFavList fav;
    fav.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    fav.add_movie("Amadeus");
    fav.add_movie("Ikiru");
    fav.add_movie("Toy Story 3");
    fav.add_movie("Snatch");
    fav.add_movie("The Great Dictator");
    std::string genre = fav.find_fav_genre();
    EXPECT_EQ(genre, "comedy");
}

TEST(UserFavList_FindFavGenre, horror) {
    UserFavList fav;
    fav.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    fav.add_movie("Insidious");
    fav.add_movie("Spiral");
    fav.add_movie("Psycho");
    fav.add_movie("Alien");
    fav.add_movie("The Thing");
    std::string genre = fav.find_fav_genre();
    EXPECT_EQ(genre, "horror");
}

TEST(UserFavList_FindFavGenre, biography) {
    UserFavList fav;
    fav.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    fav.add_movie("Goodfellas");
    fav.add_movie("The Pianist");
    fav.add_movie("Hamilton");
    fav.add_movie("Braveheart");
    fav.add_movie("Amadeus");
    std::string genre = fav.find_fav_genre();
    EXPECT_EQ(genre, "biography");
}

TEST(UserFavList_FindFavGenre, crime) {
    UserFavList fav;
    fav.set_column_keywords({"Title","Genre","Director","Actress","Rate","Year"});
    fav.add_movie("Spiral");
    fav.add_movie("The Godfather");
    fav.add_movie("The Dark Knight");
    fav.add_movie("12 Angry Men");
    fav.add_movie("Goodfellas");
    std::string genre = fav.find_fav_genre();
    EXPECT_EQ(genre, "crime");
}


#endif

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


#endif

#include "moviedatabase.cpp"
#include "search.hpp"

#include "gtest/gtest.h"

TEST(PrintTest, listOfAddedMovies) {
    Moviedatabase movie;
    movie.set_column_keywords({"Title","Genre","Starring","Rate","Year"});
    movie.add_row({"titanic","romantic","Leonardo DiCaprio and Kate Winslet","8","1997"});
    movie.add_row({"raya and the last dragon","animation","Kelly Marie Tran and Awkwafina","7","2021"});
    std::stringstream out;
    movie.print_recommendation(out);
    EXPECT_EQ(out.str(),"titanic romantic Leonardo DiCaprio and Kate Winslet 8 1997 \nraya and the last dragon animation Kelly Marie Tran and Awkwafina 7 2021 \n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


#ifndef ASSESSMENT_SCREEN_H
#define ASSESSMENT_SCREEN_H

#include <iostream>
#include "Movie.h"

using namespace std;

class Screen{
    int screenId;
    int numberOfSeats;
    Movie currentMovie;
    string screenType;

public:

    Screen();

    Screen(int, int, Movie, string);

    Screen(int, int, string);

    int getScreenId();

    void setScreenId(int);

    int getNumberOfSeats();

    void setNumberOfSeats(int);

    Movie getCurrentMovie();

    void setCurrentMovie(Movie);

    string getScreenType();

    void setScreenType(string);

    void displayScreen();
};


#endif //ASSESSMENT_SCREEN_H

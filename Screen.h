
#ifndef ASSESSMENT_SCREEN_H
#define ASSESSMENT_SCREEN_H

#include <iostream>
#include "Movie.h"

using namespace std;

class Screen{
    int screenId;   // the id of the screen
    int numberOfSeats;  // the capacity of the screen
    Movie currentMovie; // the current movie on the screen
    string screenType;  // the facility of the screen, i.e. IMAX or 3D or Premium

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

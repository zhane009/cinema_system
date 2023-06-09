
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

    int getScreenId();

    void setScreenId(int);

    int getNumberOfSeats();

    void setNumberOfSeats(int);

    Movie getCurrentMovie();

    void setCUrrentMovie(Movie);

    string getScreenType();

    void setScreenType(string);
};


#endif //ASSESSMENT_SCREEN_H

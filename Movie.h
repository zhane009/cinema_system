//
// Created by ASUS on 05/06/2023.
//

#ifndef ASSESSMENT_MOVIE_H
#define ASSESSMENT_MOVIE_H

#include <iostream>
#include "vector"
//#include "WeeklySchedule.h"
//#include "Booking.h"

using namespace std;

class Movie{
    string title;
    string description;
    string genre;
    int runningTimeInMinutes;
    string mainStar;
    string distributor;
    string releaseDate;

public:
    Movie();

    Movie(string, string, string, int, string, string, string);

    string getTitle();

    void setTitle(string);

    string getDescription();

    void setDescription(string);

    string getGenre();

    void setGenre(string);

    int getRunningTimeInMinutes();

    void setRunningTimeInMinutes(int);

    string getMainStar();

    void setMainStar(string);

    string getDistributor();

    void setDistributor(string);

    string getReleaseDate();

    void setReleaseDate(string);

    Movie getInput();

};

#endif //ASSESSMENT_MOVIE_H

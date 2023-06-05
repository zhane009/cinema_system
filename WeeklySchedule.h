//
// Created by ASUS on 05/06/2023.
//

#ifndef ASSESSMENT_WEEKLYSCHEDULE_H
#define ASSESSMENT_WEEKLYSCHEDULE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Movie.h"

using namespace std;

class WeeklySchedule {
    vector<Movie> availableMovies;
    vector<string> availableTimes;

public:
    Movie* getAvailableMovies();

    void setMovieInAvailableSchedule(Movie);

    string* getAvailableTimes();

    void setAvailableTimes(int);

    void readFromFile();

    void writeToFile(Movie);

    int getMoviesSize();

    int getTimesSize();

    void displayMovies();

};
#endif //ASSESSMENT_WEEKLYSCHEDULE_H

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
#include "Booking.h"

using namespace std;

class WeeklySchedule {
    vector<Movie> availableMovies;
    vector<string> availableTimes;

public:
    Movie* getAvailableMovies();

    void setMovieInAvailableSchedule(Movie);

    void readFromFile();

    void writeToFile(Movie);

    int getMoviesSize();

    void displayMovies();

    int checkAndFixError();

    void setAvailableTimes(int, string);

    string* getAvailableTimes();

    void editAvailableTimes();

    int getTimesSize();

    void displayAllAvailableTimes();

    void setTimeInAvailableTimes(string tempTime);
};
#endif //ASSESSMENT_WEEKLYSCHEDULE_H

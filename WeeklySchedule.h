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
#include "Screen.h"

using namespace std;

class WeeklySchedule {
private:
    vector<Screen> screens;
    vector<Movie> availableMovies;
    vector<string> availableTimes;

public:
    Movie* getAvailableMovies();

    void setMovieInAvailableSchedule(Movie);

    void readMoviesFromFile(int);

    void writeToMovieFile(Movie, int);

    int getMoviesSize();

    void displayMovies();

    int checkAndFixError();

    void setAvailableTimes(int, string);

    string* getAvailableTimes();

    string editAvailableTimes();

    int getTimesSize();

    void displayAllAvailableTimes();

    void setTimeInAvailableTimes(string tempTime);

//    int getMovieChoice();

    Screen* getScreens();

    void setScreenInScreens(Screen);

    void readScreenFromFile();

    void writeToScreenFile();

    void displayScreens();

    int getScreenSize();

    bool canAddMovies(int);
};

#endif //ASSESSMENT_WEEKLYSCHEDULE_H

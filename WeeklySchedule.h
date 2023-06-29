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
    vector<Screen> screens; // the vector of all screens
    vector<Movie> availableMovies;  // the vector of all movies in a week
    vector<string> availableTimes;  // the vector of all show times for a movie

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

    Screen* getScreens();

    void setScreenInScreens(Screen);

    void readScreenFromFile(int);

    void displayScreens();

    int getScreenSize();

    bool canAddMovies(int);

    void displaySchedule();

    void editMovieSetToScreen(int, int);
};

#endif //ASSESSMENT_WEEKLYSCHEDULE_H

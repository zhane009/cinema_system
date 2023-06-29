
#ifndef ASSESSMENT_MOVIE_H
#define ASSESSMENT_MOVIE_H

#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Movie{
    string title;   // the title of the movie
    string description; // the description of the movie
    string genre;   // the genre of the movie
    int runningTimeInMinutes;   // the running time of the movie in minutes
    string mainStar;    // the main star of the movie
    string distributor; // the distributor of the movie
    string releaseDate; // the release date of the movie

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

    int checkAndFixError();

    bool checkDateFormat(string);

};

#endif //ASSESSMENT_MOVIE_H

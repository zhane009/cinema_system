#include "Screen.h"

using namespace std;

Screen::Screen() {

}

Screen::Screen(int tempID, int tempSeats, Movie tempMovie, string tempType) {
    screenId = tempID;
    numberOfSeats = tempSeats;
    currentMovie = tempMovie;
    screenType  = tempType;
}

int Screen::getScreenId() {
    return screenId;
}

void Screen::setScreenId(int tempScreenId) {
    screenId = tempScreenId;
}

int Screen::getNumberOfSeats() {
    return numberOfSeats;
}

void Screen::setNumberOfSeats(int tempNumberOfSeats) {
    numberOfSeats = tempNumberOfSeats;
}

Movie Screen::getCurrentMovie() {
    return currentMovie;
}

void Screen::setCurrentMovie(Movie tempCurrentMovie) {
    currentMovie = tempCurrentMovie;
}

string Screen::getScreenType() {
    return screenType;
}

void Screen::setScreenType(string tempScreenType) {
    screenType = tempScreenType;
}


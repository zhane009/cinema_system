#include "Movie.h"

using namespace std;

Movie::Movie() {};

Movie::Movie(string tempTitle, string tempDescription, string tempGenre, int tempRuntime, string tempMainStar, string tempDistributor, string tempReleaseDate) {
    title = tempTitle;
    description = tempDescription;
    genre = tempGenre;
    runningTimeInMinutes = tempRuntime;
    mainStar = tempMainStar;
    distributor = tempDistributor;
    releaseDate = tempReleaseDate;
}

string Movie::getTitle() {
    return title;
}

void Movie::setTitle(string tempTitle) {
    title = tempTitle;
}

string Movie::getDescription() {
    return description;
}

void Movie::setDescription(string tempDescription) {
    description = tempDescription;
}

string Movie::getGenre() {
    return genre;
}

void Movie::setGenre(string tempGenre) {
    genre = tempGenre;
}

int Movie::getRunningTimeInMinutes() {
    return runningTimeInMinutes;
}

void Movie::setRunningTimeInMinutes(int tempRunningTimeInMinutes) {
    runningTimeInMinutes = tempRunningTimeInMinutes;
}

string Movie::getMainStar() {
    return mainStar;
}

void Movie::setMainStar(string tempMainStar) {
    mainStar = tempMainStar;
}

string Movie::getDistributor() {
    return distributor;
}

void Movie::setDistributor(string tempDistributor) {
    distributor = tempDistributor;
}

string Movie::getReleaseDate() {
    return releaseDate;
}

void Movie::setReleaseDate(string tempReleaseDate) {
    releaseDate = tempReleaseDate;
}

Movie Movie::getInput() {

    cin.clear();
    cin.ignore();
    Movie movie;
    string input;
    cout << "Movie Title: ";
    getline(cin, input);
    movie.setTitle(input);

    cout << "Description: ";
    getline(cin, input);
    movie.setDescription(input);

    cout << "Movie Genre: ";
    getline(cin, input);
    movie.setGenre(input);

    cout << "Running Time in Minutes: ";
    getline(cin, input);
    movie.setRunningTimeInMinutes(stoi(input));

    cout << "Name of Main Star: ";
    getline(cin, input);
    movie.setMainStar(input);

    cout << "Distributor: ";
    getline(cin, input);
    movie.setDistributor(input);

    cout << "Release Date of the Movie: ";
    getline(cin, input);
    movie.setReleaseDate(input);

    return movie;

}

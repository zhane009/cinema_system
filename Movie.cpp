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
    int temp;
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
    temp = checkAndFixError();
    movie.setRunningTimeInMinutes(temp);

    cout << "Name of Main Star: ";
    cin.ignore();
    cin.clear();
    getline(cin, input);
    movie.setMainStar(input);

    cout << "Distributor: ";
    getline(cin, input);
    movie.setDistributor(input);

    cout << "Release Date of the Movie in dd/mm/yyyy format: ";

    do {
        getline(cin, input);
    }
    while (!checkDateFormat(input));
    movie.setReleaseDate(input);

    return movie;

}

int Movie::checkAndFixError() {
    int temp;
    while (!(cin >> temp)){
        cout << "Invalid Input. Please type in only an integer." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return temp;

}

bool Movie::checkDateFormat(string date) {

        regex pattern(R"((\d{2})/(\d{2})/(\d{4}))");
        smatch matches;

        if (regex_match(date, matches, pattern)) {
            int day = stoi(matches[1]);
            int month = stoi(matches[2]);
            int year = stoi(matches[3]);

            if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1000 && year <= 9999) {\

                if (month == 2 && day > 28) {
                    cout << "February only have 28 days" << endl;
                    return false;
                }
                if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
                    cout << "That month only has 30 days" << endl;
                    return false;
                }
                else{
                    return true; // Date format and numbers are valid
                }
            }
        }


        cout << "Date format is incorrect. Try again" << endl;
        return false; // Date format or numbers are invalid

}

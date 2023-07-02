#include "Movie.h"

using namespace std;

//constructors
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

//getters and setters
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

// the function that will ask the user for input and return a movie object
Movie Movie::getInput() {

    cin.clear();    // clear the buffer for unwanted errors
    cin.ignore();
    Movie movie;
    string input;
    int temp;

    //ask for each value and set each value
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

    return movie;   //return the object made

}

// the function that will check if the user has entered an integer
int Movie::checkAndFixError() {
    float temp;
    while (!(cin >> temp)){

        cout << "Invalid Input. Please type in only an integer." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    while (int(temp * 10) % 10  != 0){
        if ( int(temp * 10) % 10  == 0) {
            return int(temp);
        }
        else {
            cout << "Invalid Input. Please type in only an integer." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> temp;
        }
    }

    return temp;
}

// the function that will check the date format
bool Movie::checkDateFormat(string date) {
        //regular expression for dd/mm/yyyy
        regex pattern(R"((\d{2})/(\d{2})/(\d{4}))");
        smatch matches;

        // if the pattern matches
        if (regex_match(date, matches, pattern)) {
            int day = stoi(matches[1]);     // the first one is the day
            int month = stoi(matches[2]);      // the second one is the month
            int year = stoi(matches[3]);    // the third one is the year

            // check necessary constraints for day and months
            if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1000 && year <= 9999) {\

                //February has only 28 days
                if (month == 2 && day > 28) {
                    cout << "February only have 28 days" << endl;
                    return false;
                }
                // months with only 30 days
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

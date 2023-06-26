#include "WeeklySchedule.h"

using namespace std;

Movie* WeeklySchedule::getAvailableMovies(){
    return availableMovies.data();
}

void WeeklySchedule::setMovieInAvailableSchedule(Movie movie) {
    availableMovies.push_back(movie);
}

void WeeklySchedule::readMoviesFromFile(int week) {
    availableMovies.clear();
    Movie movie;
    string line,tempWord, tempTitle, tempDescription, tempGenre, tempMainStar, tempDistributor, tempReleaseDate;
    int tempRuntime;
    ifstream MovieFile;
    if (week == 1){
        MovieFile.open("week1Movies.txt", ios::in);
    }
    else if (week == 2) {
        MovieFile.open("week2Movies.txt", ios::in);
    }
    else if (week == 3){
        MovieFile.open("week3Movies.txt", ios::in);
    }
    else {
        MovieFile.open("week4Movies.txt", ios::in);
    }

    if (MovieFile.is_open()){
        while (getline(MovieFile, line)){
            stringstream movieString(line);
            int counter = 0;

            while (getline(movieString >> ws, tempWord, ',')){

                if (counter == 0){
                    tempTitle = tempWord;
                }

                else if (counter == 1){
                    tempDescription = tempWord;
                }

                else if (counter == 2){
                    tempGenre = tempWord;
                }

                else if (counter == 3){
                    tempRuntime = stoi(tempWord);
                }

                else if (counter == 4){
                    tempMainStar= tempWord;
                }

                else if (counter == 5){
                    tempDistributor = tempWord;
                }

                else if (counter == 6){
                    tempReleaseDate = tempWord;
                }

                counter++;
            }

            Movie* tempMovie  = new Movie(tempTitle, tempDescription, tempGenre, tempRuntime, tempMainStar, tempDistributor, tempReleaseDate);
            setMovieInAvailableSchedule(*tempMovie);
        }
    }


    MovieFile.close();
}

void WeeklySchedule::writeToMovieFile(Movie movie1, int week){

    fstream MovieFile;
    if (week == 1){
        MovieFile.open("week1Movies.txt", ios::app);
    }
    else if (week == 2){
        MovieFile.open("week2Movies.txt", ios::app);
    }
    else if (week == 3){
        MovieFile.open("week3Movies.txt", ios::app);
    }
    else {
        MovieFile.open("week4Movies.txt", ios::app);
    }
    MovieFile << movie1.getTitle() << "," << movie1.getDescription() << "," << movie1.getGenre()
              << "," << movie1.getRunningTimeInMinutes() << "," << movie1.getMainStar() << ","
              << movie1.getDistributor() << "," << movie1.getReleaseDate() << endl;
    MovieFile.close();
    cout << "\nThe movie is added to your chosen week." << endl;

}

int WeeklySchedule::getMoviesSize() {
    return availableMovies.size();
}

void WeeklySchedule::displayMovies() {
    cout << "\nAll available movies are for the chosen week are : " << endl;
    for (int i = 0; i < availableMovies.size(); i++) {
        cout << "Title : " << availableMovies[i].getTitle() << endl;
        cout << "Description : " << availableMovies[i].getDescription() << endl;
        cout << "Genre : " << availableMovies[i].getGenre() << endl;
        cout << "Runtime in minutes : " << availableMovies[i].getRunningTimeInMinutes() << endl;
        cout << "Main Star : " << availableMovies[i].getMainStar() << endl;
        cout << "Distributor : " << availableMovies[i].getDistributor() << endl;
        cout << "Release Date : " << availableMovies[i].getReleaseDate() << "\n"<< endl;
    }
}

int WeeklySchedule::checkAndFixError() {
    int temp;
    while (!(cin >> temp)){
        cout << "Invalid Input. Please type in only an integer." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return temp;

}

void WeeklySchedule::setAvailableTimes(int movieIndex, string startTime) {
    availableTimes.clear();
    Movie *ptr = getAvailableMovies();
    Movie movie = *(ptr+movieIndex);
    string temp;
    int startHour;
    int startMinute;
    int counter = 0;

    int runTime = movie.getRunningTimeInMinutes();
    int minute = runTime % 60;
    int hour = (runTime - (runTime % 60)) / 60;

    stringstream stream(startTime);
    while (getline(stream >> ws, temp, ':')){

        if (counter == 0){
            startHour = stoi(temp);
        }
        else if (counter == 1){
            startMinute = stoi(temp);
        }
        counter ++;
    }
    string str;
    if (startMinute < 10){
        str = to_string(startHour) + " : 0" + to_string(startMinute);
    }
    else{
        str = to_string(startHour) + " : " + to_string(startMinute);
    }

    availableTimes.push_back(str);


    while (true){
        if ((startHour + hour) < 21){
            if ((startMinute + minute + 25) < 60){
                startHour += hour;
                startMinute += minute + 25;
                startMinute = ((startMinute + 4)/5)*5;
                if (startMinute >= 60){
                    startHour += 1;
                    startMinute = 0;
                }
            } else{
                startMinute += minute - 60 + 25;
                startHour += hour + 1;
                startMinute = ((startMinute + 4)/5)*5;
                if (startMinute >= 60){

                    startHour += 1;
                    startMinute = 0;
                }
            }
        } else{
            break;
        }
        string str1;
        if (startMinute < 10){
            str1 = to_string(startHour) + " : 0" + to_string(startMinute);
        }
        else {
            str1 = to_string(startHour) + " : " + to_string(startMinute);
        }
        availableTimes.push_back(str1);
    }
}

string WeeklySchedule::editAvailableTimes() {
    int tempHour, tempMinute;
    string str;

//    cout << "The schedule of which movie do you want to edit?" << endl;
//    int index = getMovieChoice();

    cout << "What do you want the starting time to be instead of 10 : 15?" << endl;

    cout << "Type in the hour mark: ";
    while(true){
        tempHour = checkAndFixError();
        if (tempHour < 10 or tempHour > 21){
            cout << "Please type in a reasonable hour. (i.e. from 10 to 21)" << endl;
        }

        else {
            break;
        }
    }

    cout << "What is the minute mark: ";
    while (true){
        tempMinute = checkAndFixError();
        if (tempMinute < 0 or tempMinute > 59){
            cout << "The minute mark cannot be less than 0 or greater than 59" << endl;
        }
        else {
            if (tempHour == 10 && tempMinute < 15) {
                cout << "The cinema only opens at 10 : 15. Type in the minute mark again." << endl;
            }
            else {
                break;
            }
        }
    }

    str = to_string(tempHour) + " : " + to_string(tempMinute);
//    setAvailableTimes(index, str);

//    cout << "The new schedule for the movie is : " << endl;
//    displayAllAvailableTimes();

    return str;

}

string* WeeklySchedule::getAvailableTimes() {
    return availableTimes.data();
}

void WeeklySchedule::setTimeInAvailableTimes(string tempTime){
    availableTimes.push_back(tempTime);
}

void WeeklySchedule::displayAllAvailableTimes() {
    string* ptr = getAvailableTimes();
    for (int i = 0; i < getTimesSize(); i++){
        cout << i+1 << ". " << *(ptr+i) << endl;
    }
}

int WeeklySchedule::getTimesSize() {
    return availableTimes.size();
}

Screen* WeeklySchedule::getScreens() {
    return screens.data();
}

void WeeklySchedule::readScreenFromFile(int weekChoice) {
    screens.clear();
    readMoviesFromFile(weekChoice);
    int tempID, tempSeats, tempMovie;
    string line, tempWord, tempType;
    int i = 0;

    fstream ScreenFile;
    if (weekChoice == 1){
        ScreenFile.open("screens.txt");
    }
    else if (weekChoice == 2) {
        ScreenFile.open("week2Screens.txt");
    }
    else if (weekChoice == 3) {
        ScreenFile.open("week3Screens.txt");
    }
    else if (weekChoice == 4) {
        ScreenFile.open("week4Screens.txt");
    }

    if (ScreenFile.is_open()){

        while (getline(ScreenFile, line)){
            stringstream movieString(line);
            int counter = 0;

            while (getline(movieString >> ws, tempWord, ',')){

                if (counter == 0){
                    tempID = stoi(tempWord);
                }

                else if (counter == 1){
                    tempSeats = stoi(tempWord);
                }

                else if (counter == 2){
                    tempMovie = stoi(tempWord);
                }

                else if (counter == 3){
                    tempType = tempWord;
                }
                counter++;
            }

            if (tempMovie <= getMoviesSize()){
                Movie temp = availableMovies.at(tempMovie - 1);
                Screen* tempScreen = new Screen(tempID, tempSeats, temp, tempType);
                setScreenInScreens(*tempScreen);
            }

            else {
                Screen* tempScreen = new Screen(tempID, tempSeats, tempType);
                setScreenInScreens(*tempScreen);
            }

            i++;
        }
    }
    ScreenFile.close();

}

int WeeklySchedule::getScreenSize() {
    return screens.size();
}

void WeeklySchedule::setScreenInScreens(Screen tempScreen) {
    screens.push_back(tempScreen);
}

void WeeklySchedule::displayScreens(){
    Screen* ptr = getScreens();
    for (int i = 0; i < screens.size(); i++) {
        cout << ptr[i].getScreenId() << ". " << ptr[i].getNumberOfSeats() << ", " << ptr[i].getScreenType() << ", " <<
        ptr[i].getCurrentMovie().getTitle() << endl;

    }
}

bool WeeklySchedule:: canAddMovies(int week){
    readMoviesFromFile(week);
    if (getMoviesSize() < 5){
        cout << "\nYou can still add " << 5 - getMoviesSize() << " movies to this week\n" << endl;
        return true;
    }
    else {
        cout << "\nYou cannot add more to this week, it already has 5." << endl;
        return false;
    }

}

void WeeklySchedule::displaySchedule() {
    string* ptr = getAvailableTimes();

    cout << "The schedule for this movie at this specific day is: " << endl;

    for (int i = 0; i < getTimesSize(); i++){
        cout << i+1 << ". " << ptr[i] << endl;
    }
}

void WeeklySchedule::editMovieSetToScreen(int weekChoice, int movieIndex) {
    fstream ReadFile;
    ofstream WriteFile;
    readMoviesFromFile(weekChoice);
    readScreenFromFile(weekChoice);
    string line, tempWord, tempType;
    int tempMovieIndex, screenChoice, updatedScreenIndex, tempMovie, tempID, tempSeats;
    Screen* tempScreens = getScreens();

    int i = 0;

    if (weekChoice == 1){
        ReadFile.open("screens.txt", ios::in);
    }
    else if (weekChoice == 2) {
        ReadFile.open("week2Screens.txt", ios::in);
    }
    else if (weekChoice == 3) {
        ReadFile.open("week3Screens.txt", ios::in);
    }
    else if (weekChoice == 4) {
        ReadFile.open("week4Screens.txt", ios::in);
    }

    vector<Screen> unsetScreens;

    if (ReadFile.is_open()) {
        while (getline(ReadFile, line)) {
            stringstream movieString(line);
            int counter = 0;

            while (getline(movieString >> ws, tempWord, ',')) {

                if (counter == 2) {
                    tempMovieIndex = stoi(tempWord);
                }
                counter++;
            }
            if (tempMovieIndex > getMoviesSize()){
                unsetScreens.push_back(tempScreens[i]);
            }
            i++;

        }
        ReadFile.close();
    }
    cout << "These are the unused screens for this week: " << endl;
    for (int j = 0; j < unsetScreens.size(); j++){
        cout << j + 1 << ". " << unsetScreens[j].getScreenType() << endl;
    }
    cout << "Choose one that you would like to display the movie on: ";
    screenChoice = checkAndFixError();

    for (int j = 0; j < getScreenSize(); j++){
        if (tempScreens[j].getScreenId() == unsetScreens[screenChoice - 1].getScreenId()){
            updatedScreenIndex = j;
        }
    }

    if (weekChoice == 1){
        ReadFile.open("screens.txt", ios::in);
    }
    else if (weekChoice == 2) {
        ReadFile.open("week2Screens.txt", ios::in);
    }
    else if (weekChoice == 3) {
        ReadFile.open("week3Screens.txt", ios::in);
    }
    else if (weekChoice == 4) {
        ReadFile.open("week4Screens.txt", ios::in);
    }

    vector<string> toWrite;

    if (ReadFile.is_open()){
        while (getline(ReadFile, line)) {
            stringstream movieString(line);
            int counter = 0;


            while (getline(movieString >> ws, tempWord, ',')) {
                if (counter == 0){
                    tempID = stoi(tempWord);
                }

                else if (counter == 1){
                    tempSeats = stoi(tempWord);
                }

                else if (counter == 2){
                    tempMovie = stoi(tempWord);
                }

                else if (counter == 3){
                    tempType = tempWord;
                }

                if (tempMovie == movieIndex + 1) {
                    tempMovie = updatedScreenIndex + 1;
                }

                if (updatedScreenIndex + 1 == tempID){
                    tempMovie = movieIndex + 1;
                }
                counter ++;
            }



            string str = to_string(tempID) + "," + to_string(tempSeats) + ","
                         + to_string(tempMovie) + "," + tempType;

            toWrite.push_back(str);

        }
        ReadFile.close();
    }

    for (int j = 0; j < toWrite.size(); j++) {
        cout << toWrite[j] << endl;

    }

    if (weekChoice == 1){
        WriteFile.open("screens.txt", ios::trunc);
    }
    else if (weekChoice == 2) {
        WriteFile.open("week2Screens.txt", ios::trunc);
    }
    else if (weekChoice == 3) {
        WriteFile.open("week3Screens.txt", ios::trunc);
    }
    else if (weekChoice == 4) {
        WriteFile.open("week4Screens.txt", ios::trunc);
    }

    if (WriteFile.is_open()){
        for (int j = 0; j < toWrite.size(); j ++) {
            WriteFile << toWrite[j] << endl;
        }
        WriteFile.close();
    }


}
#include "WeeklySchedule.h"

using namespace std;

// getters and setters
Movie* WeeklySchedule::getAvailableMovies(){
    return availableMovies.data();
}

void WeeklySchedule::setMovieInAvailableSchedule(Movie movie) {
    availableMovies.push_back(movie);
}

int WeeklySchedule::getMoviesSize() {
    return availableMovies.size();
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

int WeeklySchedule::getScreenSize() {
    return screens.size();
}

void WeeklySchedule::setScreenInScreens(Screen tempScreen) {
    screens.push_back(tempScreen);
}

//the function that will read the movie data from the file and populate the vector
void WeeklySchedule::readMoviesFromFile(int week) {
    availableMovies.clear(); // clear the vector first for no unwanted errors
    // declare all the necessary temporary variables
    Movie movie;
    string line,tempWord, tempTitle, tempDescription, tempGenre, tempMainStar, tempDistributor, tempReleaseDate;
    int tempRuntime;

    //open the file based on the week choice
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
        // loop through every line
        while (getline(MovieFile, line)){
            stringstream movieString(line);
            int counter = 0;

            //loop through every word in each line
            while (getline(movieString >> ws, tempWord, ',')){

                //set the appropriate values to their variables
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

            //create an instance of a movie with the data read
            Movie* tempMovie  = new Movie(tempTitle, tempDescription, tempGenre, tempRuntime, tempMainStar, tempDistributor, tempReleaseDate);
            setMovieInAvailableSchedule(*tempMovie); // push back the instance to the vector
        }
    }


    MovieFile.close();  // close the file when done
}

// the function that will append to the movie file
void WeeklySchedule::writeToMovieFile(Movie movie1, int week){

    //open the file based on the week choice
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

    //write the details of the instance from the parameter
    MovieFile << movie1.getTitle() << "," << movie1.getDescription() << "," << movie1.getGenre()
              << "," << movie1.getRunningTimeInMinutes() << "," << movie1.getMainStar() << ","
              << movie1.getDistributor() << "," << movie1.getReleaseDate() << endl;
    MovieFile.close(); // close the file when done
    cout << "\nThe movie is added to your chosen week." << endl;

}

// the function that will display all movies in the vector
void WeeklySchedule::displayMovies() {

    cout << "\nAll available movies are for the chosen week are : " << endl;
    // loop through the vector
    for (int i = 0; i < availableMovies.size(); i++) {
        // print out the details for each element
        cout << "Title : " << availableMovies[i].getTitle() << endl;
        cout << "Description : " << availableMovies[i].getDescription() << endl;
        cout << "Genre : " << availableMovies[i].getGenre() << endl;
        cout << "Runtime in minutes : " << availableMovies[i].getRunningTimeInMinutes() << endl;
        cout << "Main Star : " << availableMovies[i].getMainStar() << endl;
        cout << "Distributor : " << availableMovies[i].getDistributor() << endl;
        cout << "Release Date : " << availableMovies[i].getReleaseDate() << "\n"<< endl;
    }
}

// the function that will check if the user has entered an integer value
int WeeklySchedule::checkAndFixError() {
    int temp;
    while (!(cin >> temp)){
        cout << "Invalid Input. Please type in only an integer." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return temp;

}

// the function that will calculate the showtimes based on the runtime of the movie and populate the vector
void WeeklySchedule::setAvailableTimes(int movieIndex, string startTime) {
    availableTimes.clear(); // clear the vector for no unwanted errors

    Movie *ptr = getAvailableMovies(); // get the vector of movies
    Movie movie = *(ptr+movieIndex);    // get the movie chosen by the user
    // necessary temporary variables
    string temp;
    int startHour;
    int startMinute;
    int counter = 0;

    // get the hour and the minute mark of the runtime
    int runTime = movie.getRunningTimeInMinutes();
    int minute = runTime % 60;
    int hour = (runTime - (runTime % 60)) / 60;

    stringstream stream(startTime); // get the starting time of the day from the parameter
    while (getline(stream >> ws, temp, ':')){
        // break down the string into the hour and minute mark
        if (counter == 0){
            startHour = stoi(temp);
        }
        else if (counter == 1){
            startMinute = stoi(temp);
        }
        counter ++;
    }

    string str;
    if (startMinute < 10){  // if the minute mark is less than 10, add a 0 in front.
        str = to_string(startHour) + " : 0" + to_string(startMinute);
    }
    else{
        str = to_string(startHour) + " : " + to_string(startMinute);
    }

    availableTimes.push_back(str);  // push back the starting time


    while (true){
        // the movies will keep showing until the showtime goes to 9 pm.
        if ((startHour + hour) < 20){
            // if the addition of minute marks is less than 60
            if ((startMinute + minute + 25) < 60){
                // perform the normal additions
                startHour += hour;
                startMinute += minute + 25;
                // round up the minute mark to the nearest ceiling of 5
                // for example, 11 will be 15 and 21 will be 25.
                startMinute = ((startMinute + 4)/5)*5;
                if (startMinute >= 60){ // if it goes over 60 when rounded
                    // perform the necessary operations
                    startHour += 1;
                    startMinute = 0;
                }
            } else{
                // if the addition goes over 60
                // subtract 60 from the addition of the minute marks and increase the hour mark by 1
                startMinute += minute - 60 + 25;
                startHour += hour + 1;
                //round up to the nearest ceiling of 5
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
        if (startMinute < 10){ // if the minute mark is less than 10, add a 0 in the front
            str1 = to_string(startHour) + " : 0" + to_string(startMinute);
        }
        else {
            str1 = to_string(startHour) + " : " + to_string(startMinute);
        }
        availableTimes.push_back(str1); // populate the vector
    }
}

// the function that will let the user edit the starting time of a day
string WeeklySchedule::editAvailableTimes() {
    int tempHour, tempMinute;
    string str;

    cout << "What do you want the starting time to be instead of 10 : 15?" << endl;

    cout << "Type in the hour mark: ";
    while(true){ // check the input and let the user enter until valid
        tempHour = checkAndFixError();
        if (tempHour < 10 or tempHour > 21){
            cout << "Please type in a reasonable hour. (i.e. from 10 to 21)" << endl;
        }

        else {
            break;
        }
    }

    cout << "What is the minute mark: ";
    while (true){   // check the input and let the user enter until valid
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

    // change it to a string
    str = to_string(tempHour) + " : " + to_string(tempMinute);

    return str; // return that string

}

//the function that will read data from the screen file and populate the vector
void WeeklySchedule::readScreenFromFile(int weekChoice) {

    screens.clear(); // clear the vector for no unwanted errors

    readMoviesFromFile(weekChoice); // populate the movies vector
    // declare all necessary variables
    int tempID, tempSeats, tempMovie;
    string line, tempWord, tempType;
    int i = 0;

    //open the file based on the week choice
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
        // loop through every line
        while (getline(ScreenFile, line)){
            stringstream movieString(line);
            int counter = 0;

            // loop through every word in each line
            while (getline(movieString >> ws, tempWord, ',')){

                //set the values to their related variables
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

            if (tempMovie <= getMoviesSize()){ // if the movie is a valid movie
                // create an instance with a movie included
                Movie temp = availableMovies.at(tempMovie - 1);
                Screen* tempScreen = new Screen(tempID, tempSeats, temp, tempType);
                setScreenInScreens(*tempScreen);    // push back to the vector
            }

            else {
                // the movie is not a valid one
                // create an instance without a movie
                Screen* tempScreen = new Screen(tempID, tempSeats, tempType);
                setScreenInScreens(*tempScreen); // push back to the vector
            }

            i++;
        }
    }
    ScreenFile.close(); // close the file when done

}

// the function that will display all screens from the vector
void WeeklySchedule::displayScreens(){
    Screen* ptr = getScreens();
    for (int i = 0; i < screens.size(); i++) {
        cout << ptr[i].getScreenId() << ". " << ptr[i].getNumberOfSeats() << ", " << ptr[i].getScreenType() << ", " <<
        ptr[i].getCurrentMovie().getTitle() << endl;

    }
}

// the function that will check if there are 5 movies present in a week or not
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

// the function that will display the times from the vector
void WeeklySchedule::displaySchedule() {
    string* ptr = getAvailableTimes();

    cout << "The schedule for this movie at this specific day is: " << endl;

    for (int i = 0; i < getTimesSize(); i++){
        cout << i+1 << ". " << ptr[i] << endl;
    }
}

// the function that will let the user reallocate a movie to a different screen
void WeeklySchedule::editMovieSetToScreen(int weekChoice, int movieIndex) {

    fstream ReadFile;
    ofstream WriteFile;
    readMoviesFromFile(weekChoice); // populate the movies vector
    readScreenFromFile(weekChoice); // populate the screens vector

    //declare all necessary variables
    string line, tempWord, tempType;
    int tempMovieIndex, screenChoice, updatedScreenIndex, tempMovie, tempID, tempSeats;
    int replacedMovie = 0;
    Screen* tempScreens = getScreens();

    int i = 0;

    // open the file in read mode based on the week choice
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

    vector<Screen> unsetScreens;    // a vector for screens that does not have a movie set

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
            // if the index of the movie in the file is greater than the length of the vector
            if (tempMovieIndex > getMoviesSize()){
                unsetScreens.push_back(tempScreens[i]); // push back to the vector
            }
            i++;

        }
        ReadFile.close(); // close the file when done
    }
    // display all the unused screens
    cout << "These are the unused screens for this week: " << endl;
    for (int j = 0; j < unsetScreens.size(); j++){  // loop through the vector and print out each element
        cout << j + 1 << ". " << unsetScreens[j].getScreenType() << endl;
    }

    cout << "Choose one that you would like to display the movie on: ";
    screenChoice = checkAndFixError();  // let the user choose one

    for (int j = 0; j < getScreenSize(); j++){  // look for the index of that chosen screen in the main screens vector
        if (tempScreens[j].getScreenId() == unsetScreens[screenChoice - 1].getScreenId()){
            updatedScreenIndex = j;
        }
    }

    // open the file again in read mode
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

    vector<string> toWrite; // a vector that will overwrite the contents of the file

    if (ReadFile.is_open()){
        while (getline(ReadFile, line)) {
            stringstream movieString(line);
            int counter = 0;


            while (getline(movieString >> ws, tempWord, ',')) {
                if (counter == 0){
                    tempID = stoi(tempWord);
                }

                else if (counter == 2){
                    tempMovie = stoi(tempWord);
                }

                // if the id of the screen matches the one that will be updated
                if (tempID == tempScreens[updatedScreenIndex].getScreenId()){
                    replacedMovie = tempMovie;  // the movie index related to it is stored
                }
                counter ++;
            }

        }
        ReadFile.close(); // close the file when done
    }

    // open the file again in read mode
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


    //this will swap the movie indexes of the replacing one and the replaced one
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

                counter ++;
            }


            // if the movie index of the screen is the same as the one from the parameters
            if (tempMovie == movieIndex + 1 && replacedMovie != 0) {
                tempMovie = replacedMovie;  // replace that index with the one from updated screen
            }

            if (updatedScreenIndex + 1 == tempID){  // the screen is the updated screen
                tempMovie = movieIndex + 1; // replace its movie index with the one from the parameter
            }

            // if unaffected by the above conditions, the original string will be pushed back
            // change it to a string
            string str = to_string(tempID) + "," + to_string(tempSeats) + ","
                         + to_string(tempMovie) + "," + tempType;



            toWrite.push_back(str); // push back to the vector

        }
        ReadFile.close();   // close the file when done
    }

    // open the file again with overwrite mode this time
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
        // overwrite the contents of the file with the strings from the vector
        for (int j = 0; j < toWrite.size(); j ++) {
            WriteFile << toWrite[j] << endl;
        }
        WriteFile.close(); // close the file when done
    }

    cout << "\nYour chosen movie has been reallocated to " << tempScreens[updatedScreenIndex].getScreenType() << endl;


}
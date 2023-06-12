#include "WeeklySchedule.h"

using namespace std;

Movie* WeeklySchedule::getAvailableMovies(){
    return availableMovies.data();
}

void WeeklySchedule::setMovieInAvailableSchedule(Movie movie) {
    availableMovies.push_back(movie);
}

void WeeklySchedule::readFromFile() {
    Movie movie;
    string line,tempWord, tempTitle, tempDescription, tempGenre, tempMainStar, tempDistributor, tempReleaseDate;
    int tempRuntime;
    ifstream MovieFile;
    MovieFile.open("movies.txt", ios::in);

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

void WeeklySchedule::writeToFile(Movie movie1){
        fstream MovieFile;
        MovieFile.open("movies.txt", ios::app);
        MovieFile << movie1.getTitle() << "," << movie1.getDescription() << "," << movie1.getGenre()
                  << "," << movie1.getRunningTimeInMinutes() << "," << movie1.getMainStar() << ","
                  << movie1.getDistributor() << "," << movie1.getReleaseDate() << endl;
        MovieFile.close();
}

int WeeklySchedule::getMoviesSize() {
    return availableMovies.size();
}

void WeeklySchedule::displayMovies() {
    cout << "All available movies are : " << endl;
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
    string str = to_string(startHour) + " : " + to_string(startMinute);
    availableTimes.push_back(str);


    while (true){
        if ((startHour + hour) < 21){
            if ((startMinute + minute + 25) < 60){
                startHour += hour;
                startMinute += minute + 25;
            } else{
                startMinute += minute - 60 + 25;
                startHour += hour + 1;
            }
        } else{
            break;
        }
        string str1 = to_string(startHour) + " : " + to_string(startMinute);
        availableTimes.push_back(str1);
    }
}

void WeeklySchedule::editAvailableTimes() {
    Booking booking;
    int tempHour, tempMinute;
    string str;
    readFromFile();

    cout << "The schedule of which movie do you want to edit?" << endl;
    int index = booking.getMovieChoice();

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
            break;
        }
    }

    str = to_string(tempHour) + " : " + to_string(tempMinute);
    setAvailableTimes(index, str);

    cout << "The new schedule for the movie is : " << endl;
    displayAllAvailableTimes();

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



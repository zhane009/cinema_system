#include "WeeklySchedule.h"

using namespace std;

Movie* WeeklySchedule::getAvailableMovies(){
    return availableMovies.data();
}

void WeeklySchedule::setMovieInAvailableSchedule(Movie movie) {
    availableMovies.push_back(movie);
}

string* WeeklySchedule::getAvailableTimes() {
    return availableTimes.data();
}

void WeeklySchedule::setAvailableTimes(int movieIndex) {
    Movie *ptr = getAvailableMovies();
    Movie movie = *(ptr+movieIndex);

    int runTime = movie.getRunningTimeInMinutes();
    int minute = runTime % 60;
    int hour = (runTime - (runTime % 60)) / 60;

    int startHour = 10;
    int startMinute = 15;
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

void WeeklySchedule::readFromFile() {
    Movie movie;
    string line,tempWord, tempTitle, tempDescription, tempGenre, tempMainStar, tempDistributor, tempReleaseDate;
    int tempRuntime;
    ifstream MovieFile;
    MovieFile.open("movies.txt", ios::in);

//    bool loop = true;
//    int count = 1;
//
//    while (loop){
//
//        if (count == 1){
//            getline(MovieFile, line);
//            movie.setTitle(line);
//        }
//
//        getline(MovieFile, line);
//        movie.setDescription(line);
//
//        getline(MovieFile, line);
//        movie.setGenre(line);
//
//        getline(MovieFile, line);
//        movie.setRunningTimeInMinutes(stoi(line));
//
//        getline(MovieFile, line);
//        movie.setMainStar(line);
//
//        getline(MovieFile, line);
//        movie.setDistributor(line);
//
//        getline(MovieFile, line);
//        movie.setReleaseDate(line);
//
//        getline(MovieFile, line);
//
//        if (line.empty()){
//            availableMovies.push_back(movie);
//        }
//
//        getline(MovieFile, line);
//        if (line.empty()){
//            loop = false;
//        }
//        else{
//            movie.setTitle(line);
//        }
//
//        count ++;
//
//    }

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

int WeeklySchedule::getTimesSize() {
    return availableTimes.size();
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
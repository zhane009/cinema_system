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
//    vector<string> localTimes;
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
    string line;
    ifstream MovieFile;
    MovieFile.open("C:\\Users\\ASUS\\CLionProjects\\Assessment\\movies.txt", ios::in);

    getline(MovieFile, line);
    movie.setTitle(line);

    getline(MovieFile, line);
    movie.setDescription(line);

    getline(MovieFile, line);
    movie.setGenre(line);

    getline(MovieFile, line);
    movie.setRunningTimeInMinutes(stoi(line));

    getline(MovieFile, line);
    movie.setMainStar(line);

    getline(MovieFile, line);
    movie.setDistributor(line);

    getline(MovieFile, line);
    movie.setReleaseDate(line);

    availableMovies.push_back(movie);

    MovieFile.close();
}

void WeeklySchedule::writeToFile(Movie movie1){
        fstream MovieFile;
        MovieFile.open("C:\\Users\\ASUS\\CLionProjects\\Assessment\\movies.txt", ios::app);
        MovieFile << movie1.getTitle() << "\n" << movie1.getDescription() << "\n" << movie1.getGenre()
                  << "\n" << movie1.getRunningTimeInMinutes() << "\n" << movie1.getMainStar() << "\n"
                  << movie1.getDistributor() << "\n" << movie1.getReleaseDate() << "\n";
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
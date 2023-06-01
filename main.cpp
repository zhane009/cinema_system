#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

class Movie{
    string title;
    string description;
    string genre;
    int runningTimeInMinutes;
    string mainStar;
    string distributor;
    string releaseDate;
    vector<Movie> movies;

public:
    string getTitle() {
        return title;
    }

    void setTitle(string tempTitle) {
        title = tempTitle;
    }

    string getDescription() {
        return description;
    }

    void setDescription(string tempDescription) {
        description = tempDescription;
    }

    string getGenre() {
        return genre;
    }

    void setGenre(string tempGenre) {
        genre = tempGenre;
    }

    int getRunningTimeInMinutes() {
        return runningTimeInMinutes;
    }

    void setRunningTimeInMinutes(int tempRunningTimeInMinutes) {
        runningTimeInMinutes = tempRunningTimeInMinutes;
    }

    string getMainStar() {
        return mainStar;
    }

    void setMainStar(string tempMainStar) {
        mainStar = tempMainStar;
    }

    string getDistributor() {
        return distributor;
    }

    void setDistributor(string tempDistributor) {
        distributor = tempDistributor;
    }

    string getReleaseDate() {
        return releaseDate;
    }

    void setReleaseDate(string tempReleaseDate) {
        releaseDate = tempReleaseDate;
    }

    vector<Movie> getMovies() {
        return movies;
    }

    void setMovies(vector<Movie> tempMovies){
        movies = tempMovies;
    }

    Movie getInput() {
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

    void addMovie(Movie movie1){
        fstream MovieFile;
        MovieFile.open("C:\\Users\\ASUS\\CLionProjects\\Assessment\\movies.txt", ios::app);
        MovieFile << movie1.getTitle() << " " << movie1.getDescription() << " " << movie1.getGenre()
                  << " " << movie1.getRunningTimeInMinutes() << " " << movie1.getMainStar() << " "
                  << movie1.getDistributor() << " " << movie1.getReleaseDate() << "\n";
        MovieFile.close();
    };

    void updateMoviesFromFile() {
        vector<Movie> localMovies;
        Movie movie;
        string line;
        ifstream MovieFile;
        MovieFile.open("C:\\Users\\ASUS\\CLionProjects\\Assessment\\movies.txt", ios::in);

//        while (MovieFile >> movie.title >> movie.description >> movie.genre >> movie.runningTimeInMinutes
//                        >> movie.mainStar >> movie.distributor >> movie.releaseDate){
//            localMovies.push_back(movie);
//        }

        while (getline(MovieFile, line)) {
            istringstream iss(line);
            if (iss >> movie.title >> movie.description >> movie.genre >> movie.runningTimeInMinutes
                    >> movie.mainStar >> movie.distributor >> movie.releaseDate) {
                localMovies.push_back(movie);
            }
        }

        MovieFile.close();
        setMovies(localMovies);
    }

    void displayMovies() {
        vector<Movie> localMovies = getMovies();
        cout << "All available movies are : " << endl;
        for (int i = 0; i < localMovies.size(); i++) {
            cout << "Title : " << localMovies[i].getTitle() << endl;
            cout << "Description : " << localMovies[i].getDescription() << endl;
            cout << "Genre : " << localMovies[i].getGenre() << endl;
            cout << "Runtime in minutes : " << localMovies[i].getRunningTimeInMinutes() << endl;
            cout << "Main Star : " << localMovies[i].getMainStar() << endl;
            cout << "Distributor : " << localMovies[i].getDescription() << endl;
            cout << "Release Date : " << localMovies[i].getReleaseDate() << "\n"<< endl;
        }
    }

};

class Screen{
    int screenId;
    int numberOfSeats;
    Movie currentMovie;
    string screenType;

public:

    int getScreenId() {
        return screenId;
    }

    void setScreenId(int tempScreenId) {
        screenId = tempScreenId;
    }

    int getNumberOfSeats() {
        return numberOfSeats;
    }

    void setNumberOfSeats(int tempNumberOfSeats) {
        numberOfSeats = tempNumberOfSeats;
    }

    Movie getCurrentMovie() {
        return currentMovie;
    }

    void setCUrrentMovie(Movie tempCurrentMovie) {
        currentMovie = tempCurrentMovie;
    }

    string getScreenType() {
        return screenType;
    }

    void setScreenType(string tempScreenType) {
        screenType = tempScreenType;
    }


};

class weeklySchedule {
    vector<Movie> moviesShown;
};


class Booking{
    int numberOfTickets;
    Movie movie;
    string date;
    string time;
    double totalCost;
    string paymentType;

public:
    int getNumberOfTickets() {
        return numberOfTickets;
    }

    void setNumberOfTickets (int tempNumberOfTickets){
        numberOfTickets = tempNumberOfTickets;
    }

    Movie getMovie() {
        return movie;
    }

    void setMovie (Movie tempMovie) {
        movie = tempMovie;
    }

    string getDate() {
        return date;
    }

    void setDate(string tempDate){
        date = tempDate;
    }

    string getTime() {
        return time;
    }

    void setTime(string tempTime) {
        time = tempTime;
    }

    double getTotalCost() {
        return totalCost;
    }

    void setTotalCost(double tempTotalCost){
        totalCost = tempTotalCost;
    }

    string getPaymentType() {
        return paymentType;
    }

    void setPaymentType(string tempPaymentType) {
        paymentType = tempPaymentType;
    }

    void book() {
        cout << "You have made a booking" << endl;
    }

    int getMovieChoice() {
        Movie localMovie;
        localMovie.updateMoviesFromFile();
        string str;
        vector<Movie> localMovies = localMovie.getMovies();
        for (int i = 0; i < localMovies.size(); i++) {
            cout << i + 1 << ". Title : " << localMovies[i].getTitle() << endl;
        }
        cout << "Choose a number : ";
        getline(cin, str);
        return stoi(str);
    }

};



int main() {
    Movie movie;
//    movie.addMovie(movie.getInput());
//    Movie movie1 = movie.getInput();
//    movie.addMovie(movie1);
    movie.updateMoviesFromFile();
//    Movie movie2 = movie.getMovies().operator[](4);
//    cout << movie2.getTitle() << endl;
//    cout << movie.getMovies().size() << endl;

//    movie.displayMovies();
    Booking booking;
    booking.getMovieChoice();

//    movie.getMovies().clear();
    return 0;
}
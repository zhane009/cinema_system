#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Movie.h"
#include "WeeklySchedule.h"
#include "Booking.h"
#include "Screen.h"

using namespace std;

int main() {
    Movie movie;
//    movie.updateMoviesFromFile();
////    movie.addMovie(movie.getInput());
////    Movie movie1 = movie.getInput();
////    movie.addMovie(movie1);
//    movie.updateMoviesFromFile();
////    Movie movie2 = movie.getMovies().operator[](4);
////    cout << movie2.getTitle() << endl;
////    cout << movie.getMovies().size() << endl;
//
////    movie.displayMovies();
    Booking booking;
    int index = booking.getMovieChoice();
//    Movie bookedMovie = movie.getMovies()[index];

//    movie.getMovies().clear();
//
    WeeklySchedule weeklySchedule;

//    weeklySchedule.writeToFile(movie.getInput());
//    weeklySchedule.setAvailableTimes(index);

    weeklySchedule.readFromFile();
//    cout << weeklySchedule.getMoviesSize();
//    weeklySchedule.displayMovies();
//
    string time =  booking.getBookingTime(index);
//    cout << "You have made a booking for " << movie.getMovies().at(index).getTitle() << " at " << time << endl;
    return 0;
}
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

//    string name;
//    cout << "Your name: ";
//    getline(cin, name);

    Movie movie;
    Booking booking;

    WeeklySchedule weeklySchedule;
//    weeklySchedule.writeToFile(movie.getInput());

//    weeklySchedule.readFromFile();
//////    weeklySchedule.displayMovies();
////////    cout << "You have made a booking \nfor name: " << name << "\nfor movie: " <<  weeklySchedule.getAvailableMovies()[index].getTitle() << "\nat time: " << time << endl;
//    booking.setNumberOfTicketsFromInput();
//    booking.calculateTotalPrice();
//    booking.setPaymentTypeFromInput();
////    weeklySchedule.displayMovies();
//
//    booking.displayBookingInformation();
//
//    string time = weeklySchedule.editAvailableTimes();
//
//    booking.setDateFromInput();
//    int index = booking.getMovieChoice();
//    booking.setMovie(index);
//
//    booking.getBookingTime(index, time);

//    weeklySchedule.readFromFile();
//    weeklySchedule.setAvailableTimes(1, "10 : 15");
//

    string str = weeklySchedule.editAvailableTimes();
//    weeklySchedule.displayAllAvailableTimes();
    booking.book();

    return 0;
}
#include "Booking.h"

using namespace std;

int Booking::getNumberOfTickets() {
    return numberOfTickets;
}

void Booking::setNumberOfTickets (int tempNumberOfTickets){
    numberOfTickets = tempNumberOfTickets;
}

Movie Booking::getMovie() {
    return movie;
}

void Booking::setMovie (Movie tempMovie) {
    movie = tempMovie;
}

string Booking::getDate() {
    return date;
}

void Booking::setDate(string tempDate){
    date = tempDate;
}

string Booking::getTime() {
    return time;
}

void Booking::setTime(string tempTime) {
    time = tempTime;
}

double Booking::getTotalCost() {
    return totalCost;
}

void Booking::setTotalCost(double tempTotalCost){
    totalCost = tempTotalCost;
}

string Booking::getPaymentType() {
    return paymentType;
}

void Booking::setPaymentType(string tempPaymentType) {
    paymentType = tempPaymentType;
}

void Booking::book() {
    cout << "You have made a booking" << endl;
}

int Booking::getMovieChoice() {
    WeeklySchedule schedule;
    schedule.readFromFile();
    string str;
    Movie *ptr = schedule.getAvailableMovies();

    for (int i = 0; i < schedule.getMoviesSize(); i++) {
        cout << i + 1 << ". Title : " << ptr[i].getTitle() << endl;
    }

    cout << "Choose a number : ";
    getline(cin, str);
    return stoi(str) - 1;
}

string Booking::getBookingTime(int movieIndex){
    int input;
    WeeklySchedule schedule;
    schedule.readFromFile();
    schedule.setAvailableTimes(movieIndex);

    string *timePtr= schedule.getAvailableTimes();

    for (int i = 0; i < schedule.getTimesSize(); i ++){
        cout << i + 1 << ". " << timePtr[i] << endl;
    }

    cout << "Choose an option : ";
    cin >> input;
    return *(timePtr + (input - 1));
}
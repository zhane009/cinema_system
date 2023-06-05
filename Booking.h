//
// Created by ASUS on 05/06/2023.
//

#ifndef ASSESSMENT_BOOKING_H
#define ASSESSMENT_BOOKING_H

#include <iostream>
#include "Movie.h"
#include "WeeklySchedule.h"

using namespace std;

class Booking{
    int numberOfTickets;
    Movie movie;
    string date;
    string time;
    double totalCost;
    string paymentType;

public:
    int getNumberOfTickets();

    void setNumberOfTickets (int);

    Movie getMovie();

    void setMovie (Movie);

    string getDate();

    void setDate(string);

    string getTime();

    void setTime(string);

    double getTotalCost();

    void setTotalCost(double);

    string getPaymentType();

    void setPaymentType(string);

    void book();

    int getMovieChoice();

    string getBookingTime(int);
};

#endif //ASSESSMENT_BOOKING_H

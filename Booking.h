
#ifndef ASSESSMENT_BOOKING_H
#define ASSESSMENT_BOOKING_H

#include <iostream>
#include "WeeklySchedule.h"


using namespace std;

class Booking{
    int numberOfTickets[4];
    Movie movie;
    string date;
    string time;
    double totalCost;
    string paymentType;

    const float adultPrice = 9.5;
    const float childPrice = 5.5;
    const float seniorPrice = 6.5;
    const float studentPrice = 7;

public:
    int* getNumberOfTickets();

    void setNumberOfTickets (int*);

    Movie getMovie();

    void setMovie (int);

    string getDate();

    void setDate(string);

    string getTime();

    void setTime(string);

    double getTotalCost();

    void setTotalCost(double);

    string getPaymentType();

    void setPaymentType(string);

    float getAdultPrice();

    float getChildPrice();

    float getSeniorPrice();

    float getStudentPrice();

    void book(string = "10 : 15");

    int getMovieChoice();

    void getBookingTime(int, string);

    void setNumberOfTicketsFromInput();

    void calculateTotalPrice();

    void setPaymentTypeFromInput();

    void displayBookingInformation();

    int checkAndFixError();

    void setDateFromInput();
};

#endif //ASSESSMENT_BOOKING_H

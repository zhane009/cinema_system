
#ifndef ASSESSMENT_BOOKING_H
#define ASSESSMENT_BOOKING_H

#include <iostream>
#include "WeeklySchedule.h"
//#include "Movie.h"
//#include "Screen.h"
#include <ctime>

using namespace std;

class Booking{
    //declare all variables
    int numberOfTickets[4]; //the quantities of four types of tickets
    Movie movie; // the chosen movie by the user
    string week; // the chosen week by the user
    string day; // the chosen day by the user
    string time; // the chosen time by the user
    double totalCost; // the total cost of the transaction
    string paymentType; //the payment type chosen by the user
    Screen screen; // the screen chosen by the user

    //constant values for the prices as they cannot be edited
    const float adultPrice = 9.5;
    const float childPrice = 5.5;
    const float seniorPrice = 6.5;
    const float studentPrice = 7;

public:
    int* getNumberOfTickets();

    void setNumberOfTickets (int*);

    Movie getMovie();

    void setMovie (int, Movie*);

    string getWeek();

    void setWeek(int);

    string getDay();

    void satDay(string);

    string getTime();

    void setTime(string);

    double getTotalCost();

    void setTotalCost(double);

    string getPaymentType();

    void setPaymentType(string);

    Screen getScreen();

    void setScreen(int, Screen*);

    float getAdultPrice();

    float getChildPrice();

    float getSeniorPrice();

    float getStudentPrice();

    void book(WeeklySchedule*, string, int);

    int getWeekChoice();

    int getMovieChoice(WeeklySchedule*);

    void getBookingTime(int, string, WeeklySchedule*);

    void setNumberOfTicketsFromInput();

    void calculateTotalPrice();

    void setPaymentTypeFromInput();

    void displayBookingInformation();

    int checkAndFixError();

    int setDateFromInput(int);

    void writeToFile();

    void displayAllBookingsFromFile();

    bool checkDay(int);

    bool checkCard(string);

    bool checkExpDate(string);

    bool checkCVV(string);

    int checkSeatAvailability();
};

#endif //ASSESSMENT_BOOKING_H

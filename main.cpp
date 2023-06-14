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

    Booking booking;
    WeeklySchedule schedule;
    Movie movie;
    schedule.readMoviesFromFile(1);
//    string str = schedule.editAvailableTimes();
//    schedule.setAvailableTimes(2, "10 : 15");
////    schedule.displayAllAvailableTimes();
    schedule.readScreenFromFile();
    booking.book(&schedule);
//    schedule.displayScreens();
    return 0;
}
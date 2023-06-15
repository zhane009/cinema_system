//
// Created by ASUS on 14/06/2023.
//

#ifndef ASSESSMENT_CINEMA_H
#define ASSESSMENT_CINEMA_H

#include "Movie.h"
#include "Screen.h"
#include "WeeklySchedule.h"
#include "Booking.h"

class Cinema {

    Movie movie;
    Screen screen;
    WeeklySchedule weeklySchedule;
    Booking booking;

public:
    Movie getMovie();

    void setMovie(Movie);

    Screen getScreen();

    void setScreen(Screen);

    WeeklySchedule getWeeklySchedule();

    void setWeeklySchedule(WeeklySchedule);

    Booking getBooking();

    void setBooking(Booking);

    void execute();

};

#endif //ASSESSMENT_CINEMA_H

#include "Cinema.h"

Movie Cinema::getMovie() {
    return movie;
}

void Cinema::setMovie(Movie tempMovie) {
    movie = tempMovie;
}

Screen Cinema::getScreen() {
    return screen;
}

void Cinema::setScreen(Screen tempScreen) {
    screen = tempScreen;
}

WeeklySchedule Cinema::getWeeklySchedule() {
    return weeklySchedule;
}

void Cinema::setWeeklySchedule(WeeklySchedule tempSchedule) {
    weeklySchedule = tempSchedule;
}

Booking Cinema::getBooking() {
    return booking;
}

//void Cinema::setBooking(Booking tempBooking) {
//    booking = tempBooking;
//}
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

    WeeklySchedule schedule;
    Booking booking;
    Movie movie;
    Screen screen;

    int menuChoice;
    string startTime = "10 : 15";

    cout << "-------Welcome to the cinema--------" << endl;
    cout << "____________________________________" << endl;


    while (true) {

        cout << "\n1. Add movies to the schedule\n"
             << "2. Edit starting time for all movies\n"
             << "3. Make a booking\n"
             << "4. See all available movies\n"
             << "5. See all Bookings\n"
             << "6. Exit\n"
             << "What would you like to do? : ";

        menuChoice = schedule.checkAndFixError();

        if (menuChoice == 1) {
            int weekChoice = schedule.getWeekChoice();

//            Movie tempMovie = movie.getInput();
            schedule.writeToMovieFile(movie.getInput(), weekChoice);

        }

        else if (menuChoice == 2) {
//            int weekChoice = schedule.getWeekChoice();

//            schedule.readMoviesFromFile(weekChoice);
            startTime = schedule.editAvailableTimes();
//            schedule.setAvailableTimes(weekChoice, startTime);

        }

        else if (menuChoice == 3) {
            int weekChoice = schedule.getWeekChoice();

            schedule.readMoviesFromFile(weekChoice);
            schedule.readScreenFromFile();

            booking.book(&schedule, startTime);
        }

        else if (menuChoice == 4) {
            int weekChoice = schedule.getWeekChoice();

            schedule.readMoviesFromFile(weekChoice);

            schedule.displayMovies();
        }

        else if (menuChoice == 5) {
            booking.displayAllBookingsFromFile();
        }

        else if (menuChoice == 6){
            break;
        }

        else {
            cout << "Please choose a valid option" << endl;
        }

    }

    return 0;
}
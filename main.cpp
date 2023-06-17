#include <iostream>
#include <string>

#include "Movie.h"
#include "WeeklySchedule.h"
#include "Booking.h"
#include "Screen.h"

using namespace std;

int main() {

    WeeklySchedule schedule, firstWeekThu, firstWeekFri, firstWeekSat, firstWeekSun, firstWeekMon, firstWeekTue, firstWeekWed;
    WeeklySchedule secondWeekThu, secondWeekFri, secondWeekSat, secondWeekSun, secondWeekMon, secondWeekTue, secondWeekWed;
    Booking booking;
    Movie movie;
    Screen screen;

    int menuChoice;
    string firstThuStartTime = "10 : 15";
    string firstFriStartTime = "10 : 15";
    string firstSatStartTime = "10 : 15";
    string firstSunStartTime = "10 : 15";
    string firstMonStartTime = "10 : 15";
    string firstTueStartTime = "10 : 15";
    string firstWedStartTime = "10 : 15";
    string secondThuStartTime = "10 : 15";
    string secondFriStartTime = "10 : 15";
    string secondSatStartTime = "10 : 15";
    string secondSunStartTime = "10 : 15";
    string secondMonStartTime = "10 : 15";
    string secondTueStartTime = "10 : 15";
    string secondWedStartTime = "10 : 15";

    cout << "-------Welcome to the cinema--------" << endl;
    cout << "____________________________________" << endl;


    while (true) {

        cout << "\n1. Add movies to the schedule\n"
             << "2. Edit starting time for a day\n"
             << "3. Make a booking\n"
             << "4. See all available movies\n"
             << "5. See all Bookings\n"
             << "6. Exit\n"
             << "What would you like to do? : ";

        menuChoice = schedule.checkAndFixError();

        if (menuChoice == 1) {
            int weekChoice = schedule.getWeekChoice();
            schedule.writeToMovieFile(movie.getInput(), weekChoice);

        }

        else if (menuChoice == 2) {
            int weekChoice = schedule.getWeekChoice();
            int day = booking.setDateFromInput();

            if (weekChoice == 1){
                if (day == 1){
                    firstThuStartTime = schedule.editAvailableTimes();
                }
                else if (day == 2){
                    firstFriStartTime = schedule.editAvailableTimes();
                }
                else if (day == 3){
                    firstSatStartTime = schedule.editAvailableTimes();
                }
                else if (day == 4){
                    firstSunStartTime = schedule.editAvailableTimes();
                }
                else if (day == 5){
                    firstMonStartTime = schedule.editAvailableTimes();
                }
                else if (day == 6){
                    firstTueStartTime = schedule.editAvailableTimes();
                }
                else {
                    firstWedStartTime = schedule.editAvailableTimes();
                }
            }

            else if (weekChoice == 2){
                if (day == 1){
                    secondThuStartTime = schedule.editAvailableTimes();
                }
                else if (day == 2){
                    secondFriStartTime = schedule.editAvailableTimes();
                }
                else if (day == 3){
                    secondSatStartTime = schedule.editAvailableTimes();
                }
                else if (day == 4){
                    secondSunStartTime = schedule.editAvailableTimes();
                }
                else if (day == 5){
                    secondMonStartTime = schedule.editAvailableTimes();
                }
                else if (day == 6){
                    secondTueStartTime = schedule.editAvailableTimes();
                }
                else {
                    secondWedStartTime = schedule.editAvailableTimes();
                }
            }

        }

        else if (menuChoice == 3) {
            int weekChoice = schedule.getWeekChoice();
            int day = booking.setDateFromInput();

            if (weekChoice == 1){
                if (day == 1){
                    firstWeekThu.readMoviesFromFile(weekChoice);
                    firstWeekThu.readScreenFromFile();
                    booking.book(&firstWeekThu, firstThuStartTime);
                }
                else if (day == 2){
                    firstWeekFri.readMoviesFromFile(weekChoice);
                    firstWeekFri.readScreenFromFile();
                    booking.book(&firstWeekFri, firstFriStartTime);
                }
                else if (day == 3){
                    firstWeekSat.readMoviesFromFile(weekChoice);
                    firstWeekSat.readScreenFromFile();
                    booking.book(&firstWeekSat, firstSatStartTime);
                }
                else if (day == 4){
                    firstWeekSun.readMoviesFromFile(weekChoice);
                    firstWeekSun.readScreenFromFile();
                    booking.book(&firstWeekSun, firstSunStartTime);
                }
                else if (day == 5){
                    firstWeekMon.readMoviesFromFile(weekChoice);
                    firstWeekMon.readScreenFromFile();
                    booking.book(&firstWeekMon, firstMonStartTime);
                }
                else if (day == 6){
                    firstWeekTue.readMoviesFromFile(weekChoice);
                    firstWeekTue.readScreenFromFile();
                    booking.book(&firstWeekTue, firstTueStartTime);
                }
                else {
                    firstWeekWed.readMoviesFromFile(weekChoice);
                    firstWeekWed.readScreenFromFile();
                    booking.book(&firstWeekWed, firstWedStartTime);
                }
            }

            else if (weekChoice == 2){
                if (day == 1){
                    secondWeekThu.readMoviesFromFile(weekChoice);
                    secondWeekThu.readScreenFromFile();
                    booking.book(&secondWeekThu, secondThuStartTime);
                }
                else if (day == 2){
                    secondWeekFri.readMoviesFromFile(weekChoice);
                    secondWeekFri.readScreenFromFile();
                    booking.book(&secondWeekFri, secondFriStartTime);
                }
                else if (day == 3){
                    secondWeekSat.readMoviesFromFile(weekChoice);
                    secondWeekSat.readScreenFromFile();
                    booking.book(&secondWeekSat, secondSatStartTime);
                }
                else if (day == 4){
                    secondWeekSun.readMoviesFromFile(weekChoice);
                    secondWeekSun.readScreenFromFile();
                    booking.book(&secondWeekSun, secondSunStartTime);
                }
                else if (day == 5){
                    secondWeekMon.readMoviesFromFile(weekChoice);
                    secondWeekMon.readScreenFromFile();
                    booking.book(&secondWeekMon, secondMonStartTime);
                }
                else if (day == 6){
                    secondWeekTue.readMoviesFromFile(weekChoice);
                    secondWeekTue.readScreenFromFile();
                    booking.book(&secondWeekTue, secondTueStartTime);
                }
                else {
                    secondWeekWed.readMoviesFromFile(weekChoice);
                    secondWeekWed.readScreenFromFile();
                    booking.book(&secondWeekWed, secondWedStartTime);
                }
            }
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
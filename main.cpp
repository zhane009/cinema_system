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
    WeeklySchedule thirdWeekThu, thirdWeekFri, thirdWeekSat, thirdWeekSun, thirdWeekMon, thirdWeekTue, thirdWeekWed;
    WeeklySchedule fourthWeekThu, fourthWeekFri, fourthWeekSat, fourthWeekSun, fourthWeekMon, fourthWeekTue, fourthWeekWed;

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
    string thirdThuStartTime = "10:15";
    string thirdFriStartTime = "10:15";
    string thirdSatStartTime = "10:15";
    string thirdSunStartTime = "10:15";
    string thirdMonStartTime = "10:15";
    string thirdTueStartTime = "10:15";
    string thirdWedStartTime = "10:15";
    string fourthThuStartTime = "10:15";
    string fourthFriStartTime = "10:15";
    string fourthSatStartTime = "10:15";
    string fourthSunStartTime = "10:15";
    string fourthMonStartTime = "10:15";
    string fourthTueStartTime = "10:15";
    string fourthWedStartTime = "10:15";

    cout << "-------Welcome to the cinema--------" << endl;
    cout << "____________________________________" << endl;

    while (true) {

        cout << "\n1. Make a booking\n"
             << "2. Add a movie to the schedule of a particular week\n"
             << "3. Edit starting time for a day\n"
             << "4. See all available movies\n"
             << "5. See all Bookings\n"
             << "6. Exit\n"
             << "What would you like to do? : ";

        menuChoice = schedule.checkAndFixError();


        if (menuChoice == 1) {
            int weekChoice = booking.getWeekChoice();
            int day = booking.setDateFromInput(weekChoice);

            if (weekChoice == 1){
                if (day == 1){
                    firstWeekThu.readMoviesFromFile(weekChoice);
                    firstWeekThu.readScreenFromFile();
                    booking.book(&firstWeekThu, firstThuStartTime, weekChoice);
                }
                else if (day == 2){
                    firstWeekFri.readMoviesFromFile(weekChoice);
                    firstWeekFri.readScreenFromFile();
                    booking.book(&firstWeekFri, firstFriStartTime, weekChoice);
                }
                else if (day == 3){
                    firstWeekSat.readMoviesFromFile(weekChoice);
                    firstWeekSat.readScreenFromFile();
                    booking.book(&firstWeekSat, firstSatStartTime, weekChoice);
                }
                else if (day == 4){
                    firstWeekSun.readMoviesFromFile(weekChoice);
                    firstWeekSun.readScreenFromFile();
                    booking.book(&firstWeekSun, firstSunStartTime, weekChoice);
                }
                else if (day == 5){
                    firstWeekMon.readMoviesFromFile(weekChoice);
                    firstWeekMon.readScreenFromFile();
                    booking.book(&firstWeekMon, firstMonStartTime, weekChoice);
                }
                else if (day == 6){
                    firstWeekTue.readMoviesFromFile(weekChoice);
                    firstWeekTue.readScreenFromFile();
                    booking.book(&firstWeekTue, firstTueStartTime, weekChoice);
                }
                else {
                    firstWeekWed.readMoviesFromFile(weekChoice);
                    firstWeekWed.readScreenFromFile();
                    booking.book(&firstWeekWed, firstWedStartTime, weekChoice);
                }
            }

            else if (weekChoice == 2){
                if (day == 1){
                    secondWeekThu.readMoviesFromFile(weekChoice);
                    secondWeekThu.readScreenFromFile();
                    booking.book(&secondWeekThu, secondThuStartTime, weekChoice);
                }
                else if (day == 2){
                    secondWeekFri.readMoviesFromFile(weekChoice);
                    secondWeekFri.readScreenFromFile();
                    booking.book(&secondWeekFri, secondFriStartTime, weekChoice);
                }
                else if (day == 3){
                    secondWeekSat.readMoviesFromFile(weekChoice);
                    secondWeekSat.readScreenFromFile();
                    booking.book(&secondWeekSat, secondSatStartTime, weekChoice);
                }
                else if (day == 4){
                    secondWeekSun.readMoviesFromFile(weekChoice);
                    secondWeekSun.readScreenFromFile();
                    booking.book(&secondWeekSun, secondSunStartTime, weekChoice);
                }
                else if (day == 5){
                    secondWeekMon.readMoviesFromFile(weekChoice);
                    secondWeekMon.readScreenFromFile();
                    booking.book(&secondWeekMon, secondMonStartTime, weekChoice);
                }
                else if (day == 6){
                    secondWeekTue.readMoviesFromFile(weekChoice);
                    secondWeekTue.readScreenFromFile();
                    booking.book(&secondWeekTue, secondTueStartTime, weekChoice);
                }
                else {
                    secondWeekWed.readMoviesFromFile(weekChoice);
                    secondWeekWed.readScreenFromFile();
                    booking.book(&secondWeekWed, secondWedStartTime, weekChoice);
                }
            }
            else if (weekChoice == 3){
                if (day == 1){
                    thirdWeekThu.readMoviesFromFile(weekChoice);
                    thirdWeekThu.readScreenFromFile();
                    booking.book(&thirdWeekThu, thirdThuStartTime, weekChoice);
                }
                else if (day == 2){
                    thirdWeekFri.readMoviesFromFile(weekChoice);
                    thirdWeekFri.readScreenFromFile();
                    booking.book(&thirdWeekFri, thirdFriStartTime, weekChoice);
                }
                else if (day == 3){
                    thirdWeekSat.readMoviesFromFile(weekChoice);
                    thirdWeekSat.readScreenFromFile();
                    booking.book(&thirdWeekSat, thirdSatStartTime, weekChoice);
                }
                else if (day == 4){
                    thirdWeekSun.readMoviesFromFile(weekChoice);
                    thirdWeekSun.readScreenFromFile();
                    booking.book(&thirdWeekSun, thirdSunStartTime, weekChoice);
                }
                else if (day == 5){
                    thirdWeekMon.readMoviesFromFile(weekChoice);
                    thirdWeekMon.readScreenFromFile();
                    booking.book(&thirdWeekMon, thirdMonStartTime, weekChoice);
                }
                else if (day == 6){
                    thirdWeekTue.readMoviesFromFile(weekChoice);
                    thirdWeekTue.readScreenFromFile();
                    booking.book(&thirdWeekTue, thirdTueStartTime, weekChoice);
                }
                else {
                    thirdWeekWed.readMoviesFromFile(weekChoice);
                    thirdWeekWed.readScreenFromFile();
                    booking.book(&thirdWeekWed, thirdWedStartTime, weekChoice);
                }
            }

            else if (weekChoice == 4){
                if (day == 1){
                    fourthWeekThu.readMoviesFromFile(weekChoice);
                    fourthWeekThu.readScreenFromFile();
                    booking.book(&fourthWeekThu, fourthThuStartTime, weekChoice);
                }
                else if (day == 2){
                    fourthWeekFri.readMoviesFromFile(weekChoice);
                    fourthWeekFri.readScreenFromFile();
                    booking.book(&fourthWeekFri, fourthFriStartTime, weekChoice);
                }
                else if (day == 3){
                    fourthWeekSat.readMoviesFromFile(weekChoice);
                    fourthWeekSat.readScreenFromFile();
                    booking.book(&fourthWeekSat, fourthSatStartTime, weekChoice);
                }
                else if (day == 4){
                    fourthWeekSun.readMoviesFromFile(weekChoice);
                    fourthWeekSun.readScreenFromFile();
                    booking.book(&fourthWeekSun, fourthSunStartTime, weekChoice);
                }
                else if (day == 5){
                    fourthWeekMon.readMoviesFromFile(weekChoice);
                    fourthWeekMon.readScreenFromFile();
                    booking.book(&fourthWeekMon, fourthMonStartTime, weekChoice);
                }
                else if (day == 6){
                    fourthWeekTue.readMoviesFromFile(weekChoice);
                    fourthWeekTue.readScreenFromFile();
                    booking.book(&fourthWeekTue, fourthTueStartTime, weekChoice);
                }
                else {
                    fourthWeekWed.readMoviesFromFile(weekChoice);
                    fourthWeekWed.readScreenFromFile();
                    booking.book(&fourthWeekWed, fourthWedStartTime, weekChoice);
                }
            }

        }
        else if (menuChoice == 2) {
            int weekChoice = booking.getWeekChoice();

            if (schedule.canAddMovies(weekChoice)){
                schedule.writeToMovieFile(movie.getInput(), weekChoice);
            }

        }

        else if (menuChoice == 3) {
            int weekChoice = booking.getWeekChoice();
            int day = booking.setDateFromInput(weekChoice);

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

            else if (weekChoice == 3){
                if (day == 1){
                    thirdThuStartTime = schedule.editAvailableTimes();
                }
                else if (day == 2){
                    thirdFriStartTime = schedule.editAvailableTimes();
                }
                else if (day == 3){
                    thirdSatStartTime = schedule.editAvailableTimes();
                }
                else if (day == 4){
                    thirdSunStartTime = schedule.editAvailableTimes();
                }
                else if (day == 5){
                    thirdMonStartTime = schedule.editAvailableTimes();
                }
                else if (day == 6){
                    thirdTueStartTime = schedule.editAvailableTimes();
                }
                else {
                    thirdWedStartTime = schedule.editAvailableTimes();
                }
            }

            else if (weekChoice == 4){
                if (day == 1){
                    fourthThuStartTime = schedule.editAvailableTimes();
                }
                else if (day == 2){
                    fourthFriStartTime = schedule.editAvailableTimes();
                }
                else if (day == 3){
                    fourthSatStartTime = schedule.editAvailableTimes();
                }
                else if (day == 4){
                    fourthSunStartTime = schedule.editAvailableTimes();
                }
                else if (day == 5){
                    fourthMonStartTime = schedule.editAvailableTimes();
                }
                else if (day == 6){
                    fourthTueStartTime = schedule.editAvailableTimes();
                }
                else {
                    fourthWedStartTime = schedule.editAvailableTimes();
                }
            }

        }

        else if (menuChoice == 4) {
            int weekChoice = booking.getWeekChoice();

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
#include <iostream>
#include <string>

#include "Movie.h"
#include "WeeklySchedule.h"
#include "Booking.h"
#include "Screen.h"

using namespace std;

int main() {

    //declare necessary instances
    WeeklySchedule schedule;
    Booking booking;
    Movie movie;
    Screen screen;

    int menuChoice;

    //declare the starting times for all available days
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
             << "2. View the schedule of a movie at a particular day\n"
             << "3. Add a movie to the schedule of a particular week\n"
             << "4. Edit starting time for a day\n"
             << "5. See all available movies\n"
             << "6. See all Bookings\n"
             << "7. Edit screen allocation for a movie\n"
             << "8. Exit\n"
             << "What would you like to do? : ";

        //ask the user to choose
        menuChoice = schedule.checkAndFixError();


        if (menuChoice == 1) {
            int weekChoice = booking.getWeekChoice();
            int day = booking.setDateFromInput(weekChoice);
            schedule.readMoviesFromFile(weekChoice);//read the file according to the week choice
            schedule.readScreenFromFile(weekChoice);

            //book on based on the week and day choice
            if (weekChoice == 1){
                if (day == 1){
                    booking.book(&schedule, firstThuStartTime, weekChoice);
                }
                else if (day == 2){
                    booking.book(&schedule, firstFriStartTime, weekChoice);
                }
                else if (day == 3){
                    booking.book(&schedule, firstSatStartTime, weekChoice);
                }
                else if (day == 4){
                    booking.book(&schedule, firstSunStartTime, weekChoice);
                }
                else if (day == 5){
                    booking.book(&schedule, firstMonStartTime, weekChoice);
                }
                else if (day == 6){
                    booking.book(&schedule, firstTueStartTime, weekChoice);
                }
                else {
                    booking.book(&schedule, firstWedStartTime, weekChoice);
                }
            }

            else if (weekChoice == 2){
                if (day == 1){
                    booking.book(&schedule, secondThuStartTime, weekChoice);
                }
                else if (day == 2){
                    booking.book(&schedule, secondFriStartTime, weekChoice);
                }
                else if (day == 3){
                    booking.book(&schedule, secondSatStartTime, weekChoice);
                }
                else if (day == 4){
                    booking.book(&schedule, secondSunStartTime, weekChoice);
                }
                else if (day == 5){
                    booking.book(&schedule, secondMonStartTime, weekChoice);
                }
                else if (day == 6){
                    booking.book(&schedule, secondTueStartTime, weekChoice);
                }
                else {
                    booking.book(&schedule, secondWedStartTime, weekChoice);
                }
            }
            else if (weekChoice == 3){
                if (day == 1){
                    booking.book(&schedule, thirdThuStartTime, weekChoice);
                }
                else if (day == 2){
                    booking.book(&schedule, thirdFriStartTime, weekChoice);
                }
                else if (day == 3){
                    booking.book(&schedule, thirdSatStartTime, weekChoice);
                }
                else if (day == 4){
                    booking.book(&schedule, thirdSunStartTime, weekChoice);
                }
                else if (day == 5){
                    booking.book(&schedule, thirdMonStartTime, weekChoice);
                }
                else if (day == 6){
                    booking.book(&schedule, thirdTueStartTime, weekChoice);
                }
                else {
                    booking.book(&schedule, thirdWedStartTime, weekChoice);
                }
            }

            else if (weekChoice == 4){
                if (day == 1){
                    booking.book(&schedule, fourthThuStartTime, weekChoice);
                }
                else if (day == 2){
                    booking.book(&schedule, fourthFriStartTime, weekChoice);
                }
                else if (day == 3){
                    booking.book(&schedule, fourthSatStartTime, weekChoice);
                }
                else if (day == 4){
                    booking.book(&schedule, fourthSunStartTime, weekChoice);
                }
                else if (day == 5){
                    booking.book(&schedule, fourthMonStartTime, weekChoice);
                }
                else if (day == 6){
                    booking.book(&schedule, fourthTueStartTime, weekChoice);
                }
                else {
                    booking.book(&schedule, fourthWedStartTime, weekChoice);
                }
            }

        }

        else if (menuChoice == 2) {
            int weekChoice = booking.getWeekChoice();
            int day = booking.setDateFromInput(weekChoice);
            schedule.readMoviesFromFile(weekChoice);
            schedule.readScreenFromFile(weekChoice);

            //display schedule based on week, day and movie choice
            if (weekChoice == 1){
                if (day == 1){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, firstThuStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 2){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, firstFriStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 3){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, firstSatStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 4){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, firstSunStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 5){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, firstMonStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 6){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, firstTueStartTime);
                    schedule.displaySchedule();
                }
                else {
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, firstWedStartTime);
                    schedule.displaySchedule();
                }
            }

            else if (weekChoice == 2){
                if (day == 1){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, secondThuStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 2){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, secondFriStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 3){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, secondSatStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 4){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, secondSunStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 5){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, secondMonStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 6){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, secondTueStartTime);
                    schedule.displaySchedule();
                }
                else {
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, secondWedStartTime);
                    schedule.displaySchedule();
                }
            }
            else if (weekChoice == 3){
                if (day == 1){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, thirdThuStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 2){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, thirdFriStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 3){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, thirdSatStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 4){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, thirdSunStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 5){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, thirdMonStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 6){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, thirdTueStartTime);
                    schedule.displaySchedule();
                }
                else {
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, thirdWedStartTime);
                    schedule.displaySchedule();
                }
            }

            else if (weekChoice == 4){
                if (day == 1){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, fourthThuStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 2){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, fourthFriStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 3){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, fourthSatStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 4){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, fourthSunStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 5){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, fourthMonStartTime);
                    schedule.displaySchedule();
                }
                else if (day == 6){
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, fourthTueStartTime);
                    schedule.displaySchedule();
                }
                else {
                    int index = booking.getMovieChoice(&schedule);
                    schedule.setAvailableTimes(index, fourthWedStartTime);
                    schedule.displaySchedule();
                }
            }

        }
        else if (menuChoice == 3) {
            int weekChoice = booking.getWeekChoice();

            // if there is space
            if (schedule.canAddMovies(weekChoice)){
                //ask for input and write to the file
                schedule.writeToMovieFile(movie.getInput(), weekChoice);
            }

        }

        else if (menuChoice == 4) {
            int weekChoice = booking.getWeekChoice();
            int day = booking.setDateFromInput(weekChoice);

            //set the starting times for chosen the day in the chosen week
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

        else if (menuChoice == 5) {
            int weekChoice = booking.getWeekChoice();

            //display all available movies based on the chosen week
            schedule.readMoviesFromFile(weekChoice);

            schedule.displayMovies();
        }

        else if (menuChoice == 6) {
            //read and display all bookings from the file
            booking.displayAllBookingsFromFile();
        }

        else if (menuChoice == 7){
            int week = booking.getWeekChoice();
            schedule.readMoviesFromFile(week);
            schedule.readScreenFromFile(week);
            //if there are 5 movies already, do not let the user edit
            if (schedule.getMoviesSize() > 4) {
                cout << "You cannot edit for this week anymore. It is already filled." << endl;
            }
            else{
                //perform the edit process based on the week choice
                schedule.editMovieSetToScreen(week, booking.getMovieChoice(&schedule));
            }
        }

        else if (menuChoice == 8){
            //if the user chooses 8, exit
            break;
        }

        else {
            //if the user chooses an invalid option, repeat and ask again
            cout << "Please choose a valid option" << endl;
        }

    }
    return 0;
}
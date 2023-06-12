#include "Booking.h"

using namespace std;

int* Booking::getNumberOfTickets() {
    return numberOfTickets;
}

void Booking::setNumberOfTickets (int* tempNumberOfTickets){
    for (int i = 0; i < 4; i++){
        numberOfTickets[i] = tempNumberOfTickets[i];
    }
}

Movie Booking::getMovie() {
    return movie;
}

void Booking::setMovie (int movieIndex) {
    WeeklySchedule schedule;
    schedule.readFromFile();
    movie = schedule.getAvailableMovies()[movieIndex];

}

string Booking::getDate() {
    return date;
}

void Booking::setDate(string tempDate){
    date = tempDate;
}

string Booking::getTime() {
    return time;
}

void Booking::setTime(string tempTime) {
    time = tempTime;
}

double Booking::getTotalCost() {
    return totalCost;
}

void Booking::setTotalCost(double tempTotalCost){
    totalCost = tempTotalCost;
}

string Booking::getPaymentType() {
    return paymentType;
}

void Booking::setPaymentType(string tempPaymentType) {
    paymentType = tempPaymentType;
}

void Booking::book(string startTime) {
    setDateFromInput();
    int movieIndex = getMovieChoice();
    setMovie(movieIndex);
    getBookingTime(movieIndex, startTime);
    setNumberOfTicketsFromInput();
    calculateTotalPrice();
    setPaymentTypeFromInput();
    displayBookingInformation();
}

float Booking::getAdultPrice() {
    return adultPrice;
}

float Booking::getChildPrice() {
    return childPrice;
}

float Booking::getSeniorPrice() {
    return seniorPrice;
}

float Booking::getStudentPrice() {
    return studentPrice;
}

int Booking::getMovieChoice() {
    WeeklySchedule schedule;
    schedule.readFromFile();
    int temp;
    Movie *ptr = schedule.getAvailableMovies();
    bool loop = true;

    for (int i = 0; i < schedule.getMoviesSize(); i++) {
        cout << i + 1 << ". Title : " << ptr[i].getTitle() << endl;
    }

    cout << "Choose a number : ";

    while (loop){
        temp = checkAndFixError();

        if (temp > schedule.getMoviesSize() || temp <= 0){
            cout << "Please choose a valid option" << endl;
        }

        else {
            loop = false;
        }
    }

    return temp - 1;
}

void Booking::getBookingTime(int movieIndex, string startTime){
    int input;
    WeeklySchedule schedule;
    schedule.readFromFile();

    schedule.setAvailableTimes(movieIndex, startTime);
    bool loop = true;

    string *timePtr= schedule.getAvailableTimes();

    for (int i = 0; i < schedule.getTimesSize(); i ++){
        cout << i + 1 << ". " << timePtr[i] << endl;
    }

    cout << "Choose an option : ";
    while (loop){
        input = checkAndFixError();
        if (input > schedule.getTimesSize() || input <= 0){
            cout << "Please choose a valid option" << endl;
        }
        else {
            loop = false;
        }
    }
    setTime(*(timePtr + (input - 1)));
}

void Booking::setNumberOfTicketsFromInput() {
    string tempString;
    int tempNumber = 0;
    int tempTickets[4];
    string ques[4] = {
            "Adult Tickets: ",
            "Child Tickets: ",
            "Senior Tickets: ",
            "Student Tickets: "
    };

    for (int i = 0; i < 4; ++i) {
        cout << ques[i];
        tempNumber = checkAndFixError();
        tempTickets[i] = tempNumber;
    }

    setNumberOfTickets(tempTickets);
}

void Booking::calculateTotalPrice() {
    int* tempNumberOfTickets = getNumberOfTickets();
    float total = (getAdultPrice() * tempNumberOfTickets[0]) +
            (getChildPrice() * tempNumberOfTickets[1]) +
            (getSeniorPrice() * tempNumberOfTickets[2]) +
            (getStudentPrice() * tempNumberOfTickets[3]);

    setTotalCost(total);

}

void Booking::setPaymentTypeFromInput() {
    string tempStr;
    int tempInt;
    cout << "1. Card \n2. Cash \nHow would you like to pay?: ";


    bool loop = true;

    while(loop){
        tempInt = checkAndFixError();
        if (tempInt == 1){
            setPaymentType("Card");
            int card, expDate, cvv;
            cout << "what is your card number? :";
            cin >> card;
            cout << "what is the exp date?: ";
            cin >> expDate;
            cout << "what is the cvv?: ";
            cin >> cvv;
            loop = false;
        }

        else if (tempInt == 2){
            setPaymentType("Cash");
            loop = false;
        }

        else{
            cout << "Please choose a valid option" << endl;
        }

    }

}

void Booking::displayBookingInformation() {
    string temp[4] = {
            "Adult x ",
            "Child x ",
            "Senior x ",
            "Student x "
    };

    cout << "You have made a booking: " << endl;
    cout << "For Movie: " << getMovie().getTitle() << endl;
    cout << "On Day: " << getDate() << endl;
    cout << "At Time: " << getTime() << endl;
    cout << "With Number Of Tickets: ";

    for (int i = 0; i < 4; i++){
        cout << temp[i] <<  getNumberOfTickets()[i] << ", ";
        if (i == 3){
            cout << endl;
        }
    }

    cout << "And The Total Cost is: " << getTotalCost() << endl;
    cout << "Which was paid by: " << getPaymentType() << endl;
}

int Booking::checkAndFixError() {
    int temp;
    while (!(cin >> temp)){
        cout << "Invalid Input. Please type in only an integer." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return temp;

}

void Booking::setDateFromInput() {
    int temp;
    string days[7] = {
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday"
    };
    bool loop = true;

    for (int i = 0; i < 7; i ++) {
        cout << i + 1 << ". " << days[i] << endl;
    }
    cout << "Please choose a day: ";
    while (loop){
        temp = checkAndFixError();
        if (temp > 7 || temp <= 0){
            cout << "Please choose a valid option" << endl;
        }
        else {
            loop = false;
        }

    }
    setDate(days[temp-1]);
}



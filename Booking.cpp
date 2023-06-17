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

void Booking::setMovie (int movieIndex, Movie* availableMovies) {

    movie = availableMovies[movieIndex];

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

void Booking::book(WeeklySchedule* schedule, string startTime) {
    int movieIndex = getMovieChoice(schedule);
    setMovie(movieIndex, schedule->getAvailableMovies());
    getBookingTime(movieIndex, startTime, schedule);
    setNumberOfTicketsFromInput();
    calculateTotalPrice();
    setPaymentTypeFromInput();
    displayBookingInformation();
    writeToFile();
}

Screen Booking::getScreen() {
    return screen;
}

void Booking::setScreen(int index, Screen *screens) {
    screen = screens[index];
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

int Booking::getMovieChoice(WeeklySchedule* schedule) {
//    WeeklySchedule schedule;
//    schedule.readMoviesFromFile();
    int temp;
    Movie *ptr = schedule->getAvailableMovies();
    Screen *ptr2 = schedule->getScreens();
    bool loop = true;

    for (int i = 0; i < schedule->getMoviesSize(); i++) {
        cout << i + 1 << ". Title : " << ptr[i].getTitle() << " at Screen: " << ptr2[i].getScreenType() << endl;
    }

    cout << "Choose a number : ";

    while (loop){
        temp = checkAndFixError();

        if (temp > schedule->getMoviesSize() || temp <= 0){
            cout << "Please choose a valid option" << endl;
        }

        else {
            loop = false;
        }
    }

    setMovie(temp-1, schedule->getAvailableMovies());
    setScreen(temp-1, schedule->getScreens());
    return temp - 1;
}

void Booking::getBookingTime(int movieIndex, string startTime, WeeklySchedule* schedule){
    int input;
//
    schedule->setAvailableTimes(movieIndex, startTime);
    bool loop = true;
//
    string *timePtr= schedule->getAvailableTimes();

    for (int i = 0; i < schedule->getTimesSize(); i ++){
        cout << i + 1 << ". " << timePtr[i] << endl;
    }

    cout << "Choose an option : ";
    while (loop){
        input = checkAndFixError();
        if (input > schedule->getTimesSize() || input <= 0){
            cout << "Please choose a valid option" << endl;
        }
        else {
            loop = false;
        }
    }
    setTime(*(schedule->getAvailableTimes() + (input - 1)));
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


    while (true){
        int total = 0;
        for (int i = 0; i < 4; ++i) {
            cout << ques[i];
            tempNumber = checkAndFixError();
            tempTickets[i] = tempNumber;
            total += tempNumber;
        }

        if (screen.getNumberOfSeats() >= total){
            setNumberOfTickets(tempTickets);
            break;
        }

        else  {
            cout << "Your tickets exceed the maximum capacity of the screen. Its capacity is "
                << screen.getNumberOfSeats() << ". Please try again."<< endl;
        }


    }

}

void Booking::calculateTotalPrice() {
    int* tempNumberOfTickets = getNumberOfTickets();
    float total = (getAdultPrice() * tempNumberOfTickets[0]) +
            (getChildPrice() * tempNumberOfTickets[1]) +
            (getSeniorPrice() * tempNumberOfTickets[2]) +
            (getStudentPrice() * tempNumberOfTickets[3]);

    setTotalCost(total);
    cout << "The total cost is: " << total << endl;

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

int Booking::setDateFromInput() {
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
    return temp;
}

void Booking::writeToFile(){
//    WeeklySchedule schedule;
//    schedule.readMoviesFromFile();
    fstream BookingFile;
    BookingFile.open("booking.txt", ios::app);

    string tempScreen;
    int adultTicket, childTicket, seniorTicket, studentTicket;

    for (int i = 0; i < 4; i++){
        if (i == 0){
            adultTicket = getNumberOfTickets()[i];
        }

        else if (i == 1){
            childTicket = getNumberOfTickets()[i];
        }

        else if (i == 2){
            seniorTicket = getNumberOfTickets()[i];
        }

        else {
            studentTicket = getNumberOfTickets()[i];
        }
    }


    BookingFile << getMovie().getTitle() << "," << getScreen().getScreenType() << "," << getDate() << "," <<getTime() << ","
                << adultTicket << "," << childTicket << "," << seniorTicket << "," << studentTicket
                << "," << getTotalCost() << "," << getPaymentType() << endl;

    BookingFile.close();
}

void Booking::displayAllBookingsFromFile(){
    string tempLine, tempWord, tempTitle, tempTime, tempDate, tempPaymentType, tempScreen;
    int tempAdult, tempChild, tempSenior, tempStudent;
    double tempTotalCost;

    fstream BookingFile;
    BookingFile.open("booking.txt");
    cout << "All Bookings: \n" << endl;

    while (getline(BookingFile, tempLine)){
        stringstream stream(tempLine);
        int counter  = 0;

        while (getline(stream >> ws, tempWord, ',')){
            if (counter == 0){
                tempTitle = tempWord;
            }
            else if (counter == 1){
                tempScreen = tempWord;
            }
            else if (counter == 2){
                tempDate = tempWord;
            }
            else if (counter == 3){
                tempTime = tempWord;
            }
            else if (counter == 4){
                tempAdult = stoi(tempWord);
            }
            else if (counter == 5){
                tempChild = stoi(tempWord);
            }
            else if (counter == 6){
                tempSenior = stoi(tempWord);
            }
            else if (counter == 7){
                tempStudent = stoi(tempWord);
            }
            else if (counter == 8){
                tempTotalCost = stof(tempWord);
            }
            else if (counter == 9){
                tempPaymentType = tempWord;
            }
            counter++;
        }
        cout << "Movie Title: " << tempTitle << endl;
        cout << "Screen Type: " << tempScreen << endl;
        cout << "Day: " << tempDate << endl;
        cout << "Time: " << tempTime<< endl;
        cout << "Adult Tickets: " << tempAdult << endl;
        cout << "Child Tickets: " << tempChild << endl;
        cout << "Senior Tickets: " << tempSenior << endl;
        cout << "Student Tickets: " << tempStudent << endl;
        cout << "Total Number of Tickets: " << tempAdult + tempChild + tempSenior + tempStudent << endl;
        cout <<  "Total Cost: " << tempTotalCost << endl;
        cout << "Payment Type: " << tempPaymentType << "\n" << endl;
    }
}



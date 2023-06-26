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

string Booking::getWeek() {
    return week;
}

void Booking::setWeek(int index) {
    string weeks[4] = {
            "This week",
            "Week 2",
            "Week 3",
            "Week 4"
    };
    week = weeks[index - 1];
}

string Booking::getDay() {
    return day;
}

void Booking::satDay(string tempDay){
    day = tempDay;
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

void Booking::book(WeeklySchedule* schedule, string startTime, int weekIndex) {
    int movieIndex = getMovieChoice(schedule);
    setWeek(weekIndex);
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

int Booking::getWeekChoice() {
    int weekChoice;

    cout << "\n1. This week\n"
         << "2. Week 2\n"
         << "3. Week 3\n"
         << "4. Week 4\n"
         << "For which week?: ";

    while (true){
        weekChoice = checkAndFixError();
        if (weekChoice <= 4 && weekChoice > 0){
            break;
        }
        else {
            cout << "Please choose a valid option" << endl;
        }
    }
    return weekChoice;
}

int Booking::getMovieChoice(WeeklySchedule* schedule) {
    int temp;
    int k = 0;
    Movie *ptr = schedule->getAvailableMovies();
    Screen *ptr2 = schedule->getScreens();
    bool loop = true;
    cout << endl;

//    for (int i = 0; i < schedule->getMoviesSize(); i++) {
//        cout << i + 1 << ". Title : " << ptr[i].getTitle() << " at Screen: " << ptr2[i].getScreenType() << endl;
//    }

    for (int i = 0; i < schedule->getMoviesSize(); i++) {
        for (int j = 0; j < schedule->getScreenSize(); j++){

            if (ptr[i].getTitle() == ptr2[j].getCurrentMovie().getTitle()){
                k++;
                cout << k << ". Title: " << ptr[i].getTitle() << " at Screen: " << ptr2[j].getScreenType() << endl;
            }

        }
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
//    cout << "\nThis screen has " << checkSeatAvailability() << " seats left" << endl;
    return temp - 1;
}

void Booking::getBookingTime(int movieIndex, string startTime, WeeklySchedule* schedule){
    int input;

    schedule->setAvailableTimes(movieIndex, startTime);
    bool loop = true;

    string *timePtr= schedule->getAvailableTimes();
    cout << endl;

    for (int i = 0; i < schedule->getTimesSize(); i ++){
        cout << i + 1 << ". " << timePtr[i] << endl;
    }

    cout << "Choose a time: ";
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

    cout << endl;


    bool loop = true;

    while (true){
        int i = 0;
        int total = 0;

        while (loop) {
            cout << ques[i];
            tempNumber = checkAndFixError();
            if (tempNumber >= 0){
                tempTickets[i] = tempNumber;
                total += tempNumber;
                i++;
                if (i == 4){
                    loop = false;
                }
            }
            else {
                cout << "Number of tickets cannot be a negative number" << endl;

            }

        }

        if (checkSeatAvailability() >= total){
            cout << "Your total is " << total << " tickets" << endl;
            setNumberOfTickets(tempTickets);
            break;
        }

        else  {
            cout << "Your tickets exceed the remaining number of tickets of the screen. Its remaining capacity is "
                << checkSeatAvailability() << ". Please try again."<< endl;
            loop = true;
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
    cout << "\n1. Card \n2. Cash \nHow would you like to pay?: ";


    bool loop = true;

    while(loop){
        tempInt = checkAndFixError();
        if (tempInt == 1){

            setPaymentType("Card");
            string card, expDate, cvv;

            cout << endl;
            cout << "what is your card number in xxxx-xxxx-xxxx-xxxx format? :";
            int count = 0;
            do {
                cin.clear();
                getline(cin, card);
                if ( (count > 0) && (!(checkCard(card))) ){
                    cout << "Your card doesnt match the format." << endl;
                }
                count ++;
            } while( !(checkCard(card)) );

            cout << "what is the exp day in mm/yy format?: ";
            do {
                getline(cin, expDate);
                if ( !(checkExpDate(expDate)) ){
                    cout << "Your exp date doesnt match the format." << endl;
                }
            } while( !(checkExpDate(expDate)) );

            cout << "what is the cvv?: ";
            do {
                getline(cin, cvv);
                if ( !(checkCVV(cvv)) ){
                    cout << "Your cvv doesnt match the format." << endl;
                }
            } while( !(checkCVV(cvv)) );

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

    cout << "\nYou have made a booking: " << endl;
    cout << "For Movie: " << getMovie().getTitle() << endl;
    cout << "On screen: " << getScreen().getScreenType() << endl;
    cout << "For: " << getWeek() << endl;
    cout << "On Day: " << getDay() << endl;
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

int Booking::setDateFromInput(int weekChoice) {
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
    cout << endl;

    for (int i = 0; i < 7; i ++) {
        cout << i + 1 << ". " << days[i] << endl;
    }
    cout << "Please choose a day: ";
    if (weekChoice == 1){
        do{
            do {
                temp = checkAndFixError();
                if (temp > 7 || temp <= 0){
                    cout << "Please choose a valid option" << endl;
                }
                else {
                    break;
                }
            } while (true);

        } while ( !(checkDay(temp - 1)) );
    }
    else {
        while (loop){
            temp = checkAndFixError();
            if (temp > 7 || temp <= 0){
                cout << "Please choose a valid option" << endl;
            }
            else{
                loop = false;
            }
        }
    }
    satDay(days[temp - 1]);
    return temp;
}

void Booking::writeToFile(){

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


    BookingFile << getMovie().getTitle() << "," << getScreen().getScreenType() << "," << getWeek() << ","
                << getDay() << "," << getTime() << "," << adultTicket << "," << childTicket << ","
                << seniorTicket << "," << studentTicket << "," << getTotalCost() << "," << getPaymentType() << endl;

    BookingFile.close();
}

void Booking::displayAllBookingsFromFile(){
    string tempLine, tempWord, tempTitle, tempTime, tempWeek, tempDate, tempPaymentType, tempScreen;
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
                tempWeek = tempWord;
            }
            else if (counter == 3){
                tempDate = tempWord;
            }
            else if (counter == 4){
                tempTime = tempWord;
            }
            else if (counter == 5){
                tempAdult = stoi(tempWord);
            }
            else if (counter == 6){
                tempChild = stoi(tempWord);
            }
            else if (counter == 7){
                tempSenior = stoi(tempWord);
            }
            else if (counter == 8){
                tempStudent = stoi(tempWord);
            }
            else if (counter == 9){
                tempTotalCost = stof(tempWord);
            }
            else if (counter == 10){
                tempPaymentType = tempWord;
            }
            counter++;
        }
        cout << "Movie Title: " << tempTitle << endl;
        cout << "Screen Type: " << tempScreen << endl;
        cout << "Week: " << tempWeek << endl;
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

bool Booking::checkDay(int tempDay) {
    time_t currentTime = std::time(nullptr);
    tm* currentTm = std::localtime(&currentTime);

    int currentDay = currentTm->tm_wday;

    currentDay = (currentDay + 3) % 7;

    if (tempDay >= currentDay) {
        return true;
    }
    else {
        cout << "Your inputted day is in the past. Please choose today or a day in the future." << endl;
        return false;
    }
}

bool Booking::checkCard(string tempCard) {
    regex pattern(R"(\d{4}-\d{4}-\d{4}-\d{4})");
    return regex_match(tempCard, pattern);
}

bool Booking::checkExpDate(string tempExpDate) {
    regex pattern(R"((?:0[1-9]|1[0-2])/(?:2[3-9]|[3-9][0-9]))");
    return regex_match(tempExpDate, pattern);
}

bool Booking::checkCVV(string tempCVV) {
    regex pattern(R"(\d{3})");
    return regex_match(tempCVV, pattern);
}

int Booking::checkSeatAvailability() {
    string tempLine, tempWord, tempScreen, tempMovie, tempDay, tempWeek, tempTime;
    int tempTickets = 0;
    fstream bookingFile;
    bookingFile.open("Booking.txt", ios::in);

    while (getline(bookingFile, tempLine)) {
        stringstream stream(tempLine);
        int counter = 0;

        while (getline(stream >> ws, tempWord, ',')) {
            if (counter == 0){
                tempMovie = tempWord;

            }
            if (counter == 1){
                tempScreen = tempWord;
            }

            if (counter == 2){
                tempWeek = tempWord;
            }

            if (counter == 3){
                tempDay = tempWord;
            }

            if (counter == 4){
                tempTime = tempWord;
            }

            if ((tempMovie == getMovie().getTitle()) && (tempScreen == getScreen().getScreenType())
                && (tempDay == getDay()) && (tempWeek == getWeek()) && (tempTime == getTime())){

                if (counter >= 5 && counter <= 8){
                    tempTickets += stoi(tempWord);
                }

            }
            counter ++;

        }
    }
    int tempSeats = getScreen().getNumberOfSeats() - tempTickets;

    return tempSeats;

}



#include <iomanip>
#include "Booking.h"

using namespace std;

//getters and setters
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

//the function that will do the booking process by calling other necessary ones
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

//the function that will ask the user for week choice
int Booking::getWeekChoice() {
    int weekChoice;

    cout << "\n1. This week\n"
         << "2. Week 2\n"
         << "3. Week 3\n"
         << "4. Week 4\n"
         << "For which week?: ";

    while (true){ // check until the user enters correctly
        weekChoice = checkAndFixError();
        if (weekChoice <= 4 && weekChoice > 0){
            break;
        }
        else {
            cout << "Please choose a valid option" << endl;
        }
    }
    return weekChoice; // return the chosen integer
}

//the function that will ask the user for movie choice
int Booking::getMovieChoice(WeeklySchedule* schedule) {
    int temp;
    int k = 0;
    Movie *ptr = schedule->getAvailableMovies();
    Screen *ptr2 = schedule->getScreens();
    bool loop = true;
    cout << endl; // for separation

    //two nested loops because there are always 5 screens but there may not always be 5 movies
    for (int i = 0; i < schedule->getMoviesSize(); i++) { // loop through the movies vector first
        for (int j = 0; j < schedule->getScreenSize(); j++){ // loop through the screen vector
            // if the title of the movie matches the title of the movie the screen holds
            if (ptr[i].getTitle() == ptr2[j].getCurrentMovie().getTitle()){
                k++;
                //print the title and the screen type
                cout << k << ". Title: " << ptr[i].getTitle() << " at Screen: " << ptr2[j].getScreenType() << endl;
            }

        }
    }

    cout << "Choose a number : ";

    while (loop){ //check until the user enters correctly
        temp = checkAndFixError();

        if (temp > schedule->getMoviesSize() || temp <= 0){
            cout << "Please choose a valid option" << endl;
        }

        else {
            loop = false;
        }
    }

    setMovie(temp-1, schedule->getAvailableMovies());  // set the movie to the one chosen
    setScreen(temp-1, schedule->getScreens());  // set the screen to the one chosen
    return temp - 1;
}

void Booking::getBookingTime(int movieIndex, string startTime, WeeklySchedule* schedule){
    int input;

    //set the times
    schedule->setAvailableTimes(movieIndex, startTime);
    bool loop = true;

    //get the vector by getting the pointer to the first element
    string *timePtr= schedule->getAvailableTimes();
    cout << endl;

    //loop through the vector
    for (int i = 0; i < schedule->getTimesSize(); i ++){
        cout << i + 1 << ". " << timePtr[i] << endl;
    }

    cout << "Choose a time: ";
    while (loop){ //let the user choose until he enters correctly
        input = checkAndFixError();
        if (input > schedule->getTimesSize() || input <= 0){
            cout << "Please choose a valid option" << endl;
        }
        else {
            loop = false;
        }
    }
    setTime(*(schedule->getAvailableTimes() + (input - 1)));  // set the time to the chosen one
}

void Booking::setNumberOfTicketsFromInput() {
    string tempString;
    int tempNumber = 0;

    //declare a temporary array for storing the number of tickets
    int tempTickets[4];
    // the array of questions
    string ques[4] = {
            "Adult Tickets: ",
            "Child Tickets: ",
            "Senior Citizen Tickets: ",
            "Student Tickets: "
    };

    cout << "\nThe Prices are:" << endl;

    cout << "Price for one ticket per an adult: "  << setprecision(2) << fixed << getAdultPrice() << "GBP" << endl;
    cout << "Price for one ticket per a child: " << setprecision(2) << fixed << getChildPrice() << "GBP" << endl;
    cout << "Price for one ticket per a senior citizen: " << setprecision(2) << fixed << getSeniorPrice() << "GBP" << endl;
    cout << "Price for one ticket per a student: " << setprecision(2) << fixed << getStudentPrice() << "GBP" << endl;

    cout << endl;

    bool loop = true;

    while (true){
        int i = 0;
        int total = 0;

        while (loop) {
            //print out the questions one by one
            cout << ques[i];
            tempNumber = checkAndFixError();
            if (tempNumber >= 0){
                tempTickets[i] = tempNumber; // assign the values of the array one by one
                total += tempNumber; // calculate the total numbers of tickets by adding them every time
                i++;
                if (i == 4){    //when it has looped 4 times, break
                    loop = false;
                }
            }
            else {
                cout << "Number of tickets cannot be a negative number" << endl;

            }

        }

        if (checkSeatAvailability() >= total){  // if the remaining seats are greater than the total
            cout << "Your total is " << total << " tickets" << endl;   //let the user proceed
            setNumberOfTickets(tempTickets);    // set the number of tickets to the chosen numbers
            break;  //break the loop
        }

        else  { // if the total tickets are greater than the remaining seats
            cout << "Your tickets exceed the remaining number of tickets of the screen. Its remaining capacity is "
                << checkSeatAvailability() << ". Please try again."<< endl; // print the error message and let the user try again
            loop = true;
        }

    }

}

//the function that will calculate the total cost of the transaction
void Booking::calculateTotalPrice() {
    //get the number of tickets array by its first element
    int* tempNumberOfTickets = getNumberOfTickets();
    //calculate the total price by multiplying the quantity and cost per one
    float total = (getAdultPrice() * tempNumberOfTickets[0]) +
            (getChildPrice() * tempNumberOfTickets[1]) +
            (getSeniorPrice() * tempNumberOfTickets[2]) +
            (getStudentPrice() * tempNumberOfTickets[3]);

    setTotalCost(total); // set the total cost to the one calculated
    //print out the total cost of the transaction to 2 decimal places
    cout << "The total cost is: " << setprecision(2) << fixed << total << "GBP" << endl;

}

//the function that will ask the user for payment method
void Booking::setPaymentTypeFromInput() {
    string tempStr;
    int tempInt;

    cout << "\n1. Card \n2. Cash \nHow would you like to pay?: ";


    bool loop = true;

    while(loop){ // let the user choose until he enters correctly
        tempInt = checkAndFixError();
        if (tempInt == 1){  // if the user chooses card

            setPaymentType("Card"); // set payment type to card
            string card, expDate, cvv;

            // ask for card details
            cout << endl;
            cin.ignore(10000, '\n');
            cin.clear();
            cout << "what is your card number in xxxx-xxxx-xxxx-xxxx format? :";

            do {
                cin.clear(); //clear the buffer for unwanted errors
                getline(cin, card);
                if ( (!(checkCard(card))) ){ // check the format
                    // if it doesn't match, let the user enter again
                    cout << "Your card doesn't match the format." << endl;
                }
            } while( !(checkCard(card)) ); // break once it matches

            cout << "what is the exp day in mm/yy format?: ";
            do {
                getline(cin, expDate);  //get the exp date input
                if ( !(checkExpDate(expDate)) ){    //check the format
                    // if it doesn't match, let the user enter again
                    cout << "Your exp date doesnt match the format." << endl;
                }
            } while( !(checkExpDate(expDate)) );  // break once it matches

            cout << "what is the cvv?: ";
            do {
                getline(cin, cvv);
                if ( !(checkCVV(cvv)) ){    // check the format
                    // if it doesn't match, let the user enter again
                    cout << "Your cvv doesnt match the format." << endl;
                }
            } while( !(checkCVV(cvv)) ); // break once it matches

            cout << "\nPayment accepted." << endl;
            loop = false;   //break the big loop
        }

        else if (tempInt == 2){     // if the user chooses cash
            setPaymentType("Cash"); // set the payment type to cash
            cout << "\nPayment accepted." << endl;
            loop = false;   //break the big loop
        }

        else{
            cout << "\nPlease choose a valid option" << endl;
        }

    }

}

// the function that will display all the details about the booking
void Booking::displayBookingInformation() {
    string temp[4] = {  //a temporary array that hold the types of tickets
            "Adult x ",
            "Child x ",
            "Senior x ",
            "Student x "
    };

    //print out the details of the booking
    cout << "\nYou have made a booking: " << endl;
    cout << "For Movie: " << getMovie().getTitle() << endl;
    cout << "On screen: " << getScreen().getScreenType() << endl;
    cout << "For: " << getWeek() << endl;
    cout << "On Day: " << getDay() << endl;
    cout << "At Time: " << getTime() << endl;
    cout << "With Number Of Tickets: ";

    for (int i = 0; i < 4; i++){    //loop through the array to print the quantity for each ticket type
        cout << temp[i] <<  getNumberOfTickets()[i] << ", ";
        if (i == 3){
            cout << endl;
        }
    }

    //print the total cost to two decimal places
    cout << "And The Total Cost is: " << setprecision(2) << fixed << getTotalCost() << "GBP" << endl;
    cout << "Which was paid by: " << getPaymentType() << endl;
}

// the function that will check if a user enters an integer and return the value
int Booking::checkAndFixError() {

    string input;

    regex pattern ("\\d+");

    do {
        getline(cin, input);
        if (!regex_match(input, pattern)){
            cout << "Please enter only an integer" << endl;
        }
    }while (!regex_match(input, pattern));

    return stoi(input);


//    float temp;
//    while (!(cin >> temp)){ // check if the type of the input is integer
//
//        cout << "Invalid Input. Please type in only an integer." << endl;
//        cin.clear();
//        cin.ignore(1000, '\n');
//    }
//
//    while (int(temp * 10) % 10  != 0){  // check if it is a float
//        if ( int(temp * 10) % 10  == 0) {
//            return int(temp);
//            break;
//        }
//        else {
//            cout << "Invalid Input. Please type in only an integer." << endl;
//            cin.clear();
//            cin.ignore(1000, '\n');
//            cin >> temp;
//        }
//    }
//
//    return temp;
}

// the function that will ask the user for day choice
int Booking::setDateFromInput(int weekChoice) {
    int temp;
    //array of days
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

    for (int i = 0; i < 7; i ++) {  // loop through the array to print out all days
        cout << i + 1 << ". " << days[i] << endl;
    }
    cout << "Please choose a day: ";
    if (weekChoice == 1){   // if the week is current week
        do{ //outer loop is for validation of the day being in the past or not
            do {    // inner loop is for out of bounds and type validation
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
    else {  // if it is not the current week, check only the type and out of bounds
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
    satDay(days[temp - 1]); // set the day to the chosen one
    return temp;
}

// the function that will write the details of a booking to the file
void Booking::writeToFile(){
    //open the file in append mode
    fstream BookingFile;
    BookingFile.open("booking.txt", ios::app);

    //declare all necessary temporary variables
    string tempScreen;
    int adultTicket, childTicket, seniorTicket, studentTicket;

    //loop through the array to get tickets for individual types
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

    //write the details to the file
    BookingFile << getMovie().getTitle() << "," << getScreen().getScreenType() << "," << getWeek() << ","
                << getDay() << "," << getTime() << "," << adultTicket << "," << childTicket << ","
                << seniorTicket << "," << studentTicket << "," << getTotalCost() << "," << getPaymentType() << endl;

    BookingFile.close(); // close the file when done
}

// the function that will read the file and display all bookings in the file
void Booking::displayAllBookingsFromFile(){
    //declare all necessary variables
    string tempLine, tempWord, tempTitle, tempTime, tempWeek, tempDate, tempPaymentType, tempScreen;
    int tempAdult, tempChild, tempSenior, tempStudent;
    double tempTotalCost;

    //open the file
    fstream BookingFile;
    BookingFile.open("booking.txt");
    cout << "All Bookings: \n" << endl;

    //loop through the lines
    while (getline(BookingFile, tempLine)){
        stringstream stream(tempLine);
        int counter  = 0;

        //loop through the words in each line
        while (getline(stream >> ws, tempWord, ',')){
            //set appropriate values to their matching variables
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

        //print out all the details read
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

// the function that will check if a day is in the past or not
bool Booking::checkDay(int tempDay) {

    //get the current time
    time_t currentTime = std::time(nullptr);
    tm* currentTm = std::localtime(&currentTime);

    //get the index of current day
    int currentDay = currentTm->tm_wday;

    //since the week starts from Thursday for the cinema, make Thursday index zero.
    //Sunday is index 0.
    //Thursday is originally index 4
    //add 3 and modulus by 7 to get zero for Thursday
    currentDay = (currentDay + 3) % 7;

    //if the inputted day is in the future, return true
    if (tempDay >= currentDay) {
        return true;
    }
    //else, print the error message and return false
    else {
        cout << "Your inputted day is in the past. Please choose today or a day in the future." << endl;
        return false;
    }
}

//the function that will check the format of the card
bool Booking::checkCard(string tempCard) {
    //the regular expression pattern for 4 numbers - 4 numbers - 4 numbers - 4 numbers
    regex pattern(R"(\d{4}-\d{4}-\d{4}-\d{4})");
    return regex_match(tempCard, pattern); // return true if matches
}

// the function that will check the exp date format
bool Booking::checkExpDate(string tempExpDate) {
    // the regular expression for
    // if the first digit of the month is zero, the second one is between 1 and 9
    // if the first digit of the month is 1, the second one is between 0 and 2
    // the year cannot be less than 23
    // if the year is 23, the month cannot be less than 7 which is July
    regex pattern(R"((?:0[7-9]|1[0-2])/(?:23)|(?:0[1-9]|1[0-2])/(?:2[4-9]|[3-9][0-9]))");
    return regex_match(tempExpDate, pattern); // return true if matches
}

// the function that will check the format of CVV
bool Booking::checkCVV(string tempCVV) {
    // the regular expression for 3 numbers
    regex pattern(R"(\d{3})");
    return regex_match(tempCVV, pattern); // return true if matches
}

// the function that will check how many seats are left for a specific show
int Booking::checkSeatAvailability() {
    //declare all necessary variables
    string tempLine, tempWord, tempScreen, tempMovie, tempDay, tempWeek, tempTime;
    int tempTickets = 0;
    //open the file
    fstream bookingFile;
    bookingFile.open("Booking.txt", ios::in);

    //loop through every line
    while (getline(bookingFile, tempLine)) {
        stringstream stream(tempLine);
        int counter = 0;

        //loop through every word in each line
        while (getline(stream >> ws, tempWord, ',')) {
            //set the appropriate values
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

            // if the title of the movie, the type of the screen, the day, the week and the showtime matches,
            if ((tempMovie == getMovie().getTitle()) && (tempScreen == getScreen().getScreenType())
                && (tempDay == getDay()) && (tempWeek == getWeek()) && (tempTime == getTime())){

                if (counter >= 5 && counter <= 8){
                    tempTickets += stoi(tempWord); // add all the numbers of tickets encountered
                }

            }
            counter ++;

        }
    }
    int tempSeats = getScreen().getNumberOfSeats() - tempTickets;   // the seats left are total subtracted by the all tickets booked

    return tempSeats;   // return the value

}



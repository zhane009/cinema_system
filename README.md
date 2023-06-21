# cinema_system

Scenario: Design and develop a booking system for an independent cinema. 
Basic cinema information: The cinema is open from 10:00 to 23:30. The earliest a film can be shown is 10:15. There is a 25-minute gap between film showings so the screen can be cleaned. The cinema contains 5 screens with different seating capacities. The largest screen can hold 250 people the smallest 100 people. Tickets are available in four formats – adults: £9.50, children: £5.50, senior citizens: £6.50 and students: £7.00.

Below outlines the functionality that needs to be carried out by the system:

•	Capture booking information relating to a ticket sale:
  
    o	Number of tickets required, movie choice, date, time, total cost of transaction, payment type (cash or card). For card payments details should be taken but not stored.
  
    o	A booking cannot take place if the following conditions are met:
    
      	The number of tickets sold exceeds the maximum seating capacity of the screen
    
      	Bookings can only be made in the current week (Thursday to Wednesday)

•	Screen information:

    o	Screen ID, movie currently being shown, maximum seating capacity, screen facilities (Standard, IMAX, Couple seats, Seat service etc.
  
    o	Each screen shows a film for a weak (Thursday to Wednesday) and the number of showings is determined by the running time of the film. Remember there is a 25 minute gap between films. 
  
    o	Once a week new films to be screened have their details entered into the system including which screen is to be allocated to the film and the times of the show in the day.

•	Movie information:
    
     o	Title, description, genre, running time, main star, film distributor, release date

•	Weekly schedule information:
  
    o	Each week (Thursday) the manager adds all the new movie details to the system and creates a new schedule for the following week showing which screen is allocated to which film and  listing the times, dates and days. 
  
    o	The manager needs to record the start time and end time of each show factoring in the required 25-minute break between shows.
  
    o	The number of shows for each screen does not need to fit exactly in the amount of time available in the day so long as a show does not exceed the closing time of the cinema. You may decide what is sensible in this regard. 

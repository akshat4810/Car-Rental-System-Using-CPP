# Car-Rental-System-Using-CPP
The Car Rental System is a command-line application developed in C++ to manage car rental services efficiently. The system allows users to rent cars, view rental details, and generate invoices.

# Features
1. Welcome Screen:
   - Displays a welcome message and loads the necessary files.

2. User Authentication:
   - Login: Users can log in with a username and password stored in a file.
   - Registration: New users can register by creating a username and password.

3. Car Selection:
   - Users can choose from a list of available cars with predefined models and rental prices.
   - Displays detailed information about the selected car from a file.

4. Rental Process:
   - Users provide their name, contact details, rental start date, and duration.
   - Option to include fuel in the rental package, affecting the total rental cost.

5. Confirmation:
   - Users confirm their car choice before finalizing the rental.
   - If the user does not confirm, they can reselect the car.

6. Invoice Generation:
   - Generates a detailed invoice with customer details, car model, rental duration, and total amount.
   - Displays the current date and time, customer name, contact details, car model, and rental cost breakdown.

7. File Handling:
   - Reads and writes data to files for user information, car details, and rental confirmations.
   - Utilizes sleep functions to simulate loading times and enhance user experience.

# Implementation
- Object-Oriented Programming: Utilizes classes such as `Welcome`, `Login`, and `Rent` to modularize the system.
- File Operations: Handles file reading and writing to store and retrieve data.
- Control Structures: Uses loops and conditional statements for user interactions and decision-making.
- Error Handling: Ensures valid inputs and manages invalid choices gracefully.

# Benefits
- User-Friendly: Simple command-line interface that guides users through the rental process.
- Efficient: Automates car rental operations, reducing manual effort.
- Accurate: Provides detailed invoices and maintains data integrity through file handling.

This project demonstrates practical application of C++ programming concepts, including file handling, user authentication, and basic data processing, making it a valuable tool for managing car rental services.

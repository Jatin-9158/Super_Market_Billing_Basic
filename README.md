
# Super Market Billing System

This is a simple command-line based billing system for a super market implemented in C++.

## Description

The system allows for the registration of new customers, addition of items to their shopping cart, and printing of bills. It also includes an employee login system for accessing the customer portal.

## Features

- Customer Registration: New customers can register their name and mobile number.
- Existing Customer: Registered customers can login using their name and mobile number.
- Item Addition: Customers can add items to their shopping cart.
- Bill Generation: Once the customer is done shopping, they can print the bill which includes details of items purchased and the total amount.
- Minimal Password Conditions: Passwords are checked for length and must contain at least one uppercase letter and one digit.

## File Structure

- `main.cpp`: Contains the main code for the billing system.
- `Customer_Details.txt`: Stores details of registered customers.
- `Item_Details_Customer.txt`: Stores details of items purchased by customers.
- `Login.txt`: Stores login credentials for employees.

## Usage

1. Compile the `main.cpp` file.
2. Run the executable file.
3. Follow the on-screen instructions to register as a new customer or login as an existing customer or employee.
4. Add items to the shopping cart and print the bill when done.

## Note

- Ensure that the necessary text files (`Customer_Details.txt`, `Item_Details_Customer.txt`, `Login.txt`) are present and accessible for the system to function properly.
- The system uses command-line input and output, so it may not have a graphical user interface.


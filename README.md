# courierservice
# Online Courier Service

This code provides a simple command-line application for an online courier service. An account can be created, users can log in, and they can perform various actions such as sending products for delivery, updating account details, viewing delivery history, and accessing their profile.

## Prerequisites

To run this application, the following prerequisites should be met:

- A C++ compiler
- The Standard Template Library (STL)
- The `fstream` library
- The `string` library
- The `vector` library

## Getting Started

The following steps should be followed to get started:

1. The repository can be cloned or the source code files can be downloaded.
2. Compile the code using a C++ compiler.
3. Run the compiled executable file.

## Usage

Upon running the program, users will be presented with the following options:

1. Log in
2. Create a new account

### Log In

If the option to log in is chosen, the user will be prompted to enter their username and password. The program will check if the provided credentials match an existing account. If the login is successful, users will be logged in and presented with a menu:

- Send product
- Update account details
- View delivery history
- View profile
- Logout

Options can be selected by entering the corresponding number. The necessary prompts will be displayed to complete the desired action.

### Create a New Account

If the option to create a new account is chosen, users will be guided through providing their details, including name, password, address, phone number, and email address. Once the account is created, users can log in using the credentials they have just created.

## File Storage

User account details and delivery history are stored in text files. Each user has a dedicated text file named after their username (e.g., `username.txt`). The delivery history is stored in a text file named after the user's username followed by "deliveryhistory.txt" (e.g., `username_deliveryhistory.txt`).

The OOP (Object-Oriented Programming) concepts used in this project are:

1. **Inheritance**: The code utilizes inheritance to create classes `User` and `Recipient` that inherit from the base class `courier`. The derived classes inherit and extend the properties and behaviors of the base class.

2. **Polymorphism**: The `print()` function is declared as a pure virtual function in the base class `courier`. The derived classes (`User` and `Recipient`) provide their own implementation of the `print()` function. This demonstrates polymorphism, as objects of different classes can be treated as objects of their common base class and can be used interchangeably.

3. **Encapsulation**: The code encapsulates data and functions within classes. Data members (`username`, `address`, `phonenumber`, etc.) are encapsulated within the `User` and `Recipient` classes. Access to these data members is controlled using member functions (`setUserInfo()`, `saveDetails()`, `readDetails()`, etc.), providing a level of abstraction and encapsulation of data.

4. **Abstraction**: The classes and their member functions in the code provide an abstraction layer, hiding the underlying implementation details. Users interact with the classes and their public member functions without needing to know the internal workings of the code.

5. **Data Hiding**: The data members (`username`, `address`, etc.) of the classes are declared as `private`, restricting direct access to them from outside the class. The data members can only be accessed and modified using the member functions (`setUserInfo()`, `saveDetails()`, etc.), ensuring data hiding and encapsulation.

These OOP concepts help in organizing the code, promoting code reusability, enhancing modularity, and providing a clear and structured approach to building the online courier service application.

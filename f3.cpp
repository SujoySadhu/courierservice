#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class courier
{
public:
    void virtual print() = 0;
};

class User : public courier
{
public:
    string username;

    string address;

    string phonenumber;

    string emailaddress;

    string password;

public:
    void courie()
    {
        cout << "united online courier service" << endl;
    }
    void setUserInfo()
    {
        cout << "Enter your name: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);
        cout << "Enter your address: ";
        getline(cin, address);
        cout << "Enter your phone number: ";
        getline(cin, phonenumber);
        cout << "Enter your email address: ";
        getline(cin, emailaddress);
    }

    void saveDetails()
    {
        ofstream file(username + ".txt");
        file << username << endl;
        file << password << endl;
        file << address << endl;
        file << phonenumber << endl;
        file << emailaddress << endl;
        file.close();
    }

    void readDetails()
    {
        ifstream file(username + ".txt");
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }

    void print()
    {
        cout << "\t\t\t\t|**************|\t\t\t\t\t\n";
        cout << "\n\t\t\tWelcome to Online Courier Service\n\n";
    }

    string getUsername() const
    {
        return username;
    }
};

class Recipient
{
public:
    string recipientname;

    string raddress;

    string phonenum;

    int productweight;


    void setRecipientInfo()
    {
        cout << "Enter recipient name: ";

        getline(cin, recipientname);

        cout << "Enter recipient address: ";

        getline(cin, raddress);

        cout << "Enter recipient phone number: ";

        getline(cin, phonenum);

        cout << "Enter product weight: ";

        cin >> productweight;

        cin.ignore();
    }

    void print()
    {
        cout << "Recipient information:\n";
    }
};

class logininterface
{
public:
    friend ostream &operator<<(ostream &cout, logininterface &obj)
    {
        cout << "\t\t1 : log in\n";
        cout << "\t\t2 : create new account\n";
        return cout;
    }
};

class displayMenu
{ public:
    friend ostream & operator<<(ostream &cout,displayMenu &ob){
    cout << "\nSelect an option:\n";
    cout << "1. Send product\n";
    cout << "2. Update account details\n";
    cout << "3. Delivery history\n";
    cout << "4. View profile\n";
    cout << "5. Logout\n";
    return cout;
    }
};

void sendProduct(User &u)
{
    int deliveryOption;
    cout << "Select the type of delivery:\n";
    cout << "1. Standard Delivery\n";
    cout << "2. Express Delivery\n";
    cout << "3. Same-day Delivery\n";
    cout << "Enter your choice: ";
    cin >> deliveryOption;
    cin.ignore();

    Recipient recipient;
    recipient.setRecipientInfo();


    cout << "THANK YOU for your order.Soon it will be shifted " << recipient.recipientname << "...\n";


    string deliveryTime;

    switch (deliveryOption)
    {
    case 1:
        {
            float cost = recipient.productweight * 20;
            cout << "Please pay cost: " << cost << " TK" << endl;
            deliveryTime = "Within 3-5 business days";
            break;
        }
    case 2:
        {
            float cost = recipient.productweight * 30;
            cout << "Please pay cost: " << cost << " TK" << endl;
            deliveryTime = "Within 1-2 business days";
            break;
        }
    case 3:
        {
            float cost = recipient.productweight * 40;
            cout << "Please pay cost: " << cost << " TK" << endl;
            deliveryTime = "Same day delivery";
            break;
        }
    default:
        deliveryTime = "Unknown";
        break;
    }

    // Display order summary
    cout << "Order Summary:\n";
    cout << "Recipient Name: " << recipient.recipientname << endl;
    cout << "Recipient Address: " << recipient.raddress << endl;
    cout << "Recipient Phone Number: " << recipient.phonenum << endl;
    cout << "Product Weight: " << recipient.productweight << " kg" << endl;
    cout << "Delivery Time: " << deliveryTime << endl;

    // Save delivery history to a file
    ofstream file(u.getUsername() + "deliveryhistory.txt", ios::app);
    if (file.is_open())
    {
        file << "Order Summary:\n";
        file << "Recipient Name: " << recipient.recipientname << endl;
        file << "Recipient Address: " << recipient.raddress << endl;
        file << "Recipient Phone Number: " << recipient.phonenum << endl;
        file << "Product Weight: " << recipient.productweight << " kg" << endl;
        file << "Delivery Time: " << deliveryTime << endl;
        file << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open history file.\n";
    }
}

int main()
{
    User u;
    logininterface obj;
    u.print();

    cout << obj;

    int option;
    cout << "Enter your choice: ";
    cin >> option;
    cin.ignore();

    switch (option)
    {
    case 1:
        // Log in
        {
            string username, password;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);

            ifstream file(username + ".txt");
            if (file.is_open())
            {
                string storedUsername, storedPassword;
                getline(file, storedUsername);
                getline(file, storedPassword);

                if (storedUsername == username && storedPassword == password)
                {
                    cout << "Login successful.\n";
                    u.username = storedUsername;
                    displayMenu a;
                    cout<<a;

                    int menuOption;
                    cout << "Enter your choice: ";
                    cin >> menuOption;
                    cin.ignore();

                    while (menuOption != 5)
                    {
                        switch (menuOption)
                        {
                        case 1:
                            sendProduct(u);
                            break;
                        case 2:
                            u.setUserInfo();
                            u.saveDetails();
                            break;
                        case 3:
                        {
                            // Delivery history
                            ifstream file(u.getUsername() + "deliveryhistory.txt");
                            if (file.is_open())
                            {
                                string line;
                                while (getline(file, line))
                                {
                                    cout << line << endl;
                                }
                                file.close();
                            }
                            else
                            {
                                cout << "No delivery history found.\n";
                            }
                            break;
                        }
                        case 4:
                            u.readDetails();
                            break;
                        default:
                            cout << "Invalid option.\n";
                            break;
                        }

                        displayMenu();
                        cout << "Enter your choice: ";
                        cin >> menuOption;
                        cin.ignore();
                    }
                }
                else
                {
                    cout << "Invalid username or password.\n";
                }

                file.close();
            }
            else
            {
                cout << "Account does not exist.\n";
            }

            break;
        }
    case 2:
        // Create new account
        u.setUserInfo();
        u.saveDetails();
        cout << "Account created successfully.\n";
        main();
        break;
    default:
        cout << "Invalid option.\n";
        break;
    }

    return 0;
}


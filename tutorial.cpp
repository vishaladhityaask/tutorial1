//1
#include <iostream>

class Vehicle {
public:
    int speed;
    float fuelLevel;
    Vehicle(int spd, float fuel) : speed(spd), fuelLevel(fuel) {}
    void displayStatus() {
        std::cout << "Speed: " << speed << " km/h, Fuel Level: " << fuelLevel << " liters\n";
    }
};

int main() {
    Vehicle car(50, 10.5);
    int Vehicle::*ptrSpeed = &Vehicle::speed;
    void (Vehicle::*ptrDisplayStatus)() = &Vehicle::displayStatus;
    car.*ptrSpeed = 80;
    (car.*ptrDisplayStatus)();

    return 0;
}


//2
#include <iostream>
#include <string>
class Student {
public:
    std::string name;  
    Student(std::string studentName, int studentId) : name(studentName), id(studentId) {}

    int getId() const {
        return id;
    }

private:
    int id;  
};

int main() {
    Student student1("Alice", 12345);
    student1.name = "Bob";
    std::cout << "Student Name: " << student1.name << std::endl;
    std::cout << "Student ID: " << student1.getId() << std::endl;

    return 0;
}


//3
#include <iostream>
#include <string>

class BankAccount {
private:
    int accountNumber;
    double balance;
    std::string accountHolderName;

public:
    // Constructor
    BankAccount(int accNum, double initialBalance, std::string holderName) 
        : accountNumber(accNum), balance(initialBalance), accountHolderName(holderName) {}

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful! New balance: $" << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful! New balance: $" << balance << "\n";
        } else {
            std::cout << "Insufficient funds or invalid amount!\n";
        }
    }

    void displayBalance() const {
        std::cout << "Current balance: $" << balance << "\n";
    }
};

int main() {
    int accNum;
    double initialBalance;
    std::string holderName;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cin.ignore();  // Clear input buffer
    std::cout << "Enter Account Holder Name: ";
    std::getline(std::cin, holderName);
    std::cout << "Enter Initial Balance: ";
    std::cin >> initialBalance;

    BankAccount myAccount(accNum, initialBalance, holderName);

    int choice;
    double amount;
    do {
        std::cout << "\n*** Banking System Menu ***\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                myAccount.displayBalance();
                break;
            case 4:
                std::cout << "Exiting the banking system. Have a great day!\n";
                break;
            default:
                std::cout << "Invalid choice! Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}


//4
#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

    // Constructor
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i), available(true) {}

    // Display book details
    void displayBook() const {
        std::cout << "Title: " << title << ", Author: " << author 
                  << ", ISBN: " << isbn 
                  << ", Status: " << (available ? "Available" : "Borrowed") << "\n";
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    // Add a new book to the library
    void addBook(const Book& book) {
        books.push_back(book);
        std::cout << "Book added successfully!\n";
    }

    // Search for a book by title
    void searchBookByTitle(const std::string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.title == title) {
                book.displayBook();
                found = true;
            }
        }
        if (!found) {
            std::cout << "Book with title \"" << title << "\" not found.\n";
        }
    }

    // Borrow a book by ISBN
    void borrowBook(const std::string& isbn) {
        for (auto& book : books) {
            if (book.isbn == isbn) {
                if (book.available) {
                    book.available = false;
                    std::cout << "You have successfully borrowed \"" << book.title << "\".\n";
                } else {
                    std::cout << "Sorry, \"" << book.title << "\" is already borrowed.\n";
                }
                return;
            }
        }
        std::cout << "Book with ISBN " << isbn << " not found.\n";
    }

    // Return a book by ISBN
    void returnBook(const std::string& isbn) {
        for (auto& book : books) {
            if (book.isbn == isbn) {
                if (!book.available) {
                    book.available = true;
                    std::cout << "You have successfully returned \"" << book.title << "\".\n";
                } else {
                    std::cout << "\"" << book.title << "\" was not borrowed.\n";
                }
                return;
            }
        }
        std::cout << "Book with ISBN " << isbn << " not found.\n";
    }

   



































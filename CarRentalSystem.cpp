#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// -------------------- Car Class --------------------
class Car {
private:
    int carID;
    string brand;
    string model;
    double pricePerDay;
    bool available;

public:
    Car(int id, string b, string m, double price, bool avail = true)
        : carID(id), brand(b), model(m), pricePerDay(price), available(avail) {}

    void displayCar() const {
        cout << left << setw(10) << carID
             << setw(15) << brand
             << setw(15) << model
             << setw(10) << pricePerDay
             << (available ? "Available" : "Rented") << endl;
    }

    int getCarID() const { return carID; }
    double getPricePerDay() const { return pricePerDay; }
    bool isAvailable() const { return available; }

    void rentCar() { available = false; }
    void returnCar() { available = true; }
};

// -------------------- Customer Class --------------------
class Customer {
private:
    int customerID;
    string name;

public:
    Customer(int id, string n) : customerID(id), name(n) {}

    int getCustomerID() const { return customerID; }
    string getName() const { return name; }
};

// -------------------- Rental Class --------------------
class Rental {
private:
    Customer customer;
    Car* car;
    int days;
    double totalCost;

public:
    Rental(Customer c, Car* ca, int d)
        : customer(c), car(ca), days(d), totalCost(ca->getPricePerDay() * d) {
        car->rentCar();
    }

    void displayRental() const {
        cout << "\n--- Rental Receipt ---\n";
        cout << "Customer Name: " << customer.getName() << endl;
        cout << "Car ID: " << car->getCarID() << endl;
        cout << "Days Rented: " << days << endl;
        cout << "Total Cost: " << totalCost << " BDT" << endl;
        cout << "----------------------\n";
    }

    string getCustomerName() const { return customer.getName(); }
    int getCarID() const { return car->getCarID(); }
    int getDays() const { return days; }
    double getTotalCost() const { return totalCost; }
};

// -------------------- Main System --------------------
class CarRentalSystem {
private:
    vector<Car> cars;
    vector<Rental> rentals;
    int customerCount = 0;

public:
    CarRentalSystem() {
        // Default Cars
        cars.push_back(Car(1, "Toyota", "Corolla", 3500));
        cars.push_back(Car(2, "Honda", "Civic", 4000));
        cars.push_back(Car(3, "BMW", "X5", 8500));
        cars.push_back(Car(4, "Tesla", "Model 3", 9500));
    }

    void displayCars() {
        cout << "\n--- Available Cars ---\n";
        cout << left << setw(10) << "Car ID"
             << setw(15) << "Brand"
             << setw(15) << "Model"
             << setw(10) << "Price/Day"
             << "Status" << endl;
        cout << "----------------------------------------------------\n";
        for (auto &car : cars) {
            car.displayCar();
        }
    }

    void rentCar() {
        string name;
        int carID, days;
        cout << "\nEnter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Car ID to rent: ";
        cin >> carID;
        cout << "Enter number of days: ";
        cin >> days;

        for (auto &car : cars) {
            if (car.getCarID() == carID && car.isAvailable()) {
                Customer c(++customerCount, name);
                Rental r(c, &car, days);
                rentals.push_back(r);
                r.displayRental();
                saveRentalToFile(r);
                return;
            }
        }
        cout << "Sorry, car not available or invalid ID.\n";
    }

    void returnCar() {
        int carID;
        cout << "\nEnter Car ID to return: ";
        cin >> carID;

        for (auto &car : cars) {
            if (car.getCarID() == carID && !car.isAvailable()) {
                car.returnCar();
                cout << "✅ Car successfully returned!\n";
                return;
            }
        }
        cout << "Invalid Car ID or Car is not rented.\n";
    }

    void saveRentalToFile(const Rental &r) {
        ofstream file;
        file.open("rental_records.txt", ios::app);

        if (!file) {
            cout << "\n[Error] Could not open file for writing!\n";
            return;
        }

        file << "==============================\n";
        file << "Customer Name: " << r.getCustomerName() << endl;
        file << "Car ID: " << r.getCarID() << endl;
        file << "Days Rented: " << r.getDays() << endl;
        file << "Total Cost: " << r.getTotalCost() << " BDT\n";
        file << "==============================\n\n";

        file.close();
        cout << "\n✅ Rental details saved to rental_records.txt\n";
    }

    void viewRentalRecords() {
        ifstream file("rental_records.txt");
        if (!file) {
            cout << "\n[Error] No records found yet.\n";
            return;
        }

        cout << "\n--- Rental Records ---\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void showMenu() {
        int choice;
        do {
            cout << "\n========= Car Rental System =========\n";
            cout << "1. Show Available Cars\n";
            cout << "2. Rent a Car\n";
            cout << "3. Return a Car\n";
            cout << "4. View Rental Records\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: displayCars(); break;
                case 2: rentCar(); break;
                case 3: returnCar(); break;
                case 4: viewRentalRecords(); break;
                case 5: cout << "Thank you for using our system!\n"; break;
                default: cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 5);
    }
};

// -------------------- Main Function --------------------
int main() {
    CarRentalSystem system;
    system.showMenu();
    return 0;
}

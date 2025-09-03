#include <iostream>
#include <cctype>
using namespace std;

class Person {
protected:
    int id;
    string password, name;

public:
    void setName(string n) {
        if (n.size() >= 3 && n.size() <= 20) {
            bool valid = true;
            for (char c : n) {
                if (!isalpha(c) && c != ' ') {
                    valid = false;
                    break;
                }
            }
            if (valid) name = n;
        }
    }
    string getName() { return name; }

    void setId(int i) { id = i; }
    int getId() { return id; }

    bool isValidPassword(string pass) {
        if (pass.size() < 8 || pass.size() > 20) return false;
        for (char c : pass) if (c == ' ') return false;
        return true;
    }

    void setPassword(string p) {
        if (isValidPassword(p)) password = p;
    }
    string getPassword() { return password; }
};

class Client : public Person {
private:
    double balance;

public:

    void setBalance(double b) {
        if (b >= 1500) balance = b;
    }
    double getBalance() { return balance; }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1500) balance -= amount;
    }

    void transfer(Client &recipient, double amount) {
        if (amount > 0 && balance - amount >= 1500) {
            balance -= amount;
            recipient.deposit(amount);
        }
    }
    void display() {
        cout << "Client Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Balance: " << balance << "\n";
        cout<<"--------------------------\n";
    }
};

class Employee : public Person {
private:
    double salary;

public:
    void setSalary(double s) { salary = s; }
    double getSalary() { return salary; }

    void display() {
        cout << "Employee Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Salary: " << salary << "\n";
        cout<<"--------------------------\n";
    }
};
class Admin : public Person {
    private:
    double salary;
    public:
    void setSalary(double s) { salary = s; }
    double getSalary() { return salary; }
    void minsalary(double s) { 
        if(s>=5000){ 
        salary=s; 
        }   
    }
    void display() {
        cout << "Admin Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Salary: " << salary << "\n";
        cout<<"--------------------------\n";
    }
};
int main() {
    Client c1;
    c1.setName("Alice Smith");
    c1.setId(101);
    c1.setPassword("securePass123");
    c1.setBalance(2000);
    c1.deposit(500);
    c1.withdraw(300);
    c1.display();

    Client c2;
    c2.setName("Bob Johnson");
    c2.setId(102);
    c2.setPassword("anotherPass456");
    c2.setBalance(2500);
    c1.transfer(c2, 400);
    c2.display();

    Employee e1;
    e1.setName("Charlie Brown");
    e1.setId(201);
    e1.setPassword("empPass789");
    e1.setSalary(4000);
    e1.display();

    Admin a1;
    a1.setName("Diana Prince");
    a1.setId(301);
    a1.setPassword("adminPass321");
    a1.minsalary(6000);
    a1.display();

    return 0;
}
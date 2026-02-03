#include <iostream>
using namespace std;
const int MAX = 100;
void ShowMenu();
void CreateAccount(int& count, int accNo[], int pin[], double balance[]);
int Login(int count, int accNo[], int pin[]);
void CheckBalance(int index, double balance[]);
void Deposit(int index, double balance[]);
void Withdraw(int index, double balance[]);
void ExitATM(bool& running);

int main() {
    int accNo[MAX];
    int pin[MAX];
    double balance[MAX];

    int count = 0, choice;
    bool running = true;

    cout << "-------------------------------------"<<endl;
    cout << "        WELCOME TO ATM MACHINE        "<<endl;
    cout << "-------------------------------------"<<endl;

    while (running) {
        ShowMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                CreateAccount(count, accNo, pin, balance);
                break;

            case 2: {
                int index = Login(count, accNo, pin);
                if (index != -1)
                    CheckBalance(index, balance);
                break;
            }

            case 3: {
                int index = Login(count, accNo, pin);
                if (index != -1)
                    Deposit(index, balance);
                break;
            }

            case 4: {
                int index = Login(count, accNo, pin);
                if (index != -1)
                    Withdraw(index, balance);
                break;
            }

            case 5:
                ExitATM(running);
                break;

            default:
                cout << " Invalid choice! "<<endl;
        }
    }
    return 0;
}
void ShowMenu() {
    cout << " ATM MENU "<<endl;
    cout << "1. Create Account"<<endl;
    cout << "2. Check Balance"<<endl;
    cout << "3. Deposit Money"<<endl;
    cout << "4. Withdraw Money"<<endl;
    cout << "5. Exit"<<endl;
    cout << "Enter your choice: "<<endl;
}

void CreateAccount(int& count, int accNo[], int pin[], double balance[]) {
    cout << "Enter Account Number: "<<endl;
    cin >> accNo[count];

    cout << "Set 4-digit PIN: "<<endl;
    cin >> pin[count];

    balance[count] = 0.0;
    count++;

    cout << "Account created successfully! "<<endl;
}

int Login(int count, int accNo[], int pin[]) {
    int a, p;
    cout << "Enter Account Number: "<<endl;
    cin >> a;
    cout << "Enter PIN: "<<endl;
    cin >> p;

    for (int i = 0; i < count; i++) {
        if (accNo[i] == a && pin[i] == p) {
            cout << "Login successful! "<<endl;
            return i;
        }
    }
    cout << "Wrong Account Number or PIN! "<<endl;
    return -1;
}

void CheckBalance(int index, double balance[]) {
    cout << "Your Balance: $" << balance[index]<<endl;
}

void Deposit(int index, double balance[]) {
    double amount;
    cout << "Enter deposit amount: "<<endl;
    cin >> amount;

    if (amount > 0) {
        balance[index] =balance[index] + amount;
        cout << "Deposit successful! "<<endl;
    } else {
        cout << "Invalid amount! "<<endl;
    }
}

void Withdraw(int index, double balance[]) {
    double amount;
    cout << "Enter withdrawal amount: "<<endl;
    cin >> amount;

    if (amount > 0 && amount <= balance[index]) {
        balance[index] =balance[index] - amount;
        cout << "Please collect your cash. "<<endl;
    } else {
        cout << "Insufficient balance! "<<endl;
    }
}

void ExitATM(bool& running) {
    running = false;
    cout << "Thank you for using ATM Machine! "<<endl;
}

#include <iostream>

//Show balance
void showBalance(double balance);

//Deposit Money
double depositAmount();

//Withdraw Money
double withdrawAmount(double balance);


int main() {

    double balance = 0;
    int choice;

    std::cout << "********** Welcome To Pietas Banking ***************" << std::endl;
    do {
    std::cout << "Enter your choice:" << std::endl;
    std::cout << "##################################################" << std::endl;
    std::cout << "1. Show Balance" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "##################################################" << std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += depositAmount();
            showBalance(balance);
            break;
        case 3:
            balance -= withdrawAmount(balance);
            showBalance(balance);
            break;
        case 4: 
            std::cout << "Thank you for banking with us. Have a good day!" << std::endl;
            break;
    }

    } while (choice != 4);

    return 0;
}

void showBalance(double balance) {
    std::cout << "Your balance is >> $" << balance << std::endl;
};

double depositAmount(){
    std::cout << "Enter amount to deposit >> $";
    double deposit = 0;
    std::cin >> deposit;
    
    if(deposit > 0) {
        std::cout << "Your deposit of $" << deposit << " was successful!" << std::endl;
        return deposit;
    } else {
        std::cout << "You entered an invalid amount!" << std::endl;
        return 0;
    }
};

double withdrawAmount(double balance) {
    std::cout << "Enter amount to withdraw >> $";
    double amount;
    std::cin >> amount;

    if (amount <= balance) {
        return amount;
    } else if (amount > balance) {
        std::cout << "You have insufficient funds, cannot withdraw $" << amount << " as it is greater than current balance of $" << balance << std::endl;
        return 0; 
    } else {
        std::cout << "You entered an invalid amount!" << std::endl;
        return 0;
    }
};
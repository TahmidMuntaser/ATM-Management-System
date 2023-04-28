/*

Author: Tahmid Muntaser......

ATM Management System 1.0

*/

#include <bits/stdc++.h>

using namespace std;

class Screen
{

public:

    void displayMessage(string message){
        cout<<message;
    }

    void displayMessageLine(string message){
        cout << message << endl;
    }

    void displayMoneyAmount(double amount){
        cout<<amount<<" tk ";
    }


};

class Keypad
{
public:
    int getInput(){
        int input;
        cin>>input;

        return input;
    }

    double getAmountInput(){
        double input;
        cin>>input;

        return input;
    }

};

class CashDispenser
{
public:
    void dispenseCash(double amount){
        cout<<"Dispensing cash "<<amount<<" tk...."<<endl;
    }

};

class DepositSlot
{
public:

    void accenptEnvelope(){
        cout<<"Please insert your envelope..."<<endl;
    }

};

class BankDatabase
{
    private:
    struct Account{

        int accountNumber;
        int pin;
        double balance;

    };

    vector<Account> accounts;

    public:

    BankDatabase(){
        accounts.push_back({1234,5678, 1000.00});
         accounts.push_back({5678,1234, 2000.00});
          accounts.push_back({1357,2468, 3424.00});
            accounts.push_back({9999, 1111, 321.34});
              accounts.push_back({1290, 9876, 1290.00});
               accounts.push_back({3456, 1290, 4278.00});
    }

    bool authenticateUser(int accountNumber, int pin){
        for(auto& account : accounts){
            if(account.accountNumber == accountNumber && account.pin == pin){
                return true;
            }
        }
        return false;
    }

    double getAvailableBalance(int accountNumber){

        for(auto& account : accounts){
            if(account.accountNumber == accountNumber){
                return account.balance;
            }
        }
        return 0.0;
    }

    void credit(int accountNumber, double amount){
        for(auto account : accounts){
            if(account.accountNumber == accountNumber){
                account.balance += amount;
                break;
            }
    }
    }

    void debit(int accountNumber, double amount){
        for(auto account : accounts){
                    if(account.accountNumber == accountNumber){
                        account.balance -= amount;
                        break;
                    }

    }
    }


};

class Deposit
{
    private:

        double amount;

    public:
        Deposit(double amount): amount(amount){

        }

        double getAmount() const{
            return amount;
        }
};

class ATMController
{
    private:
        Screen screen;
        Keypad keypad;
        CashDispenser cashDispenser;
        DepositSlot depositSlot;
        BankDatabase bankDatabase;

        int accountNumber;
        bool userAuthenticated;


    public:


    void performBalanceInquiry(){

    }

    void performWithdrawal(){

    }

    void performDeposit(){

    }

    void authenticateUser(){

    }

    public:
        void run(){
            
        }

};

int main(int argc, char const *argv[])
{
    ATMController atm;
    atm.run();

    return 0;
}

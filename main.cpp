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


public:

    BankDatabase(){

    }

    bool authenticateUser(int accountNumber, int pin){

    }

    double getAvailableBalance(int accountNumber){

    }

    void credit(int accountNumber, double amount){

    }

    void debit(int accountNumber, double amount){


    }


};

class Deposit
{
    private:


    public:
        Deposit(double amount){

        }

        double getAmount() const{

        }
};

class ATMController
{
    private:

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

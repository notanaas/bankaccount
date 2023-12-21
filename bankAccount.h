//Bank account class with 4 functions
//Anas Alsayed 202020067 JAN11
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include<iostream>
#include<string>
using namespace std;
class BankAccount{
	private: 
		string name;
		int accountNumber;
		double balance;
	public:
		BankAccount(string, int , double );
		string getName();
		int getAccountNumber();
		double getBalance();
		double setBalance(double);
		void Deposit() ;
		void WithDraw();
		
		virtual void printStatement() = 0;	
		
		
};
#endif

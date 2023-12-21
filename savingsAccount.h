#include<iostream>
#include<string>
#include"bankAccount.h"
using namespace std;
class SavingsAccount: public BankAccount{
	public:
		SavingsAccount(string, double , int );
		void printStatement();
		void Deposit();
		void WithDraw();
		double getIR();
		int getMB();
	private:
		double IntRate ;
		int MinBalance ; 


};

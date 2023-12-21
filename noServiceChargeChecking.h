#include <iostream>
#include<string>
#include"checkingAccount.h"
using namespace std;

class NoServiceChargeChecking : public CheckingAccount {
	public:
		NoServiceChargeChecking(string , double , int );
		void writeCheck();
		void printStatement();
		void WithDraw(double am);		      
         	int checksWritten;
		int getMB();
		double getIR();
	private:
		int MinBalance;
		double IntRate;
		
};

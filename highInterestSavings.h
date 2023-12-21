#include<iostream>
#include<string>
#include"savingsAccount.h"
using namespace std;
class HighInterestSavings: public SavingsAccount{
	public:
		HighInterestSavings(string , double , int AccNo);
		int getMinimumBalance();
		void printStatement();
		void WithDraw();
		int minimumBalance;
};

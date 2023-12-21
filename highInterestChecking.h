#include <iostream>
#include"noServiceChargeChecking.h"
using namespace std;

class HighInterestChecking : public NoServiceChargeChecking {
	public:
		HighInterestChecking(string, double , int );
		void printStatement();
		int getMB();
                double getIR();
        private:
                int MinBalance;
                double IntRate;

};

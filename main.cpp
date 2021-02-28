/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*/


#ifndef FUNCTION_H
#define FUNCTION_H

class Function {
    public:
        void With(double t_investmentAmount, double t_monthlyDeposit, double t_annualAmount, int t_numYears);
        void Without(double t_investmentAmount, double t_annualAmount, int t_numYears);
    private:
        double endOfYearAmount;
        double withInterest;
        double justInterest;
        double withMonthlyInterest;
        double monthlyTotal;
        double addingMonthlyInterest;
        double totalInterest;
        int numMonths;
        double initial;
        double interest;
        double lastYearInterest;
        int year;
        int i;
};

#endif

#include <iostream>
using namespace std;


void Function :: Without(double t_investmentAmount, double t_annualAmount, int t_numYears){
    endOfYearAmount = t_investmentAmount;
    year = 0;
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    cout << "Year     Year End Balance       Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    
    for (i = 0; i < t_numYears; ++i){
        withInterest = endOfYearAmount + (endOfYearAmount * (t_annualAmount / 100));
        justInterest = endOfYearAmount * (t_annualAmount / 100);
        year = year + 1;
        cout << year << "        ";
        printf("%.2f", withInterest);
        cout << "                   ";
        printf("%.2f", justInterest);
        cout << endl;
        endOfYearAmount = withInterest;
    }
    cout << endl << endl;
}
void Function :: With(double t_investmentAmount, double t_monthlyDeposit, double t_annualAmount, int t_numYears){
    year = 0;
    initial = t_investmentAmount;
    monthlyTotal = t_monthlyDeposit + t_investmentAmount;
    numMonths = t_numYears * 12;
    totalInterest = 0;
    addingMonthlyInterest = 0;
    interest = 0;
    lastYearInterest = 0;

    
    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    cout << "Year     Year End Balance       Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for (i = 1; i <= numMonths; ++i){
        interest = (monthlyTotal * (t_annualAmount / 100/12));
        withMonthlyInterest =  monthlyTotal + interest;
        addingMonthlyInterest = addingMonthlyInterest + interest;
        if (i % 12 == 0){
            year = year + 1;
            cout << year << "         ";
            printf("%.2f", withMonthlyInterest);
            cout << "                ";
            printf("%.2f", addingMonthlyInterest - lastYearInterest);
            cout << endl;
            lastYearInterest = addingMonthlyInterest;
        }
        
        monthlyTotal = withMonthlyInterest + 50;
        
    }
    cout << endl << endl; 
    
    
}

int main()
{
    double investmentAmount;
    double monthlyDeposit;
    double annualAmount;
    int numYears;
    char randomKey;
    char restart = 'c';

        Function customer;
            
        cout << "*******************Welcome**********************" << endl;
        cout << "************************************************" << endl;
        cout << "   Enter initial investment amount: ";
        cin >> investmentAmount;
        while (investmentAmount < 0){
            cout << "   Invalid amount. Enter a number equal to or over 0. ";
            cin >> investmentAmount;
        }
        cout << endl << "   Enter monthly deposit: ";
        cin >> monthlyDeposit;
        while (monthlyDeposit < 0){
            cout << "   Invalid amount. Enter a number equal to or over 0. ";
            cin >> monthlyDeposit;
        }
        cout << endl << "   Enter annual amount of interest (exclude '%'): ";
        cin >> annualAmount;
        while (annualAmount < 0){
            cout << "   Invalid amount. Enter a number equal to or over 0. ";
            cin >> annualAmount;
        }
        cout << endl << "   Enter number of years: ";
        cin >> numYears;
        while (numYears <= 0){
            cout << "    Invalid amount. Enter a number over 0. ";
            cin >> numYears;
        }
        cout << endl << "   Enter any character to continue...";
        cin >> randomKey;
        cout << endl << endl;
            
        customer.Without(investmentAmount, annualAmount, numYears);
        customer.With(investmentAmount, monthlyDeposit, annualAmount, numYears);
            

        cout << endl;
        

    return 0;
}

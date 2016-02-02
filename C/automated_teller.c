/*
	A console-based Automated Teller Machine.
	~Michael Rutherford
	[08/02/2014]
*/
//import standard input/output library
#include <stdio.h>
//import string handling library
#include <string.h>
	//deposit_acctotal function prototype
	float deposit_acctotal(float, float);	
	//deposit_money function prototype	
	float deposit_money(float, float);
	//withdraw_acctotal function prototype
	float withdraw_acctotal(float, float);
	//withdraw_money function prototype
	float withdraw_money(float, float);
	//declare acctotal to represent the account balance
	float acctotal = 1000;
	//declare money to represent the amount of money the user has
	float money = 100;
	//declare amount to hold user input
	float amount = 0;
//main function
int main() {
	//create new file for printing the receipt
	FILE *automatedteller;
	//initialize automatedteller and set it's name and file state
	automatedteller = fopen("Receipt.txt", "w");
	//if statement returns an error to the compiler if file creation does not execute properly
	if (!automatedteller) {
		//returns 1 to tell the compiler that an error occurred 
		return 1;
	}
	//declare input to hold user input for commands
	char input[10];
	//declare deposit to compare to the user input 
	const char deposit[10] = "deposit";
	//declare withdraw to compare to the user input 
	const char withdraw[10] = "withdraw";
	//print statement shows the current amount of money the user has
	printf("Your money: $%.2f\n", money);
	//print statement shows the current account balance
	printf("Account total: $%.2f\n", acctotal);
	//print statement prompts user
	printf("What would you like to do today?\n");
	//read user input and assign value to input string
	scanf("%s", &input);
	//compare input string to deposit string
	if (strcmp (input, deposit) == 0 ) {
		//print statement prompts user
		printf("How much would you like to deposit?\n");
		//read user input and assign value to amount
		scanf("%f", &amount);
		//evaluate and check that amount is less than or equal to money
		if (amount <= money) {
			//calls deposit_acctotal function and assigns acctotal to the return value
			acctotal = deposit_acctotal(amount, acctotal);
			//calls deposit_money function and assigns money to the return value
			money = deposit_money(amount, money);
			//print statement shows the current amount of money the user has
			printf("Your money: $%.2f\n", money);
			//print statement prints the current amount of money that the person has to the receipt file
			fprintf(automatedteller, "Your money: $%.2f\n", money);
			//print statement shows the current account balance
			printf("Account total: $%.2f\n", acctotal);
			//print statement prints the current account balance to the receipt file
			fprintf(automatedteller, "Account total: $%.2f\n", acctotal);
			//fclose closes the .txt file
			fclose(automatedteller);
		} else {
			//if amount is greater than money, Error prints to the console
			printf("Error.\n");		
		}
	}
	//compare input string to withdraw string
	if (strcmp (input, withdraw) == 0 ) {
		//print statement prompts user
		printf("How much would you like to withdraw?\n");
		//read user input and assign value to amount
		scanf("%f", &amount);
		//evaluate and check that acctotal is greater than or equal to amount
		if (amount <= acctotal) {
			//calls withdraw_acctotal function and assigns acctotal to the return value
			acctotal = withdraw_acctotal(amount, acctotal);
			//calls withdraw_money function and assigns money to the return value
			money = withdraw_money(amount, money);
			//print statement shows the current amount of money the user has
			printf("Your money: $%.2f\n", money);
			//print statement prints the current amount of money that the person has to the receipt file
			fprintf(automatedteller, "Your money: $%.2f\n", money);
			//print statement shows the current account balance
			printf("Account total: $%.2f\n", acctotal);
			//print statement prints the current account balance to the receipt file
			fprintf(automatedteller, "Account total: $%.2f\n", acctotal);
			//fclose closes the .txt file
			fclose(automatedteller);
		} else {
			//if amount is greater than acctotal, Error prints to the console
			printf("Error.\n");		
		}
	}
	//print statement prompts user
	printf("Your receipt has printed to the folder containing this program. \n");
	//print statement prompts user
	printf("Press [Enter] to continue.\n");
	//getch() prevents the program from ending prematurely
	getch();
	//returns 0 to the compiler
	return 0;
}
//function to add amount to acctotal
float deposit_acctotal(float fncAmount, float fncTotal) {
	//fncAmount is added to fncTotal
	fncTotal = fncTotal + fncAmount;
	//returns fncTotal back to where the function was called
	return (fncTotal);
}
//function to subtract amount from money
float deposit_money(float fncAmount, float fncMoney) {
	//fncAmount is subtracted from fncMoney	
	fncMoney = fncMoney - fncAmount;
	//returns fncMoney back to where the function was called
	return (fncMoney);
}
//function to subtract amount from acctotal
float withdraw_acctotal(float fncAmount, float fncTotal) {		
	//fncAmount is subtracted from fncTotal	
	fncTotal = fncTotal - fncAmount;
	//returns fncTotal back to where the function was called
	return (fncTotal);
}
//function to add amount to money
float withdraw_money(float fncAmount, float fncMoney) {
	//fncAmount is added to fncMoney	
	fncMoney = fncMoney + fncAmount;
	//returns fncMoney back to where the function was called
	return (fncMoney);
}

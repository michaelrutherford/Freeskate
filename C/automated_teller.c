#include <stdio.h>
#include <string.h>
float deposit_acctotal(float, float);	
float deposit_money(float, float);
float withdraw_acctotal(float, float);
float withdraw_money(float, float);
float acctotal = 1000;
float money = 100;
float amount = 0;
int main() {
	FILE *automatedteller;
	automatedteller = fopen("Receipt.txt", "w");
	if (!automatedteller) {
		return 1;
	}
	char input[10];
	const char deposit[10] = "deposit";
	const char withdraw[10] = "withdraw";
	printf("Your money: $%.2f\n", money);
	printf("Account total: $%.2f\n", acctotal);
	printf("What would you like to do today?\n");
	scanf("%s", &input);
	if (strcmp (input, deposit) == 0 ) {
		printf("How much would you like to deposit?\n");
		scanf("%f", &amount);
		if (amount <= money) {
			acctotal = deposit_acctotal(amount, acctotal);
			money = deposit_money(amount, money);
			printf("Your money: $%.2f\n", money);
			fprintf(automatedteller, "Your money: $%.2f\n", money);
			printf("Account total: $%.2f\n", acctotal);
			fprintf(automatedteller, "Account total: $%.2f\n", acctotal);
			fclose(automatedteller);
		} else {
			printf("Error.\n");		
		}
	}
	if (strcmp (input, withdraw) == 0 ) {
		printf("How much would you like to withdraw?\n");
		scanf("%f", &amount);
		if (amount <= acctotal) {
			acctotal = withdraw_acctotal(amount, acctotal);
			money = withdraw_money(amount, money);
			printf("Your money: $%.2f\n", money);
			fprintf(automatedteller, "Your money: $%.2f\n", money);
			printf("Account total: $%.2f\n", acctotal);
			fprintf(automatedteller, "Account total: $%.2f\n", acctotal);
			fclose(automatedteller);
		} else {
			printf("Error.\n");		
		}
	}
	printf("Your receipt has printed to the folder containing this program.\n");
	return 0;
}
float deposit_acctotal(float fncAmount, float fncTotal) {
	fncTotal = fncTotal + fncAmount;
	return (fncTotal);
}
float deposit_money(float fncAmount, float fncMoney) {
	fncMoney = fncMoney - fncAmount;
	return (fncMoney);
}
float withdraw_acctotal(float fncAmount, float fncTotal) {		
	fncTotal = fncTotal - fncAmount;
	return (fncTotal);
}
float withdraw_money(float fncAmount, float fncMoney) {
	fncMoney = fncMoney + fncAmount;
	return (fncMoney);
}

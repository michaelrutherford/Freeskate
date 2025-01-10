#include <stdio.h>
#include <string.h>

char encrypt(char);

int main() 
{
	char i[7];
	char x;
	char e[7] = "Encrypt";
	char d[7] = "Decrypt";
    
	printf("Encrypt or Decrypt?\n");
	scanf("%s", &i);
    
	if (strcmp (i, e) == 0 ) {
		printf("Enter text:: \n");
		scanf("%s", &x);
		encrypt(x);
	} else if (strcmp (i, d) == 0 ) {
		printf("Enter text:: \n");
		scanf("%s", &x);
	} else {
		printf("Error.\n");
	}
        
	return 0;
}

char encrypt(char en) 
{
	en++;
	return (en);
}

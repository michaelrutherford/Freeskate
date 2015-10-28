#include<stdio.h>
#include<string.h>
int main(){
	char input[25]="";
	short location=0;
	int active=1;
	while(active==1){
		if(location==0){
			printf("type test then press [ENTER]\n");
			fgets(input,25,stdin);
			if(strncmp(input,"test",4)==0){
				printf("correct\n");
				location++;
			} 
			if(strncmp(input,"exit test",4)==0){
				printf("exiting test...\n");
				active=0;
			}
		if(location==1){
			printf("type test2 then press [ENTER]\n");
			fgets(input,25,stdin);
			if(strncmp(input,"test2",4)==0){
				printf("correct2\n");
				active=0;	
				}
			}		
		}
	}
	printf("test over");
	return 0;
}

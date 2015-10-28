#include <stdio.h>
#include <stdlib.h>
#define MAX 9999999
#define MIN -9999999
float add(float, float);
float sub(float, float);
float mlt(float, float);
float dvn(float, float);
float mod(float, float);
float abv(float);
float fct(float);
float sqt(float);
float cbt(float);
float fnum = 0;
float snum = 0;
float ans = 0;
float his[50];
short act;
short err;
short tst;
short hct;
short hcn = 0;
short mn;
char op;
int main()
{
	for(short i = 0; i <= 50; i++) {
		his[i] = 0;
	}
	hct = 0;
	err = 0;
	tst = 0;
	r:
	act = 0;
	while(act != 1) {
		ans = 0;
		fnum = 0;
		snum = 0;
		printf("+(ADD) -(SUB) *(MLT) /(DVN) A(ABV)");
		printf("!(FCT) R(SQT) C(CBT) %%(MOD) @(OPTIONS)");
		printf("\n");
		printf("ENTER AN OPERATION.");
		printf("\n");
		scanf("%c", &op);
		if(op != '+' 
		&& op != '-' 
		&& op != 'R'
		&& op != '/'
		&& op != '*' 
		&& op != '^'
		&& op != '!' 
		&& op != 'A' 
		&& op != 'C'
		&& op != '%' 
		&& op != '@') {
			if(tst == 1) {
				scanf("%c", &op);
				if(op != '+' 
				&& op != '-' 
				&& op != 'R'
				&& op != '/' 
				&& op != '*' 
				&& op != '^'
				&& op != '!' 
				&& op != 'A' 
				&& op != 'C'
				&& op != '%' 
				&& op != '@') {
					printf("ERROR 1");
					printf("\n");
					err = 1;
					act = 1;
					break;
					break;
					exit(0);
				}
			}
			else {
				printf("ERROR 1");
				printf("\n");
				err = 1;
				act = 1;
				break;
				break;
				exit(0);
			}
		}
		if(op == '@') {
			goto s;
		}
		printf("ENTER A VALUE.");
		printf("\n");
		scanf("%f", &fnum);
		if(fnum > MAX 
		|| fnum < MIN) {
			printf("ERROR 2");
			printf("\n");
			err = 1;
			act = 1;
			break;
			exit(0);
		}
		if(op == 'A'
		|| op == '!' 
		|| op == 'R'
		|| op == '@' 
		|| op == 'C') {
			goto s;
		}
		printf("ENTER ANOTHER VALUE.");
		printf("\n");
		scanf("%f", &snum);
		if(snum > MAX 
		|| snum < MIN) {
			printf("ERROR 3");
			printf("\n");
			err = 1;
			act = 1;
			break;
			exit(0);
		}
		s:
		switch(op) {
		case '+':
			ans = add(fnum, snum);
			printf("%.1f + %.1f = %.1f", fnum, snum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
			tst = 1;
			act = 1;
			break;
			break;
		case '-':
			ans = sub(fnum, snum);
			printf("%.1f - %.1f = %.1f", fnum, snum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
			tst = 1;
			act = 1;
			break;
			break;
		case '/':
			ans = dvn(fnum, snum);
			printf("%.1f / %.1f = %.1f", fnum, snum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			tst = 1;
			act = 1;
			break;
			break;
		case '*':
			ans = mlt(fnum, snum);
			printf("%.1f * %.1f = %.1f", fnum, snum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
			tst = 1;
			act = 1;
			break;
			break;
		case '%':
			ans = mod(fnum, snum);
			printf("%.1f %% %.1f = %.1f", fnum, snum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
			tst = 1;
			act = 1;
			break;
			break;
       		case 'A':
			ans = abv(fnum);
	      		printf("ABS(%.1f) = %.1f", fnum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
	      		tst = 1;
		 	act = 1;
			break;
			break;
	       	case 'R':
			ans = sqt(fnum);
		   	printf("SQRT(%.1f) = %.1f", fnum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
		   	tst = 1;
			act = 1;
			break;
			break;
	       	case 'C':
			ans = cbt(fnum);
		   	printf("CBRT(%.1f) = %.1f", fnum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
		   	tst = 1;
			act = 1;
			break;
			break;
		case '@':
			printf("1(ESC) 2(ABT) 3(HLP) 4(HIS)");
			printf("\n");
			scanf("%hd", &mn);
			switch(mn) {
			case 1:
				act = 1;
				exit(0);
				break;
			case 2:
				printf("WIP ~ RUTHERFORD");
				printf("\n");
				act = 1;
				break;
				break;
				goto r;
			case 3:
				printf("HELP PAGE");
				printf("\n");
				act = 1;
				break;
				break;
				goto r;
			case 4:
				printf("HISTORY PAGE");
				printf("\n");
				for(short x = 0; x <= hcn; x++) {
					printf("%.1f", his[x]);
					printf("\n");
				}
				act = 1;
				break;
				break;
				goto r;
			default:
				printf("ERROR 3.5");
				printf("\n");
				act = 1;
	  		       	break;
				break;
				exit(0);
			}
			his[hct] = ans;
			hct++;
	      		tst = 1;
		   	act = 1;
			break;
			break;
	       	case '!':
			ans = fct(fnum);
		  	printf("%.1f! = %.1f", fnum, ans);
			printf("\n");
			his[hct] = ans;
			hct++;
			hcn++;
		  	tst = 1;
		   	act = 1;
		   	break;
			break;
		default:
			printf("ERROR 4");
			printf("\n");
			err = 1;
			act = 1;
			break;
			break;
			exit(0);
  		}
	}
	if(err != 1 
	&& tst == 1) {
		goto r;
	}
	else {
		return 0;
	}
}
float add(float f, float s)
{
	float t;
	t = f + s;
	if(t > MAX 
	|| t < MIN) {
		printf("ERROR 5");
		printf("\n");
		exit(0);
	}
	else {
		return t;
	}
}
float sub(float f, float s)
{
	float t;
	t = f - s;
	if(t > MAX 
	|| t < MIN) {
		printf("ERROR 5");
		printf("\n");
		exit(0);
	}
	else {
		return t;
	}
}
float mlt(float f, float s)
{
	float t;
	t = f * s;
	if(t > MAX 
	|| t < MIN) {
		printf("ERROR 5");
		printf("\n");
		exit(0);
	}
	else {
		return t;
	}
}
float mod(float f, float s)
{
	float t;
	t = (int) f % (int) s;
	if(t > MAX 
	|| t < MIN) {
		printf("ERROR 5");
		printf("\n");
		exit(0);
	}
	else {
		return t;
	}
}
float dvn(float f, float s)
{
	float t;
	t = f / s;
	if(t > MAX 
	|| t < MIN) {
		printf("ERROR 5");
		printf("\n");
		exit(0);
	}
	else {
		return t;
	}
}
float fct(float f)
{
	float t = 1;
	float n = f;
	while(n != 1) {
		t = t * n;
		n--;
	}
	if(t > MAX 
	|| t < MIN) {
		printf("ERROR 5");
		printf("\n\n");
		exit(0);
	}
	else {
		return t;
	}
}
float sqt(float f)
{
	float t = 1;
	while((t * t) != f 
	&& t != f) {
		t++;
	}
	if(t > MAX 
	|| t < MIN 
	|| t == f) {
		printf("ERROR 5");
		printf("\n\n");
		exit(0);
	}
	else {
		return t;
	}
}
float cbt(float f)
{
	float t = 1;
	while((t * t * t) != f 
	&& t != f) {
		t++;
	}
	if(t > MAX 
	|| t < MIN 
	|| t == f) {
		printf("ERROR 5");
		printf("\n\n");
		exit(0);
	}
	else {
		return t;
	}
}
float abv(float f)
{
    	float t;
	if(f < 0) {
		t = (f * -1.0);
	}
	else {
		t = f;
	}
	if(t > MAX 
	|| t < MIN) {
		printf("ERROR 5");
		printf("\n\n");
		exit(0);
	}
	else {
		return t;
	}
}

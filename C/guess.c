#include <stdio.h>
#include <stdlib.h>
int main() {
	int rnd;
	int trk = 0;
	int uth = 0;
	int lth = 0;
	int hgh = 0;
	int ans = 0;
	int lct = 1;
	int act = 1;
	while (act != 0) {
		switch (lct) {
		case 1:
			printf("GUESS A VALUE BETWEEN 0 AND 255");
			int agn = 1;
			int gss = 0;
			trk = 0;
			uth = 0;
			lth = 0;
			ans = rand() % 256; 
			lct = 2;
			break;
		case 2:
			scanf("%d", &gss);
			if (gss == ans) {
				printf("CORRECT. IT TOOK YOU %d ATTEMPTS", trk);
				if (hgh == 0) {
					hgh = trk;
				} else if (hgh > trk) {
					printf("< < NEW HIGH SCORE > >");
					hgh = trk;
				}
				printf("HIGH SCORE :: %d", hgh);
				printf("PLAY AGAIN? (0 = N/1 = Y)");
				scanf("%d", &agn);
				if (agn == 1) {
					lct = 1;
					break;
				} else if (agn == 0) {
					act = 0;
					return 1;
				} else {
					printf("INVALID RESPONSE.");
					act = 0;
					return 1;
				}
			} else {
				if (gss > ans) {
					if ((gss - ans) >= uth) {
						if (uth != 0) {
							printf("ANSWER IS NOT HIGHER THAN %d", (ans + uth));
						} else {
							uth = (gss - ans);
						}
					} else {
						uth = (gss - ans);
					}
					printf("TOO HIGH. GUESS AGAIN.");
					trk++;
				} else if (gss < ans) {
					if ((ans - gss) >= lth) {
						if (lth != 0) {
							printf("ANSWER IS NOT LOWER THAN %d", (ans - lth));
						} else {
							lth = (ans - gss);
						}
					} else {
						lth = (ans - gss);
					}
					printf("TOO LOW. GUESS AGAIN.");
					trk++;
				}
			}
		default:
			break;
		}
	}
}

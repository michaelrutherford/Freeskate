#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int guess_count = 0, upper_threshold = 0, lower_threshold = 0, high_score = 0, answer = 0;
	int location = 1, active = 1;
	while (active != 0) {
		switch (location) {
		case 1:
			printf("GUESS A VALUE BETWEEN 0 AND 255\n");
			int play_again = 1;
			int guess = 0;
			guess_count = 0;
			upper_threshold = 0;
			lower_threshold = 0;
			srand(time(NULL));
			answer = rand() % 256;
			location = 2;
			break;
		case 2:
			scanf("%d", &guess);
			if (guess == answer) {
				printf("CORRECT. IT TOOK YOU %d ATTEMPTS\n", guess_count);
				if (high_score == 0) {
					high_score = guess_count;
				} else if (high_score > guess_count) {
					printf("< < NEW HIGH SCORE > >\n");
					high_score = guess_count;
				}
				printf("HIGH SCORE :: %d\n", high_score);
				printf("PLAY AGAIN? (0 = N/1 = Y)\n");
				scanf("%d", &play_again);
				if (play_again == 1) {
					location = 1;
					break;
				} else if (play_again == 0) {
					active = 0;
					return 1;
				} else {
					printf("INVALID RESPONSE.\n");
					active = 0;
					return 1;
				}
			} else {
				if (guess > answer) {
					if ((guess - answer) >= upper_threshold) {
						if (upper_threshold != 0) {
							printf("ANSWER IS NOT HIGHER THAN %d\n", (answer + upper_threshold));
						} else {
							upper_threshold = (guess - answer);
						}
					} else {
						upper_threshold = (guess - answer);
					}
					printf("TOO HIGH. GUESS AGAIN.\n");
					guess_count++;
				} else if (guess < answer) {
					if ((answer - guess) >= lower_threshold) {
						if (lower_threshold != 0) {
							printf("ANSWER IS NOT LOWER THAN %d\n", (answer - lower_threshold));
						} else {
							lower_threshold = (answer - guess);
						}
					} else {
						lower_threshold = (answer - guess);
					}
					printf("TOO LOW. GUESS AGAIN.\n");
					guess_count++;
				}
			}
		default:
			break;
		}
	}
}

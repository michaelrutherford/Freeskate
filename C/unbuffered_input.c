#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main()
{
				char buffer;
				while(1) {
								buffer = readch();
								if(buffer == 'a')
									   printf("%c\n", buffer);
								if(buffer == 'x')
												break;
				}
				printf("%c\n", buffer);
				return EXIT_SUCCESS;
}

int readch(void)
{
    struct termios oldattr, newattr;
				int ch;
				tcgetattr(STDIN_FILENO, &oldattr);
				newattr = oldattr;
				newattr.c_lflag &= ~(ICANON | ECHO);
				tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
				ch = getchar();
				tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
				return ch;
}

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
        initscr();
        struct player {
                char *name;
                unsigned short age;
                unsigned short health;
                unsigned int level;
                unsigned short location;
                unsigned short active;
                unsigned short inventory[50];
        };
        char input[25] = "";
        struct player *main_character = NULL;
        main_character = malloc(sizeof(struct player));
        main_character -> level = 1;
        main_character -> location = 0;
        main_character -> health = 100;
        main_character -> active = 1;
        for (unsigned short i = 0; i < 50; i++) {
                main_character -> inventory[i] = 0;
        }
        main_character -> name = malloc(sizeof(char) * 15);
        printw("What is your name? (Maximum of 15 characters)\n");
        getstr(main_character -> name);
        refresh();
        printw("Welcome, %s\n", main_character -> name);
        refresh();
        while (main_character -> active == 1) {
                if (main_character -> location == 0) {
                        printw("You are in a dark room. There is a door to the north.\n");
                        refresh();
                        scanw("%s", &input);
                        if (strncmp(input, "north", 5) == 0 || strncmp(input, "n", 1) == 0) {
                                printw("You walk through the doorway.\n");
                                refresh();
                                main_character -> location = 1;
                        }
                        if (strncmp(input, "exit", 4) == 0 || strncmp(input, "quit", 4) == 0) {
                                printw("Exiting game...");
                                refresh();
                                main_character -> active = 0;
                        }
                }
                if (main_character -> location == 1) {
                        printw("You are now in a hallway. There is a light to the west.\n");
                        refresh();
                        scanw("%s", &input);
                        if (strncmp(input, "west", 4) == 0 || strncmp(input, "w", 1) == 0) {
                                printw("You are free.\n");
                                refresh();
                                main_character -> active = 0;
                        }
                }
        }
        printw("Game over. Press any key to quit.\n");
        refresh();
        getch();
        endwin();
        return 0;
}

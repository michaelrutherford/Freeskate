/*
Copyright 2016 Michael Rutherford

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>

//Declares a struct that holds data and a pointer to another struct of the same type.
struct node {
        int node_data;
        int node_ID;
        struct node *next_node;
};

void print_menu()
{       
        //Prints the operation menu.
        printf("1: NEW NODE\n");
        printf("2: SET NODE DATA\n");
        printf("3: DELETE NODE\n");
        printf("4: PREVIOUS NODE\n");
        printf("5: NEXT NODE\n");
        printf("6: PRINT NODE\n");
        printf("7: PRINT ALL NODES\n");
        printf("8: ABOUT PROGRAM\n");
        printf("9: EXIT PROGRAM\n\n");
}

void print_all_nodes(struct node *list_node)
{
        //Loops while list_node is not equal to NULL.
        while (list_node != NULL) {
                //Prints the node ID, the data in the node, and the pointer to the next node.
                printf("ID: %d\n", list_node -> node_ID);
                printf("DATA: %d\n", list_node -> node_data);
                printf("NEXT: %p\n\n", list_node -> next_node);
                
                //Points list_node to the next node in the list.
                list_node = list_node -> next_node;
        }
}

void print_node(struct node *list_node)
{
        //Prints the node ID, the data in the node, and the pointer to the next node.
        printf("ID: %d\n", list_node -> node_ID);
        printf("DATA: %d\n", list_node -> node_data);
        printf("NEXT: %p\n\n", list_node -> next_node);
}

int main(int argc, char *argv[])
{
        //Declares integers to accept input, determine status, and keep track of nodes.
        int user_input_op = 0;
        int user_input_data = 0;
        int user_status = 0;
        int node_count = 0;
        int current_node = 0;

        //Creates and instantiates the root node.
        struct node *root = NULL;
        root = malloc(sizeof(struct node));
        root -> node_data = 0;
        root -> node_ID = 0;
        root -> next_node = 0;
        node_count++;

        //Creates the navigator node and sets it equal to root.
        struct node *navigator = NULL;
        navigator = root;

        //Prints the user opertation menu.
        print_menu();
        
        //Loops until status is equal a non-zero number.
        while (user_status != 1) {
                //Prints a message stating the current node and prompts the user for input.
                printf("[NODE %d] ENTER AN OPERATION: ", navigator -> node_ID);

                //Reads what the user types and stores it in input.
                scanf("%d", &user_input_op);

                //Matches the user input to the operation.
                switch (user_input_op) {
                case 1:
                        //Prints a message stating that a new node will be created.
                        printf("CREATING NEW NODE...\n");

                        //Moves the navigator node to the last existing node.
                        while (navigator -> next_node != NULL) {
                                navigator = navigator -> next_node;
                        }

                        //Allocates space for another node and points navigator to that node.
                        navigator -> next_node  = malloc(sizeof(struct node));

                        //Increases the node count by 1 and sets ID for the new node.
                        node_count++;
                        navigator = navigator -> next_node;
                        navigator -> node_ID = node_count - 1;

                        //Prints a message stating that the node has been created successfully.
                        printf("NODE %d CREATED SUCCESSFULLY\n\n", navigator -> node_ID);

                        //Moves the navigator node to the root node and then to the current node.
                        navigator = root;
                        while (navigator -> node_ID != current_node) {
                                navigator = navigator -> next_node;
                        }

                        break;

                case 2:
                        //Prints a message stating that the user must enter the node data.
                        printf("ENTER NODE %d DATA: ", navigator -> node_ID);

                        //Reads user input and stores it in the node data of the current node.
                        scanf("%d", &user_input_data);
                        navigator -> node_data = user_input_data;

                        //Prints a message stating that the node data has been set to what the user entered.
                        printf("NODE %d DATA SET TO %d\n\n", navigator -> node_ID, navigator -> node_data);
                        
                        break;

                case 3:
                        //Prints a message stating that the current node will be deleted.
                        printf("DELETING NODE %d...\n\n", navigator -> node_ID);

                        //Moves the navigator node to the root node.
                        navigator = root;

                        //Checks to see that the current node is not the root node and not the only node.
                        if (current_node > 0 && node_count > 1) {

                                //Moves the navigator node the the node before the current node.
			        while (navigator -> node_ID < current_node - 1) {
                                        navigator = navigator -> next_node;
                                }

                                //Checks to see if the node count is less than one.
                                if (node_count < 1) {
                                        //Sets the next node to be the node after the current node.
                                        navigator -> next_node = navigator -> next_node -> next_node;
                                        navigator -> next_node -> node_ID = current_node;
                                } else {
                                        //Sets the next node to NULL.
                                        navigator -> next_node = NULL;
                                }

                                //Sets the current node to the node ID of the navigator node.
                                current_node = navigator -> node_ID;

                                //Decreases the node count by one.
			        node_count--;
                        } else if (current_node == 0 && node_count > 1){

                                //Sets the root node to be the node after the navigator node.
                                root = navigator -> next_node;

                                //Sets the root ID and the current node to zero and decreases the node count.
                                root -> node_ID = 0;
                                current_node = 0;
                                node_count--;
                        } else {
                                //Prints a message stating that there is no node before the current node.
                                printf("ERROR: NO PRECEEDING NODES\n\n");
                        }
                        
                        break;

                case 4:
                        //Prints a message stating that the current node has moved back one.
                        printf("MOVING TO NODE %d...\n\n", current_node - 1);

                        //Moves the navigator node to the previous node if that node exists.
                        if (navigator -> node_ID != root -> node_ID) {
                                navigator = root;
                                while (navigator -> node_ID != current_node - 1 && navigator -> next_node != NULL) {
                                        navigator = navigator -> next_node;
                                }
                                current_node--;
                        } else {
                                //Prints a message stating that there are no nodes before the current node.
                                printf("ERROR: NO PRECEEDING NODES\n\n");
                        }

                        break;

                case 5:
                        //Prints a message stating that the current node has moved up one.
                        printf("MOVING TO NODE %d...\n\n", current_node + 1);

                        //Moves the navigator node to the next node if that node exists.
                        if (navigator -> node_ID != node_count - 1 && node_count > 1) {
                                navigator = navigator -> next_node;
				current_node++;
                        } else {
                                //Prints a message stating that the next node does not exist.
                                printf("ERROR: NODE %d DOES NOT EXIST\n\n", current_node + 1);

                        }

                        break;

                case 6:
                        //Prints a message stating that the current node will be printed.
                        printf("PRINTING CURRENT NODE...\n\n");

                        //Sets the navigator node to root then moves to the current node.
                        navigator = root;
                        while (navigator -> node_ID != current_node) {
                                navigator = navigator -> next_node;
                        }

                        //Prints the current node data and pointer to the next node.
                        print_node(navigator);

                        break;

                case 7:
                        //Prints a message stating that all nodes will be printed.
                        printf("PRINTING ALL NODES...\n\n");

                        //Points the navigation node back to the root node.
                        navigator = root;

                        //Prints the data and pointers from all of the nodes in the list.
                        print_all_nodes(navigator);

                        //Points the navigator node back to the current node.
                        while (navigator -> node_ID != current_node) {
                                navigator = navigator -> next_node;
                        }

                        break;

                case 8:
                        //Prints the legal information about the program.
                        printf("\nLLV-CLI: CREATE LINKED LISTS IN THE COMMAND LINE\n");
                        printf("COPYRIGHT MICHAEL RUTHERFORD (2016)\n");
                        printf("LICENSED UNDER THE APACHE LICENSE, VERSION 2\n\n");

                        break;

                case 9:
                        //Prints a message stating the program is ending.
                        printf("EXITING PROGRAM...\n\n");

                        //Exits the program and returns a value of 0 back to the main function.
                        exit(EXIT_SUCCESS);

                        break;

                default:
                        //Prints a message stating that the input was invalid.
                        printf("ERROR: INVALID INPUT\n\n");

                        //Breaks out of the switch statement when the input is invalid.
                        break;

                }
        }
        
        //Returns a value of 0 back to the main function.
        return EXIT_SUCCESS;
}

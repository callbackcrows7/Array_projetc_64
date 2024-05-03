/* 
 * File:            1D Array Project.c
 * Version:         2.0
 * 
 * Author:          HM Nayem (Vi)
 * Created on:      Jun 29, 2022. 00:00 AM / PM
 * 
 * Updated by:      MD. SHAHRIAR AHAMMAD
 * Updated date:    May 02, 2024. 1:23 PM
 * 
 * Description:     This program allows users to perform various operations on a one-dimensional array. 
 *                  Users can add, insert, edit, delete, display, and clear elements in the array. 
 *                  Additionally, the program provides functionalities such as finding the minimum and maximum values, 
 *                  calculating the sum and average of elements, searching for elements, and sorting the array. 
 *                  The user interacts with the program through a menu system where each option corresponds to a specific operation. 
 */

#include<stdio.h>
#include<stdlib.h>
#include"local_function.h"

// define Max Array Length
#define MAX_LENGTH 1024
// defile Max Menu Length
#define MAX_MENU_CHOICE 13

// Main function to interact with the user.
// The user can add, insert, edit, delete, display, clear elements in an array, and also perform more operation like exit the program etc.
int main(void)
{   
    // Declare variables
    int menu = 1; // Variable to store the menu choice
    int arr[MAX_LENGTH]; // Array to store elements
    int pre_len = 0; // Variable to store the current length of the array

    // Prompt the user to enter the menu item and perform the corresponding operation.
    do
    {   
        // Display the menu options for the user.
        print_menu();

        // Read the menu item chosen by the user.
        printf("Enter Menu: ");
        // Check input validation.
        while (scanf("%d", &menu) != 1 || menu < 0 || menu > MAX_MENU_CHOICE) {
            printf("\n!Invalid input. Please enter a positive number between 0 and 13: ");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        system("clear || cls"); // Clear the screen

        printf("----==::RESULT BEGIN::==----\n\n");

        // Perform the selected operation.
        switch (menu)
        {   
            // Exit the program.
            case 0:
                printf("Exiting program...\n\n");
                break;

            // Add elements to the array.
            case 1:
                add_elements(arr, &pre_len);
                break;

            // Insert elements into the array.
            case 2:
                insert_element(arr, &pre_len);
                break;

            // Edit elements in the array.
            case 3:
                edit_element(arr, &pre_len);
                break;

            // Delete elements from the array.
            case 4:
                delete_element(arr, &pre_len);
                break;

            // Display elements in the array.
            case 5:
                display_array(arr, pre_len);
                break;

            // Clear all elements from the array.
            case 6:
                clear_array(arr, &pre_len);
                break;

            // Find the minimum value in the array.
            case 7:
                calculate_min(arr, pre_len);
                break;

            // Find the maximum value in the array.
            case 8:
                calculate_max(arr, pre_len);
                break;

            // Calculate the sum of all elements in the array.
            case 9:
                calculate_sum(arr, pre_len);
                break;

            // Calculate the average of all elements in the array.
            case 10:
                calculate_avg(arr, pre_len);
                break;

            // Search for an element in the array.
            case 11:
                search_element(arr, pre_len);
                break;

            // Sort the elements in the array.
            case 12:
                sort_element(arr, pre_len);
                break;

            // Handle invalid menu choices.
            default:
                printf("!Invalid Input. Please Select Menu Between 0 And 13.\n\n");
                break;
        }
        
        printf("-----==::RESULT END::==-----\n\n");

        clear_input_buffer(); // Clear the input buffer before prompting again

    } while (menu != 0); // Continue until '0' is pressed

    return 0;
}
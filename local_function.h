// Define variables
int i, j;

// Function to display menu items.
// ------------------------------
// Parameters:
//    Don't take any parameters.
// Returns:
//    None
void print_menu()
{
    // Print the header of the menu
    printf("::Menu Item Name::\n");
    printf("------------------\n");

    // Print each menu item with its corresponding number
    printf(" 1. Add\n");       // Option to add elements
    printf(" 2. Insert\n");    // Option to insert elements
    printf(" 3. Edit\n");      // Option to edit elements
    printf(" 4. Delete\n");    // Option to delete elements
    printf(" 5. Display\n");   // Option to display elements
    printf(" 6. Clear\n");     // Option to clear the array
    printf(" 7. Min\n");       // Option to find the minimum value
    printf(" 8. Max\n");       // Option to find the maximum value
    printf(" 9. Sum\n");       // Option to calculate the sum of elements
    printf("10. Avg\n");       // Option to calculate the average of elements
    printf("11. Search\n");    // Option to search for an element
    printf("12. Sort\n");      // Option to sort the array
    printf(" 0. Exit\n");      // Option to exit the program

    // Print the footer of the menu
    printf("------------------\n");
}


// Function: clear_input_buffer
// ----------------------------
// Clears the input buffer by reading characters until a newline character or end-of-file (EOF) is encountered.
// This function is useful for clearing any extra characters from the input buffer, especially after using functions like scanf().
void clear_input_buffer() {
    int c; // Variable to store characters read from the input buffer
    
    // Loop until newline character or end of file is encountered
    while ((c = getchar()) != '\n' && c != EOF) {
        // Keep reading characters from the input buffer until a newline or EOF is found
    }
}


// Function to add elements to the array.
// --------------------------------------
// Parameters:
//    array: the array to which the element will be added
//    pre_len: pointer to the current length of the array
// Returns:
//    None
void add_elements(int array[], int *present_length) {
    int data; // Variable to store the user input

    // Prompt the user to enter a positive integer
    printf("Enter a Positive Integer: ");
    scanf("%d", &data);

    // Validation loop to ensure the entered value is positive
    while (data < 0) {
        clear_input_buffer(); // Clear the input buffer before prompting again
        printf("Invalid input! Enter a Positive Integer: ");
        scanf("%d", &data);
    }

    // Store the entered value in the array at the current length
    array[*present_length] = data;

    // Inform the user that the element has been added at a specific index
    printf("%d Added To Index: %d\n", data, *present_length);

    // Print a new line for better readability
    printf("\n");

    // Update the length after adding the element
    (*present_length)++;

    return;
}

// Function to display array elements.
// -----------------------------------
// Parameters:
//    array: the array containing elements to be displayed
//    present_length: the current length of the array
// Returns:
//    None
void display_array(int array[], int present_length) {
    // Check if there is only one element in the array
    if (present_length == 1) {
        printf("The Element Is: ");
    }
    else if (present_length == 0) 
    {
        printf("There Is No Elements.");
    }
    else
    {
        printf("The Element Are: ");
    }

    // Print each element of the array
    for (int i = 0; i < present_length; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n\n");

    return;
}

// Function: clear_array
// ---------------------
// Clears all elements of the array by setting them to zero and updates the present length of the array to zero.
// Parameters:
//    array:  array: Pointer to the array whose elements need to be cleared.
//    present_length: Pointer to the current length of the array.
// Returns:
//    None
void clear_array(int array[], int *present_length) {
    // Reset all elements of the array to zero
    for (i = 0; i < *present_length; i++) {
        array[i] = 0;  // Set each element to zero
    }
    
    // Set the present length of the array to zero
    *present_length = 0;  // Update the length to indicate an empty array

    printf("Array is cleared!\n\n");  // Print a message confirming array clearance

    return;  // Return from the function
}

// Function: insert_element
// ------------------------
// Inserts a new element into the array at the specified index, shifting existing elements to the right.
// Parameters:
//    array: Pointer to the array into which the element will be inserted.
//    present_length: Pointer to the current length of the array.
// Returns:
//    None
void insert_element(int array[], int *present_length){
    int data, index; // Variables to store data and the index.

    // Prompt the user to enter a positive integer
    printf("Enter a Positive Integer: ");
    scanf("%d", &data);

    // Validation loop to ensure the entered value is positive
    while (data < 0) {
        clear_input_buffer(); // Clear the input buffer before prompting again
        printf("Invalid input! Enter a Positive Integer: ");
        scanf("%d", &data);
    }

    // Prompt the user to enter an index within the range of the array
    printf("Please Enter an Index Between 0 - %d: ", *present_length - 1);
    scanf("%d", &index);

    // Validate if the entered index is within the valid range
    while (index < 0 || index >= *present_length) {
        clear_input_buffer(); // Clear the input buffer before prompting again
        printf("Invalid index! Please enter an index between 0 - %d: ", *present_length - 1);
        scanf("%d", &index);
    }

    // Shift elements to make space for the new element
    for (int i = *present_length; i > index; i--) {
        array[i] = array[i - 1];
    }

    // Insert the new element at the specified index
    (*present_length)++; // Increase the length of the array
    array[index] = data; // Insert the new element at the specified index

    return;
}

// Function: edit_element
// -----------------------
// Allows the user to edit an element at a specified index in the array.
//
// Parameters:
//    array: Pointer to the array whose element needs to be edited.
//    present_length: Pointer to the current length of the array.
//
// Returns:
//    None
void edit_element(int array[], int *present_length) {
    int data, index; // Variables to store data and the index.

    // Prompt the user to enter an index within the range of the array
    printf("Please Enter an Index Between 0 - %d: ", *present_length - 1);
    scanf("%d", &index);

    // Validate if the entered index is within the valid range
    while (index < 0 || index >= *present_length) {
        clear_input_buffer(); // Clear the input buffer before prompting again
        printf("Invalid index! Please enter an index between 0 - %d: ", *present_length - 1);
        scanf("%d", &index);
    }

    // Prompt the user to enter a positive integer
    printf("Enter a New Positive Integer: ");
    scanf("%d", &data);

    // Validation loop to ensure the entered value is positive
    while (data < 0) {
        clear_input_buffer(); // Clear the input buffer before prompting again
        printf("Invalid input! Enter a Positive Integer: ");
        scanf("%d", &data);
    }  

    // Update the value at the specified index
    array[index] = data;

    return;
}

// Function: delete_element
// ------------------------
// Deletes an element from the array at the specified index, shifting subsequent elements to the left.
//
// Parameters:
//    array: Pointer to the array from which the element will be deleted.
//    present_length: Pointer to the current length of the array.
//
// Returns:
//    None
void delete_element(int array[], int *present_length) {
    int index; // Variable to store the index.

    // Prompt the user to enter an index within the range of the array
    printf("Please Enter an Index Between 0 - %d: ", *present_length - 1);
    scanf("%d", &index);

    // Validate if the entered index is within the valid range
    while (index < 0 || index >= *present_length) {
        clear_input_buffer(); // Clear the input buffer before prompting again
        printf("Invalid index! Please enter an index between 0 - %d: ", *present_length - 1);
        scanf("%d", &index);
    }

    // Shift elements to fill the gap left by the deleted element
    for (int i = index; i < *present_length - 1; i++) {
        array[i] = array[i + 1];
    }

    // Delete the element at the specified index by setting it to 0
    array[*present_length - 1] = 0;

    // Decrease the length of the array
    (*present_length)--;
}

// Function: calculate_min
// -----------------------
// Description: This function calculates the minimum element in an integer array.
// Parameters:
//     array[]: Integer array from which the minimum element is to be found.
//     present_length: Number of elements in the array.
// Returns: None
void calculate_min(int array[], int present_length) {
    // Initialize min with the first element of the array
    int min = array[0];

    // Loop through the array elements to find the minimum
    for(int i = 0; i < present_length; i++) {
        // If the current element is less than the current minimum,
        // update the minimum value
        if (min > array[i]) {
            min = array[i];
        }
    }

    // Print the minimum element
    printf("Min Element Is: %d\n\n", min);

    return; // Return statement indicating the end of the function
}

// Function: calculate_max
// -----------------------
// Description: This function calculates the maximum element in an integer array.
// Parameters:
//     array[]: Integer array from which the maximum element is to be found.
//     present_length: Number of elements in the array.
// Returns: None
void calculate_max(int array[], int present_length) {
    // Initialize max with the first element of the array
    int max = array[0];

    // Loop through the array elements to find the maximum
    for(int i = 0; i < present_length; i++) {
        // If the current element is greater than the current maximum,
        // update the maximum value
        if (max < array[i]) {
            max = array[i];
        }
    }

    // Print the maximum element
    printf("Max Element Is: %d\n\n", max);

    return; // Return statement indicating the end of the function
}

// Function: calculate_sum
// -----------------------
// Description: This function calculates the sum of elements in an integer array.
// Parameters:
//     array[]: Integer array for which the sum of elements is to be calculated.
//     present_length: Number of elements in the array.
// Returns: None
void calculate_sum(int array[], int present_length) {
    // Initialize sum to zero
    int sum = 0;

    // Loop through the array elements to calculate the sum
    for (int i = 0; i < present_length; i++) {
        // Add the current element to the sum
        sum += array[i];
    }

    // Print the sum of array elements
    printf("Sum Of Array Elements Is: %d\n", sum);

    return; // Return statement indicating the end of the function
}

// Function: calculate_avg
// Description: This function calculates the average of elements in an integer array.
// Parameters:
//     array[]: Integer array for which the average of elements is to be calculated.
//     present_length: Number of elements in the array.
// Returns: None
void calculate_avg(int array[], int present_length) {
    // Initialize sum to zero
    int sum = 0;
    // Define avg variable to store the average
    size_t avg;

    // Loop through the array elements to calculate the sum
    for (int i = 0; i < present_length; i++) {
        // Add the current element to the sum
        sum += array[i];
    }

    // Calculate the average by dividing the sum by the number of elements
    avg = sum / present_length;
    
    // Print the average of array elements
    printf("Avg Of Array Elements Is: %llu\n\n", avg);

    return; // Return statement indicating the end of the function
}

// Function: search_element
// Description: This function searches for a specified element in an integer array.
// Parameters:
//     array[]: Integer array in which the element is to be searched.
//     present_length: Number of elements in the array.
// Returns: None
void search_element(int array[], int present_length) {
    // Declare variables
    int search_key;
    int is_found = -1; // Initialize a variable to store the index where the element is found, initialized to -1 indicating not found.

    // Prompt user to enter the element to search for
    printf("Please Enter Search Element: ");
    scanf("%d", &search_key);

    // Loop through the array elements to search for the element
    for (int i = 0; i < present_length; i++) {
        // If the element is found, store its index and exit the loop
        if (array[i] == search_key) {
            is_found = i;
            break;
        }
    }

    // Check if the element is found or not and print the appropriate message
    if (is_found == -1) {
        printf("Item not found!\n\n");
    } else {
        printf("Item found at index %d\n\n", is_found);
    }

    return; // Return statement indicating the end of the function
}

// Function: sort_element
// Description: This function sorts the elements of an integer array in ascending order using the bubble sort algorithm.
// Parameters:
//     array[]: Integer array to be sorted.
//     present_length: Number of elements in the array.
// Returns: None
void sort_element(int array[], int present_length) {
    // Declare a temporary variable to hold values during swapping
    int temp;

    // Iterate through the array using nested loops for bubble sort
    for (int i = 0; i < present_length; i++) {
        for (int j = 0; j < present_length; j++) {
            // Compare adjacent elements and swap if they are in the wrong order
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted Array Elements Are: ");
    for (int i = 0; i < present_length; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n\n");

    return; // Return statement indicating the end of the function
}
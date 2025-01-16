#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define arrays and variables to store buyer and sales data
char  NameKharidar[50][30];    // Stores the names of buyers (up to 50 buyers, each with a max name length of 30)
int   ID_NamKharidar[250];     // Links each purchase record to a buyer
char  NamKhala[250][30];       // Stores names of items (up to 250 items, each with a max name length of 30)
int   TedadKala[250];          // Stores the quantity of each item
float GeymatKala[250];         // Stores the unit price of each item
int   Index_1 = 0;             // Index for the current buyer
int   Index_2 = 0;             // Index for the current purchase record

// Function to display the login page and validate user credentials
int Login_Page() {
    char Password[10];         // Stores the entered password
    char Username[10];         // Stores the entered username
    int Return_Mode = 0;       // Determines if the user is a Manager (1) or Cashier (2)

    do {
        system("cls");         // Clears the console
        printf("|_____________________|\n");
        printf("| Username : ");      // Prompt for username
        scanf("%s", &Username);
        printf("| Password : ");      // Prompt for password
        scanf("%s", &Password);
        printf("|_____________________|\n");

        // Check if the user is a Manager
        if (strcmp(Username, "Manager") == 0) {
            int Pass_Return_Value = strcmp(Password, "12345678M");
            if (Pass_Return_Value == 0) {
                Return_Mode = 1; // Manager mode
            } else {
                printf("\n Invalid Password! \n");
                getch();        // Wait for user input
            }
        }
        // Check if the user is a Cashier
        else if (strcmp(Username, "Cashier") == 0) {
            int Pass_Return_Value = strcmp(Password, "87654321A");
            if (Pass_Return_Value == 0) {
                Return_Mode = 2; // Cashier mode
            } else {
                printf("\n Invalid Password! \n");
                getch();
            }
        }
        // If neither, display an error
        else {
            printf("\n Error! \n");
            getch();
        }
    } while (Return_Mode == 0); // Keep prompting until valid credentials are entered

    return Return_Mode;         // Return the user's role
}

// Function to display a sales invoice or summary
void Factor_Page(int Index_NamKharidar) {
    system("cls");              // Clears the console
    if (Index_NamKharidar != -1) {
        printf("Buyer Name: %s\n", NameKharidar[Index_NamKharidar]);
    } else {
        printf("Store Sales Summary\n");
    }

    printf("Item Name       Quantity       Unit Price       Total Price\n");
    float GeymatKol = 0;        // Total amount payable
    if (Index_NamKharidar != -1) {
        // Display details for a specific buyer
        for (int i = 0; i < 250; i++) {
            if (ID_NamKharidar[i] == Index_NamKharidar) {
                float Mablag_Record = (TedadKala[i] * GeymatKala[i]);
                GeymatKol += Mablag_Record;
                printf("%s          %d          %.2f          %.2f\n", NamKhala[i], TedadKala[i], GeymatKala[i], Mablag_Record);
            }
        }
    } else {
        // Display details for all sales
        for (int i = 0; i < Index_2; i++) {
            float Mablag_Record = (TedadKala[i] * GeymatKala[i]);
            GeymatKol += Mablag_Record;
            printf("%s          %d          %.2f          %.2f\n", NamKhala[i], TedadKala[i], GeymatKala[i], Mablag_Record);
        }
    }
    printf("Total Amount Payable: %.2f\n", GeymatKol);
}

// Function to handle the Manager Panel
void Manager_Page() {
    int Exit_Status = 1;
    printf("Manager Panel\n");
    do {
        Factor_Page(-1);        // Display all sales
        char Exit_String[5];
        scanf("%s", &Exit_String);
        Exit_Status = strcmp(Exit_String, "exit"); // Exit if "exit" is entered
    } while (Exit_Status != 0);
}

// Function to add a new purchase record
void Add_New_Record(int Index_NamKharidar) {
    ID_NamKharidar[Index_2] = Index_NamKharidar; // Link purchase to buyer

    printf("Item Name: ");
    scanf("%s", &NamKhala[Index_2]);

    printf("Quantity: ");
    scanf("%d", &TedadKala[Index_2]);

    printf("Unit Price: ");
    scanf("%f", &GeymatKala[Index_2]);

    if ((Index_2 + 1) < 250) {
        Index_2++;              // Increment purchase record index
    }
}

// Function to handle the Cashier Panel
void Cashier_Page() {
    int Exit_Status = 1;
    do {
        printf("Buyer Name: ");
        scanf("%s", &NameKharidar[Index_1]); // Enter buyer name

        char Dollar = 'A';
        do {
            Add_New_Record(Index_1);        // Add purchase records for this buyer
            Dollar = getch();              // Wait for keypress
        } while (Dollar != '$');           // Exit if '$' is pressed

        Factor_Page(Index_1);              // Display buyer's invoice

        if ((Index_1 + 1) < 50) {
            Index_1++;                     // Increment buyer index
        }

        char Exit_String[5];
        scanf("%s", &Exit_String);
        Exit_Status = strcmp(Exit_String, "exit"); // Exit if "exit" is entered
    } while (Exit_Status != 0);
}

// Main function
int main() {
    // Initialize buyer IDs
    for (int i = 0; i < 250; i++) {
        ID_NamKharidar[i] = -1;
    }

    do {
        int Mode = Login_Page();           // Prompt user to log in
        if (Mode == 1) {
            Manager_Page();                // Access Manager Panel
        } else if (Mode == 2) {
            Cashier_Page();                // Access Cashier Panel
        }
    } while (1);                           // Keep running the program

    return 0;
}

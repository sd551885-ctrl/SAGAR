#include <stdio.h>

int main() {
    int registeredPin;
    int enteredPin;
    int pinAttempts = 0;
    int pinAuthenticated = 0;

    float balance = 1000.00; 
    int Amount, choice, numNotes, noteValue;
    int Deposit, withdrawAmount;
    int n500, n200, n100;
    int menuChoice;
    int confirmPin; // Added variable for withdrawal confirmation

    printf("       Welcome to Sagar Bank ATM System \n\n");

    // ----------------------------------------------------
    // STEP 1: REGISTER NEW PIN
    // ----------------------------------------------------
    printf("--- PIN Registration ---\n");
    printf("Create a new 4-digit PIN: ");
    scanf("%d", &registeredPin);
    printf("PIN registered successfully!\n\n");

    // ----------------------------------------------------
    // STEP 2: LOG IN WITH CREATED PIN
    // ----------------------------------------------------
    printf("--- ATM Login ---\n");
    while (pinAttempts < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == registeredPin) {
            pinAuthenticated = 1;
            printf("\n\t  log in successfully\n\n");
            break;
        } else {
            pinAttempts++;
            printf("Incorrect PIN. please try again: %d\n\n", 3 - pinAttempts);
        }
    }

    if (!pinAuthenticated) {
        printf("Too many incorrect attempts. Your card has been blocked.\n");
        printf("Transaction cancelled.\n");
        return 1; 
    }

    // ----------------------------------------------------
    // STEP 3: MAIN ATM MENU
    // ----------------------------------------------------
    while(1) {
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);

        switch(menuChoice) {
            case 1:
                printf("\nYour current balance is: %.2f\n", balance);
                break;

            case 2:
                printf("\nEnter total deposit amount: ");
                scanf("%d", &Amount);
                
                if (Amount < 100 || Amount > 10000) {
                    printf("\nError: Please input the right amount.\n");
                    printf("Deposit must be 100 - 10000.\n");
                    printf("Transaction cancelled.\n");
                    break; 
                }

                printf("\nAvailable notes:\n");
                printf("1. 500\n2. 200\n3. 100\n");
                printf("Select currency (1-3): ");
                scanf("%d", &choice);

                switch(choice) {
                    case 1: noteValue = 500; break;
                    case 2: noteValue = 200; break;
                    case 3: noteValue = 100; break;
                    default:
                        printf("\nInvalid selection. Transaction cancelled.\n");
                        noteValue = 0; 
                }

                if (noteValue == 0) break; 

                printf("Enter number of %d notes: ", noteValue);
                scanf("%d", &numNotes);
                Deposit = noteValue * numNotes;

                if (Deposit == Amount) {
                    printf("\nProcessing...");
                    balance += Deposit; 
                    printf("\nSuccess! You deposited %d notes of %d. Total: %d\n", numNotes, noteValue, Deposit);
                    printf("New Balance: $%.2f\n", balance);
                } 
                else {
                    printf("\nAmount does not match!\n");
                    printf("How many 500 notes: ");
                    scanf("%d", &n500);
                    printf("How many 200 notes: ");
                    scanf("%d", &n200);
                    printf("How many 100 notes: ");
                    scanf("%d", &n100);
                    
                    Deposit = (n200 * 200) + (n100 * 100) + (n500 * 500);
                    
                    if (Deposit == Amount) {
                        balance += Deposit; 
                        printf("\nSuccess... Deposit successful\n");
                        printf("New Balance: %.2f\n", balance);
                    } else {
                        printf("\nError: The number of notes does not match.\n");
                        printf("Transaction cancelled.\n");
                        printf("Expected: %d | Calculated: %d\n", Amount, Deposit);
                    }
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: ");
                scanf("%d", &withdrawAmount);

                if (withdrawAmount < 100) {
                    printf("Withdrawal must be at least 100.\n");
                } else if (withdrawAmount % 100 != 0) {
                    printf("Withdrawal must be in multiples of 100 (e.g., 100, 200, 500).\n");
                } else if (withdrawAmount > balance) {
                    printf("Wrong Balance. You only have %.2f available.\n", balance);
                } else {
                    // --- PIN CONFIRMATION FOR WITHDRAWAL ---
                    printf("Confirm your PIN to proceed with withdrawal: ");
                    scanf("%d", &confirmPin);

                    if (confirmPin == registeredPin) {
                        balance -= withdrawAmount; 
                        printf("Successfully withdrew: %d\n", withdrawAmount);
                        printf("Current balance: %.2f\n", balance);
                    } else {
                        printf("\nIncorrect PIN. Withdrawal cancelled!\n");
                    }
                }
                break;

            case 4:
                printf("\nThank you for using Sagar Bank ATM\n");
                return 0;

            default:
                printf("\nInvalid choice please try again\n");
        }
    }

    return 0;
}

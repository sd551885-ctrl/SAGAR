#include <stdio.h>

struct Ticket {
    int ticketID;
    char passengerName[50];
    int trainNumber;
    char classType[20];
    int isBooked;
    int price; 
};

int main() {
    char regUser[20], regPass[20];
    char logUser[20], logPass[20];
    int loginSuccess = 0;
    struct Ticket system[10]; 
    int choice;
    int ticketCounter = 1001;
    int validTrains[20] = {
        12860, 12859, 12951, 12952, 12381, 
        12382, 15906, 15905, 12841, 12842, 
        1911,  1912,  22436, 22435, 12013, 
        12014, 12259, 12260, 12245, 12246
    };
    for(int i = 0; i < 10; i++) {
        system[i].isBooked = 0;
    }
    printf("******** Railway System - Register Account ********\n");
    printf("Create Username \n (No spaces use (A-Z,a-z,0-9)): ");
    scanf("%s", regUser);
    printf("\nCreate Password \n (No spaces use (8-character password suggestions containing a mix of uppercase letters, lowercase letters, numbers, and symbols)): ");
    scanf("%s", regPass);
    printf("\nRegistration Successful!\n\n");
    while(!loginSuccess) {
        printf("******** Railway System - Login ********\n");
        printf("Enter Username: ");
        scanf("%s", logUser);
        printf("Enter Password: ");
        scanf("%s", logPass);
        int uMatch = 1, pMatch = 1;
        for(int i = 0; regUser[i] != '\0' || logUser[i] != '\0'; i++) {
            if(regUser[i] != logUser[i]) { uMatch = 0; break; }
        }
        for(int i = 0; regPass[i] != '\0' || logPass[i] != '\0'; i++) {
            if(regPass[i] != logPass[i]) { pMatch = 0; break; }
        }

        if(uMatch && pMatch) {
            printf("\nLogin Successful! Welcome to the system.\n");
            loginSuccess = 1;
        } else {
            printf("\nInvalid Username or Password! Try again.\n\n");
        }
    }
    while(1) {
        printf("\n******** Railway Reservation System ********\n");
        printf("1. View Trains\n");
        printf("2. Search Train Info (By No / Name)\n"); // Updated Option Description
        printf("3. Book Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Search Ticket\n");
        printf("6. Display All Reservations\n");
        printf("7. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\n--- Available Trains ---\n");
                printf("\n1.\nTrain No:12860 | Gitanjali express | Route: Station howrah-> Mumbai |\n Departure-1.40pm | Arrived- (next day) 9.20pm\n");
                printf("\n2.\nTrain No: 12859 | Gitanjali express | Route: Station Mumbai-> Howrah|\n Departure-06:00AM|Arrived-(next day)12:30pm\n");
                printf("\n3.\nTrain No:12951 |Central Rajdhani Express | Route: Station New Delhi -> Mumbai |\nDeparture-05:00pm | Arrived- (next day) 08:32am\n");
                printf("\n4.\nTrain No: 12952|Central Rajdhani Express | Route: Station Mumbai -> New Delhi |\nDeparture-04:55pm | Arrived- (next day) 08:35am\n");
                printf("\n5.\nTrain No: 12381|Poorva Express | Route: Station Howrah -> New Delhi |\nDeparture-08:15am | Arrived- (next day)06:05am\n");
                printf("\n6.\nTrain No: 12382|Poorva Express | Route: Station New Delhi -> Howrah |\n| Departure-05:40pm | Arrived- (next day) 04:55pm\n");
                printf("\n7.\nTrain No: 15906| Vivek Express| Route: Station  Dibrugarh-> Kanyakumari |\nDeparture-07:25pm | Arrived- (4th day )10:00pm\n");
                printf("\n8.\nTrain No: 15905| Vivek Express| Route: Station  kanyakumari->Dibrugarh  |\nDeparture-11:00pm | Arrived- (4th day) 08:50pm\n");
                printf("\n9.\nTrain No: 12841| Central Coromandel Express| Route: Station Shalimar ->chennai | \nDeparture-03:20pm | Arrived- (next day) 05:00pm\n");
                printf("\n10.\nTrain No: 12842| Central Coromandel Express| Route: Station chennai->shalimar |\nDeparture-07:00am | Arrived- (next day )10:40am\n");
                printf("\n11.\nTrain No:1911 |Central Gujarat Express | Route: Station Ahmedabad-> Gujrat |\nDeparture-05:45am | Arrived- (same day) 02:30pm\n");
                printf("\n12.\nTrain No:1912 |Central Gujarat Express | Route: Station Gujrat-> Ahmedabad |\nDeparture-07:10am | Arrived- (same day) 03:55pm\n");
                printf("\n13.\nTrain No:22436|Vande Bharat Express| Route: Station New Delhi-> Varanasi |\nDeparture-06:00am | Arrived- (same day) 02:00pm\n");
                printf("\n14.\nTrain No:22435|Vande Bharat Express| Route: Station Varanasi-> New Delhi\nDeparture-07:10am | Arrived- (same day) 11:00pm\n");
                printf("\n15.\nTrain No:12013|  Shatabdi Express | Route: Station New Delhi->Amritsar \nDeparture-04:30pm | Arrived- (same day) 11:05pm\n");
                printf("\n16.\nTrain No:12014|  Shatabdi Express | Route: Station Amritsar->New Delhi \nDeparture-04:55am | Arrived- (same day)11:20am\n");
                printf("\n17.\nTrain No:12259| Duronto express  | Route: Station Sealdah->New Delhi\nDeparture-05:00am | Arrived- (next day)11:00am\n");
                printf("\n18.\nTrain No:12260| Duronto express  | Route: Station New Delhi->Sealdh\nDeparture-07:45pm | Arrived- (next day )01:30pm\n");
                printf("\n19.\nTrain No:12245| Duronto express  | Route: Station howrah->yesvantpur\nDeparture-10:40am | Arrived- (next day) 03:45pm\n");
                printf("\n20.\nTrain No:12246| Duronto express  | Route: Station yesvantpur->howrah\nDeparture-11:15am | Arrived-( next day) 05:05pm\n");
                break;
                case 2: {
                int subChoice, searchNum, infoFound = 0;
                char searchName[30];
                
                printf("\n--- Search Train Information ---\n");
                printf("1. Search by Train Number\n");
                printf("2. Search by Train Name (No spaces)\n");
                printf("Enter your preference: ");
                scanf("%d", &subChoice);
                if(subChoice == 1) {
                    printf("Enter Train Number: ");
                    scanf("%d", &searchNum);
                } else if(subChoice == 2) {
                    printf("Enter Train Name keyword (e.g. Gitanjali, Rajdhani, Poorva, Vivek, Coromandel, Gujarat, Vande, Shatabdi, Duronto): ");
                    scanf("%s", searchName);
                    for(int c=0; searchName[c] != '\0'; c++) {
                        if(searchName[c] >= 'A' && searchName[c] <= 'Z') searchName[c] += 32;
                    }
                } else {
                    printf("Invalid input option selection!\n");
                    break;
                }
                printf("\n--- Matching Train Records ---\n");
                if ((subChoice == 1 && searchNum == 12860) || (subChoice == 2 && (searchName[0]=='g' && searchName[1]=='i'))) {
                    printf("Train No:12860 | Gitanjali express | Route: Station howrah-> Mumbai |\nDeparture-1.40pm | Arrived- (next day) 9.20pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12859) || (subChoice == 2 && (searchName[0]=='g' && searchName[1]=='i'))) {
                    printf("Train No: 12859 | Gitanjali express | Route: Station Mumbai-> Howrah|\nDeparture-06:00AM|Arrived-(next day)12:30pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12951) || (subChoice == 2 && (searchName[0]=='r' || searchName[0]=='c'))) {
                    printf("Train No:12951 |Central Rajdhani Express | Route: Station New Delhi -> Mumbai |\nDeparture-05:00pm | Arrived- (next day) 08:32am\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12952) || (subChoice == 2 && (searchName[0]=='r' || searchName[0]=='c'))) {
                    printf("Train No: 12952|Central Rajdhani Express | Route: Station Mumbai -> New Delhi |\nDeparture-04:55pm | Arrived- (next day) 08:35am\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12381) || (subChoice == 2 && searchName[0]=='p')) {
                    printf("Train No: 12381|Poorva Express | Route: Station Howrah -> New Delhi |\nDeparture-08:15am | Arrived- (next day)06:05am\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12382) || (subChoice == 2 && searchName[0]=='p')) {
                    printf("Train No: 12382|Poorva Express | Route: Station New Delhi -> Howrah |\nDeparture-05:40pm | Arrived- (next day) 04:55pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 15906) || (subChoice == 2 && searchName[0]=='v' && searchName[1]=='i')) {
                    printf("Train No: 15906| Vivek Express| Route: Station  Dibrugarh-> Kanyakumari |\nDeparture-07:25pm | Arrived- (4th day )10:00pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 15905) || (subChoice == 2 && searchName[0]=='v' && searchName[1]=='i')) {
                    printf("Train No: 15905| Vivek Express| Route: Station  kanyakumari->Dibrugarh  |\nDeparture-11:00pm | Arrived- (4th day) 08:50pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12841) || (subChoice == 2 && searchName[0]=='c' && searchName[5]=='o')) {
                    printf("Train No: 12841| Central Coromandel Express| Route: Station Shalimar ->chennai | \nDeparture-03:20pm | Arrived- (next day) 05:00pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12842) || (subChoice == 2 && searchName[0]=='c' && searchName[5]=='o')) {
                    printf("Train No: 12842| Central Coromandel Express| Route: Station chennai->shalimar |\nDeparture-07:00am | Arrived- (next day )10:40am\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 1911)  || (subChoice == 2 && searchName[0]=='g' && searchName[2]=='j')) {
                    printf("Train No:1911 |Central Gujarat Express | Route: Station Ahmedabad-> Gujrat |\nDeparture-05:45am | Arrived- (same day) 02:30pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 1912)  || (subChoice == 2 && searchName[0]=='g' && searchName[2]=='j')) {
                    printf("Train No:1912 |Central Gujarat Express | Route: Station Gujrat-> Ahmedabad |\nDeparture-07:10am | Arrived- (same day) 03:55pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 22436) || (subChoice == 2 && searchName[0]=='v' && searchName[1]=='a')) {
                    printf("Train No:22436|Vande Bharat Express| Route: Station New Delhi-> Varanasi |\nDeparture-06:00am | Arrived- (same day) 02:00pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 22435) || (subChoice == 2 && searchName[0]=='v' && searchName[1]=='a')) {
                    printf("Train No:22435|Vande Bharat Express| Route: Station Varanasi-> New Delhi\nDeparture-07:10am | Arrived- (same day) 11:00pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12013) || (subChoice == 2 && searchName[0]=='s')) {
                    printf("Train No:12013|  Shatabdi Express | Route: Station New Delhi->Amritsar \nDeparture-04:30pm | Arrived- (same day) 11:05pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12014) || (subChoice == 2 && searchName[0]=='s')) {
                    printf("Train No:12014|  Shatabdi Express | Route: Station Amritsar->New Delhi \nDeparture-04:55am | Arrived- (same day)11:20am\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12259) || (subChoice == 2 && searchName[0]=='d')) {
                    printf("Train No:12259| Duronto express  | Route: Station Sealdah->New Delhi\nDeparture-05:00am | Arrived- (next day)11:00am\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12260) || (subChoice == 2 && searchName[0]=='d')) {
                    printf("Train No:12260| Duronto express  | Route: Station New Delhi->Sealdh\nDeparture-07:45pm | Arrived- (next day )01:30pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12245) || (subChoice == 2 && searchName[0]=='d')) {
                    printf("Train No:12245| Duronto express  | Route: Station howrah->yesvantpur\nDeparture-10:40am | Arrived- (next day) 03:45pm\n"); infoFound = 1;
                }
                if ((subChoice == 1 && searchNum == 12246) || (subChoice == 2 && searchName[0]=='d')) {
                    printf("Train No:12246| Duronto express  | Route: Station yesvantpur->howrah\nDeparture-11:15am | Arrived-( next day) 05:05pm\n"); infoFound = 1;
                }
                if (!infoFound) {
                    printf("No records matched your search query.\n");
                }
                break;
            }
            case 3: {
                int foundEmptySlot = -1;
                for(int i = 0; i < 10; i++) {
                    if(system[i].isBooked == 0) {
                        foundEmptySlot = i;
                        break;
                    }
                }
                if(foundEmptySlot == -1) {
                    printf("\nBooking Full! No seats available.\n");
                } else {
                    int i = foundEmptySlot;
                    int inputTrainNo;
                    int isValidTrain = 0;
                    int isPremiumTrain = 0;
                    int classChoice;
                    int calculatedPrice = 0;
                    printf("\n--- Book Ticket ---\n");
                    printf("Enter Train Number: ");
                    scanf("%d", &inputTrainNo);
                    for(int t = 0; t < 20; t++) {
                        if(validTrains[t] == inputTrainNo) {
                            isValidTrain = 1;
                            if(inputTrainNo == 12951 || inputTrainNo == 12952 || 
                               inputTrainNo == 22436 || inputTrainNo == 22435 || 
                               inputTrainNo == 12013 || inputTrainNo == 12014 || 
                               inputTrainNo == 12259 || inputTrainNo == 12260 || 
                               inputTrainNo == 12245 || inputTrainNo == 12246) {
                                isPremiumTrain = 1;
                            }
                            break;
                        }
                    }
                    if(!isValidTrain) {
                        printf("\nBooking Failed! Invalid Train Number.\n");
                        break; 
                    }
                    printf("Enter Passenger First Name (No spaces): ");
                    scanf("%s", system[i].passengerName);
                    printf("\nSelect Class Option:\n");
                    if(isPremiumTrain) {
                        printf("1. sleeper (Not Available / Premium Base: Rs. 820)\n");
                        printf("2. 3rd A/C  (Original Fare: Rs. 2250)\n");
                        printf("3. 2nd A/C  (Original Fare: Rs. 3180)\n");
                        printf("4. 1st A/C  (Original Fare: Rs. 4645)\n");
                    } else {
                        printf("1. sleeper (Original Fare: Rs. 495)\n");
                        printf("2. 3rd A/C  (Original Fare: Rs. 1325)\n");
                        printf("3. 2nd A/C  (Original Fare: Rs. 1890)\n");
                        printf("4. 1st A/C  (Original Fare: Rs. 3160)\n");
                    }
                    printf("Enter Class Choice (1-4): ");
                    scanf("%d", &classChoice);
                    if(classChoice == 1) {
                        char s[] = "sleeper"; for(int k=0; s[k]!='\0'; k++) system[i].classType[k]=s[k]; system[i].classType[7]='\0';
                        calculatedPrice = (isPremiumTrain) ? 820 : 495;
                    } else if(classChoice == 2) {
                        char s[] = "3rd A/C"; for(int k=0; s[k]!='\0'; k++) system[i].classType[k]=s[k]; system[i].classType[7]='\0';
                        calculatedPrice = (isPremiumTrain) ? 2250 : 1325;
                    } else if(classChoice == 3) {
                        char s[] = "2nd A/C"; for(int k=0; s[k]!='\0'; k++) system[i].classType[k]=s[k]; system[i].classType[7]='\0';
                        calculatedPrice = (isPremiumTrain) ? 3180 : 1890;
                    } else if(classChoice == 4) {
                        char s[] = "1st A/C"; for(int k=0; s[k]!='\0'; k++) system[i].classType[k]=s[k]; system[i].classType[7]='\0';
                        calculatedPrice = (isPremiumTrain) ? 4645 : 3160;
                    } else {
                        char s[] = "Unknown"; for(int k=0; s[k]!='\0'; k++) system[i].classType[k]=s[k]; system[i].classType[7]='\0';
                        calculatedPrice = 0;
                    }
                    system[i].trainNumber = inputTrainNo;
                    system[i].price = calculatedPrice;
                    system[i].ticketID = ticketCounter++;
                    system[i].isBooked = 1;
                    
                    printf("\nBooking Successful!\nYour Ticket ID is: %d\nOriginal Ticket Price: Rs. %d\n", system[i].ticketID, system[i].price);
                }
                break;
            }
            case 4: {
                int searchID, found = 0;
                printf("\nEnter Ticket ID to Cancel: ");
                scanf("%d", &searchID);
                for(int i = 0; i < 10; i++) {
                    if(system[i].isBooked == 1 && system[i].ticketID == searchID) {
                        system[i].isBooked = 0;
                        printf("\nTicket ID %d has been successfully canceled.\n", searchID);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("\nTicket ID not found or active.\n");
                }
                break;
            }
            case 5: {
                int searchID, found = 0;
                printf("\nEnter Ticket ID to Search: ");
                scanf("%d", &searchID);
                for(int i = 0; i < 10; i++) {
                    if(system[i].isBooked == 1 && system[i].ticketID == searchID) {
                        printf("\n--- Ticket Found ---\n");
                        printf("Ticket ID: %d\n", system[i].ticketID);
                        printf("Passenger Name: %s\n", system[i].passengerName);
                        printf("Train Number: %d\n", system[i].trainNumber);
                        printf("Class: %s\n", system[i].classType);
                        printf("Ticket Fare: Rs. %d\n", system[i].price);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("\nNo active ticket found with ID %d.\n", searchID);
                }
                break;
            }
            case 6: {
                int activeReservations = 0;
                printf("\n--- All Active Reservations ---\n");
                printf("ID\tName\t\tTrain\tClass\t\tFare\n");
                printf("-----------------------------------------------------------\n");
                for(int i = 0; i < 10; i++) {
                    if(system[i].isBooked == 1) {
                        printf("%d\t%s\t\t%d\t%s\t\tRs. %d\n", system[i].ticketID, system[i].passengerName, system[i].trainNumber, system[i].classType, system[i].price);
                        activeReservations++;
                    }
                }
                if(activeReservations == 0) {
                    printf("(No active bookings in the system)\n");
                }
                break;
            }
            case 7:
                printf("\nThank you for using the Railway Reservation System. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid Choice! Please select between 1 and 7.\n");
        }
    }
    return 0;
}
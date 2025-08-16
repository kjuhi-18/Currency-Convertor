#include<stdio.h>

// Function to display the available currencies
void currencies();
void currencies(){
    printf("1.INR(India)\n2.Dollar(USA)\n3.Euros(EU)\n4.Pounds(UK)\n5.Baht(Thailand)\n6.Yen(Japan)\n7.Dirham(UAE)\n8.Yuan(China)\n9.Ruble(Russia)\n10.Riyal(Saudi Arabia)\n");
}

// Conversion functions (All take Dollar value as base and convert to target currency)

// Convert Dollar to INR
int to_inr(float*dollar){
    float convertedinr = *dollar * 86.39;
    printf("The converted amount in INR is: %.2lf\n", convertedinr);
}

// Convert Dollar to Euro
int to_euro(float*dollar){
    float convertedeuro = *dollar * 0.91;
    printf("The converted amount in Euro is: %.2lf\n", convertedeuro);
}

// Convert Dollar to Pounds
int to_pounds(float*dollar){
    float convertedpounds = *dollar * 0.78;
    printf("The converted amount in Pounds is: %.2lf\n", convertedpounds);
}

// Convert Dollar to Baht
int to_baht(float*dollar){
    float convertedbaht = *dollar * 34.91;
    printf("The converted amount in Baht is: %.2lf\n", convertedbaht);
}

// Convert Dollar to Yen
int to_yen(float*dollar){
    float convertedyen = *dollar * 146.3;
    printf("The converted amount in Yen is: %.2lf\n", convertedyen);
}

// Convert Dollar to Dirham
int to_dirham(float*dollar){
    float converteddirham = *dollar * 3.67;
    printf("The converted amount in Dirham is: %.2lf\n", converteddirham);
}

// Convert Dollar to Yuan
int to_yuan(float*dollar){
    float convertedyuan = *dollar * 7.34;
    printf("The converted amount in Yuan is: %.2lf\n", convertedyuan);
}

// Convert Dollar to Ruble
int to_ruble(float*dollar){
    float convertedruble = *dollar * 85.85;
    printf("The converted amount in Ruble is: %.2lf\n", convertedruble);
}

// Convert Dollar to Riyal
int to_riyal(float*dollar){
    float convertedriyal = *dollar * 3.75;
    printf("The converted amount in Riyal is: %.2lf\n", convertedriyal);
}

// Main program
int main(){
    int n, n1, choice, choice1;
    float dollar, amount;
    char ch;

    printf("WELCOME TO CURRENCY CONVERTER\n");

    // Step 1: Ask user for their input currency
    printf("Please Choose the INDEX of the currency you have:\n");
    currencies();
    scanf("%d", &n);

    // Validate input currency
    if(n > 10 || n < 1){
        printf("Kindly check your choice\n Exiting....");
    }
    else{
        // Step 2: Take amount input
        printf("Enter the amount: ");
        if (scanf("%f%c", &amount, &ch) == 2 && (ch == '\n')) {
            
            // Step 3: Ask for conversion type (single or multiple currencies)
            printf("You want to convert the currency to\n1. Single currency\n2. Multiple currencies\nPlease choose the index: ");
            scanf("%d", &choice);

            // ---- SINGLE CURRENCY CONVERSION ----
            if(choice == 1){
                printf("Please Choose the INDEX of the currency you want to convert in:\n");
                currencies();
                scanf("%d", &n1);

                // Convert entered currency into base Dollar value
                switch(n){
                    case 1: dollar = amount / 86.39; break;
                    case 2: dollar = amount; break;
                    case 3: dollar = amount / 0.91; break;
                    case 4: dollar = amount / 0.78; break;
                    case 5: dollar = amount / 34.91; break;
                    case 6: dollar = amount / 146.3; break;
                    case 7: dollar = amount / 3.67; break;
                    case 8: dollar = amount / 7.34; break;
                    case 9: dollar = amount / 85.85; break;
                    case 10: dollar = amount / 3.75; break;
                    default: printf("Error Please check your choice!");
                }

                // Validate target currency
                if(n1 > 10 || n1 < 1){
                    printf("Kindly check your choice\nExiting....");
                }
                else if(n == n1){
                    printf("\nThe amount is same %.2lf", amount);
                }
                else{
                    // Convert from Dollar to chosen target currency
                    switch(n1){
                        case 1: to_inr(&dollar); break;
                        case 2: printf("The converted amount in Dollar is: %.2lf", dollar); break;
                        case 3: to_euro(&dollar); break;
                        case 4: to_pounds(&dollar); break;
                        case 5: to_baht(&dollar); break;
                        case 6: to_yen(&dollar); break;
                        case 7: to_dirham(&dollar); break;
                        case 8: to_yuan(&dollar); break;
                        case 9: to_ruble(&dollar); break;
                        case 10: to_riyal(&dollar); break;
                        default: printf(" ");
                    }
                }
            }

            // ---- MULTIPLE CURRENCY CONVERSION ----
            else if(choice == 2){
                printf("Please Enter the number of currencies you want to convert: ");
                scanf("%d", &choice1);

                // Convert entered currency into Dollar first
                switch(n){
                    case 1: dollar = amount / 86.39; break;
                    case 2: dollar = amount; break;
                    case 3: dollar = amount / 0.91; break;
                    case 4: dollar = amount / 0.78; break;
                    case 5: dollar = amount / 34.91; break;
                    case 6: dollar = amount / 146.3; break;
                    case 7: dollar = amount / 3.67; break;
                    case 8: dollar = amount / 7.34; break;
                    case 9: dollar = amount / 85.85; break;
                    case 10: dollar = amount / 3.75; break;
                    default: printf("Error Please check your choice!");
                }

                // If user enters more than 9, convert into all available currencies
                if(choice1 > 9){
                    printf("Since the choice is maximum, proceeding with the conversion of all 10 currencies:\n");
                    to_inr(&dollar);
                    printf("The amount in Dollar is: %.2lf\n", dollar);
                    to_euro(&dollar);
                    to_pounds(&dollar);
                    to_baht(&dollar);
                    to_yen(&dollar);
                    to_dirham(&dollar);
                    to_yuan(&dollar);
                    to_ruble(&dollar);
                    to_riyal(&dollar);
                }
                else{
                    // Ask for specific multiple currencies
                    int curr[choice1];
                    currencies();
                    for(int i=0; i<choice1; i++){
                        printf("Enter the INDEX for currency %d: ", i+1);
                        scanf("%d", &curr[i]);
                    }

                    // Convert into all chosen currencies
                    for(int j=0; j<choice1; j++){
                        switch(curr[j]){
                            case 1: to_inr(&dollar); break;
                            case 2: printf("The amount in Dollar is: %.2lf\n", dollar); break;
                            case 3: to_euro(&dollar); break;
                            case 4: to_pounds(&dollar); break;
                            case 5: to_baht(&dollar); break;
                            case 6: to_yen(&dollar); break;
                            case 7: to_dirham(&dollar); break;
                            case 8: to_yuan(&dollar); break;
                            case 9: to_ruble(&dollar); break;
                            case 10: to_riyal(&dollar); break;
                            default: printf(" ");
                        }
                    }
                }
            }

            // Invalid option handling
            else if(choice > 2 || choice < 1){
                printf("Kindly check your choice, exiting!!");
            }
        }
        else {
            printf("Error: Input is not a valid float.\n");
        }
    }
}

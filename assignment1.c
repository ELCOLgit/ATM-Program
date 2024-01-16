/*
    Program Description: Program is made to enable the user to manage their 4 digit PIN on an ATM. This will include inputting and
    changing their PIN, viewing correct and incorrect attempts entering the PIN and gracefully ending the program.
    Author: Aileen Coliban C22304291      
    Date: 15/11/22
*/
#include <stdio.h>

int main()
{
    int pin;
    int userMenu;
    int userInput;
    int correct;
    int fail;
    int programEnd;
    int inputVer;

    pin = 1234;
    userMenu = 0;
    programEnd = 0;
    correct = 0;
    fail = 0;

    printf("\n\nWelcome to the ATM program!\n");

    do{
        //menu interface
        printf("\nTo progress enter a number out of the choices below:\n");
        printf("\n1. Enter PIN. \n");
        printf("2. Change PIN. \n");
        printf("3. View successful and unsuccessful attempts when PIN has been entered.\n");
        printf("4. Program Ends.\n\n");
        scanf("%d", &userMenu);
        printf("\n");

        switch (userMenu)
        {
            //case 1 = to input users PIN
            case 1:
            {
                printf("Enter your pin: \n");
                scanf("%d", &userInput);
                printf("\n");

                //if user input is equal to the PIN
                if(userInput == pin)
                {
                    printf("Correct PIN has been entered.\n");
                    //increment counter for correct entries
                    correct++;

                }//end if

                else
                {
                    printf("Incorrect PIN has been entered.");

                    //this validates the input and does not read the char \n
                    while (getchar() != '\n');

                    //increment counter for incorrect entries
                    fail++;
                    
                }//end else

                break;

            }//end case 1

            //case 2 = to change the users PIN
            case 2:
            {
                printf("Change PIN:\n");
                scanf("%d", &userInput);
                printf("Please verify your PIN.\n");
                scanf("%d", &inputVer);
                //this validates the input and does not read the char \n
                while (getchar() != '\n');

                //if verification input is equal to user input it will change the PIN
                if(inputVer == userInput)
                {
                    //once verified the pin is changed to the userInput
                    pin = userInput;
                    printf("\nYour PIN has successfully changed.\n");

                }//end if

                else
                {
                    printf("\nPIN does not match. \n Unsuccessfully changed.\n");

                }//end else

                break;

            }//end case 2

            //show how many times PIN was entered successfully and unsuccessfully
            case 3:
            {
                printf("\nPIN entered successfully: %d\n", correct);
                printf("PIN entered unsuccessfully: %d\n", fail);
                
                break;

            }// end case 3

            //this will end the program
            case 4:
            {
                printf("ATM program has ended.\n");

                //if 4 is inputted the 4 will go into programEnd which will make the program end since it does not equal to 0 anymore.
                programEnd = userMenu;

                break;

            }//end case 4

            default:
            {
                printf("ERROR: incorrect user input\n");

                //this validates the input and does not read the char \n
                while (getchar() != '\n');

                break;
            }

        }//end switch

    //if the programEnd is equal to 0 it will continously run
    }//do end
    while(programEnd == 0);

    return 0;
}
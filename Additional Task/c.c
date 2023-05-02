#include <stdio.h>

int main(void)
{
    int dollars=0, cent=0; //Initialize
    int check;

    do {
        printf("Please enter total value: ");
        //To assign values to the addresses of declared int variables, int check is used as a "checker", for formatting and input error checking
        check = scanf("%d.%d", &dollars, &cent);

        if (check != 2) { //checks for invalid input formatting
            puts("Program ended\n");
        }
        else if (0 > cent || 99 < cent)   { //invalid value of cent
            puts("Program ended\n");
            break;
        }
        else if (dollars < 0)   { //invalid value of dollars
            puts("Program ended\n");
            break;
        }
        else    {
            //cent = dollars*100 + cent;
            //coins(cent);
            printf("okay\n");
        }
    }   while (check == 2);

    return 0;
}



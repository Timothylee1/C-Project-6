// Upload a plain-text file with the program
#include <stdio.h> //printf, scanf

void print_line(int index, int value, int cents)
{
    if(index == 10 || index == 11){
        printf("| %-2d |         0.0%d | %5d |\n", index, value, cents);
    }
        else if(index > 6 && index < 10)
    {
        printf("| %-2d |         0.%d | %5d |\n", index, value, cents);
    }   else {
        printf("| %-2d | %9d.00 | %5d |\n", index, value, cents);
    }
    
}

void coins(int cents)
{
    int Hun=0, Fifty=0, Ten=0, Five=0, Two=0, One=0;  //Dollars 100, 50, 10, 5, 2, 1 
    int fiftyC=0, twenC=0, tenC=0, fiveC=0, oneC=0; //Cents 50, 20, 10, 5, 1
    int rem=0;

    printf("\n+----+--------------+-------+\n");
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");

    Hun = cents / 10000; // Used for counts of 10,000 cents ($100)
    rem = cents % 10000; 
    print_line(1, 100, Hun);

    Fifty = rem / 5000; // Used for counts of 5,000 cents ($50)
    rem = rem % 5000; 
    print_line(2, 50, Fifty);

    Ten = rem / 1000; // Used for counts of 1,000 cents ($10)
    rem = rem % 1000; 
    print_line(3, 10, Ten);

    Five = rem / 500; // Used for counts of 500 cents ($5)
    rem = rem % 500; 
    print_line(4, 5, Five);

    Two = rem / 200; // Used for counts of 200 cents ($2)
    rem = rem % 200; 
    print_line(5, 2, Two);

    One = rem / 100; // Used for counts of 100 cents ($1)
    rem = rem % 100; 
    print_line(6, 1, One);

    fiftyC = rem / 50; // Used for counts of 50 cents
    rem = rem % 50; 
    print_line(7, 50, fiftyC);

    twenC = rem / 20; // Used for counts of 20 cents
    rem = rem % 20; 
    print_line(8, 20, twenC);

    tenC = rem / 10; // Used for counts of 10 cents
    rem = rem % 10; 
    print_line(9, 10, tenC);

    fiveC = rem / 5; // Used for counts of 5 cents
    rem = rem % 5; 
    print_line(10, 5, fiveC);

    oneC = rem / 1; // Used for counts of 1 cents
    rem = rem % 1; 
    print_line(11, 1, oneC);

    printf("+----+--------------+-------+\n");
    
}

int main(void)
{
    printf("Please enter total value: ");
    
    int dollars=0, cent=0;
    int check = scanf("%d.%d", &dollars, &cent);
    if (0 > cent || 99 < cent)  {
        puts("The cents part specified must be between 0...99 (inclusive).");
    }   
    else if (dollars < 0)   {
        puts("The dollars part specified must be non-negative.");
    }   
    else if (check != 2)   {
        puts("You did not type in the correct format in terms of dollars and cents.");
    }    
    else if (check == 2 && (dollars == 0 && cent == 0))  {
        cent = dollars*100 + cent;
        coins(cent);
    }   
    else {
        cent = dollars*100 + cent;
        coins(cent);
    }

return 0;
}

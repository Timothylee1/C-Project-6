/*!
@file       q2.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Laboratory exercise 4
@lab        Lab 4, Task 2
@date       02/10/2021
@brief      This file contains code for sorting cash denominations, and there are three 
            functions used to constantly prompt for valid inputs, count and print; 
            print_line(), coins(), main().
            The coins() function counts the number of denominations and calls the 
            print_line() funtion. It then prints out a table after aligning and adding 
            sufficient padding.
            The main() function will keep prompting the user for valid inputs. If the 
            inputs are invalid, the program will end, and if the inputs are valid, it 
            will call the coins() function, print out a table with the appropriate 
            denominations allocations before prompting the user for another input and 
            the cycle repeats itself.
            
            For example:
            Prompt: Please enter total value: 
            Input: 12.34
            Output: 
                   +----+--------------+-------+
                   | #  | Denomination | Count |
                   +----+--------------+-------+
                   | 1  |       100.00 |     0 |
                   | 2  |        50.00 |     0 |
                   | 3  |        10.00 |     1 |
                   | 4  |         5.00 |     0 |
                   | 5  |         2.00 |     1 |
                   | 6  |         1.00 |     0 |
                   | 7  |         0.50 |     0 |
                   | 8  |         0.20 |     1 |
                   | 9  |         0.10 |     1 |
                   | 10 |         0.05 |     0 |
                   | 11 |         0.01 |     4 |
                   +----+--------------+-------+
            Prompt: Please enter total value: 
            Input: 0
            Output: Program ended

            -end of example-
*//*______________________________________________________________________________________*/
#include <stdio.h> //printf, scanf


/*!
@brief  print_line() function reads the value from coins(), and prints out the body of 
        the table. The table is separated into 3 columns, column 1 must be aligned to 
        the left with a sufficient space for 2 digits, column 2 must be aligned to the 
        right with space for 9 digits of the integer portion, which represents dollars, 
        followed with a "." and 2 decimal places representing cents. Column 3 is aligned 
        to the right space for 5 digits. All of which will include borders to separate 
        the columns

@param  index, value, cents - int data types for column 1,2,3 respectively

@return Returns nothing
*//*_______________________________________________________________________________________*/
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

/*!
@brief  coins() function reads the value from main(), and prints out the header and 
        structure of the table. The process: counting the denominations and uses modulus 
        operator to account for the remaining amount, before calling print_line() to 
        print the statement. This process is repeated till the remaining amount reaches 0 
        and the closing border is printed.

@param  Hun, Fifty, Ten, Five, Two, One - int data types for Dollars
        fiftyC, twenC, tenC, fiveC, oneC - int data types for Cents
        rem - int data type for use of modulus operator

@return Returns nothing
*//*_______________________________________________________________________________________*/
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


/*!
@brief  main() function reads the inputs from the user and verifies it. It uses a do while 
        loop, which carries out the task before checking if the task should be repeated.
        main() will prompt the user for inputs, should it be invalid, program ends and 
        breaks out of the loop, and if it is valid, the program continues and prompts for 
        another input and the task is repeated.
        A proper input would look like: 0.05 or 1.0 or 4.04 
        An inproper input would look like: x or 1.-2 or -5.2 or 5.2358 or 1

        After ensuring the input's validity, it calculates the dollars to cents and totals
        up before returning the assigned value to coins() function

@param  dollars, cent, check - int data types 

@return Returns assigned cent to coins(); returns 0 as function is declared as int
*//*_______________________________________________________________________________________*/
int main(void)
{
    int dollars=0, cent=0; //Initialize
    int check;

    do {
        printf("Please enter total value: ");
        //To assign values to the addresses of declared int variables, int check is used as a "checker", for formatting and input error checking
        check = scanf("%d.%d", &dollars, &cent);

        if (check != 2) { //checks for invalid input formatting
            puts("Program ended");
        }
        else if (0 > cent || 99 < cent)   { //invalid value of cent
            puts("Program ended");
            break;
        }
        else if (dollars < 0)   { //invalid value of dollars
            puts("Program ended");
            break;
        }
        else    {
            cent = dollars*100 + cent;
            coins(cent);
        }
    }   while (check == 2);

    return 0;
}

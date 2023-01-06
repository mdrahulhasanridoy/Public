//Assignment
//Author: Md. Rahul Hasan Ridoy
//Date: 07/01/2023
//Description: Write a C program to take current date (day, month, and year) as input and determine the next date. You should take three integers as inputs – day, month, and year. 

//Sample input (current date)             Sample output (next date)              Explanation
//Day: 12   Month: 12  Year: 2022         Day: 13   Month: 12  Year: 2022        Just increment the day variable by 1 as the day is not the last day of the month.
//Day: 30   Month: 11  Year: 2022         Day: 1   Month: 12  Year: 2022         Increment the month variable by 1 and set the day variable to 1 as the input was the last date of the month.
//Day: 31   Month: 12  Year: 2022         Day: 1   Month: 1  Year: 2023          As the date is the last date of the year, the day and month variables are set to 1 and the year is incremented by 1
//Day: 28   Month: 2   Year: 2023         Day: 1   Month: 3  Year: 2023          The input was the last date of February in a non-leap year.Therefore, the date is set to the first of the March. 
//Day: 28   Month: 2   Year: 2024         Day: 29   Month: 2  Year: 2024         The input was the 28th of February in a leap year. Therefore, the date is set by only incrementing the day variable by 1.
//Day: 34   Month: 13  Year: 24           Invalid input                          The input date is not valid.


#include<stdio.h>//header file
int main()
{
    //variable declaration
    int Day, Month, Year;//Day, Month, and Year are the variables for the day, month, and year respectively.
    printf("Day: ");//print the day
    scanf("%d", &Day);//take input of day
    printf("Month: ");//print the month
    scanf("%d", &Month);//take input of month
    printf("Year: ");//print the year
    scanf("%d", &Year);//take input of year

    //check for invalid input of day, month, and year
    if (Day < 1 || Day > 31 || Month < 1 || Month > 12 || Year < 1 || Year > 9999)//if the day is less than 1 or greater than 31 or the month is less than 1 or greater than 12 or the year is less than 1 or greater than 9999
    {
        printf("Invalid input\n");//print invalid input
        return 0;
    }
    Day++;//increment the day by 1
    if (Day > 28)//if the day is greater than 28
    {
        //check for the month of February
        if (Month == 2)
        {
            //check for leap year
            if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
            {
                if (Day > 29)
                {
                    Day = 1;
                    Month++;
                }
            }
            else
            {
                Day = 1;
                Month++;
            }
        }
        else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
        //check for the month of January, March, May, July, August, October, and December
        {
            if (Day > 31)
            {
                Day = 1;
                Month++;
            }
        }
        else
        {
            if (Day > 30)
            {
                Day = 1;
                Month++;
            }
        }
    }
    if (Month > 12)
    {
        Month = 1;
        Year++;
    }
    printf("Day: %d\n", Day);
    printf("Month: %d\n", Month);
    printf("Year: %d\n", Year);
    return 0;
}


// Input: Day: 29
//        Month: 2
//        Year: 2024
// Output: Day: 1
//         Month: 3
//         Year: 2024

// Input: Day: 31
//        Month: 12
//        Year: 2022
// Output: Day: 1
//         Month: 1
//         Year: 2023

// Input: Day: 34
//        Month: 13
//        Year: 24
// Output: Invalid input

// Input: Day: 12
//        Month: 12
//        Year: 2022
// Output: Day: 13
//         Month: 12
//         Year: 2022

// Input: Day: 30
//        Month: 11
//        Year: 2022
// Output: Day: 1
//         Month: 12
//         Year: 2022

// Input: Day: 28
//        Month: 2
//        Year: 2023
// Output: Day: 1
//         Month: 3
//         Year: 2023

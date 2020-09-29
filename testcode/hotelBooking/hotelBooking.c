#include <stdio.h>

int main(void) {
    int nights = 0;
    char arrive[15] = " ";
    char depart[15] = " ";
    double weekdays = 100.00;
    double weekends = 150.00;
    double lateCheckout = 25.00;
    double dryCleaning = 15.00;
    double poolAccess = 5.00;
    double breakfast = 10.00;
    double serviceFee = 15.00;

    printf("Welcome to Jay's hotel.\n");
    printf("Which day would you like to arrive?\n");
    scanf("%s", arrive);
    printf("Which day would you like to depart?\n");
    scanf("%s", depart);

    printf("Arrival day: %s\n", arrive);
    printf("Departure day: %s\n", depart);

    return 0;
}

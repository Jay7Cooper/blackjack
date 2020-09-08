#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player(int, int, char);
int dealer(int, int, char, int);
void choice(char, int, int, int);
int playerScore(int, int/*, int*/);
int pScore(int, int, int);
int dScore(int dealerTotal, int playerTotal, int bet, int funds);

int main(void)
{
    int bet, funds/*, win, loss, record, winStreak, playerTotal, dealerTotal*/ = 0;
    char answer = ' ';
    time_t t;
    srand((unsigned)time(&t));

    system("clear");/*Write code to clear terminal when the game starts*/
    printf("Welcome to the Blackjack table.\n");
    printf("How much would you like to deposit?\n$");
    scanf("%d", &funds);

    if (funds > 0) {
        printf("You have $%d available. How much would you like to bet?\n$", funds);
        scanf("%d", &bet);
        player(bet, funds, answer);
        /*Add code for dealer hands so it deals and then calculates who wins
        It will have to work in between player hands so you can decide whether to hit or stand, etc*/
    }
    else {
        printf("You have no money left.\n\nSecurity will now escort you out of the casino.\n\n");
    }
    return 0;
}

int player(int bet, int funds, char answer) {
    int playerTotal;
    int playerDraw1;
    int playerDraw2;
    int dealerTotal = 0;
//    char answer = ' ';
    while (bet > funds) {
        printf("Insufficient funds, please enter another amount:\n$");
        scanf("%d", &bet);
    }
    printf("Here are your cards, good luck.\n");
    playerDraw1 = rand() % 13 + 1;
    playerDraw2 = rand() % 13 + 1;

    // If both cards are a JQK or A then the system breaks
    if (playerDraw1 == 11) {
        playerTotal = playerDraw1 - 1 + playerDraw2;
        printf("J %d\n", playerDraw2);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw2 == 11) {
        playerTotal = playerDraw2 - 1 + playerDraw1;
        printf("%d J\n", playerDraw1);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw1 == 12) {
        playerTotal = playerDraw1 - 2 + playerDraw2;
        printf("Q %d\n", playerDraw2);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw2 == 12) {
        playerTotal = playerDraw2 - 2 + playerDraw1;
        printf("%d Q\n", playerDraw1);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw1 == 13) {
        playerTotal = playerDraw1 - 3 + playerDraw2;
        printf("K %d\n", playerDraw2);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw2 == 13) {
        playerTotal = playerDraw2 - 3 + playerDraw1;
        printf("%d K\n", playerDraw1);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw1 == 1) {
        if (playerDraw1 + playerDraw2 <= 10) {
            playerDraw1 = 11;
            playerTotal = playerDraw1 + playerDraw2;
            printf("A %d\n", playerDraw2);
            printf("Player total: %d\n", playerTotal);
        } else {
            playerDraw2 = 1;
            playerTotal = playerDraw1 + playerDraw2;
            printf("A %d\n", playerDraw2);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw2 == 1) {
        if (playerDraw1 + playerDraw2 <= 10) {
            playerDraw2 = 11;
            playerTotal = playerDraw1 + playerDraw2;
            printf("%d A\n", playerDraw1);
            printf("Player total: %d\n", playerTotal);
        } else {
            playerDraw2 = 1;
            playerTotal = playerDraw1 + playerDraw2;
            printf("%d A\n", playerDraw1);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else {
        printf("%d %d\n", playerDraw1, playerDraw2);
        playerTotal = playerDraw1 + playerDraw2;
        printf("Player total: %d\n", playerTotal);
    }
    dealer(playerTotal, dealerTotal, answer, funds);
}

void choice(char answer, int playerTotal, int bet, int funds) {
    int pTotal = playerTotal;
    int newPlayerCard;
    time_t t;
    srand((unsigned)time(&t));

    switch(answer) {
        case 'H':
        case 'h':
            newPlayerCard = rand() % 13 + 1;
            if (newPlayerCard == 11) {
                printf("J\n");
                newPlayerCard = 10;
                pScore(playerTotal, /*dealerTotal,*/bet, funds);
                //Call needed to function saying < or > 21. Repeat for Q, K, etc
            }
            else if (newPlayerCard == 12) {
                printf("Q\n");
                newPlayerCard = 10;
            }
            else if (newPlayerCard == 13) {
                printf("K\n");
                newPlayerCard = 10;
            }
            else if (newPlayerCard == 1 && pTotal <= 10) {
                printf("A\n");
                newPlayerCard = 11;
                //revert 11 to 1 if total > 21
            }
            else if (newPlayerCard == 1 && pTotal > 10) {
                printf("A\n");
                newPlayerCard = 1;
                //revert 11 to 1 if total > 21
            }
//                if (playerDraw1 + playerDraw2 <= 10) {
//                    playerDraw2 = 11;
//                    playerTotal = playerDraw1 + playerDraw2;
//                    printf("%d A\n", playerDraw1);
//                } else {
//                    playerDraw2 = 1;
//                    playerTotal = playerDraw1 + playerDraw2;
//                    printf("%d A\n", playerDraw1);
//                }
                // add code for 1 or 11
                // see line 136
                // if more than one Ace, all other aces count as 1
                // If an Ace is eleven but you draw over 21, it reverts back to 1


            else {
                printf("%d\n", newPlayerCard);
            }
            pTotal += newPlayerCard;
            printf("Player Total: %d\n", pTotal);

        case 'S':
        case 's':
            // Add code to go to dealers draw function
            break;

//        default:
//            printf("Pay attention. Would you like to (H)it, (S)tand, S(P)lit, or (D)ouble Down?\n");
//            break;
    }
}

int dealer(int playerTotal, int dealerTotal, char answer, int funds) {
    int dTotal = dealerTotal;
    int dealerDraw1;
    int dealerDraw2 = 0;

//    while (bet > funds) {
//        printf("Insufficient funds, please enter another amount:\n$");
//        scanf("%d", &bet);
//    }
    printf("\nDealers cards are:\n");
    dealerDraw1 = rand() % 13 + 1;
//    choice(answer, );
//    dealerDraw2 = rand() % 13 + 1;

    // If both cards are a JQK or A then the system breaks
    if (dealerDraw1 == 11) {
        dealerTotal = dealerDraw1 - 1 + dealerDraw2;
        printf("J %d\n", dealerDraw2);
        printf("Dealer total: %d\n", dealerTotal);
    }
    //*** This won't be used until the dealer draws the second card ***
//    else if (dealerDraw2 == 11) {
//        dealerTotal = dealerDraw2 - 1 + dealerDraw1;
//        printf("%d J\n", dealerDraw1);
//        printf("Dealer total: %d\n", dealerTotal);
//    }
    else if (dealerDraw1 == 12) {
        dealerTotal = dealerDraw1 - 2 + dealerDraw2;
        printf("Q %d\n", dealerDraw2);
        printf("Dealer total: %d\n", dealerTotal);
    }
        //*** This won't be used until the dealer draws the second card ***
//    else if (dealerDraw2 == 12) {
//        dealerDraw2 = 10 + dealerDraw2;
//        //dealerDraw2 = 10;
//        printf("%d Q\n", dealerDraw1);
//        printf("Dealer total: %d\n", dealerTotal);
//    }
    else if (dealerDraw1 == 13) {
        dealerTotal = dealerDraw1 - 3 + dealerDraw2;
        printf("K %d\n", dealerDraw2);
        printf("Dealer total: %d\n", dealerTotal);
    }
        //*** This won't be used until the dealer draws the second card ***
//    else if (dealerDraw2 == 13) {
//        dealerDraw2 = 10 + dealerDraw2;
//        //dealerDraw2 = 10;
//        printf("%d K\n", dealerDraw1);
//        printf("Dealer total: %d\n", dealerTotal);
//    }
    else if (dealerDraw1 == 1) {
        if (dealerDraw1 + dealerDraw2 <= 10) {
            dealerDraw1 = 11;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Dealer total: %d\n", dealerTotal);
        } else {
            dealerDraw2 = 1;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
        //*** This won't be used until the dealer draws the second card ***
//    else if (dealerDraw2 == 1) {
//        if (dealerDraw1 + dealerDraw2 <= 10) {
//            dealerDraw2 = 11;
//            dealerTotal = dealerDraw1 + dealerDraw2;
//            printf("%d A\n", dealerDraw1);
//            printf("Dealer total: %d\n", dealerTotal);
//        } else {
//            dealerDraw2 = 1;
//            dealerTotal = dealerDraw1 + dealerDraw2;
//            printf("%d A\n", dealerDraw1);
//            printf("Dealer total: %d\n", dealerTotal);
//        }
//    }
    else {
//        printf("%d %d\n", dealerDraw1, dealerDraw2);
        printf("%d \n", dealerDraw1);
        dealerTotal = dealerDraw1 /* + dealerDraw2*/;
        printf("Dealer total: %d\n", dealerTotal);
    }
    choice(answer, playerTotal, dealerTotal, funds);
}

int pScore(int playerTotal, /*int dealerTotal,*/int bet, int funds)
{
    char answer = ' ';

    //Put this in a separate function to make it repeat if under 21
    if (playerTotal > 21) {
        printf("%d\n", playerTotal);
        printf("You've busted. Thank you for playing\n");
        funds = funds - bet;
    } else if (playerTotal == 21) {
        printf("Congratulations!\n");
        //insert code for comparing to dealer hand
        //insert code for calculating win loss amount
        //Don't forget win amount for blackjack hand
    } else {
        printf("Would you like to (H)it, (S)tand, S(P)lit, or (D)ouble Down?\n");
        scanf(" %c", &answer);
        choice(answer, playerTotal, bet, funds);
    }
    if (funds == 0) {
        printf("You are out of funds.\nSecurity will now escort you out of the casino.\n");
        printf("Thank you for playing!\n");
        //break;
    }
    return funds;
}

int dScore(int dealerTotal, int playerTotal, int bet, int funds)
{
    if (dealerTotal > 21)
    {
        printf("Dealer busted. Congratulations");
        playerTotal = bet * 2 + funds;
    }
    else if (dealerTotal < 17)
    {
        
    }
}
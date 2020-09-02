#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <time.h>

int player(int, int);
void choice(char, int, int);
int score(int, int, int);

int main(void)
{
    int bet, funds/*, win, loss, record, winStreak, playerTotal, dealerTotal*/ = 0;    
    time_t t;
    srand((unsigned)time(&t));

    /*Write code to clear terminal when the game starts*/
    printf("Welcome to the Blackjack table.\n");
    printf("How much would you like to deposit?\n$");
    scanf("%d", &funds);

    if (funds > 0) {
        printf("You have $%d available. How much would you like to bet?\n$", funds);
        scanf("%d", &bet);
        player(bet, funds);
        /*Add code for dealer hands so it deals and then calculates who wins
        It will have to work in between player hands so you can decide whether to hit or stand, etc*/
    }
    else {
        printf("You have no money left.\n\nSecurity will now escort you out of the casino.\n\n");
    }
    return 0;
}

void choice(char answer, int playerTotal, int funds) {
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
                score(playerTotal, dealerTotal, funds);
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
            }
            else if (newPlayerCard == 1 && pTotal > 10) {
                printf("A\n");
                newPlayerCard = 1;
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

        default:
            printf("Pay attention. Would you like to (H)it, (S)tand, S(P)lit, or (D)ouble Down?\n");
            break;
    }
}

int player(int bet, int funds) {
    int playerTotal;
    int playerDraw1;
    int playerDraw2;
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
        playerTotal = 10 + playerDraw2;
        // playerDraw1 = 10;
        printf("J %d\n", playerDraw2);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw2 == 11) {
        playerTotal = 10 + playerDraw1;
        //playerDraw2 = 10;
        printf("%d J\n", playerDraw1);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw1 == 12) {
        playerTotal = 10 + playerDraw1;
        //playerDraw1 = 10;
        printf("Q %d\n", playerDraw2);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw2 == 12) {
        playerTotal = 10 + playerDraw2;
        //playerDraw2 = 10;
        printf("%d Q\n", playerDraw1);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw1 == 13) {
        playerTotal = 10 + playerDraw1;
        //playerDraw1 = 10;
        printf("K %d\n", playerDraw2);
        printf("Player total: %d\n", playerTotal);
    }
    else if (playerDraw2 == 13) {
        playerTotal = 10 + playerDraw2;
        //playerDraw2 = 10;
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
}

int dealer(int bet, int funds) { //*** bet and funds shouldn't be in this function, replace them with something else like dealerTotal, etc***
    int dealerTotal;
    int dealerDraw1;
    int dealerDraw2;
//    char answer = ' ';

//    while (bet > funds) {
//        printf("Insufficient funds, please enter another amount:\n$");
//        scanf("%d", &bet);
//    }
    printf("Here are your cards, good luck.\n");
    dealerDraw1 = rand() % 13 + 1;
    dealerDraw2 = rand() % 13 + 1;

    // If both cards are a JQK or A then the system breaks
    if (dealerDraw1 == 11) {
        dealerTotal = 10 + dealerDraw2;
        // playerDraw1 = 10;
        printf("J %d\n", dealerDraw2);
        printf("Player total: %d\n", dealerTotal);
    }
    else if (dealerDraw2 == 11) {
        dealerTotal = 10 + dealerDraw1;
        //dealerDraw2 = 10;
        printf("%d J\n", dealerDraw1);
        printf("Player total: %d\n", dealerTotal);
    }
    else if (dealerDraw1 == 12) {
        dealerTotal = 10 + dealerDraw1;
        //dealerDraw1 = 10;
        printf("Q %d\n", dealerDraw2);
        printf("Player total: %d\n", dealerTotal);
    }
    else if (dealerDraw2 == 12) {
        dealerTotal = 10 + dealerDraw2;
        //dealerDraw2 = 10;
        printf("%d Q\n", dealerDraw1);
        printf("Player total: %d\n", dealerTotal);
    }
    else if (dealerDraw1 == 13) {
        dealerTotal = 10 + dealerDraw1;
        //dealerDraw1 = 10;
        printf("K %d\n", dealerDraw2);
        printf("Player total: %d\n", dealerTotal);
    }
    else if (dealerDraw2 == 13) {
        dealerTotal = 10 + dealerDraw2;
        //dealerDraw2 = 10;
        printf("%d K\n", dealerDraw1);
        printf("Player total: %d\n", dealerTotal);
    }
    else if (dealerDraw1 == 1) {
        if (dealerDraw1 + dealerDraw2 <= 10) {
            dealerDraw1 = 11;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Player total: %d\n", dealerTotal);
        } else {
            dealerDraw2 = 1;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 1) {
        if (dealerDraw1 + dealerDraw2 <= 10) {
            dealerDraw2 = 11;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("%d A\n", dealerDraw1);
            printf("Player total: %d\n", dealerTotal);
        } else {
            dealerDraw2 = 1;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("%d A\n", dealerDraw1);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else {
        printf("%d %d\n", dealerDraw1, dealerDraw2);
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Player total: %d\n", dealerTotal);
    }
}



int score(int playerTotal, int dealerTotal, int funds)
{
//    int playerTotal;
    char answer = ' ';
//    int funds;

    //Put this in a separate function to make it repeat if under 21
    if (playerTotal > 21) {
        printf("%d\n", playerTotal);
        printf("You've busted. Thank you for playing\n");
    } else if (playerTotal == 21) {
        printf("Congratulations!\n");
    } else {
        printf("Would you like to (H)it, (S)tand, S(P)lit, or (D)ouble Down?\n");
        scanf(" %c", &answer);
        choice(answer, playerTotal, funds);
    }
    if (funds == 0) {
        printf("You are out of funds.\nSecurity will now escort you out of the casino.\n");
        printf("Thank you for playing!\n");
        //break;
    }
    return funds;
}

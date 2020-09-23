#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*** make sure to add return types to each function ***
double betting(double, double); //return bet and funds
int player(); //return only playerTotal
int dealer(); //return only dealerTotal
int choice(int);
int playerScore(int, int, int); //feed only playerTotal and then transfer to compareScore
double dealerScore(double, double, double, double); //feed only dealerTotal and then transfer to compareScore
int compareScore(int, int); //feed playerTotal and dealerTotal in and then feed score back to main
double playAgainOrQuit(double, double);

int main() {
    double funds, bet = 0.0;
    int playerTotal = 0;
    int playerTotal2 = 0;
    int dealerTotal = 0; //add variables later for wins, losses, record, winStreak
    time_t t;
    srand((unsigned)time(&t));
    system("clear");
    printf("Welcome to the Blackjack table.\n");
    printf("How much would you like to deposit?\n$");
    scanf("%lf", &funds);
    funds = betting(funds, bet); // make pointers
    playerTotal = player(); // This is calculating the playerTotal
    dealerTotal = dealer(); // This is calculating the dealerTotal
    printf("\nYou have $%.2lf in funds\n", funds);
//    choice(playerTotal);
    playerScore(playerTotal, playerTotal2, dealerTotal);
    playerTotal += playerTotal2;
    printf("Player total: %d\n", playerTotal);
    playAgainOrQuit(funds, bet);
//    playerTotal;
    return 0;
}

double betting(double funds, double bet) {
    printf("How much would you like to bet?\n$");
    scanf("%lf", &bet);
    if (bet > funds) {
        printf("Insufficient funds. Please enter another amount:\n$");
        scanf("%lf", &bet);
    }
    funds = funds - bet;

    return funds; //??? I'm returning it to main but where does it go?
//    playAgainOrQuit();
//Put calculation of playerTotal and dealerTotal here?
//compareScore(playerTotal, dealerTotal); Put this at the end of dealer function?
//calculate whether win or loss, then print the result

}

int player() {
    int playerDraw1, playerDraw2, playerTotal;

    printf("Here are your cards, good luck\n");
    //Don't forget to change the draw cards back to random numbers
//    char jack = 'J';
//    char queen = 'Q';
//    char king = 'K';
//    char ace = 'A';
    playerDraw1 = rand() % 13 + 1;
    playerDraw2 = rand() % 13 + 1;
//    playerDraw1 = 13;
//    playerDraw2 = 1;
    //MOVE HALF OF THE CODE INTO A SEPARATE FUNCTION, MAYBE EVEN HAVE EACH RANDOM DRAW IN A SEPARATE FUNCTION
    //Put the calculations of cards in a separate function so it re-uses code in choice function?
    if (playerDraw1 == 1 && playerDraw2 == 1) {
        printf("A A\n");
        playerDraw1 = 1;
        playerDraw2 = 1;
        playerTotal = playerDraw1 + playerDraw2;
        printf("Player total: %d\n", playerTotal);
        //Ask whether player wants to count 1 Ace as 11 for a total of 12? (probably not though)
        //Goto split function, it may have to be in a separate function
    }
    else if (playerDraw1 == 11 && playerDraw2 == 11) {
        printf("J J\n");
        playerDraw1 = 10;
        playerDraw2 = 10;
        playerTotal = playerDraw1 + playerDraw2;
        printf("Player total: %d\n", playerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (playerDraw1 == 12 && playerDraw2 == 12) {
        printf("Q Q\n");
        playerDraw1 = 10;
        playerDraw2 = 10;
        playerTotal = playerDraw1 + playerDraw2;
        printf("Player total: %d\n", playerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (playerDraw1 == 13 && playerDraw2 == 13) {
        printf("K K\n");
        playerDraw1 = 10;
        playerDraw2 = 10;
        playerTotal = playerDraw1 + playerDraw2;
        printf("Player total: %d\n", playerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (playerDraw1 == 11) {
        if (playerDraw2 == 1) {
            playerDraw2 = 11;
            playerDraw1 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("J A\n");
            printf("Player total: %d\n", playerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else if (playerDraw2 == 12) {
            playerDraw1 = 10;
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("J Q\n");
            printf("Player total: %d\n", playerTotal);
        }
        else if (playerDraw2 == 13) {
            playerDraw1 = 10;
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("J K\n");
            printf("Player total: %d\n", playerTotal);
        }
        else {
            playerDraw1 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("J %d\n", playerDraw2);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw2 == 11) {
        if (playerDraw1 == 1) {
            playerDraw1 = 11;
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("A J\n");
            printf("Player total: %d\n", playerTotal);
            //go to BLACKJACK winning function
        }
        else if (playerDraw1 == 12) {
            playerDraw1 = 10;
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("Q J\n");
            printf("Player total: %d\n", playerTotal);
        }
        else if (playerDraw1 == 13) {
            playerDraw1 = 10;
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("K J\n");
            printf("Player total: %d\n", playerTotal);
        }
        else {
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("%d J\n", playerDraw1);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw1 == 12) {
        if (playerDraw2 == 1) {
            playerDraw2 = 11;
            playerDraw1 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("Q A\n");
            printf("Player total: %d\n", playerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else {
            playerDraw1 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("J %d\n", playerDraw2);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw2 == 12) {
        if (playerDraw1 == 1) {
            playerDraw1 = 11;
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("Q A\n");
            printf("Player total: %d\n", playerTotal);
        }
        else {
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("%d Q\n", playerDraw1);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw1 == 13) {
        if (playerDraw2 == 1) {
            playerDraw2 = 11;
            playerDraw1 = 10;
            playerTotal = playerDraw1 + playerDraw2;
            printf("K A\n");
            printf("Player total: %d\n", playerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else {
            playerDraw1 = 10;
            playerTotal = playerDraw1 + playerDraw2;
            printf("K %d\n", playerDraw2);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw2 == 13) {
        if (playerDraw1 == 1) {
            playerDraw1 = 11;
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("A K\n");
            printf("Player total: %d\n", playerTotal);
            //go to BLACKJACK winning function
        }
        else {
            playerDraw2 = 10;
            playerTotal = playerDraw2 + playerDraw1;
            printf("%d K\n", playerDraw1);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw1 == 1) {
        if (playerDraw1 + playerDraw2 <= 11) {
            playerDraw1 = 11;
            playerTotal = playerDraw1 + playerDraw2;
            printf("A %d\n", playerDraw2);
            printf("Player total: %d\n", playerTotal);
        }
        else {
            playerDraw1 = 1;
            playerTotal = playerDraw1 + playerDraw2;
            printf("A %d\n", playerDraw2);
            printf("Player total: %d\n", playerTotal);
        }
    }
    else if (playerDraw2 == 1) {
        if (playerDraw1 + playerDraw2 <= 11) {
            playerDraw2 = 11;
            playerTotal = playerDraw1 + playerDraw2;
            printf("%d A\n", playerDraw1);
            printf("Player total: %d\n", playerTotal);
        }
        else {
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
    return playerTotal;
}

int dealer() {
    int dealerDraw1, dealerDraw2, dealerTotal;

    printf("\nDealer cards are:\n");
    dealerDraw1 = rand() % 13 + 1;
    dealerDraw2 = rand() % 13 + 1;
//    dealerDraw1 = 12;
//    dealerDraw2 = 1;

    if (dealerDraw1 == 1 && dealerDraw2 == 1) {
        printf("A A\n");
        dealerDraw1 = 1;
        dealerDraw2 = 1;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Dealer total: %d\n", dealerTotal);
        //Ask whether player wants to count 1 Ace as 11 for a total of 12? (probably not though)
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 11 && dealerDraw2 == 11) {
        printf("J J\n");
        dealerDraw1 = 10;
        dealerDraw2 = 10;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Dealer total: %d\n", dealerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 12 && dealerDraw2 == 12) {
        printf("Q Q\n");
        dealerDraw1 = 10;
        dealerDraw2 = 10;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Dealer total: %d\n", dealerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 13 && dealerDraw2 == 13) {
        printf("K K\n");
        dealerDraw1 = 10;
        dealerDraw2 = 10;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Dealer total: %d\n", dealerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 11) {
        if (dealerDraw2 == 1) {
            dealerDraw2 = 11;
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J A\n");
            printf("Dealer total: %d\n", dealerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else if (dealerDraw2 == 12) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J Q\n");
            printf("Dealer total: %d\n", dealerTotal);
        }
        else if (dealerDraw2 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J K\n");
            printf("Dealer total: %d\n", dealerTotal);
        }
        else {
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J %d\n", dealerDraw2);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 11) {
        if (dealerDraw1 == 1) {
            dealerDraw1 = 11;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("A J\n");
            printf("Dealer total: %d\n", dealerTotal);
            //go to BLACKJACK winning function
        }
        else if (dealerDraw1 == 12) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q J\n");
            printf("Dealer total: %d\n", dealerTotal);
        }
        else if (dealerDraw1 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("K J\n");
            printf("Dealer total: %d\n", dealerTotal);
        }
        else {
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("%d J\n", dealerDraw1);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw1 == 12) {
        if (dealerDraw2 == 1) {
            dealerDraw2 = 11;
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q A\n");
            printf("Dealer total: %d\n", dealerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else if (dealerDraw2 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q K\n");
            printf("Dealer total: %d\n", dealerTotal);
        }
        else {
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J %d\n", dealerDraw2);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 12) {
        if (dealerDraw1 == 1) {
            dealerDraw1 = 11;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q A\n");
            printf("Dealer total: %d\n", dealerTotal);
        }
        else if (dealerDraw1 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("K Q\n");
            printf("Dealer total: %d\n", dealerTotal);
        }
        else {
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("%d Q\n", dealerDraw1);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw1 == 13) {
        if (dealerDraw2 == 1) {
            dealerDraw2 = 11;
            dealerDraw1 = 10;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("K A\n");
            printf("Dealer total: %d\n", dealerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else {
            dealerDraw1 = 10;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("K %d\n", dealerDraw2);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 13) {
        if (dealerDraw1 == 1) {
            dealerDraw1 = 11;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("A K\n");
            printf("Dealer total: %d\n", dealerTotal);
            //go to BLACKJACK winning function
        }
        else {
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("%d K\n", dealerDraw1);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw1 == 1) {
        if (dealerDraw1 + dealerDraw2 <= 11) {
            dealerDraw1 = 11;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Dealer total: %d\n", dealerTotal);
        }
        else {
            dealerDraw1 = 1;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 1) {
        if (dealerDraw1 + dealerDraw2 <= 11) {
            dealerDraw2 = 11;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("%d A\n", dealerDraw1);
            printf("Dealer total: %d\n", dealerTotal);
        }
        else {
            dealerDraw2 = 1;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("%d A\n", dealerDraw1);
            printf("Dealer total: %d\n", dealerTotal);
        }
    }
    else {
        printf("%d %d\n", dealerDraw1, dealerDraw2);
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Dealer total: %d\n", dealerTotal);
    }
    return dealerTotal;

//    dealerScore(playerTotal, dealerTotal, bet, funds); // fix last two variables (bet, funds) that turn red
}

int playerScore(int playerTotal, int playerTotal2, int dealerTotal) {
    if (playerTotal == 21 && dealerTotal == 21) {
        printf("Push. No one wins");
        //money goes back to the player
    }
    else if (playerTotal == 21 && dealerTotal < 21) {
        //compare to dealer total and see who wins, may need a separate function for a 3rd dealer card
        //If dealer has less that 17 then they will draw another card
        //dealer only gets one more card after player gets blackjack
    }
    else if (playerTotal == 21 && dealerTotal > 21) {
        printf("Congratulations, you win.\n");
        //calculate playerTotal and then ask if they want to play again
    }
    else {
        choice(playerTotal);
    }
    return playerTotal;
}

int choice(int playerTotal) { //add dealerTotal into function header, and look at last line of each code block
    int playerDraw3;
    char answer = ' ';

    printf("\nWould you like to (H)it, (S)tand, S(p)lit, (D)ouble Down, or S(t)ay?\n");
    scanf(" %c", &answer);

    switch(answer) {
        case 'H': case 'h':
            playerDraw3 = rand() % 13 + 1;
            if (playerDraw3 == 1 && playerTotal <= 10) {
                printf("A\n");
                playerDraw3 = 11;
                playerTotal += playerDraw3;
                //playerScore(); ???
                //Print playerTotal but also print previous cards if possible
            }
            else if (playerDraw3 == 1 && playerTotal >= 11) {
                printf("A\n");
                playerDraw3 = 1;
                playerTotal += playerDraw3;
                //playerScore(); ???
                //Print playerTotal but also print previous cards if possible
            }
            else if (playerDraw3 == 11) { // finish adding J, Q, K
                printf("J\n");
                playerDraw3 = 10;
                playerTotal += playerDraw3;
                //playerScore(); ???
                //Print playerTotal but also print previous cards if possible
            }
            else if (playerDraw3 == 12) {
                printf("Q\n");
                playerDraw3 = 10;
                playerTotal += playerDraw3;
                //playerScore(); ???
                //Print playerTotal but also print previous cards if possible
            }
            else if (playerDraw3 == 13) {
                printf("K\n");
                playerDraw3 = 10;
                playerTotal += playerDraw3;
                //playerScore(); ???
                //Print playerTotal but also print previous cards if possible
            }
            else {
                printf("\n%d\n", playerDraw3);
                playerTotal += playerDraw3;
                //playerScore(); ???
                //Print playerTotal but also print previous cards if possible
            }
        case 'S': case 's': //This means Stand! Not Split!
            //add dealerScore comparison so you know who wins

            //Don't forget that splitting doubles the bet
            //dealer();//determine what to do here, this is wrong
        default: ;
    }
    return playerTotal;
}

double dealerScore(double playerTotal, double dealerTotal, double bet, double funds) {
    int dealerDraw3;
    if (dealerTotal < 17) {
        dealerDraw3 = rand() % 13 + 1;
        dealerTotal += dealerDraw3;
    }
    else if (dealerTotal > 21 && playerTotal == 21) {
        printf("\nDealer busted and you got Blackjack!\n");
        funds = funds + (bet * 1.5); // Put this line in another function
//        playAgainOrQuit();
    }
    else if (dealerTotal > 21) {
        printf("\nDealer busted. Congratulations.\n");
        funds = funds + bet;
//        playAgainOrQuit();
    }
    return playerTotal;
//    return dealerTotal; //can only return one thing
//    return bet;
//    return funds;
}

int compareScore(int playerScore, int dealerScore) {

}

double playAgainOrQuit(double funds, double bet) {
    char decision = ' ';
    printf("Would you like to play again? (Y/N)\n");
    scanf("%c", &decision);

    switch (decision) {
        case 'Y':
        case 'y':
            if (funds > 0) {
                betting(funds, bet);
            } else {
                printf("You have no money left, please wait for Security to escort you from the casino");
            }
        case 'N':
        case 'n':
            printf("Thank you for playing, your winnings are: $%.2lf\n", funds);
    }
}

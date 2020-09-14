#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int betting(int, int);
void player();
void dealer(int, int);
int compareScore(int, int);
int choice(int);
void playerScore(int, int);
void dealerScore(int);
void playAgainOrQuit();

int main() {
    int funds, bet;
    int playerTotal = 0;
    int dealerTotal = 0; //add variables later for wins, losses, record, winStreak
    time_t t;
    srand((unsigned)time(&t));
    system("clear");
    printf("Welcome to the Blackjack table.\n");
    printf("How much would you like to deposit?\n$");
    scanf("%d", &funds);

    betting(bet, funds);
    player();
    dealer(playerTotal, dealerTotal);
    //compareScore(playerTotal, dealerTotal); //Put this at the end of dealer function?
    return 0;
}

int betting(int bet, int funds) {
    printf("How much would you like to bet?\n$");
    scanf("%d", &bet);
    if (bet > funds) {
        printf("Insufficient funds. Please enter another amount:\n$");
        scanf("%d", &bet);
    }
//  funds = funds - bet;
    return bet;
}

void player() {
    int playerDraw1, playerDraw2, playerTotal;

    printf("Here are your cards, good luck\n");
    //Don't forget to change the draw cards back to random numbers
    char jack = 'J';
    char queen = 'Q';
    char king = 'K';
    char ace = 'A';
    playerDraw1 = rand() % 13 + 1;
    playerDraw2 = rand() % 13 + 1;
//    playerDraw1 = 13;
//    playerDraw2 = 11;
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
}

void dealer(int playerTotal, int dealerTotal) {
    int dealerDraw1, dealerDraw2;

    printf("\nDealer cards are:\n");
    dealerDraw1 = rand() % 13 + 1;
    dealerDraw2 = rand() % 13 + 1;
//    dealerDraw1 = 12;
//    dealerDraw2 = 11;

    if (dealerDraw1 == 1 && dealerDraw2 == 1) {
        printf("A A\n");
        dealerDraw1 = 1;
        dealerDraw2 = 1;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Player total: %d\n", dealerTotal);
        //Ask whether player wants to count 1 Ace as 11 for a total of 12? (probably not though)
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 11 && dealerDraw2 == 11) {
        printf("J J\n");
        dealerDraw1 = 10;
        dealerDraw2 = 10;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Player total: %d\n", dealerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 12 && dealerDraw2 == 12) {
        printf("Q Q\n");
        dealerDraw1 = 10;
        dealerDraw2 = 10;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Player total: %d\n", dealerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 13 && dealerDraw2 == 13) {
        printf("K K\n");
        dealerDraw1 = 10;
        dealerDraw2 = 10;
        dealerTotal = dealerDraw1 + dealerDraw2;
        printf("Player total: %d\n", dealerTotal);
        //Goto split function, it may have to be in a separate function
    }
    else if (dealerDraw1 == 11) {
        if (dealerDraw2 == 1) {
            dealerDraw2 = 11;
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J A\n");
            printf("Player total: %d\n", dealerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else if (dealerDraw2 == 12) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J Q\n");
            printf("Player total: %d\n", dealerTotal);
        }
        else if (dealerDraw2 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J K\n");
            printf("Player total: %d\n", dealerTotal);
        }
        else {
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J %d\n", dealerDraw2);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 11) {
        if (dealerDraw1 == 1) {
            dealerDraw1 = 11;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("A J\n");
            printf("Player total: %d\n", dealerTotal);
            //go to BLACKJACK winning function
        }
        else if (dealerDraw1 == 12) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q J\n");
            printf("Player total: %d\n", dealerTotal);
        }
        else if (dealerDraw1 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("K J\n");
            printf("Player total: %d\n", dealerTotal);
        }
        else {
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("%d J\n", dealerDraw1);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw1 == 12) {
        if (dealerDraw2 == 1) {
            dealerDraw2 = 11;
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q A\n");
            printf("Player total: %d\n", dealerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else if (dealerDraw2 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q K\n");
            printf("Player total: %d\n", dealerTotal);
        }
        else {
            dealerDraw1 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("J %d\n", dealerDraw2);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 12) {
        if (dealerDraw1 == 1) {
            dealerDraw1 = 11;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("Q A\n");
            printf("Player total: %d\n", dealerTotal);
        }
        else if (dealerDraw1 == 13) {
            dealerDraw1 = 10;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("K Q\n");
            printf("Player total: %d\n", dealerTotal);
        }
        else {
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("%d Q\n", dealerDraw1);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw1 == 13) {
        if (dealerDraw2 == 1) {
            dealerDraw2 = 11;
            dealerDraw1 = 10;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("K A\n");
            printf("Player total: %d\n", dealerTotal);
            //go to BLACKJACK winning function, which may be the playerScore function
        }
        else {
            dealerDraw1 = 10;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("K %d\n", dealerDraw2);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 13) {
        if (dealerDraw1 == 1) {
            dealerDraw1 = 11;
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("A K\n");
            printf("Player total: %d\n", dealerTotal);
            //go to BLACKJACK winning function
        }
        else {
            dealerDraw2 = 10;
            dealerTotal = dealerDraw2 + dealerDraw1;
            printf("%d K\n", dealerDraw1);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw1 == 1) {
        if (dealerDraw1 + dealerDraw2 <= 11) {
            dealerDraw1 = 11;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Player total: %d\n", dealerTotal);
        }
        else {
            dealerDraw1 = 1;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("A %d\n", dealerDraw2);
            printf("Player total: %d\n", dealerTotal);
        }
    }
    else if (dealerDraw2 == 1) {
        if (dealerDraw1 + dealerDraw2 <= 11) {
            dealerDraw2 = 11;
            dealerTotal = dealerDraw1 + dealerDraw2;
            printf("%d A\n", dealerDraw1);
            printf("Player total: %d\n", dealerTotal);
        }
        else {
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
    playerScore(playerTotal, dealerTotal);
    dealerScore(dealerTotal);
}

void playerScore(int playerTotal, int dealerTotal) {
    if (playerTotal < 21) {
        choice(playerTotal);
    }
    else if (playerTotal == 21) {
        //compare to dealer total and see who wins
    }
}

void dealerScore(int dealerTotal) {
        int dealerDraw3;
        if (dealerTotal < 17) {
            dealerDraw3 = rand() % 13 + 1;
            dealerTotal += dealerDraw3;
        }
        else if (dealerTotal > 21) {
            printf("\nDealer busted. Congratulations.\n");
            playAgainOrQuit();
        }
}



int choice(int playerTotal) {
    int playerDraw3;
    char answer = ' ';

    printf("\nWould you like to (H)it, (S)tand, (D)ouble Down, S(t)ay?\n");
    scanf("%c", &answer);

    switch(answer) {
        case 'H':
        case 'h':
            playerDraw3 = rand() % 13 + 1;
            if (playerDraw3 == 1 && playerTotal <= 10) {
                printf("A\n");
                playerDraw3 = 11;
                playerTotal += playerDraw3;
            }
            else {
                printf("A\n");
                playerDraw3 = 1;
                playerTotal += playerDraw3;
            }
//        case 'S':
//        case 's':
            //dealer();//determine what to do here, this is wrong
    }
    return playerTotal;
}

void playAgainOrQuit() {
            

}
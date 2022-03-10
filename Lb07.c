/*****+---*--*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Lab #:07
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Program Description: Plays a game of blackjack depending on user inputted seed
*
******+---*--*--**-*---**-****-**-*--*-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 52 // the max number of cards in a deck 
#define MIN 1 // the minimum number of cards in a deck

//function declaration
int generateRandom(void);
int input(void);

void playGame(int score, int numberCards, int numberOfAce);
int findCard(int random);

void printResults(int score);
int cardValue(int rand, int cardNumber, int *numberOfAce);

void outputCardNumber(int rand, int cardNumber);
void outputScore(int score);

int main(void) 
{
  //variable declaration
  int score; //score of the dealer
  int numberOfAce = 0; //number of aces
  
  //function call
  srand(input());
  score = cardValue(generateRandom(), 1, &numberOfAce);
  outputScore(score);
  
  score = score + cardValue(generateRandom(), 2, &numberOfAce);
  outputScore(score);
  playGame(score, 2, numberOfAce);
  
  return 0;
}
/*****+------*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int score - score of dealer
*   
*  Function Description: Prins the results of the dealer
*
******+------*--**-*---**-****-**-*--*-*-*-**-*****************************/
void printResults(score)
{
  if (score > 21)
  {
    printf("\nDealer busts.\n");
  }
    
  else if (score == 21)
  {
    printf("\nDealer wins!\n");
  }
    
  else
  {
    printf("\nDealer holds.\n");  
  }
}
/*****+------*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: playGame
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int score - current score of dealer
*  2. int numberCards - number of cards that have been drawn
*   
*  Function Description: Plays the game of blackjack
*
******+------*--**-*---**-****-**-*--*-*-*-**-*****************************/
void playGame(int score, int numberCards, int numberOfAce)
{ 
  if (score >= 16 || numberCards >= 5)
  {
    printResults(score); 
    return;
  }
    
  else 
  { 
    numberCards = numberCards + 1;
    score = score + cardValue(generateRandom(), numberCards, &numberOfAce); 
    
    if(numberOfAce > 1 && score > 21)
    {
      score -= 10;
    }
    
    outputScore(score);
    playGame(score, numberCards, numberOfAce);
  }
}
/*****+------*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: input
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): 
*   
*  Function Description: Gets seed from user
*
******+------*--**-*---**-****-**-*--*-*-*-**-*****************************/
int input(void)
{
  int input; //input from user
  printf("Enter the seed value -> ");
  scanf("%d", &input);
  
  printf("\n");
  return input;
}
/*****+------*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: generateRandom
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):None  
*   
*  Function Description: Generate a random number based on the seed set between the range Min to Max inclusive
*
******+------*--**-*---**-****-**-*--*-*-*-**-*****************************/
int generateRandom(void)
{
  return rand() % (MAX - MIN + 1) + MIN;
}
/*****+------*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: cardValue
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): 
*  1. int rand - the random number generated
*  2. int cardNumber -  the number of the card
*  3. int *numberOfAce - the number of the Ace card
*   
*  Function Description: This function determines and print which hierarchy based on its card number. 
*
******+------*--**-*---**-****-**-*--*-*-*-**-*****************************/
int cardValue(int rand, int cardNumber, int *numberOfAce)
{
  int value; //value of card
  int evenlyDivisable; //if value of card is evenly divisable by 13
  outputCardNumber(rand, cardNumber); 
  value = rand % 13; 
  
  switch(rand % 13)
  {
    case 0: value = 10;
            printf("(King");
            break;
    
    case 1: 
            value = (*numberOfAce)++ > 0 ? 1 : 11; 
            printf("(Ace");
            break;
    
    case 11: value = 10;
            printf("(Jack");
            break;
    
    case 12: value = 10;
            printf("(Queen");
            break;
    
    default: printf("(%d", value);
  }
  
  evenlyDivisable = rand % 13 == 0 ? 1 : 0;  //This is a conditional expression that when rand is divided by 13, returns 1 and when it is not returns 0.
  
  switch((rand / 13) - (1 * evenlyDivisable))
  {
    case 0: printf(" of Clubs)");
            break;
    
    case 1: printf(" of Diamonds)");
            break;
    
    case 2: printf(" of Hearts)");
            break; 
    
    case 3: printf(" of Spades)");
            break; 
  }
  return value;
}
/*****+------*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: outputCardNumber
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int rand - the random number generated
*  2. int cardNumber - the number of the card
*   
*  Function Description: Prints the card number and what random number it is
*
******+------*--**-*---**-****-**-*--*-*-*-**-*****************************/
void outputCardNumber(int rand, int cardNumber)
{
  switch(cardNumber)
  {
    case 1: printf("The first card is #: %d ", rand);
            break;
    
    case 2: printf("The second card is #: %d ", rand); 
            break;
    
    case 3: printf("The third card is #: %d ", rand);
            break;
    
    case 4: printf("The fourth card is #: %d ", rand); 
            break;
    
    case 5: printf("The fifth card is #: %d ", rand);
            break;
  }
}
/*****+------*--**-*---**-****-**-*--*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: outputScore
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*  1. int score - current score of dealer
*   
*  Function Description: Prints the score of the dealer
*
******+------*--**-*---**-****-**-*--*-*-*-**-*****************************/
void outputScore(int score)
{
  printf(" Current score: %d", score);
  printf("\n");
}


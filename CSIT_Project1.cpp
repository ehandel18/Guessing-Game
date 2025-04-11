#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Function to get random number for easy difficulty
int gRandomNum_easy()
{   //define variables
    int randomNum; //declare random number variable
    randomNum = rand() % 11; //generate random number 0-10
    return (randomNum); //return generated number
}
//Function to get random number for medium difficulty
int gRandomNum_medium()
{   //define variables
    int randomNum; //declare random number variable
    randomNum = rand() % 51; //generate random number 0-50
    return (randomNum); //return generated number
}
//Function to get random number for hard difficulty
int gRandomNum_hard()
{   //define variables
    int randomNum; //declare random number variable
    randomNum = rand() % 101; //generate random number 0-100
    return (randomNum); //return generated number
}
//Function to play easy difficulty game
void playGame_easy() {
    int randomNum = gRandomNum_easy();//declare random number variable
    int numGuess; //declare number to guess
    int count = 7; //set the number of guesses
    while (true) {
        cout << "Please guess a number 0-10 ";
        cin >> numGuess;
        
        //see if guess is out of range
        if (numGuess < 0 || numGuess > 10) {
            cout << "Invalid Input. Please enter a number 0-10 ";
            continue;
        }
        //Give hints based on guess
        if (numGuess > randomNum) {
            cout << "Guess a smaller number. ";
        } 
        if (numGuess < randomNum) {
            cout << "Guess a larger number. ";
        }

        //check if guess is correct
        if (numGuess == randomNum) {
            cout << "You guessed correctly! ";
            cout << "You scored a " << count << endl;
            break;
        }

        //keep track of the number of guesses
        count = count - 1; //decrement guess count
        if (count <= 0) {
            cout << "Sorry, you ran out of attempts. The correct number was " << randomNum << endl;
            break;
        }
        
    }
}

//Function to play medium difficulty game
void playGame_medium() {
    int randomNum = gRandomNum_medium(); //declare random number variable
    int numGuess; //declare number to guess
    int count = 5; //set the number of guesses
    while (true) {
        cout << "Please guess a number 0-50 ";
        cin >> numGuess;
        
        //see if guess is out of range
        if (numGuess < 0 || numGuess > 50) {
            cout << "Invalid Input. Please enter a number 0-50 ";
            continue;
        }

        //Give hints based on guess
        if (numGuess > randomNum) {
            cout << "Guess a smaller number. ";
        } 
        if (numGuess < randomNum) {
            cout << "Guess a larger number. ";
        }

        //check if guess is correct
        if (numGuess == randomNum) {
            cout << "You guessed correctly! ";
            cout << "You scored a " << count << endl;
            break;
        }


        count = count - 1; //decrement guess count
        //Check to see if guesses have run out
        if (count <= 0) {
            cout << "Sorry, you ran out of attempts. The correct number was " << randomNum << endl;
            break;
        }
        
    }
}

//Function to play hard difficulty game
void playGame_hard() {
    int randomNum = gRandomNum_hard(); //declare random number variable
    int numGuess; //declare number to guess
    int count = 3; //set the number of guesses
    while (true) {
        cout << "Please guess a number 0-100 ";
        cin >> numGuess;
        //see if guess is out of range
        if (numGuess < 0 || numGuess > 100) {
            cout << "Invalid Input. Please enter a number 0-100 ";
            continue;
        }
        //Give hints based on guess
        if (numGuess > randomNum) {
            cout << "Guess a smaller number. ";
        } 
        if (numGuess < randomNum) {
            cout << "Guess a larger number. ";
        }
        //check if guess is correct
        if (numGuess == randomNum) {
            cout << "You guessed correctly! " << endl;
            cout << "You scored a " << count << endl;
            break;
        }
        count = count - 1; //decrement count
        //Check if player ran out of guesses
        if (count <= 0) {
            cout << "Sorry, you ran out of attempts. The correct number was " << randomNum << endl;
            break;
        }
        
    }
}
//main function to play game
int main() {
    srand(time(0)); //seed random number generator with current time
    int difficulty; //variable to store chosen difficulty
    char playAgain; //varaible for player's choice to play again
    //Explanation of game instructions
    cout << "We will be playing a guess game. You may choose easy, medium, or hard difficulty " << endl;
    cout << "Easy difficulty: Numbers will be 0-10 and you will have 7 guesses" << endl;
    cout << "Medium difficulty: Numbers will be 0-50 and you will have 5 guesses" << endl;
    cout << "Hard difficulty: Numbers will be 0-100 and you will have 3 guesses" << endl;
    cout << "The number of guesses you have remaining will be your score" << endl;
    
    //loop to allow multiple games
    while (true) {
        cout << "Please enter (1) for easy, (2) for medium and (3) for hard difficulty ";
        cin >> difficulty; //read in players difficulty
        
        if (difficulty == 1) {
            playGame_easy();//play easy game
        } 
        else if (difficulty == 2) {
            playGame_medium();//play medium game
        } 
        else if (difficulty == 3) {
            playGame_hard(); //play hard game
        } 
        //make sure sure entry is valid
        else {
            cout << "Invalid entry. Please enter (1), (2), or (3)." << endl;
            continue; //prompt user to enter difficulty again
        }
        //Ask player if they would like to play again
        cout << " Would you like to play again? Press (y) to play again or any other key to quit ";
        cin >> playAgain; //read in player's decision
        if (playAgain == 'y' || playAgain == 'Y') {
            continue;
        }
        else {
            break; //exit loop and finish program
        }
    }
    return 0;

}
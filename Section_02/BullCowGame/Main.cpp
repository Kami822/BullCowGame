
// Libraries
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string Guess = "";
std::string GetGuess();
std::string ReturnGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //Instantiate a new game

int MaxTries = BCGame.GetMaxTries();

// The entry point for our application
int main() 
{

	bool bWantsToPlayAgain = false;
	do {
	PrintIntro();
	PlayGame();
	// TODO Summarize game
	bWantsToPlayAgain = AskToPlayAgain();
	
	} 
	while (bWantsToPlayAgain);

	std::cout << std::endl;

	// Exit the application
	return	0; 

}


// Introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 6;
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;

}

void PlayGame()
{
	
	BCGame.Reset();
	// Loop GetAndReturnGuess function until the guess limit is reached
	

	for (int loopcount = 1; loopcount <= MaxTries; loopcount++)
	{
		GetGuess();
		ReturnGuess();
		std::cout << std::endl;
	}
}


// Get a guess from the player and repeat it back to them
std::string GetGuess()
{
	// Get a guess from the player
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}


std::string ReturnGuess()
{

	// Repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl;

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?";
	std::string Response = ""; 
	std::getline(std::cin, Response);
	 
	return (Response[0] == 'y') || (Response[0] == 'Y');

}
 
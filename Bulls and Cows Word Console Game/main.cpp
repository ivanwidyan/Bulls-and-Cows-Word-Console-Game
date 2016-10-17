/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For Game logic see the FBullCowGameFirst
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // Instantiate a new game, which we re-use across plays

//The entry point for our application
int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0; //Exit the applicationasds
}

void PrintIntro() {
	std::cout << "	            \\  |  /         ___________" << std::endl;
	std::cout << "     ____________  \\ \\_# /         |  ___      |       _________" << std::endl;
	std::cout << "    |            |  \\  #/          | |   |     |      | = = = = |" << std::endl;
	std::cout << "    | |   |   |  |   \\\\#           | |`v'|     |      |         |" << std::endl;
	std::cout << "    |            |    \\#  //       |  --- ___  |      | |  || | |" << std::endl;
	std::cout << "    | |   |   |  |     #_//        |     |   | |      |         |" << std::endl;
	std::cout << "    |            |  \\\\ #_/_______  |     |   | |      | |  || | |" << std::endl;
	std::cout << "    | |   |   |  |   \\\\# /_____/ \\ |      ---  |      |         |" << std::endl;
	std::cout << "    |            |    \\# |+ ++|  | |  |^^^^^^| |      | |  || | |" << std::endl;
	std::cout << "    |            |    \\# |+ ++|  | |  |^^^^^^| |      | |  || | |" << std::endl;
	std::cout << " ^^^|    (^^^^^) |^^^^^#^| H  |_ |^|  | |||| | |^^^^^^|         |" << std::endl;
	std::cout << "    |    ( ||| ) |     # ^^^^^^    |  | |||| | |      | ||||||| |" << std::endl;
	std::cout << "    ^^^^^^^^^^^^^________/  /_____ |  | |||| | |      | ||||||| |" << std::endl;
	std::cout << "         `v'-                      ^^^^^^^^^^^^^      | ||||||| |" << std::endl;
	std::cout << "          || |`.      (__)    (__)                          ( )" << std::endl;
	std::cout << "                      (oo)    (oo)                       /---V" << std::endl;
	std::cout << "               /-------\\/      \\/ --------\\             * |  |" << std::endl;
	std::cout << "              / |     ||        ||_______| \\" << std::endl;
	std::cout << "             *  ||W---||        ||      ||  *" << std::endl;
	std::cout << "                ^^    ^^        ^^      ^^" << std::endl;
	std::cout << "\WELCOME TO BULLS AND WORDS CONSOLE GAME" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	return;
}

// Plays a singe game to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game
	// is NOT WON and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();
		
		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}

	PrintGameSummary();
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess() {
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// Get a Guess from the Player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		// Check Status and give feedbacks
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n" << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n" << std::endl;
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE - YOU WIN!" << std::endl;
	}
	else {
		std::cout << "Better luck next time!" << std::endl;
	}
}
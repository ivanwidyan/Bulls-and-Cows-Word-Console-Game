/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind
*/

#pragma once
#include <string>

// all values initialise to 0
struct FBullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status, OK, Not_Isogram, Wrong_Length, Not_Lowercase
};

class FBullCowGame {

public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	int GetHiddenWordLength() const;

	EGuessStatus CheckGuessValidity(std::string) const; // TODO make a more rich return value
	bool IsGameWon() const;

	void Reset();
	FBullCowCount SubmitValidGuess(std::string);


private:
	// See constructor for initialisation
	int MyCurrentTry;
	std::string MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(std::string) const;
	bool IsLowecrase(std::string) const;
};
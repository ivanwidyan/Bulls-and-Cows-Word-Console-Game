#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialise to 0
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	BullCowCount SubmitGuess(FString);


private:
	// See constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
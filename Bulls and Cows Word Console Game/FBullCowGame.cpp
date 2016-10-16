#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries () const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	
	MyCurrentTry = 1;
	return;
}

// received a VALID guess, increments
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;
	BullCowCount;

	// loop through all leters in the guess
		// compare letters against the hidden word

	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

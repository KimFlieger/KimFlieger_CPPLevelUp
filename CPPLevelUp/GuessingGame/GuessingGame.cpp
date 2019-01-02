#include "GuessingGame.h"

bool GuessingGame::CheckGuess(const std::string& guess, const std::string& answer)
{
	for (unsigned int i = 0; i < guess.size(); ++i)
	{
		for (unsigned int j = 0; j < answer.size(); ++j)
		{
			if (guess[i] == answer[j])
			{
				if (i == j)
				{
					mCorrectWords++;
					continue;
				}
				mCorrectWordsInWrongSpot++;
			}
		}
	}

	std::cout << "Correct Words: " << mCorrectWords << "\n";
	std::cout << "Correct Words In Wrong Spot: " << mCorrectWordsInWrongSpot << "\n";

	return mCorrectWords == answer.size();
}

bool GuessingGame::Guess(const std::string& answer)
{
	std::string guess = "";
	std::cout << "Guess:";
	std::cin >> guess;
	bool isCorrect = false;

	isCorrect = CheckGuess(guess, answer);

	return isCorrect;
}

void GuessingGame::PlayGame()
{
	for (unsigned int i = 0; i < mGuessesNum; ++i)
	{
		mIsCorrect = Guess(mAnswer);

		if (mIsCorrect)
		{
			std::cout << "You won!";
			return;
		}
	}

	std::string playAgainAnswer = "";
	std::cout << "You lost. Play again? Y/n\n";
	std::cin >> playAgainAnswer;

	if (playAgainAnswer == "y" || playAgainAnswer == "Y")
	{
		PlayGame();
	}
	else
	{
		return;
	}
}
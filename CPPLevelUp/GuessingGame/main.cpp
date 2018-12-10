#include <string>
#include <iostream>

bool CheckGuess(const std::string& guess, const std::string& answer)
{
	unsigned int correctWords = 0;
	unsigned int correctWordsInWrongSpot = 0;

	for (unsigned int i = 0; i < guess.size(); ++i)
	{
		for (unsigned int j = 0; j < answer.size(); ++j)
		{
			if (guess[i] == answer[j])
			{
				if(i == j)
				{
					correctWords++;
					continue;
				}
				correctWordsInWrongSpot++;
			}
		}
	}

	std::cout << "Correct Words: " << correctWords << "\n";
	std::cout << "Correct Words In Wrong Spot: " << correctWordsInWrongSpot << "\n";

	return correctWords == answer.size();
}

void PlayGame()
{
	unsigned int guessesNum = 2;
	std::string answer = "games";
	std::string guess = "";
	bool isPlaying = true;
	bool isCorrect = false;

	do
	{
		std::cin >> guess;

		isCorrect = CheckGuess(guess, answer);

		if (isCorrect)
		{
			std::cout << "You won!";
			isPlaying = false;
			break;
		}
	} while (isPlaying);
}

int main()
{
	PlayGame();
	return 0; 
}
// Author: @Owen Miller-Fast (oray-byte).
// Date: 06/17/2021

// FIXEME: Any information that the user enters that is not the correct type will cause the application to operate incorrectly.
// Will implement a solution after I find one.
 
#include <iostream>
#include <ctime>
#include <typeinfo>

struct user
{
	std::string name = "John Doe", gender = "Unspecified", email = "generic@gmail.com";
	int age = 23;
};

struct highscore
{
	user player = user();
	int score = INT_MAX;
};

// Definition: The quit function allows the user to exit the program. It confirms the user wants to leave.
// Pre: None
// Post: User exits the application;
void quit();

// Definition: The userInfoInput function allows the user to enter there information where it is stored in the 
// user variable passed in
// Pre: user variable that is passed by reference. The user variable contains the user's information
// Post: Sets the user's name, age, gender, and email to the entered values.
void userInfoInput(user &currentUser);

// Definition: The displayUserInfo function displays the user's information
// Pre: The user variable contains the user's information
// Post: Prints the user's name, age gender and emal to the console
void displayUserInfo(const user currentUser);

// Definition: The game function handles the highscore and the game logic
// Pre: score of type highscore and player of type user are passed by reference. 
// score handles the highscore and the player who set the highscore. player allows
// the score's player to be updated if there is a new highscore
// Post: returns the original highscore if it was not beat. Otherwise, it returns
// the new highscore.
highscore game(highscore &score, const user &player);

int main() 
{
	int userInput;
	user currentUser;
	highscore score;

	std::cout << "Welcome [$USER] to my console application. Please choose one of the following commands!" << std::endl << std::endl;
	while (true)
	{
		std::cout << "[1] Input information\n[2] Display information\n[3] Play a game\n[4] Quit" << std::endl << std:: endl;
		std::cout << "Your input: ";
		
		std::cin >> userInput;

		switch(userInput) 
		{
			case 1:
				userInfoInput(currentUser);
				break;
			case 2:
				displayUserInfo(currentUser);
				break;
			case 3:
				score = game(score, currentUser);
				break;
			case 4:
				quit();
				break;
			default:
				std::cout << "Please enter a valid option..." << std::endl;
				std::cout << std::endl;
		}
	}

	return 0;
}

void quit() 
{
	char confirmation;

	std::cout << std::endl << "Are you sure [Y/N]: ";
	std::cin >> confirmation;
	std::cout << std::endl;

	if (tolower(confirmation) == 'y')
	{
		exit(0);
	}

}

void userInfoInput(user &currentUser) 
{
	std::cout << std::endl << "Please enter the following information" << std::endl;
	
	std::cout << std::endl << "First name: ";
	// FIXME: If user enters first and last name, it exits the function and the while loop loops forever.
	// Need to allow for user to enter multiple words. getLine() might work.
	std::cin >> currentUser.name; 
	std::cout <<  "Age: ";
	std::cin >> currentUser.age;
	std::cout  << "Gender: ";
	std::cin >> currentUser.gender;
	std::cout  << "Email: ";
	std::cin >> currentUser.email;
	std::cout << std::endl;
}

void displayUserInfo(const user currentUser)
{
	std::cout << std::endl << "Name: " << currentUser.name << std::endl;
	std::cout << "Age: " << currentUser.age << std::endl;
	std::cout << "Genger: " << currentUser.gender << std::endl;
	std::cout << "Email: " << currentUser.email << std::endl << std::endl;
}

highscore game(highscore &score, const user &player)
{
	srand((unsigned) time(0));
	int randomNumber = rand() % 20; // Random number between 0 - 20
	int guesses = 0;
	int userGuess = -1;

	std::cout << std::endl << "Let's play a game. Guess a number between 0 - 20" << std::endl;
	std::cout << std::endl << "Current highscore (Lower the better): " << score.score << std::endl;
	std::cout << "Held by: " << score.player.name << std::endl;
	std::cout << std::endl;

	while(userGuess != randomNumber) {
		std::cout << "Your guess: ";
		std::cin >> userGuess;
		// NOTE: If user enter a noninteger value, the function with loop endlessly. Will continue looking 
		// for solution and implement when found.
		guesses++;
	}

	if (guesses < score.score)
	{
		std::cout << std::endl <<  "Congratulations, you set a new highscore!" << std::endl;
		std::cout << "The number was: " << randomNumber << std::endl;
		std::cout << "Number of guesses: " << guesses << std::endl;
		std::cout << std::endl;

		score.score = guesses;
		score.player = player;
	}
	else
	{
		std::cout << std::endl << "The number was: " << randomNumber << std::endl;
		std::cout << "You did not set a new highscore, try again." << std::endl;
		std::cout << "Number of guesses: " << guesses << std::endl;
		std::cout << std::endl;
	}


	return score;
}
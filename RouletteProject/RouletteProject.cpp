// RouletteProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <time.h>
using namespace std;

bool promptBet();
void initializeBankroll();
int startingBankroll;
short betTypeChoice = -1;
int betAmount = 0;
int bankroll = 0;
bool continueBetting = true;
int *bets;
int *betAmounts;
int numberOfBets;
int index;
int betTemp;
int numberOfValidBets;
int luckyNumber;
void getRetry();
void determineWinnings();
void spinTheWheel();
void getBets();
bool isExact(int);
bool isOdd(int);
bool isEven(int);
bool isBlack(int);
bool isRed(int);
bool isFirstTwelve(int);
bool isSecondTwelve(int);
bool isThirdTwelve(int);
bool isFirstHalf(int);
bool isSecondHalf(int);
bool isFirstColumn(int);
bool isSecondColumn(int);
bool isThirdColumn(int);




int _tmain(int argc, _TCHAR* argv[])
{
	initializeBankroll();

	while(continueBetting){
		getBets();
		spinTheWheel();
		determineWinnings();
		getRetry();
	}

	system("pause");
	return 0;
}

void getBets()
{
	numberOfBets = 0;
	bool validInput = false;
	while(!validInput){
	cout<<"How many bets would you like to make for this spin: (up to 8)"<<endl;
	cin>>numberOfBets;			//get # of bets
	if(numberOfBets % 1 == 0 && numberOfBets > 0 && numberOfBets <= 8){
		validInput = true;
	}
	}
	numberOfValidBets = 0;
	bets = new int[numberOfBets]; //create dynamic array of size = numberOfBets
	betAmounts = new int[numberOfBets];
	bool shouldContinueBetting = true;

	for(index = 1; index <= numberOfBets; index++)
	{
		if(bankroll >= 1)
		{
			cout<<"You are on bet number "<< index <<". You have $"<<bankroll<<" remaining."<<endl;
			shouldContinueBetting = promptBet(); //get bet type, get bet amount

			if (!shouldContinueBetting)
			{
				break;
			}
		}
		else{
			cout<<"You have no more money to bet with!"<<endl<<endl;
		}
	}
}

bool promptBet()
{
	cout<<"What type of bet would you like to place?"<<endl;
	cout<<"0-36: Bet on corresponsing single number."<<endl;
	cout<<"37: Bet on Red"<<endl;
	cout<<"38: Bet on Black"<<endl;
	cout<<"39: Bet on Odd"<<endl;
	cout<<"40: Bet on Even"<<endl;
	cout<<"41: Bet on First 12"<<endl;
	cout<<"42: Bet on Second 12"<<endl;
	cout<<"43: Bet on Third 12"<<endl;
	cout<<"44: Bet on First Half"<<endl;
	cout<<"45: Bet on Second Half"<<endl;
	cout<<"46: Bet on First Column"<<endl;
	cout<<"47: Bet on Second Column"<<endl;
	cout<<"48: Bet on Third Column"<<endl;
	cout<<"Enter a number from the menu to make your selection: ";
	cin>>bets[index];
	cout<<endl<<"Enter the amount you'd like to bet: $";
	cin>>betTemp;
	cout<<endl;

	if(betTemp > bankroll)
	{
		cout<<"You do not have enough money to make that bet. The wheel will spin now."<<endl;
		return false;
		//break the loop, then return to the main function and call the wheelspin function.
	}

	numberOfValidBets++;
	betAmounts[index] = betTemp;
	bankroll -= betTemp;
	return true;
}


void initializeBankroll()
{
	cout<<"How much money would you like to begin playing with?"<<endl;
	cout<<"$";
	cin>>bankroll;
	if(bankroll < 1 || bankroll > 1000000){
		cout<<"That was an invalid entry. Please enter a number from 1 to 1,000,000."<<endl;
		cin>>bankroll;
		startingBankroll = bankroll;
	}
}

void spinTheWheel()
{
	srand(time(NULL));
	luckyNumber = static_cast<int>(floor((rand() % 37)));
	cout<<endl<<"The Winning Number Is: "<<luckyNumber<<"!"<<endl<<endl;
}

void determineWinnings() 
{
	for (int i = 0; i < numberOfValidBets; i++)
	{
		int bet = bets[i];

		if (isExact(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on "<<luckyNumber<<" won you $"<< betAmounts[i] * 35<<"!"<<endl;
			bankroll += betAmounts[i] * 36;
		}
		if (isRed(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on red won you $"<< betAmounts[i] <<"!"<<endl;
			bankroll += betAmounts[i] * 2;
		}
		if (isBlack(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on black won you $"<< betAmounts[i] <<"!"<<endl;
			bankroll += betAmounts[i] * 2;
		}

		if (isEven(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on even won you $"<< betAmounts[i] <<"!"<<endl;
			bankroll += betAmounts[i] * 2;
		}

		if (isOdd(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on odd won you $"<< betAmounts[i] <<"!"<<endl;
			bankroll += betAmounts[i] * 2;
		}

		if (isFirstTwelve(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the first 12 won you $"<< betAmounts[i] * 2<<"!"<<endl;
			bankroll += betAmounts[i] * 3;
		}
		if (isSecondTwelve(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the second 12 won you $"<< betAmounts[i] * 2<<"!"<<endl;
			bankroll += betAmounts[i] * 3;
		}
		if (isThirdTwelve(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the third 12 won you $"<< betAmounts[i] * 2<<"!"<<endl;
			bankroll += betAmounts[i] * 3;
		}
		if (isFirstHalf(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the first half won you $"<< betAmounts[i]<<"!"<<endl;
			bankroll += betAmounts[i] * 2;
		}
		if (isSecondHalf(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the second half won you $"<< betAmounts[i] * 2<<"!"<<endl;
			bankroll += betAmounts[i] * 2;
		}
		if (isFirstColumn(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the first column won you $"<< betAmounts[i] * 2<<"!"<<endl;
			bankroll += betAmounts[i] * 3;
		}
		if (isSecondColumn(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the second column won you $"<< betAmounts[i] * 2<<"!"<<endl;
			bankroll += betAmounts[i] * 3;
		}
		if (isThirdColumn(bet))
		{
			cout<<"Your $"<< betAmounts[i] <<" bet on the third column won you $"<< betAmounts[i] * 2<<"!"<<endl;
			bankroll += betAmounts[i] * 3;
		}

	}
}

bool isExact(int bet)
{
	return bet == luckyNumber;
}


bool isRed(int bet)
{
	if (bet == 37 &&(luckyNumber == 1 ||
		luckyNumber == 3 ||
		luckyNumber == 5 ||
		luckyNumber == 7 ||
		luckyNumber == 9 ||
		luckyNumber == 12 ||
		luckyNumber == 14 ||
		luckyNumber == 16 ||
		luckyNumber == 18 ||
		luckyNumber == 19 ||
		luckyNumber == 21 ||
		luckyNumber == 23 ||
		luckyNumber == 25 ||
		luckyNumber == 27 ||
		luckyNumber == 30 ||
		luckyNumber == 32 ||
		luckyNumber == 34 ||
		luckyNumber == 36)){
			return true;
	}
	else
	{
		return false;
	}
}

bool isBlack(int bet)
{
	if (bet == 38 && (luckyNumber == 2 ||
		luckyNumber == 4 ||
		luckyNumber == 6 ||
		luckyNumber == 8 ||
		luckyNumber == 10 ||
		luckyNumber == 11 ||
		luckyNumber == 13 ||
		luckyNumber == 15 ||
		luckyNumber == 17 ||
		luckyNumber == 20 ||
		luckyNumber == 22 ||
		luckyNumber == 24 ||
		luckyNumber == 26 ||
		luckyNumber == 28 ||
		luckyNumber == 29 ||
		luckyNumber == 31 ||
		luckyNumber == 33 ||
		luckyNumber == 35)){
			return true;
	}
	else
	{
		return false;
	}
}


bool isEven(int bet)
{
	return bet == 40 && luckyNumber % 2 == 0;
}

bool isOdd(int bet)
{
	return bet == 39 && luckyNumber % 2 == 1;
}

bool isFirstTwelve(int bet)
{
	return bet == 41 && luckyNumber != 0 && luckyNumber <= 12;
}

bool isSecondTwelve(int bet)
{
	return bet == 42 && luckyNumber >= 13 && luckyNumber <= 24;
}

bool isThirdTwelve(int bet)
{
	return bet == 43 && luckyNumber >= 25 && luckyNumber <= 36;
}

bool isFirstHalf(int bet)
{
	return bet == 44 && luckyNumber != 0 && luckyNumber <= 18;
}

bool isSecondHalf(int bet)
{
	return bet == 45 && luckyNumber >= 19;
}

bool isFirstColumn(int bet)
{
	if (bet == 46 &&(luckyNumber == 1 ||
		luckyNumber == 4 ||
		luckyNumber == 7 ||
		luckyNumber == 10 ||
		luckyNumber == 13 ||
		luckyNumber == 16 ||
		luckyNumber == 19 ||
		luckyNumber == 22 ||
		luckyNumber == 25 ||
		luckyNumber == 28 ||
		luckyNumber == 31 ||
		luckyNumber == 34)){
			return true;
	}
	else
	{
		return false;
	}
}
bool isSecondColumn(int bet)
{
	if (bet == 47 &&(luckyNumber == 2 ||
		luckyNumber == 5 ||
		luckyNumber == 8 ||
		luckyNumber == 11 ||
		luckyNumber == 14 ||
		luckyNumber == 17 ||
		luckyNumber == 20 ||
		luckyNumber == 23 ||
		luckyNumber == 26 ||
		luckyNumber == 29 ||
		luckyNumber == 32 ||
		luckyNumber == 35)){
			return true;
	}
	else
	{
		return false;
	}
}
bool isThirdColumn(int bet)
{
	if (bet == 48 &&(luckyNumber == 3 ||
		luckyNumber == 6 ||
		luckyNumber == 9 ||
		luckyNumber == 12 ||
		luckyNumber == 15 ||
		luckyNumber == 18 ||
		luckyNumber == 21 ||
		luckyNumber == 24 ||
		luckyNumber == 27 ||
		luckyNumber == 30 ||
		luckyNumber == 33 ||
		luckyNumber == 36)){
			return true;
	}
	else
	{
		return false;
	}
}




void getRetry()
{
	char answer;
	bool validInput = false;
	while (validInput == false){
		cout<<"You have $"<<bankroll<<" remaining."<<endl;
		cout<<"Would you like to continue playing?(Enter Y or N)"<<endl;
		cin>>answer;

		if(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N'){
			validInput = true;
			if(answer == 'y' || answer == 'Y'){
			continueBetting = true;
			}
			else if(answer == 'n' || answer == 'N'){
				continueBetting = false;
				cout<<"Thank you for playing Roulette"<<endl;
				cout<<"Your net profit was: $"<<bankroll - startingBankroll<<endl;
			}
		}

	}
}
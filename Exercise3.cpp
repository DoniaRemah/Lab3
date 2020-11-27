#include <iostream>
using namespace std;

class GameProfile
{
private:
	string name = "p";
	int currentLevel = 0;
	int coins = 0;
	int hints = 3;
	bool IsPremiumVersion = false;
	int watchedAdvertisements = 0;

public:

	// Constructor:

	GameProfile(string n, int icl, int ic, int h, bool iip, int iwa) 
	{
		string name = n;
		int currentLevel = icl;
		int coins = ic;
		int hints = h;
		bool IsPremiumVersion = iip;
		int watchedAdvertisements = iwa;
	}

	// Set Functions:

	void setName(string n)
	{
		name = n;
	}

	void setCoins(int c)
	{
		coins = c;
	}

	void setCurrentLevel(int icl)
	{
		currentLevel = icl;
	}

	void Sethints(int ih)
	{
		hints = ih;
	}

	void setIsPremiumVersion(bool iip)
	{
		IsPremiumVersion = iip;
	}

	void setWatchedAds(int iwa)
	{
		watchedAdvertisements = iwa;
	}

	// Get Functions:

	string getName()
	{
		return name;
	}

	int getCoins()
	{
		return coins;
	}

	int getHints()
	{
		return hints;
	}

	int getCurrentLevel()
	{
		return currentLevel;
	}

	int getWatchedAds()
	{
		return watchedAdvertisements;
	}

	bool getIsPremium()
	{
		return IsPremiumVersion;
	}

	// Object Functions

	bool BuyHints(int number)
	{
		if (coins > number * 100)
		{
			hints = hints + number;
			coins = coins - (number * 100);
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetRank()
	{
		int rank = currentLevel / 1000;
		return rank;
	}

	bool BuyPremium()
	{
		if (coins > 500)
		{
			IsPremiumVersion = true;
			coins = coins - 500;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool ShowAdvertise()
	{
		if (IsPremiumVersion)
			return true;
		else
		{
			coins = coins + 50;
			watchedAdvertisements++;
		}
	}

};
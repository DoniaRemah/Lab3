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
		currentLevel = icl;
		coins = ic;
		hints = h;
		IsPremiumVersion = iip;
		watchedAdvertisements = iwa;
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
		if (coins >= number * 100)
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
		if (coins >= 500)
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

	void TransferCoins(GameProfile pv_player)
	{
		coins += pv_player.getCoins();
 	}


};

int main()
{
	GameProfile player1("james", 3,3000,5,false,0);
	cout << "Before buying anything: " << player1.getCoins() << endl;
	player1.BuyHints(1);
	cout << "After buying hint: " << player1.getCoins() << endl;
	player1.BuyPremium();
	cout << "After buying premium: " << player1.getCoins() << endl;
	GameProfile player2("Alex", 3, 200, 1, false, 0);
	player1.TransferCoins(player2);
	cout << "After transfering: " << player1.getCoins() << endl;
	player1.ShowAdvertise();
	cout << "coins after adds: " << player1.getCoins();
	cout << "player rank: " << player1.GetRank();
	return 0;
}
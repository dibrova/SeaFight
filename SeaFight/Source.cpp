#include <iostream>
using namespace std;

class Player
{
public:
	Player() { int health = 20; }

	int GetHhalth() { return health; }
	void DecrHelth() { health -= 1; }

	~Player() {};

private:
	int health;
};

class BatleFeld
{
public:
	BatleFeld() {}

	void SetPointType(int x, int y, int type) { map[x][y] = type; }
	int GetPointType(int x, int y) { return map[x][y]; }
	
	~BatleFeld() {}

private:
	int map[10][10] = { 0 };
};

class LogManager
{
public:
	LogManager() {};
	~LogManager() {};

private:

};

void ShowBatleFeld(BatleFeld &batleFeld,int mode){ 
	for (size_t i = 0; i < 10; i++)	{
		for (size_t j = 0; j < 10; j++)	{
			if (batleFeld.GetPointType(i, j) == 0) cout << " "; //clear
			if (batleFeld.GetPointType(i, j) == 1 && mode) cout << "U"; //ship
			if (batleFeld.GetPointType(i, j) == 2) cout << "X"; //shot
			if (batleFeld.GetPointType(i, j) == 3) cout << "+"; //miss
		}cout << endl;
	}
}

int Rnd() { return rand() % 9; }

void InitBatleFeld(BatleFeld &batleFeld) {
	size_t shipSize = 4;
	for (size_t i = 20; i > 0;)	{
		int x = Rnd(), y = Rnd();
		for (size_t j = 0; j == shipSize; j++){
			batleFeld.SetPointType(x, y, 1);
			x++;
		}
		i -= shipSize;//???
		shipSize--;
	}

}

void MakeShot(Player enemy, BatleFeld &target, int x, int y){//???bool
	if (target.GetPointType(x, y) == 1) {
		target.SetPointType(x, y, 2); //return true >>log
		enemy.DecrHelth();
	}
	if (target.GetPointType(x, y) == 0) target.SetPointType(x, y, 3); //return false >>log
	
}



void main()
{

}
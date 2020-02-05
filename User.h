using namespace std;

class User{
public:
	void move(string s);
	string getRDescription();
	void printRDescription(string s);
	string getLocation();
	bool inventorySpace();
	void addInventory(string s);
	void removeInventory(string s);
	void printInventory(string s);
	struct room
	{
		string name;
		string description;
		char hasDoor;//direction of door, blank if none
		string itemsHere[5];//list of any items there.
		bool canEnter;
	};
	void addRInventory(string s);
	void removeRInventory(string s);
	void unlock(string s);
	User();
	

private:
	string location;
	string inventory[10];
	int playerx;
	int playery;
	room locMap[3][5];
};
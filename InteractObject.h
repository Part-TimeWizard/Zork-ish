using namespace std;

class InteractObject{
public:
	InteractObject(bool p, bool i, string d, string l, string n);
	virtual void beUsed() = 0;
	virtual void beCalled(string v, User& b) = 0;
	virtual void beCalled2(string v, User& b, InteractObject* p) = 0;
	virtual void bePickedUp(User& b) = 0;
	virtual void beDropped(User& b) =0;
	virtual void beLooked() = 0;
	string getDescription();
	void setDescription(string s);
	void changeInventoryState(string s, User& b);
	bool getInventoryState();
	string getLocation();
	void changeLocation(string s);
	bool sameLoc(User& b);
	string getName();

private:
	bool canPickup;
	bool inInventory;
	string description;
	string location;
	string name;
};
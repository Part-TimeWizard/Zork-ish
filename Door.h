using namespace std;

class Door : 
	public InteractObject{
public:
	Door(string d,string l);
	virtual void beCalled(string v, User& b);
	virtual void beCalled2(string v, User& b, InteractObject* p);
	virtual void beUsed();
	virtual void beLooked();
	virtual void bePickedUp(User& b);
	virtual void beDropped(User& b);
	void unlock();
	void open();
private:
	bool isOpen;
	bool isLocked;
	User* B;
};
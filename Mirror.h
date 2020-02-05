using namespace std;

class Mirror : 
	public InteractObject{
public:
	Mirror(string d,string l);
	virtual void beCalled(string v, User& b);
	virtual void beCalled2(string v, User& b, InteractObject* p);
	virtual void beUsed();
	virtual void beLooked();
	virtual void bePickedUp(User& b);
	virtual void beDropped(User& b);
	void beBroken(User& b);
private:
	bool isOpen;
};
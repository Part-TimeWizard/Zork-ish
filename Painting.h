using namespace std;

class Painting :
	public InteractObject
{
public:
	Painting(string d, string l, InteractObject * k);
	virtual void beCalled(string v, User& b);
	virtual void beCalled2(string v, User& b, InteractObject* p);
	virtual void beUsed();
	virtual void beLooked();
	virtual void bePickedUp(User& b);
	virtual void beDropped(User& b);
	void beBurned();
private:
	bool hasKey;
	Key* heldKey;
};
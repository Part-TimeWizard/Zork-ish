#include <string>
#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"
#include "Door.h"
#include "Key.h"

using namespace std;

Key::Key(string d, string l):InteractObject(true,false,d,l,"key")
{
	behindPainting = true;
}

void Key::beCalled(string v, User& b)
{
	if(sameLoc(b)||getInventoryState())
	{
		if(v == "use")
			beUsed();
		else if(v == "get")
			bePickedUp(b);
		else if(v == "drop")
			beDropped(b);
		else if(v == "look")
			beLooked();
		else
			cout<<"I can't do that."<<endl;
	}
	else
		cout<<"I don't see a key."<<endl;
};

void Key::beCalled2(string v, User& b, InteractObject* p)
{
	if(p->sameLoc(b))
	{
		if(p->getName() == "door" && getInventoryState() && (v == "unlock"|| v == "use"))
		{
			dynamic_cast<Door*>(p)->unlock();
		}
		else if(p->getName() == "door" && getInventoryState() && v == "open")
		{
			cout<<"That doesn't make any sense."<<endl;
		}
		else if(!(getInventoryState()))
		{
			cout<<"You don't have a key"<<endl;
		}
		else
		{
			cout<<"I can't do that."<<endl;
		}
	}
	else
		cout<<"I can't do that."<<endl;
};

void Key::beUsed()
{
	if(getInventoryState())
	{
		cout<<"You spin the key on your finger, but achieve nothing."<<endl;
	}
	else
		cout<<"You don't have a key."<<endl;
};

void Key::bePickedUp(User& b)
{
	if(!behindPainting)
	{
		if(getInventoryState())
		{
			cout<<"The key is already in your inventory."<<endl;
		}
		else
		{
			cout<<"Picked up key"<<endl;
			changeInventoryState("Key", b);
		}
	}
	else
	{
		cout<<"I don't see a key."<<endl;
	}
};

void Key::beDropped(User& b)
{
	if(!behindPainting)
	{
		if(getInventoryState())
		{
			cout<<"Key dropped"<<endl;
			changeLocation(b.getLocation()); 
			changeInventoryState("Key", b);
		}
		else
			cout<<"You don't have a key"<<endl;
	}
	else
	{
		cout<<"I don't see a key."<<endl;
	}
};

void Key::beLooked()
{
	cout<<getDescription()<<endl;
};

void Key::fall()
{
	behindPainting = false;
};
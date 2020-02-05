#include <string>
#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"
#include "Mirror.h"
#include "Sword.h"

using namespace std;

Sword::Sword(string d, string l):InteractObject(true,false,d,l,"sword")
{

}

void Sword::beCalled(string v, User& b)
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
		cout<<"I don't see a sword."<<endl;
};

void Sword::beCalled2(string v, User& b, InteractObject* p)
{
	if(p->sameLoc(b))
	{
		if(p->getName() == "mirror")
		{
			dynamic_cast<Mirror*>(p)->beBroken(b);
		}
		else if (p->getName() == "painting")
		{
			cout<<"Why would you try to destroy such a nice piece of artwork?"<<endl;
		}
		else
		{
			cout<<"I can't do that."<<endl;
		}
	}
	else
		cout<<"I can't do that."<<endl;
};

void Sword::beUsed()
{
	if(getInventoryState())
	{
		cout<<"You swing the sword around with a flourish, but you then fumble and \ncut yourself and realize how exceedingly stupid you look."<<endl;
	}
	else
		cout<<"You don't have a sword.  Be cool if you did though."<<endl;
};

void Sword::bePickedUp(User& b)
{
	if(getInventoryState())
	{
		cout<<"The sword is already in your inventory."<<endl;
	}
	else
	{
		cout<<"The sword seems to glow softly as you pick it up"<<endl;
		cout<<"Picked Up"<<endl;
		changeInventoryState("Sword", b);
	}
};

void Sword::beDropped(User& b)
{
	if(getInventoryState())
	{
		cout<<"Dropped the Sword"<<endl;
		changeInventoryState("Sword", b);
		changeLocation(b.getLocation()); 
	}
	else
	{
		cout<<"You don't have a sword (I'm sure you wish you did)."<<endl;
	}

}

void Sword::beLooked()
{
	cout<<getDescription()<<endl;
};

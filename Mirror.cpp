#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"
#include "Sword.h"
#include "Mirror.h"

using namespace std;



Mirror::Mirror(string d,string l):InteractObject(false,false,d,l,"mirror")
{
	isOpen = false;
};

void Mirror::beCalled(string v, User& b)
{
	if(sameLoc(b))
	{
	
		if(v == "use")
		{
			beUsed();
		}
		else if(v=="break")
		{
			cout<<"You smash your hand against the mirror, but it only seems to hurt your hand."<<endl;//bad practice to not make it a function, but for this, its ok, I guess.
		}
		else if(v == "look")
			beLooked();
		else
			cout<<"I can't do that."<<endl;
	}
	else
		cout<<"I don't see a mirror."<<endl;
}
void Mirror::beCalled2(string v, User& b, InteractObject* p)//if an indirect object is included
{
	if(p->getName() == "sword"&&p->getInventoryState())
	{
		beBroken(b);
	}
	else
	{
		cout<<"I can't do that."<<endl;
	}
}
void Mirror::beBroken(User& b)
{
	if(!isOpen)
	{
		cout<<"The mirror smashes into a million shimmering pieces.  A large\nopening to a ledge can now be seen where the mirror once was"<<endl;
		isOpen = true;
		string s = "";
		b.unlock("The Ledge");
		setDescription("The remnants of the mirror lie on the floor.");

	}
	else
	{
		cout<<"The mirror is already broken."<<endl;
	}
}

void Mirror::beUsed()
{
	
	cout<<"You look into the mirror and see a horrible, hideous monst... oh, that's just \nyour reflection."<<endl;
}

void Mirror::bePickedUp(User& b)
{
	cout<<"I can't do that"<<endl;
}

void Mirror::beDropped(User& b)
{
	cout<<"I cant do that."<<endl;
}

void Mirror::beLooked()
{
	cout<<getDescription()<<endl;
}

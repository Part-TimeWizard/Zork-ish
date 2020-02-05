#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"
#include "Key.h"
#include "Painting.h"
#include "Door.h"

using namespace std;



Door::Door(string d,string l):InteractObject(false,false,d,l,"door")
{
	isOpen = false;
	isLocked = true;
};

void Door::beCalled(string v, User& b)
{
	B = &b;
	if(sameLoc(b))
	{
	
		if(v == "use"||v == "open")
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
		cout<<"I don't see a door."<<endl;
}
void Door::beCalled2(string v, User& b, InteractObject* p)//if an indirect object is included
{
	B = &b;
	if(sameLoc(b))
	{
		if(p->getName() == "key" && p->getInventoryState() && (v == "unlock"|| v == "use"))
		{
			unlock();
		}
		else if(p->getName() == "key" && p->getInventoryState() && v == "open")
		{
			unlock();
			open();
		}
		else if(p->getName() == "key" && !(p->getInventoryState()))
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
}
void Door::open()
{
	if(!isOpen)
	{
		cout<<"Opening"<<endl;
		isOpen = true;
		B->unlock("Tiny Room");
		

	}
	else
	{
		cout<<"Closing"<<endl;
		isOpen = false;
		B->unlock("Tiny Room");
	}
}

void Door::beUsed()
{
	
	if(!isLocked)
		open();
	else
	{
		cout<<"The door is locked."<<endl;
	}
}

void Door::bePickedUp(User& b)
{
	cout<<"Who in their right mind would try to pick up a door?"<<endl;
}

void Door::beDropped(User& b)
{
	cout<<"I can't do that."<<endl;
}

void Door::beLooked()
{
	cout<<getDescription()<<endl;
}

void Door::unlock()
{
	isLocked = false;
	cout<<"You unlock the door"<<endl;
}
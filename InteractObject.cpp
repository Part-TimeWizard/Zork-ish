#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"

using namespace std;

InteractObject::InteractObject(bool p, bool i, string d, string l, string n)
{
	canPickup = p;
	inInventory = i;
	description = d;
	location = l;
	name = n;
}

string InteractObject::getDescription()
{
	return description;
}

void InteractObject::setDescription(string s)
{
	description = s;
}

void InteractObject::changeInventoryState(string s,User& b)
{
		if(inInventory)
		{
			inInventory = false;
			b.removeInventory(s);
			b.addRInventory(name);

		}
		else
		{
			if(b.inventorySpace())
			{
				inInventory = true;
				b.addInventory(s);
				b.removeRInventory(name);
			}
			else
				cout<<"I'm already holding too much"<<endl;
		}

};

bool InteractObject::getInventoryState()
{
	return inInventory;
};

bool InteractObject::sameLoc(User& b)
{
	return (b.getLocation() == getLocation());
};

string InteractObject::getLocation()
{
	return location;
};
void InteractObject::changeLocation(string s)
{
	location = s;
};

string InteractObject::getName()
{
	return name;
};
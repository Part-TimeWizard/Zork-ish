#include <string>
#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"
#include "Key.h"
#include "Painting.h"

using namespace std;


Painting::Painting(string d, string l, InteractObject *k):InteractObject(false,false,d,l,"painting")
{
	hasKey = true;
	heldKey = dynamic_cast<Key*>(k);
}

void Painting::beCalled(string v, User& b)
{
	if(sameLoc(b))
	{
		if(v == "use"||v == "get"||v== "drop")
			beUsed();
		else if(v == "look")
			beLooked();
		else if(v == "burn")
			beBurned();
		else
			cout<<"I can't do that."<<endl;
	}
	else
		cout<<"I don't see a key."<<endl;
}

void Painting::beCalled2(string v, User& b, InteractObject* p)
{
	cout<<"I can't do that."<<endl;
};

void Painting::beUsed()
{
	cout<<"As you move the painting, a key falls from behind it onto the ground."<<endl;
	heldKey->fall();
}

void Painting::bePickedUp(User& b)
{
	beUsed();
}

void Painting::beDropped(User& b)
{
	beUsed();
}

void Painting::beLooked()
{
	cout<<getDescription()<<endl;
}

void Painting::beBurned()
{
	cout<<"You monster! Why would you want to burn a painting?  \"What else do you do with "<<endl<<"a painting whose eyes follow you around the room?\"  You don't burn it thats for sure!"<<endl;
}

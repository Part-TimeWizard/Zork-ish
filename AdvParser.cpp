#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"
#include "Door.h"
#include "Key.h"
#include "Painting.h"
#include "Mirror.h"
#include "Sword.h"
#include "AdvParser.h"


using namespace std;

//the class is static since there will only be one version needed.

typedef void (User::*userFunc)(string s);//tells the computer that pointer userFunc is a pointer to a void method
typedef InteractObject *objectPointer;
map<string, userFunc> playerVerbSynonym;//map between strings and a userFunc pointer  This one checks to see if the verb is one specific to the user only
map<string, string> verbSynonym;//map between strings and a condensed string
map<string, objectPointer> dObjectSynonym;
map<string, objectPointer> iObjectSynonym;


void AdvParser::initMap()
{
	playerVerbSynonym.insert(make_pair("move", &User::move));
	playerVerbSynonym.insert(make_pair("go", &User::move));
	playerVerbSynonym.insert(make_pair("inv", &User::printInventory));
	playerVerbSynonym.insert(make_pair("look", &User::printRDescription));
	
	verbSynonym.insert(make_pair("use", "use"));//used to condense and make the pairs
	verbSynonym.insert(make_pair("push", "use"));
	verbSynonym.insert(make_pair("pull", "use"));
	verbSynonym.insert(make_pair("move", "use"));
	verbSynonym.insert(make_pair("open", "open"));
	verbSynonym.insert(make_pair("pull", "open"));
	verbSynonym.insert(make_pair("unlock", "unlock"));
	verbSynonym.insert(make_pair("get", "get"));
	verbSynonym.insert(make_pair("pick", "get"));
	verbSynonym.insert(make_pair("pickup", "get"));
	verbSynonym.insert(make_pair("grab", "get"));
	verbSynonym.insert(make_pair("take", "get"));
	verbSynonym.insert(make_pair("drop", "drop"));
	verbSynonym.insert(make_pair("remove", "drop"));
	verbSynonym.insert(make_pair("look", "look"));
	verbSynonym.insert(make_pair("examine", "look"));
	verbSynonym.insert(make_pair("check", "look"));
	verbSynonym.insert(make_pair("break", "break"));
	verbSynonym.insert(make_pair("smash", "break"));
	verbSynonym.insert(make_pair("hit", "break"));
	verbSynonym.insert(make_pair("stab", "break"));
	verbSynonym.insert(make_pair("burn", "burn"));

	dObjectSynonym.insert(make_pair("door", new Door("A simple, wooden door.", "Mirror Room")));
	iObjectSynonym.insert(make_pair("door", dObjectSynonym["door"]));

	dObjectSynonym.insert(make_pair("mirror", new Mirror("A large floor to ceilling mirror spanning the entire wall.", "Mirror Room")));
	iObjectSynonym.insert(make_pair("mirror", dObjectSynonym["mirror"]));

	dObjectSynonym.insert(make_pair("sword", new Sword("A strangely ornate, if a bit rusty, sword.", "Tiny Room")));
	iObjectSynonym.insert(make_pair("sword", dObjectSynonym["sword"]));

	dObjectSynonym.insert(make_pair("key", new Key("A shiny key.", "Mirror Room")));
	iObjectSynonym.insert(make_pair("key", dObjectSynonym["key"]));

	dObjectSynonym.insert(make_pair("painting", new Painting("An unnerving portrait whose eyes seem to follow you around the room.", "Mirror Room", dObjectSynonym["key"])));
	dObjectSynonym.insert(make_pair("portrait", dObjectSynonym["painting"]));
	iObjectSynonym.insert(make_pair("painting", dObjectSynonym["painting"]));
}

void AdvParser::parseInput(string userInput, User& B)
{
	//reset the fields
	verb = "";
	directObject = "";
	indirectObject = "";
	
	string input = userInput;
	//Variables
	int counter = 0;//used for tokenizing
	string cursor = "";
	

	//Make sure input has something in it.
	if (input.length() < 1)
	{
		cout<<"What did you say?"<<endl;
		return;
	}


	//Step 0: all to lower

	for(int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}


	//Use loop to process all input
	if(input.find(' ') == -1)//only one word
	{
		//look for move
		if (input == "north" || input == "n")
		{
			verb = "move";
			directObject = "n";
		}
		else if (input == "south" || input == "s")
		{
			verb = "move";
			directObject= "s";
		}
		else if (input == "west" || input == "w")
		{
			verb = "move";
			directObject = "w";
		}
		else if (input == "east" || input == "e")
		{
			verb = "move";
			directObject = "e";
		}
		else if(input == "i" || input == "inv" || input == "inventory")
		{
			verb = "inv";
			directObject = "inv";
		}
		else if(input == "look")
		{
			verb = "look";
			directObject ="look";
		}

	}
	else
	{
		while(input.find(' ') != -1)
		{
			if (counter > 9)//too long
			{
				cout<<"Speak more consise please"<<endl;
				return;
			}

			cursor = input.substr(0,input.find(' '));

			if(counter == 0)//first word
			{
				verb = cursor;
				userInput = input.substr(input.find(' ')+1);
			}
			else if(directObject == "")//if the directObject is not yet found
			{
				if(dObjectSynonym.find(cursor) != dObjectSynonym.end())
				{
					directObject = cursor;
				}
			}
			else
			{
				if(iObjectSynonym.find(cursor) != iObjectSynonym.end())
				{
					indirectObject = cursor;
				}
			}
			input = input.substr(input.find(' ')+1);//gets rid of word from input
			counter++;
		}
		cursor = input.substr(0,input.find(' '));

			if(counter == 0)//first word
			{
				verb = cursor;
			}
			else if(directObject == "")//if the directObject is not yet found
			{
				//cout<<input<<" "<<cursor<<endl; //use to error check
				if(cursor == "north")//CONDENSE THIS AT SOME POINT
					directObject = "n";
				else if(cursor == "south")
					directObject = "s";
				else if(cursor == "east")
					directObject = "e";
				else if(cursor == "west")
					directObject = "w";
				else if(dObjectSynonym.find(cursor) != dObjectSynonym.end())
				{
					directObject = cursor;
				}
			}
			else
			{
				if(iObjectSynonym.find(cursor) != iObjectSynonym.end())
				{
					indirectObject = cursor;
				}
			}
			input = input.substr(input.find(' ')+1);//gets rid of word from input

	}

	if(directObject == "")
	{
		cout<<"Sorry, I don't understand \"" + userInput +"\"."<<endl;\
		return;
	}
	//cout<<endl<<verbSynonym[verb]<<" "<<directObject<<" "<<indirectObject<<endl<<endl; //use to error check for verbs
	interpretInput(B);
}

void AdvParser::interpretInput(User& B)//calls the methods using the dictionary
{
	userFunc a;
	string b;
	objectPointer objPoint, iobjPoint;

	if((playerVerbSynonym.find(verb) != playerVerbSynonym.end()) && (directObject == "n" || directObject == "s" || directObject == "w"|| directObject == "e"|| directObject == "inv" || directObject == "look"))//currently only checks if direct object is a direction, eventually could change into a dictionary of items.
	{
		a = playerVerbSynonym[verb];//creates a to store location
		(B.*a)(directObject);//use pointer  USES ACTUAL DIRECT OBJECT, OK FOR MOVE
	}
	else if((verbSynonym.find(verb) != verbSynonym.end() && dObjectSynonym.find(directObject) != dObjectSynonym.end() )&&indirectObject == "")
	{
		b = verbSynonym[verb];//creates a to store location
		objPoint = dObjectSynonym[directObject];
		objPoint->beCalled(b, B);
		
	}
	else if((verbSynonym.find(verb) != verbSynonym.end() && dObjectSynonym.find(directObject) != dObjectSynonym.end() )&&(iObjectSynonym.find(indirectObject) != iObjectSynonym.end() ))
	{
		b = verbSynonym[verb];//creates a to store location
		objPoint = dObjectSynonym[directObject];
		iobjPoint = iObjectSynonym[indirectObject];
		objPoint->beCalled2(b, B,iobjPoint);
	}
	else
	{
		if(verbSynonym.find(verb) == verbSynonym.end())
			cout<<"I don't understand " <<verb<<"."<<endl;
		else
			cout<<"I don't understand " <<directObject<<"."<<endl;
	}

}

AdvParser::AdvParser()
{
	verb = "";
	directObject = "";
	indirectObject = "";
		
};
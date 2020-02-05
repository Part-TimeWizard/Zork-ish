#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "InteractObject.h"

using namespace std;


User::User()
{
	location = "Mirror Room";
	playerx = 2;
	playery = 1;

	locMap[1][2].name = "Mirror Room";
	locMap[1][2].description = "A large, dark room with a large mirror along the west wall.\nA strange painting stands on the north wall, and a wooden door stands \non the eastern wall.";
	locMap[1][2].hasDoor = 'e';
	locMap[1][2].canEnter = true;
	locMap[1][3].name = "Tiny Room";
	locMap[1][3].description = "A small, damp room whose walls make you feel uncomfortable and \nslightly claustrophobic.";
	locMap[1][3].hasDoor = ' ';
	locMap[1][3].itemsHere[0] = "sword";
	locMap[1][3].canEnter = false;
	locMap[1][1].name = "The Ledge";
	locMap[1][1].description = "";
	locMap[1][1].hasDoor = ' ';
	locMap[1][1].canEnter = false;


	for(int i = 0; i < 10; i++)
	{
		inventory[i] = "";
	}
}

//move methods
void User::move(string s)
{
	char c = s[0];

	switch(c)
	{
		case 'n'://y+1
			if(locMap[playery+1][playerx].name != "")//is room valid?
			{
				if(locMap[playery+1][playerx].canEnter)//Can room be entered?
				{
					//yes
					playery++;
					location = locMap[playery][playerx].name;//new location
					cout<<getRDescription()<<endl<<endl;//print description

				}
				else
				{
					if(locMap[playery][playerx].hasDoor == 'n')//If no, why? Door?
					{
						cout<<"The door is closed"<<endl;
					}
					else//general no
					{
						cout<<"I can't go that way."<<endl;
					}
				}
			}
			else
			{
				cout<<"I can't go that way."<<endl;
			}
			break;
		case 's'://y-1
			if(locMap[playery-1][playerx].name != "")//is room valid?
			{
				if(locMap[playery-1][playerx].canEnter)//Can room be entered?
				{
					//yes
					playery--;
					location = locMap[playery][playerx].name;//new location
					cout<<getRDescription()<<endl<<endl;//print description

				}
				else
				{
					if(locMap[playery][playerx].hasDoor == 's')//If no, why? Door?
					{
						cout<<"The door is closed"<<endl;
					}
					else//general no
					{
						cout<<"I can't go that way."<<endl;
					}
				}
			}
			else
			{
				cout<<"I can't go that way."<<endl;
			}
			break;
		case 'w'://x--
			if(locMap[playery][playerx-1].name != "")//is room valid?
			{
				if(locMap[playery][playerx-1].canEnter)//Can room be entered?
				{
					//yes
					playerx--;
					location = locMap[playery][playerx].name;//new location
					cout<<getRDescription()<<endl<<endl;//print description

				}
				else
				{
					if(locMap[playery][playerx].hasDoor == 'w')//If no, why? Door?
					{
						cout<<"The door is closed"<<endl;
					}
					else//general no
					{
						cout<<"I can't go that way."<<endl;
					}
				}
			}
			else
			{
				cout<<"I can't go that way."<<endl;
			}
			break;
		case 'e'://x+1
			if(locMap[playery][playerx+1].name != "")//is room valid?
			{
				if(locMap[playery][playerx+1].canEnter)//Can room be entered?
				{
					//yes
					playerx++;
					location = locMap[playery][playerx].name;//new location
					cout<<getRDescription()<<endl<<endl;//print description

				}
				else
				{
					if(locMap[playery][playerx].hasDoor == 'e')//If no, why? Door?
					{
						cout<<"The door is closed"<<endl;
					}
					else//general no
					{
						cout<<"I can't go that way."<<endl;
					}
				}
			}
			else
			{
				cout<<"I can't go that way."<<endl;
			}
			break;
		default:
			cout<<"I can't move there"<<endl;
	}
}

string User::getLocation()
{
	return location;
}
string User::getRDescription()//helper method for move
{
	string strReturn = "" + locMap[playery][playerx].name + "\n" + locMap[playery][playerx].description;
	int i = 0;
	while(i<5 && locMap[playery][playerx].itemsHere[i] != "")
	{
		strReturn += "\nA " + locMap[playery][playerx].itemsHere[i] + " lies on the floor.";
		i++;
	}
	return strReturn;
}

void User::printRDescription(string s)
{
	string strReturn = "" + locMap[playery][playerx].name + "\n" + locMap[playery][playerx].description;
	int i = 0;
	while(i<5 && locMap[playery][playerx].itemsHere[i] != "")
	{
		strReturn += "\nA " + locMap[playery][playerx].itemsHere[i] + " lies on the floor.";
		i++;
	}
	cout<<strReturn<<endl;
}

void User::addRInventory(string s)
{
	for(int i = 0; i < 5; i++)
	{
		if(locMap[playery][playerx].itemsHere[i] == "")
		{
			locMap[playery][playerx].itemsHere[i] = s;
			break;
		}
	}
};

void User::removeRInventory(string s)
{
	int empty = 0;
	for(int i = 0; i < 5; i++)
	{
		if(locMap[playery][playerx].itemsHere[i] == s)
		{
			locMap[playery][playerx].itemsHere[i] = "";
			empty = i;
			break;
		}
	}
	for(int j = empty; j < 4; j++)
	{
		locMap[playery][playerx].itemsHere[j] = locMap[playery][playerx].itemsHere[j+1];
	}
	locMap[playery][playerx].itemsHere[4] = "";
};

void User::unlock(string s)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(locMap[i][j].name == s)
			{
				if(locMap[i][j].canEnter)
				{
					locMap[i][j].canEnter = false;
				}
				else
				{
					locMap[i][j].canEnter = true;
				}
			}
		}
	}
}





//Inventory methods
bool User::inventorySpace()//is there space in the inventory
{
	for(int i = 0; i < 10; i++)
	{
		if(inventory[i] == "")
			return true;
	}
	return false;
}

void User::addInventory(string s)
{
	for(int i = 0; i < 10; i++)
	{
		if(inventory[i] == "")
		{
			inventory[i] = s;
			break;
		}
	}
};

void User::removeInventory(string s)
{
	int empty = 0;
	for(int i = 0; i < 10; i++)
	{
		if(inventory[i] == s)
		{
			inventory[i] = "";
			empty = i;
			break;
		}
	}
	for(int j = empty; j < 9; j++)
	{
		inventory[j] = inventory[j+1];
	}
	inventory[9] = "";
};

void User::printInventory(string s)//string s needed to make map work
{
	cout<<"[";
	int i = 0;
	while(i<10 && inventory[i] != "")
	{
		if(i != 0)
		{
			cout<<", ";
		}
		cout<<inventory[i];
		i++;
	}
	if(i == 0)
	{
		cout<<"Empty";
	}
	cout<<"]"<<endl;
};
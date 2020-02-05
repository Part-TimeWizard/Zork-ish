#include <iostream>
#include <string>
#include <map>
#include "User.h"
#include "AdvParser.h"

using namespace std;


int main()
{
	User Player;
	AdvParser b;
	b.initMap();

	string input;

	cout<<"ZORK-ish  v1.6"<<endl;
	cout<<"Updated 10/28/17"<<endl;
	cout<<"PTW-NJM"<<endl<<endl;

	cout<<"The Mirror Room"<<endl<<"You wake up in a large, dark room with a large mirror along the west wall.\nA strange painting stands on the north wall, and a wooden door stands \non the eastern wall."<<endl<<endl;
	do
	{
		cout<<endl<<">>>";
		getline(cin, input);
		if(input == "Frobozz")
			break;
		b.parseInput(input,Player);
	}while(Player.getLocation() != "The Ledge");


	cout<<endl<<"You step through where the mirror once resided and find yourself on a tall "<<endl<<"outcropping of rock. You look out and see the walls of a massive cavern rise"<<endl;
	cout<<"above your head, disapearing into the darkness. Turning back forward, you see a"<<endl<<"magnificent city hewn from the same stone as the cavern.  Tightening your "<<endl<<"grip on the sword, you wonder what new adventures await."<<endl;
	cout<<"<Press ENTER to Continue>";
	cin.get();
	cout<<"The End?"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"<Press ENTER to Continue>";
	cin.get();
	cout<<endl<<"What?  That's it.  That's all I've got."<<endl;
	cin.get();
	cout<<endl<<"I know it's not much, but it takes a lot of time to make "<<endl<<"this stuff."<<endl;
	cin.get();
	cout<<endl<<"I'm a high school student.  I have finals I have to study for..."<<endl;
	cin.get();
	cout<<endl<<"I've got to study for Calculus, Computer Science, Language Arts,"<<endl<<"it's a rough life."<<endl;
	cin.get();
	cout<<endl<<"Not to mention practice for sports, and I'd actually like to get some sleep."<<endl;
	cin.get();
	cout<<endl<<"See?  So I don't have time to make more of this."<<endl;
	cin.get();
	cout<<endl<<"If you want more, then play the actual Zork.  They did a much better job "<<endl<<"than I did."<<endl;
	cin.get();
	cout<<endl<<"Its a huge game, at least 1 MB in size.  A bunch of MIT guys made it.  It's "<<endl<<"pretty sweet."<<endl;
	cin.get();
	cout<<endl<<"So... Go on now... That's it."<<endl;
	cin.get();
	cout<<endl<<"Please?"<<endl;
	cin.get();
	cout<<endl<<"Pretty please?"<<endl;
	cin.get();
	cout<<endl<<"With a cherry on top?"<<endl;
	cin.get();
	cout<<endl<<"C'mon, really, there isn't anything else."<<endl;
	cin.get();
	cout<<endl<<"This is it."<<endl;
	cin.get();
	cout<<endl<<"So... See ya"<<endl;
	
	
	return 0;
}
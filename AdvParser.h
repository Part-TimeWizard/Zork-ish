using namespace std;

class AdvParser{
public:
	void initMap();
	void parseInput(string userInput, User& B);
	void interpretInput(User& B);
	string getVerb();
	string getdObj();
	string getiObj();
	AdvParser();

private:
	string verb;
	string directObject;
	string indirectObject;
};
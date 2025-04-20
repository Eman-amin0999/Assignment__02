#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void add() {
	ofstream adding("players.txt", ios::app);
	string playername, team, role;
	int wicket, runs;
	if (adding.is_open()) {
		cout << "enter Player Name: " << endl;
		cin.ignore();
		getline(cin, playername);

		cout << "enter Team Name: " << endl;
		getline(cin, team);

		cout << "enter Player Role: " << endl;
		getline(cin, role);

		cout << "enter total Runs of Player: " << endl;
		cin >> runs;

		cout << "enter total wickets of Player: " << endl;
		cin >> wicket;

		adding << playername <<" " << team <<" " << role <<" " << runs << " " << wicket << endl;
		cout << "player record entered Successfully" << endl;
		adding.close();

	}
}
void view() {
	string str;
	ifstream view("players.txt");
	if (view.is_open()) {
		while (getline(view, str)){
			cout << str << endl;
		}
	}
	else {
		cout << "error in file opeing" << endl;
	}
	view.close();
}
void search() {
	ifstream searching("players.txt");
	if (!(searching.is_open())) {
		return;
	}
	string playernametofind;
	string findplayername, findteam, findrole;
		int findwicket, findruns;
		bool found = false;

		cout << "Enter Player Name to find: " << endl;
		cin.ignore();
		getline(cin, playernametofind);

		while (searching >> findplayername >> findteam >> findrole >> findwicket >> findruns) {
			if (playernametofind == findplayername) {
				cout << "Name " << findplayername << "TeamName:" << findteam << " Player Role:" << findrole <<
					"Player Wickets:" << findwicket << " Player Runs:" << findruns << endl;
				found = true;
			}
		}
		if (found == true) {
			cout << "Player Found Successfully" << endl;
		}
		else {
			cout << "Player with this Name " << playernametofind << " Not Found" << endl;
		}
		searching.close();
}
void update() {
	ifstream updating("players.txt");
	ofstream temp("temp.txt");

	int replacingRuns, replacingWickets;
	string playernametoupdate;
	string updateplayername, updateteam, updaterole;
	int updatewicket, updateruns;
	bool found = false;

	cout << "Enter Player Name to find: " << endl;
	cin.ignore();
	getline(cin, playernametoupdate);
	while (updating >> updateplayername >> updateteam >> updaterole >> updatewicket >> updateruns) {
		if (playernametoupdate == updateplayername) {
			cout << "Enter Run to Update: ";
			cin >> replacingRuns;

			cout << "Enter Wickets to Update: ";
			cin >> replacingWickets;

			updateruns = replacingRuns;
			updatewicket = replacingWickets;
			
			found = true;
			temp << " " << updateplayername << " " << updateteam
				<< " " << updaterole << " " <<updatewicket << " " << updateruns << endl;
		}
		else {
			
			temp << updateplayername << " " << updateteam << " " << updaterole << " "
				<< updatewicket << " " << updateruns << endl;
		}
	}
	updating.close();
	temp.close();
     remove("players.txt");
        rename("temp.txt", "players.txt");
         if (found == true) {
	       cout << "Players record updated sucessfully" << endl;
         }
         else {
	      cout << "Player with this name " << playernametoupdate << " not Found" << endl;
          }
       }
void del() {
	ifstream deleting("players.txt");  
	ofstream temp("temp.txt");  

	if (!deleting.is_open() || !temp.is_open())
	{
		cout << "Error in opening in File. ";
		return;
	}

	int deleteRuns, deleteWickets;
	string deletePlayerName, deleteTeam, deleteRole;

	string playernametodel;
	bool found = false;
	cout << "Enter Player name to Delete:" << endl;
	cin >> playernametodel;

	while (deleting >> deletePlayerName >> deleteTeam >> deleteRole >> deleteWickets >> deleteRuns) {
		if (playernametodel != deletePlayerName) {
			temp << " " << deletePlayerName << " " << deleteTeam
				<< " "<< deleteRole << " " << deleteWickets << " " << deleteRuns << endl;
		}
		else{
			found = true;
	}
	}
	deleting.close();
	temp.close();

	remove("players.txt");
	rename("temp.txt", "players.txt");
	if (found == true) {
		cout << "Players record deleted sucessfully" << endl;
	}
	else {
		cout << "Player with this name " << playernametodel << " not Found" << endl;
	}
}
int main() {
	int n;
	while (true){
	cout << "PSL Management System" << endl;
	cout << "Perss 1 to Add Player Record" << endl;
	cout << "Perss 2 to View all the Players " << endl;
	cout << "Perss 3 to Search Player by Name or by Team " << endl;
	cout << "Perss 4 to Update Player Status " << endl;
	cout << "Perss 5 to Delete Player Record " << endl;
	cout << "Perss 6 to Exit from Menu " << endl;
	cin >> n;
	
		if (n == 1) {
			add();
		}
		else if (n == 2) {
			view();
		}
		else if (n == 3) {
			search();
		}
		else if (n == 4) {
			update();
		}
		else if (n == 5) {
			del();
		}
		else if (n == 6) {
			cout << "you enter exit button" << endl;
			break;
		}
		else{
			cout << "you enter invalid button ,Try Again" << endl;
	}
	} 
	return 0;
}

// Basic Login App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void login();
void registration();
void forgot();

int main() {
	string ans, ret;
	int choice;
	cout << "\t\t\t____________________________________________________\n\n\n ";
	cout << "\t\t\t_____Hi, welcome to my very basic login system._____\n\n\n ";
	cout << "\t\t\t_____Feel free to select from one of our options____\n\n\n ";
	cout << "\t\t\t___________________     MENU    ____________________\n\n";
	cout << "                                                          \n\n";
	cout << "\t| Press 1 to LOGIN" << endl;
	cout << "\t| Press 2 to register" << endl;
	cout << "\t| Press 3 if you forgot your PASSWORD" <<endl;
	cout << "\t| Press 4 to EXIT" <<endl;
	cout << "\n\t\t\tPlease select and option: ";
	cin >> choice;
	cout << endl;
	
	switch (choice) {
	case(1):
		login();
		break;
	case(2):
		registration();
		break;
	case(3):
		forgot();
		break;
	case(4):
		cout << "\t\t\t Bye bye! \n" << endl;
		break;
	default:
		system("cls");
		cout << "\t\t\t Please choose a valid option\n" << endl;
		main();
	}
	return 0;
}
void login() {
	bool count = false;
	string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t USERNAME ";
	cin >> userId;
	cout << endl << "\t\t\t PASSWORD ";
	cin >> password;
	ifstream input("database.txt");
	while (input >> id >> pass) {
		if (id == userId && pass == password) {
			count =true;
			system("cls");
			input.close();
			cout << "\t\t\t Welcome in " << userId << ", I hope you enjoy your time"<<endl;
			
		}
	}
	if(!count) {
		cout << "\t\t\t Sorry, the username or password is incorrect. Please check your username and password";
	}
	system("pause");
	system("cls");
	main();
	return;
}
void registration() {
	string userId, password, checkerId, pass;
	system("cls");
	cout << "\t\t\t Please enter username: ";
	cin >> userId;
	cout << "\t\t\t Please enter password: ";
	cin >> password;

	ifstream input("database.txt");
	while (input >> checkerId >> pass) {
		if (checkerId == userId) {
			cout << "\t\t\t We apologize but that username is taken. Please try again.";
			system("pause");
			registration();
			return;
		}
	}
	input.close();
	ofstream write("database.txt", ios::app);
	write << userId << " " << password<<endl;
	write.close();
	cout << "\t\t\t Registration successful."<<endl;
	system("pause");
	system("cls");
	main();
	
	
	return;
}
void forgot() {
	string userId, user, pass;
	cout << "\t\t\tThat's ok, we'll find it for you. Just tell us the username: ";
	cin >> userId;
	ifstream input("database.txt");
	while (input >> user >> pass) {
		if (user == userId) {
			cout << "\t\t\t We found it. Your password is " << pass<<endl;
			system("pause");
			system("cls");
			main();
			return;
		}
	}
	input.close();
	cout << "We are sorry but no such users exist in our database. You're free to register though\n";
	system("pause");
	system("cls");
	main();
	return ;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctime>
#include <iomanip>

using namespace std;

//Global Declarations
bool isLogin;
int choice;

void OpenFile(string ch, bool check) {
	ifstream in(ch.c_str());
	if (!in) {
		cout << "Cannot open input file.\n";
	}
	char str[200];
	while (in) {
		in.getline(str, 200);
		if (in) {
			usleep(500000);
			if (check)
				cout << str << endl;
			else
				cout << str << " \t|" << endl;
		}
	}
	in.close();
}

void WriteFile(string ch, string data) {
	ofstream new_file;
	new_file.open(ch.c_str() ,ios::out);
	if(!new_file) {
		cout << "Cannot open input file.\n";
	}
	new_file << data.c_str();
	new_file.close();
}

int Confirm(string car, string no) {
	char cnfrm;
	cout << "    -> ";
	cin >> cnfrm;
	if (cnfrm == 'Y' || cnfrm == 'y') {
		WriteFile("CARS/confirm.txt", car.c_str());
		WriteFile("CARS/carno.txt", no.c_str());
	} else if (cnfrm == 'N'|| cnfrm == 'n') {
		system("cls");
		return 2;
	} else {
		cout << "    Enter Valid Choice\n";
		Confirm(car.c_str(), no.c_str());
	}
}

class Welcome {
	public:
		void welcome() {
			OpenFile("CARS/welcome.txt", true);
			sleep(1);
			cout << "\nStarting the program please wait....." << endl;
			sleep(1);
			cout << "\nloading up files....." << endl;
			sleep(1);
			system("CLS");
		}
};

class Login {
	private:
		char login_password[20];
		char stored_password[20];
		char login_username[20];
		char stored_username[20];
		char login_name[20];
		char stored_name[20];
		char register_user[20];
		char register_pass[20];
		char register_name[20];
	public:
		char cust_name[50];
		int Disp(int c) {
			if (c == 1) {
IsLogin:
				do {
					cout << "\n\tLogin With User & Pass\n";
					fstream pull("CARS/users.txt", ios::in);
					if (!pull) {
						cout << "File not loaded!" << endl;
						return -1;
					}
					cout << "\tUsername: ";
					cin >> login_username;
					while (strcmp(login_username, stored_username)) {
						pull >> stored_username;
						if (pull.eof()) {
							cout << "\tUsername does not exist." << endl;
							goto IsLogin;
						}
					}
					pull >> stored_password;
					cout << "\tPassword: ";
					cin >> login_password;
					while (strcmp(stored_password, login_password)) {
						cout << "\tWrong password, Try again\n\t";
						cin >> login_password;
					}
					cout << "\tChecking.";
					sleep(1);
					cout << ".";
					sleep(1);
					cout << ".";
					sleep(1);
					cout << ".";
					cout << "\33[2k\r";
					cout << "\tLogin Successful";
					isLogin=true;
					sleep(2);
				} while (!isLogin);
			} else {
				do {
					printf("\n\tRegister New User\n\n");
					ofstream MyFile("CARS/users.txt", ios::app);
					cout << "\tEnter Username: ";
					cin>>register_user;
					cout << "\tEnter Password: ";
					cin>>(register_pass);
					MyFile << "\n" << register_user<<"\n" << register_pass<<"\n";
					MyFile.close();
					system("CLS");
					goto IsLogin;
				} while (!isLogin);
			}
			return 0;
		}
};

class Rent : public Login {
	private:
		int days, rentalfee, carmodel, fuel;
		double rentdays, price;
		string custmobileno, CustName, fromdate;
	public:
		void data() {
			system("CLS");
			cout << "\n\tEnter your Name: ";
			cin >> CustName;
			cout << "\tEnter your Mobile no: ";
			cin >> custmobileno;
			cout << endl;
RentCar:
			cout << "\tPlease Select a Car\n" << endl;
			cout << "\t1. Maruthi Suzuki Swift" << endl;
			cout << "\t2. Hyundai Grand I10" << endl;
			cout << "\t3. Ford Figo" << endl;
			cout << "\t4. Maruthi Suzuki Ciaz" << endl;
			cout << "\t5. Hyundai Verna" << endl;
			cout << "\t6. Toyota Etios" << endl;
			cout << "\t7. Mahindra Xuv 500" << endl;
			cout << "\t8. Mahindra Scorpio" << endl;
			cout << "\t9. Hyundai Creta\n\n";
			cout << "\tChoose a Car from the above options: ";
			cin >> carmodel;
			system("CLS");
			if (carmodel == 1) {
				OpenFile("CARS/1.txt", true);
				price = 2200;
				if (Confirm("Swift 2016", "MH12SU3596") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 2) {
				OpenFile("CARS/2.txt", true);
				price = 2250;
				if (Confirm("I10 2015", "MH12CX1256") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 3) {
				OpenFile("CARS/3.txt", true);
				price = 2300;
				if (Confirm("Figo 2013", "MH10AN5629") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 4) {
				OpenFile("CARS/4.txt", true);
				price = 2500;
				if (Confirm("Ciaz 2018", "MH10CX5829") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 5) {
				OpenFile("CARS/5.txt", true);
				price = 2550;
				if (Confirm("Verna 2016", "MH12SX8487") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 6) {
				OpenFile("CARS/6.txt", true);
				price = 2600;
				if (Confirm("Etios 2017", "MH11EU1568") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 7) {
				OpenFile("CARS/7.txt", true);
				price = 3000;
				if (Confirm("XUV 500 2018", "MH12LV9856") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 8) {
				OpenFile("CARS/8.txt", true);
				price = 2950;
				if (Confirm("Scorpio 2016", "MH10CA2378") == 2) {
					goto RentCar;
				}
			} else if (carmodel == 9) {
				OpenFile("CARS/9.txt", true);
				price = 2900;
				if (Confirm("Creta 2018", "MH10CX6669") == 2) {
					goto RentCar;
				}
			} else {
				cout << "\n\n\tInvaild Car Model. Please try again!\n" << endl;
				goto RentCar;
			}
			cout << "\n    Enter Rent From Date (xx/xx/xxxx): ";
			cin >> fromdate;
			cout << "    Enter Number Of Days To Rent (xx): ";
			cin >> rentdays;
			cout << "\n    1. Car With Fuel (Price + Rs.2000)\n    2. Car Without Fuel\n    Enter Your Choice: ";
			cin >> fuel;
			cout<<"\n    This Car Is Booked.\n";
			system("pause");
			system("cls");
		}
		void Invoice() {
			cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
			cout << "\t\t	/////////////////////////////////////////////////////////" << endl;
			cout << "\t\t	| Invoice No.       : " << "--------------|" << "\t" << "#CN81353" << " \t|" << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "\t\t	| Invoice Date      : " << "--------------|" << "\t" << ltm->tm_mday << "/" <<  1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " \t|" << endl;
			cout << "\t\t	| Invoice Time      : " << "--------------|" << "\t" << ltm->tm_hour << ":" << ltm->tm_min  << ":" << ltm->tm_sec << " \t|" << endl;
			cout << "\t\t        | Customer Name     : " << "--------------|" << "\t" << CustName << " \t|" << endl;
			cout << "\t\t        | Contact Details   : " << "--------------|" << "\t" << custmobileno << " \t|" << endl;
			cout << "\t\t	| Car Model         : " << "--------------|" << "\t";
			OpenFile("CARS/confirm.txt", false);
			cout << "\t\t	| Car No.           : " << "--------------|" << "\t";
			OpenFile("CARS/carno.txt", false);
			cout << "\t\t        | From Date         : " << "--------------|" << "\t" << fromdate << " \t|" << endl;
			cout << "\t\t	| Number of Days    : " << "--------------|" << "\t" << rentdays << " \t\t|" << endl;
			double total = fuel == 1 ? price + 2000 * rentdays : price * rentdays;
			cout << "\t\t	| Total Amount      : " << "--------------|" << "\t" << total << " \t\t|" << endl;
			double advance = total * 0.45;
			cout << "\t\t	| Advance Amount    : " << "--------------|" << "\t" << advance << " \t\t|" << endl;
			cout << "\t\t	/////////////////////////////////////////////////////////" << endl;
			sleep(3);
			system("pause");
			system("CLS");
			OpenFile("CARS/thanks.txt", true);
		}
};

int main() {
	Login login;
	Rent rent;
	Welcome obj1;
	obj1.welcome();
	while (!isLogin) {
		cout << "\tChoose\n\t1. Login\n\t2. Register\n\tEnter Your Choice: ";
		cin >> choice;
		if (choice>2) {
			cout<<"\tEnter Valid Choice\n";
			isLogin = false;
		} else {
			login.Disp(choice);
			isLogin = true;
		}
	}
	rent.data();
	rent.Invoice();
	return 0;
}


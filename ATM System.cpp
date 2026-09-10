#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool MarkForDelete = false;
};

enum enMainMenuOptions
{
	QucikWithdraw = 1, NormalWithDraw = 2, Deposit = 3,
	CheckBalance = 4, Exit = 5
};

const string ClientsFileName = "Clients.txt";
stClient CurrentClient;

void ShowMainMenu();
void Login();
void ShowQuickWithdrawScreen();
void ShowNormalWithDrawScreen();

vector<string> SplitString(string S, string Delim)
{
	vector<string> vString;
	short Pos = 0;
	string Word = "";

	while ((Pos = S.find(Delim)) != std::string::npos)
	{
		Word = S.substr(0, Pos);
		if (Word != "")
		{
			vString.push_back(Word);
		}
		S.erase(0, Pos + Delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}

	return vString;
}

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	stClient Client;
	vector<string> vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}

string ConvertRecordToLine(const stClient& Client, string Seperator = "#//#")
{
	string ClientData = "";

	ClientData += Client.AccountNumber + Seperator;
	ClientData += Client.PinCode + Seperator;
	ClientData += Client.Name + Seperator;
	ClientData += Client.Phone + Seperator;
	ClientData += to_string(Client.AccountBalance);

	return ClientData;
}

vector<stClient> LoadClientsDataFromFile(string FileName)
{
	vector<stClient> vClients;
	fstream MyFile;

	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vClients.push_back(ConvertLineToRecord(Line));
		}
		MyFile.close();
	}

	return vClients;
}

void SaveClientsDataToFile(string FileName, vector<stClient>& vclients)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		string DataLine;
		for (stClient& Client : vclients)
		{
			if (Client.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(Client);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
}

bool AddDepositToClient(string AccountNumber, double Amount, vector<stClient>& vClients)
{
	char Sure = 'N';

	cout << "\n\nAre you sure you want perfrom this transaction? [Y / N] ";
	cin >> Sure;

	if (toupper(Sure) == 'Y')
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone Successfully. New balance is: "
					<< C.AccountBalance;
				return true;
			}
		}
		return false;
	}

	return false;
}

double ReadDepositAmount()
{
	double Amount;
	cout << "\nEnter a positive Deposit Amount? ";
	cin >> Amount;
	while (Amount <= 0)
	{
		cout << "\nEnter a positive Deposit Amount? ";
		cin >> Amount;
	}
	return Amount;
}

void PerfromDepositOption()
{
	double DepositAmount = ReadDepositAmount();
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	if (AddDepositToClient(CurrentClient.AccountNumber, DepositAmount, vClients))
	{
		CurrentClient.AccountBalance += DepositAmount;
	}
}

void ShowDepositScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t     Deposit Screen\n";
	cout << "===========================================\n";

	PerfromDepositOption();
}

short ReadQuickWithdrawOption()
{
	short Choice = 0;

	do
	{
		cout << "\nChoose what do you want to do? [1 to 9]? ";
		cin >> Choice;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid choise, Enter a valid one:" << endl;
			cin >> Choice;
		}

	} while (Choice <= 0 || Choice > 9);

	return Choice;
}

short getQuickWithDrawAmount(short QuickWithDrawOption)
{
	switch (QuickWithDrawOption)
	{
	case 1:
		return 20;
	case 2:
		return 50;
	case 3:
		return 100;
	case 4:
		return 200;
	case 5:
		return 400;
	case 6:
		return 600;
	case 7:
		return 800;
	case 8:
		return 1000;
	default:
		return 0;
	}
}

void PerfromQuickWithdrawOption(short QuickWithDrawOption)
{
	if (QuickWithDrawOption == 9)
		return;

	short WithDrawBalance = getQuickWithDrawAmount(QuickWithDrawOption);

	if (WithDrawBalance > CurrentClient.AccountBalance)
	{
		cout << "\nThe amount exceeds your balance, make another choice.\n";
		cout << "Press Anykey to continue...";
		system("pause>0");
		ShowQuickWithdrawScreen();
		return;
	}

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	if (AddDepositToClient(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients))
	{
		CurrentClient.AccountBalance -= WithDrawBalance;
	}
}

void ShowQuickWithdrawScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t     Qucik Withdraw\n";
	cout << "===========================================\n";
	cout << "\t[1] 20\t\t[2] 50\n";
	cout << "\t[3] 100\t\t[4] 200\n";
	cout << "\t[5] 400\t\t[6] 600\n";
	cout << "\t[7] 800\t\t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "===========================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance;

	PerfromQuickWithdrawOption(ReadQuickWithdrawOption());
}

int ReadWithDrawAmont()
{
	int Amount;
	cout << "\nEnter an amount multiple of 5's ? ";
	cin >> Amount;
	while (Amount % 5 != 0)
	{
		cout << "\nEnter an amount multiple of 5's ? ";
		cin >> Amount;
	}
	return Amount;
}

void PerfromNormalWithdrawOption()
{
	int WithDrawBalance = ReadWithDrawAmont();

	if (WithDrawBalance > CurrentClient.AccountBalance)
	{
		cout << "\nThe amount exceeds your balance, make another choice.\n";
		cout << "Press Anykey to continue...";

		system("pause>0");
		ShowNormalWithDrawScreen();

		return;
	}

	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	if (AddDepositToClient(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients))
	{
		CurrentClient.AccountBalance -= WithDrawBalance;
	}
}

void ShowNormalWithDrawScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t  Normal Withdraw Screen\n";
	cout << "===========================================\n";

	PerfromNormalWithdrawOption();
}

void ShowCheckBalanceScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t   Check Balance Screen\n";
	cout << "===========================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause>0");
	ShowMainMenu();
}

short ReadMainMenuOption()
{
	short Choice = 0;

	do
	{
		cout << "Choose what do you want to do? [1 to 5]? ";
		cin >> Choice;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid choise, Enter a valid one:" << endl;
			cin >> Choice;
		}

	} while (Choice <= 0 || Choice > 5);

	return Choice;
}

void PerfromMainMenueOption(enMainMenuOptions MainMenuOption)
{
	switch (MainMenuOption)
	{
	case enMainMenuOptions::QucikWithdraw:

		system("cls");
		ShowQuickWithdrawScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::NormalWithDraw:
		system("cls");
		ShowNormalWithDrawScreen();
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::Deposit:
		system("cls");
		ShowDepositScreen();
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::CheckBalance:
		system("cls");
		ShowCheckBalanceScreen();
		GoBackToMainMenu();
		break;
	case enMainMenuOptions::Exit:
		system("cls");
		Login();
	}
}

void ShowMainMenu()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t  ATM Main Menu Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "===========================================\n";

	PerfromMainMenueOption((enMainMenuOptions)ReadMainMenuOption());
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
	vector<stClient>vClients = LoadClientsDataFromFile(ClientsFileName);

	for (stClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{
			Client = C;
			return true;
		}
	}

	return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
	if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
		return true;
	else
		return false;
}

void Login()
{
	bool LoginFailed = false;
	string AccountNumber, PinCode;

	do
	{
		system("cls");

		cout << "===========================================\n";
		cout << "\t      Login Screen\n";
		cout << "===========================================\n";

		if (LoginFailed)
		{
			cout << "Invalid Account Number/PinCode!\n";
		}

		cout << "Enter AccountNumber? ";
		cin >> AccountNumber;
		cout << "Enter PinCode? ";
		cin >> PinCode;

		LoginFailed = !LoadClientInfo(AccountNumber, PinCode);

	} while (LoginFailed);

	ShowMainMenu();
}

int main()
{
	Login();

	return 0;
}
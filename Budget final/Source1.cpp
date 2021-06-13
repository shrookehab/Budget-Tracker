#include<iostream>


#include<istream>
#include<string>
#include <stdlib.h>
#include<conio.h>
#include<fstream>
#include <limits>
#define num 50
#define SurSize 20
#define ExSize 100
#define RecSize 100


using namespace std;


struct SourceInfo
{
	string SName;
	int month = NULL;
	int tybe = NULL;
	int Date = NULL;
	double Value = NULL;
};
struct ExpenseInfo
{
	string EName;
	int Date = NULL;
	double Value = NULL;
	int month = NULL;
};
struct RecurringInfo
{
	string RName;
	int Date = NULL;
	double Value = NULL;
};

void MainMenu();
double AddSource(SourceInfo Soln[], int);
double AddExpense(ExpenseInfo ExIn[], int);
double AddRecurring(int&, int&, int&, RecurringInfo food[], RecurringInfo&, RecurringInfo carfuel[], RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo others[]);

void ListRecurring(int&, int&, int&, RecurringInfo food[], RecurringInfo&, RecurringInfo carfuel[], RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo others[]);
void ListSource(SourceInfo SoIn[], int);
void ListExpense(ExpenseInfo ExIn[], int);

void EditSource(SourceInfo Soln[], int);
void EditExpense(ExpenseInfo ExIn[], int);
void EditRec(int&, int&, int&, RecurringInfo food[], RecurringInfo &, RecurringInfo carfuel[], RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo&, RecurringInfo othrs[]);

void DeleteSource(SourceInfo SoIn[], int&, double &);
void DeleteExpens(ExpenseInfo ExIn[], int&, double &);
void DeleteRec(int&, int&, int&, RecurringInfo food[], RecurringInfo &, RecurringInfo carfuel[], RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo &, RecurringInfo&, RecurringInfo othrs[], double &);

void DisDetalied(SourceInfo SoIn[], ExpenseInfo ExIn[], int, int, double, double, double, int, int, int, RecurringInfo food[], RecurringInfo, RecurringInfo carfuel[], RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo others[]);

void DisQuick(double, double, double);
double GenerateReport(SourceInfo Soln[], ExpenseInfo ExIn[], RecurringInfo Food[], RecurringInfo&, RecurringInfo CarFuel[], RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo&, RecurringInfo Others[], int&, int&, int&, int&, int&, int&, int&, int&, int&, double&);


void InFile(SourceInfo SoIn[], ExpenseInfo ExIn[], int, int, double, double, double, int, int, int, RecurringInfo food[], RecurringInfo, RecurringInfo carfuel[], RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo, RecurringInfo others[]);
void ReadData(SourceInfo SoIn[], ExpenseInfo ExIn[], int& NumSource, int& NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo Others[], RecurringInfo Food[], RecurringInfo HomeRent, RecurringInfo CarFuel[], RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill);


void main()
{
	cout << "||-----------------------------------------------------------------------------------------------||\n";
	cout << "||-----------------------------------------------------------------------------------------------||\n||\t\t\t\t \t\t\t\t \t\t\t\t ||\n";

	cout << "||\t\t\t\t \t\t\t\t \t\t\t\t ||\n||\t         Welcome in our programe \" BUDGET TRACKER \" ;)... \t\t\t\t ||\n||\t\t\t\t \t\t\t\t \t\t\t\t ||\n||\t\t\t\t \t\t\t\t \t\t\t\t ||" << endl;

	cout << "||-----------------------------------------------------------------------------------------------||\n";
	cout << "||-----------------------------------------------------------------------------------------------||\n";


	char charcter;

	cout << "\n\n\n  If you want to see our MAINMINUE soo press the leter \"M\" ;)...\n\n";

	cout << "  If you want to EXIT from our programe so press the leter \"E\"  :'(.... \n\n\t\t\t UR ANSWER IS :  ";

	cin >> charcter;

	if (charcter == 'm' || charcter == 'M') {
		system("cls");
		MainMenu(); //choice's function

	}

	else if (charcter == 'e' || charcter == 'E')
		exit(0); //to exit from the program


	system("pause");

}
//fuction that the user will choose from
void MainMenu()
{
	system("Color 7c");

	SourceInfo SoIn[num];
	ExpenseInfo  ExIn[num];
	//RecurringInfo RrIn[num];
	int NumSource = 0, SourcesEachTime;
	int NumExpense = 0, ExpenseEachTime;
	double UserSources = 0;
	double TotalExpenses = 0;
	double TotalRecurring = 0;
	RecurringInfo Food[num], HomeRent, CarFuel[num], ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others[num];
	int FoodCounter = 0, FuelCounter = 0, OtherCounter = 0;





	while (true) {

		//to read the saved data from a text file 
		ReadData(SoIn, ExIn, NumSource, NumExpense, UserSources, TotalExpenses, TotalRecurring, FoodCounter, FuelCounter, OtherCounter, Others, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill);


		int choice;  //the number of choice that the user will choose
		int EditChoice;
		cout << "Please enter number _1_ to Add New Incomes :)...\n\n";

		cout << "Please enter number _2_ to Add New (instantaneous) Expenses :)... \n\n";

		cout << "Please enter number _3_ to Add (Recurring) expenses :)... \n\n";

		cout << "Please enter number _4_ to display The List of recurring costs :)... \n\n";

		cout << "Please enter number _5_ to display The List of incomes sources :)... \n\n";

		cout << "Please enter number _6_ to display The List of Instant expense :)... \n\n";

		cout << "Please enter number _7_ to Edit any value :)... \n\n";

		cout << "Please enter number _8_ to Delete any value :)... \n\n";

		cout << "Please enter number _9_ to Show quick view on your current status (monthly) :) \n\n";

		cout << "Please enter number _10_ to Show the detailed status of a month :)... \n\n";

		cout << "Please enter number _11_ to generate a report :)... \n\n";

		cout << endl;
		cout << "YOUR ANS IS : ";

		cin >> choice;

		/*system("cls");*/
		switch (choice)
		{
		case 1:  //Income source
			system("cls");
			cout << "Hello user :) how many source you want to add : ";
			cin >> SourcesEachTime;
			while (cin.fail())
			{
				system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Hello user :) how many source you want to add : ";
				cin >> SourcesEachTime;

			}

			NumSource += SourcesEachTime;

			UserSources += AddSource(SoIn, NumSource);

			//	cout << "your total value of income during this month is : " << UserSources << endl;
			break;

		case 2:  //Inst. expenses
			system("cls");
			cout << "hello user :) how many expenses you want to add : ";
			cin >> ExpenseEachTime;
			while (cin.fail())
			{
				system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Hello user :) how many instantaneous expenses you want to add : ";
				cin >> ExpenseEachTime;

			}

			NumExpense += ExpenseEachTime;
			TotalExpenses += AddExpense(ExIn, NumExpense);
			//cout << "your total value of INSTANT expense during this month is : " << TotalExpenses << endl;

			break;

		case 3:  //Recurring expenses
			system("cls");

			TotalRecurring += AddRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);
			break;

		case 4:  //List of Recurring
			system("cls");
			ListRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);
			break;

		case 5:  //List of Income source
			system("cls");
			ListSource(SoIn, NumSource);
			break;

		case 6:
			system("cls");
			ListExpense(ExIn, NumExpense);

			break;

		case 7:  //Edit any value
			system("cls");

			{
				cout << "hello :) please select what do u want to edit :\n_1_Edit source\n_2_Edit expense\n_3_Edit recurring\n";
				cin >> EditChoice;
				switch (EditChoice)
				{
				case 1: //Edit source
					system("cls");
					EditSource(SoIn, NumSource);
					break;

				case 2://Edit expense
					system("cls");
					EditExpense(ExIn, NumExpense);
					break;

				case 3: //Edit Reccuring
					system("cls");
					EditRec(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);
					break;
				}
			}
			break;

		case 8://Delete
			system("cls");
			int DeleteChoice;
			cout << "Hello User :).. Please choose the number U want to delete :(... \n _1_DELETE Source :(.. \n _2_DELETE Expense :(.. \n _3_DELETE Reccuiring :(..\n THE ANSWER IS :  ";
			cin >> DeleteChoice;

			switch (DeleteChoice)
			{
			case 1://Delete Source
				system("cls");
				DeleteSource(SoIn, NumSource, UserSources);
				break;

			case 2://Delete Expens
				system("cls");
				DeleteExpens(ExIn, NumExpense, TotalExpenses);
				break;

			case 3://Delete Recurring
				system("cls");
				DeleteRec(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others, TotalRecurring);

				break;
			}
			break;

		case 9://Display Quick status
			system("cls");
			DisQuick(UserSources, TotalExpenses, TotalRecurring);
			break;

		case 10://Diplay Delailed status
			system("cls");
			DisDetalied(SoIn, ExIn, NumSource, NumExpense, UserSources, TotalExpenses, TotalRecurring, FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);
			break;

		case 11://Generated a report
			system("cls");
			cout << "\n  THE generate reporte choice to enter a specifed date range as U want from start date to the end date U want ;).. \n\t !!! DURING the same Year \" It means from January to December \" ;)... \n\t AAND the programe will show what you got and paid during this interval :).. \n\t  AT the end it will print to U if you saving or in debt and how much is money ;)... \n   ";
			system("cls");


			int StartDay, StartMonth, EndDay, EndMonth;


			cout << " Please enter the START date \"DAY\" :  ";
			cin >> StartDay;
			while (cin.fail())// while the end-of-file has not been reached
			{

				cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
				cout << " Please enter the START date \"DAY\" :  ";
				cin >> StartDay;


			}//end while (cin.fail())

			cout << "\n Please enter the START date \"MONTH\" :  ";
			cin >> StartMonth;
			while (cin.fail())// while the end-of-file has not been reached
			{


				cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
				cout << "\n Please enter the START date \"MONTH\" :  ";
				cin >> StartMonth;

			}//end while (cin.fail())

			cout << "\n Please enter the END date \"DAY\" :  ";
			cin >> EndDay;
			while (cin.fail())// while the end-of-file has not been reached
			{

				cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
				cout << "\n Please enter the END date \"DAY\" :  ";
				cin >> EndDay;

			}//end while (cin.fail())

			cout << "\n Please enter the END date \"MONTH\" :  ";
			cin >> EndMonth;


			while (cin.fail())// while the end-of-file has not been reached
			{

				cerr << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
				cout << "\n Please enter the END date \"MONTH\" :  ";
				cin >> EndMonth;

			}//end while (!cin.eof())

			cout << endl << endl;

			double Current = 0;

			cout << "START = " << Current << endl << endl;

			GenerateReport(SoIn, ExIn, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others, OtherCounter, NumSource, NumExpense, FoodCounter, FuelCounter, StartDay, StartMonth, EndDay, EndMonth, Current);



			cout << "END = " << Current << endl << endl;

			if (Current > 0)
				cout << "Today Is Ur Day :)).. U R SAVIIING MONEY ;)....\n\n";
			else if (Current < 0)
				cout << "WATCH OUT :<.. U R In DEBTT :<... \n\n";
			else
				cout << "TOO Baaad :(.. U HAVE NO MORE MONEY :(...  \n\n";
			cout << endl;

			cout << "-----------------------------------------------------------------------------------------------\n";

			cout << endl;
			break;

			//default:
			//cout << "\tUNDEFIND CHOICE :(.. \n\n";


		}

		//saving everything in a file :) 
		InFile(SoIn, ExIn, NumSource, NumExpense, UserSources, TotalExpenses, TotalRecurring, FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);


		string answer;

		cout << endl << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << "Please enter \"Yes\" if you want to back to the MainMenu :).. or \"No\" if you want to exit :(.. \n\n ";

		cin >> answer;//enter his choice ..

		cin.ignore();
		cout << endl;


		if (answer == "no" || answer == "No")
		{
			//clean screen at first then exit from the function
			system("cls");
			break; //to exit from this function

		}

		else
			system("cls");



	}


}
double AddSource(SourceInfo SoIn[], int NumSource)
{

	double UserSources = 0;
	int i = 0;

	while (i < NumSource)
	{
		//check foe an empty array to start filling the data in 
		if (SoIn[i].Value == NULL && SoIn[i].Date == NULL && SoIn[i].SName.size() == NULL)
		{
			cout << endl;
			cout << "please enter source  " << i + 1 << "  name :: ";
			cin.ignore();

			getline(cin, SoIn[i].SName);

			cout << endl;

			cout << "please enter source  " << i + 1 << "  date :: ";
			cin >> SoIn[i].Date;
			while (cin.fail())
			{
				//system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "please enter source  " << i + 1 << "  date :: ";
				cin >> SoIn[i].Date;

			}
			cout << endl;
			cout << "please enter source  " << i + 1 << "  value :: ";
			cin >> SoIn[i].Value;
			while (cin.fail())
			{
				//system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "please enter source  " << i + 1 << "  value :: ";
				cin >> SoIn[i].Value;

			}
			cout << endl;

			cout << "please enter your income tybe ( _1_for instant /_2_for recurrent) :: ";
			cin >> SoIn[i].tybe;
			while (cin.fail())
			{
				//system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "please enter your income tybe ( _1_for instant /_2_for recurrent) :: ";
				cin >> SoIn[i].tybe;

			}
			cout << endl;


			while (true)
			{
				if (SoIn[i].tybe == 1)
				{
					cout << " since this income is instant :) So plz enter the month you have it in (ex: April= 4)  :: ";
					cin >> SoIn[i].month;
					break;
				}
				if (SoIn[i].tybe == 2)
					break;

				if (SoIn[i].tybe != 1 || SoIn[i].tybe != 2)
				{
					cout << "wrong choice !! \n";
					cout << "please renter your income tybe ( _1_for instant /_2_for recurrent) :: ";
					cin >> SoIn[i].tybe;
					cout << endl;
				}
			}


			cout << "----------------------------------------------------------\n";
			UserSources += SoIn[i].Value;


		}
		else
			i++;
	}

	return UserSources;
}

double AddExpense(ExpenseInfo ExIn[], int NumExpense)
{

	double TotalExpense = 0;
	int i = 0;
	while (i < NumExpense)
	{

		if (ExIn[i].Value == NULL && ExIn[i].Date == NULL && ExIn[i].EName.size() == NULL)
		{
			cout << endl;
			cout << "enter expense  " << i + 1 << "  name : ";
			cin.ignore();
			getline(cin, ExIn[i].EName);
			cout << endl;

			cout << "enter expense  " << i + 1 << " day " << ":";
			cin >> ExIn[i].Date;
			while (cin.fail())
			{
				//system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "enter expense  " << i + 1 << " day " << ":";
				cin >> ExIn[i].Date;

			}

			cout << endl;
			cout << "enter expense " << i + 1 << "  month (ex: April= 4)  " << ":";
			cin >> ExIn[i].month;
			while (cin.fail())
			{
				//system("cls");
				cout << "ERROR !! wrong input " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "enter expense " << i + 1 << "  month (ex: April= 4)  " << ":";
				cin >> ExIn[i].month;

			}

			cout << endl;

			cout << "enter expense  " << i + 1 << "  value " << ":";
			cin >> ExIn[i].Value;
			cout << endl;

			TotalExpense += ExIn[i].Value;

		}

		else
			i++;

	}

	return TotalExpense;
}
//AddRecurring function
double AddRecurring(int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo Food[], RecurringInfo& HomeRent, RecurringInfo CarFuel[], RecurringInfo& ElecBill, RecurringInfo & WaterBill, RecurringInfo &GasBill, RecurringInfo& Wi_Fi, RecurringInfo &MobileBill, RecurringInfo Others[])
{
	int n;
	string ans = "yes";

	string answer;
	double TotalFood = 0, TotalFuel = 0, TotalOther = 0, TotalRecurring = 0;

	while (true)
	{
		system("cls");

		cout << "_1_Food\n_2_Car Fuel\n_3_Electricity Bill\n_4_Water Bill\n_5_Gas Bill\n_6_Wi_Fi <3 \n_7_Mobile Bill\n_8_Home Rent \n_9_OTHERS....\n";
		cin >> n;
		while (cin.fail())
		{
			system("cls");
			cout << "ERROR !! wrong input " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "_1_Food\n_2_Car Fuel\n_3_Electricity Bill\n_4_Water Bill\n_5_Gas Bill\n_6_Wi_Fi <3 \n_7_Mobile Bill\n_8_Home Rent \n_9_OTHERS....\n";
			cin >> n;

		}
		switch (n)
		{
		case 1:
			do
			{
				cout << "<<< Food " << FoodCounter + 1 << ">>>> \n ";
				cout << "The Date" << FoodCounter + 1 << " : " << endl;
				cin >> Food[FoodCounter].Date;
				cout << "value" << FoodCounter + 1 << " : " << endl;
				cin >> Food[FoodCounter].Value;
				TotalFood += Food[FoodCounter].Value;
				cout << "Do you want to add more food costs ? \"yes\" OR \"no\" \n ";
				cin >> answer;
				FoodCounter++;
			} while (answer == "yes" || answer == "Yes");
			break;
		case 2:
			do
			{
				cout << "<<< Car Fuel " << FuelCounter + 1 << " >>>" << endl;
				cout << "The Date " << FuelCounter + 1 << " : " << endl;
				cin >> CarFuel[FuelCounter].Date;
				cout << "value " << FuelCounter + 1 << " : " << endl;
				cin >> CarFuel[FuelCounter].Value;
				TotalFuel += CarFuel[FuelCounter].Value;
				cout << "Do you want to add more Car Fuel costs ? \"yes\" OR \"no\" \n";
				cin >> answer;
				FuelCounter++;
			} while (answer == "yes" || answer == "Yes");
			break;
		case 3:
			cout << "<<< Electricity Bill >>>\n ";
			cout << "The Date : ";
			cin >> ElecBill.Date;
			cout << " value : ";
			cin >> ElecBill.Value;
			TotalRecurring += ElecBill.Value;
			break;
		case 4:
			cout << "<<< Water Bill >>> \n ";
			cout << "The Date : ";
			cin >> WaterBill.Date;
			cout << " value : ";
			cin >> WaterBill.Value;
			TotalRecurring += WaterBill.Value;
			break;
		case 5:
			cout << "<<< Gas Bill >>> \n ";
			cout << "The Date : ";
			cin >> GasBill.Date;
			cout << " value : ";
			cin >> GasBill.Value;
			TotalRecurring += GasBill.Date;
			break;
		case 6:
			cout << "<<< Wi_Fi Bill >>>\n  ";
			cout << "The Date : ";
			cin >> Wi_Fi.Date;
			cout << "value : ";
			cin >> Wi_Fi.Value;
			TotalRecurring += Wi_Fi.Value;
			break;
		case 7:
			cout << "<<< Mobile Phone Bill >>>\n ";
			cout << "The Date : ";
			cin >> MobileBill.Date;
			cout << "value : ";
			cin >> MobileBill.Value;
			TotalRecurring += MobileBill.Value;
			break;
		case 8:
			cout << "<<< Home Rent >>>\n  ";
			cout << "The Date: ";
			cin >> HomeRent.Date;
			cout << "value : ";
			cin >> HomeRent.Value;
			TotalRecurring += HomeRent.Value;
			break;
		case 9:
		{	cout << "<<<OTHERS>>>\n";
		do
		{
			cout << "<<_" << OtherCounter + 1 << "_>>\n ";
			cout << "Name : ";
			cin.ignore();

			getline(cin, Others[OtherCounter].RName);

			cout << "Date : ";
			cin >> Others[OtherCounter].Date;
			cout << "Value : ";
			cin >> Others[OtherCounter].Value;
			TotalOther += Others[OtherCounter].Value;
			cout << "Do you want to add more Others costs ? \"yes\" OR \"no\" \n";
			cin >> answer;
			OtherCounter++;
		} while (answer == "yes" || answer == "Yes");
		}	break;
		}
		TotalRecurring += (TotalFood + TotalFuel + TotalOther);
		cout << endl << "-------------------------------------------------------------\n";
		cout << "Do you want to add more recurring data (yes/no)? ";
		cin >> ans;
		if (ans == "no")
			break;
	}
	return TotalRecurring;

}// End AddRecurring function

void EditSource(SourceInfo SoIn[], int NumSource)
{
	string answer = "yes";
	int i;
	string NewName;
	int NewMonth;
	int UserChoice, NewDate, ans;
	double NewVal;
	while (true)
	{

		ListSource(SoIn, NumSource);
		cout << "plz choose number of source you want to edit in :: ";
		cout << "you choice is :: ";
		cin >> UserChoice;
		while (cin.fail())
		{
			//system("cls");
			cout << "ERROR !! wrong input " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "you choice is :: ";
			cin >> UserChoice;

		}

		cout << "choose what do u want to edit in your selectd source \n_1_name\n_2_value\n_3_date\n_4_month(For your instant incomes only :)\n";
		cout << "your answer is :: ";
		cin >> ans;
		if (ans == 1)
		{
			cout << "please enter your New name :) : ";
			cin.ignore();
			getline(cin, NewName);
			SoIn[UserChoice - 1].SName = NewName;
			cout << "DONE :) " << endl;

		}
		if (ans == 2)
		{
			cout << "Enter your new value :: ";
			cin >> NewVal;
			SoIn[UserChoice - 1].Value = NewVal;
			cout << "DONE :) " << endl;

		}
		if (ans == 3)
		{
			cout << "Enter you new date :: ";
			cin >> NewDate;
			SoIn[UserChoice - 1].Date = NewDate;
			cout << "DONE :) " << endl;

		}
		if (ans == 4)
		{
			if (SoIn[UserChoice - 1].tybe == 1)
			{

				cout << "plz enter your new month ::";
				cin >> NewMonth;
				SoIn[UserChoice - 1].month = NewMonth;

				cout << "DONE :) " << endl;
			}
			else
				cout << "this is a recurrent source .. NO Month to edit \n";

		}
		cout << "Do u want to edit any more ! (yes/no) :";
		cin >> answer;
		if (answer == "no" || answer == "NO")
			break;
	}

}//end edit of source

//function to edit expense of the user
void EditRec(int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo Food[], RecurringInfo& HomeRent, RecurringInfo CarFuel[], RecurringInfo& ElecBill, RecurringInfo& WaterBill, RecurringInfo& GasBill, RecurringInfo& Wi_Fi, RecurringInfo& MobileBill, RecurringInfo Others[])
{

	int userAns, NewVal, NewDate;
	string NewName;
	char ans;
	do
	{
		ListRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);

		cout << endl << "choose what do u want to edit in your Recurring List \n ";
		cin >> userAns;
		switch (userAns)
		{
		case 1://Food edit
			int FoodNo, choice1;
			cout << "Which food no. you want to edit ?!! ";
			cin >> FoodNo;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n  ";
			cin >> choice1;
			if (choice1 == 1)
			{
				cout << "Enter your new value :: ";
				cin >> NewVal;
				Food[FoodNo - 1].Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice1 == 2)
			{
				cout << "Enter your new Date :: ";
				cin >> NewDate;
				Food[FoodNo - 1].Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		case 2://Car Fuel edit
			int CarFuelNo, choice2;
			cout << "Which car fuel no. you want to edit ?!! ";
			cin >> CarFuelNo;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n  ";
			cin >> choice2;
			if (choice2 == 1)
			{
				cout << "Enter your new value :: ";
				cin >> NewVal;
				CarFuel[CarFuelNo - 1].Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice1 == 2)
			{
				cout << "Enter your new Date :: ";
				cin >> NewDate;
				CarFuel[CarFuelNo - 1].Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		case 3://Electric bill edit
			int choice3;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n ";
			cin >> choice3;
			if (choice3 == 1)
			{
				cout << "<<< Electricity Bill (Value) >>>\n";
				cout << "enter new value of your Electricity Bill :\n";
				cin >> NewVal;
				ElecBill.Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice3 == 2)
			{
				cout << "<<< Electricity Bill (Date) >>>\n";
				cout << "enter new date of your Electricity Bill : \n";
				cin >> NewDate;
				ElecBill.Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		case 4://Home rent edit 
			int choice4;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date \n  ";
			cin >> choice4;
			if (choice4 == 1)
			{
				cout << "<<< Home Rent (Value) >>>\n";
				cout << "enter new value of your Home Rent : ";
				cin >> NewVal;
				HomeRent.Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice4 == 2)
			{
				cout << "<<< Home Rent (Date) >>>\n";
				cout << "enter new date of your Home Rent : ";
				cin >> NewDate;
				HomeRent.Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		case 5://Water bill edit 
			int choice5;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
			cin >> choice5;
			if (choice5 == 1)
			{
				cout << "<<< Water Bill (Value) >>>\n";
				cout << "enter new value of your Water Bill \n:";
				cin >> NewVal;
				WaterBill.Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice5 == 2)
			{
				cout << "<<<  Water Bill (Date) >>>\n";
				cout << "enter new date of your Water Bill :\n";
				cin >> NewDate;
				WaterBill.Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		case 6://Gas bill edit
			int choice6;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
			cin >> choice6;
			if (choice6 == 1)
			{
				cout << "<<< Gas Bill (Value) >>>\n";
				cout << "enter new value of your Gas Bill \n:";
				cin >> NewVal;
				GasBill.Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice6 == 2)
			{
				cout << "<<<  Gas Bill (Date) >>>\n";
				cout << "enter new date of your Gas Bill :\n";
				cin >> NewDate;
				GasBill.Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;
		case 7://Wi_Fi bill edit
			int choice7;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
			cin >> choice7;
			if (choice7 == 1)
			{
				cout << "<<< Wi_Fi Bill (Value) >>>\n";
				cout << "enter new value of your Wi_Fi Bill \n:";
				cin >> NewVal;
				Wi_Fi.Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice7 == 2)
			{
				cout << "<<<  Wi_Fi Bill (Date) >>>\n";
				cout << "enter new date of your Wi_Fi Bill :\n";
				cin >> NewDate;
				Wi_Fi.Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		case 8://Mobile bill edit
			int choice8;
			cout << "You want to edit the Value OR Date ?!\n _1_Value \n _2_Date  ";
			cin >> choice8;
			if (choice8 == 1)
			{
				cout << "<<< Mobile Bill (Value) >>>\n";
				cout << "enter new value of your Mobile Bill \n:";
				cin >> NewVal;
				MobileBill.Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice8 == 2)
			{
				cout << "<<<  Mobile Bill (Date) >>>\n";
				cout << "enter new date of your Mobile Bill :\n";
				cin >> NewDate;
				MobileBill.Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		case 9://other Rec. edit
			int OtherNo, choice9 = 0;
			string NewName;
			cout << "Which  no. you want to edit ?!! ";
			cin >> OtherNo;
			cout << "You want to edit the Name OR Value OR Date ?!\n _1_Name \n _2_Value \n _3_Date \n ";
			cin >> choice9;
			if (choice9 == 1)
			{
				cout << "please enter your New name :) : ";
				cin.ignore();
				getline(cin, NewName);
				Others[OtherNo - 1].RName = NewName;
				cout << "DONE :) " << endl;
			}
			if (choice9 == 2)
			{
				cout << "Enter your new Vale :: ";
				cin >> NewVal;
				Others[OtherNo - 1].Value = NewVal;
				cout << "Done :) " << endl;
			}
			if (choice9 == 3)
			{
				cout << "Enter your new Date :: ";
				cin >> NewDate;
				Others[OtherNo - 1].Date = NewDate;
				cout << "Done :) " << endl;
			}
			break;

		}
		cout << "Do you want to Edit more Recurring ? if yes press 'y' \n";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');


}//end edit recurring

void ListSource(SourceInfo SoIn[], int NumSource)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	if (SoIn[0].Value != NULL)
	{

		cout << "\t\tYour recurrent Sources is :: \n";

		cout << "---------------------------------------------------------------" << endl;
		cout << "#num\tname\t date\t value \n";
		cout << "---------------------------------------------------------------" << endl;

		for (int i = 0; i < NumSource; i++)
		{
			if (SoIn[i].tybe == 2)
				cout << i + 1 << "\t" << SoIn[i].SName << " \t" << SoIn[i].Date << " \t" << SoIn[i].Value << endl;

		}

		cout << "-----------------------------------------------------------------" << endl;
		cout << "\t\tAnd your instant incomes is :: \n";
		cout << "-----------------------------------------------------------------" << endl;
		cout << "#num\tname\t date\t month\t value \n";
		cout << "-----------------------------------------------------------------" << endl;

		for (int i = 0; i < NumSource; i++)
		{
			if (SoIn[i].tybe == 1)
				cout << i + 1 << "\t" << SoIn[i].SName << " \t" << SoIn[i].Date << " \t" << SoIn[i].month << "  \t" << SoIn[i].Value << endl;

		}
	}
	else
		cout << "no incomes entred yet " << endl;
	cout << "----------------------------------------------------------------------" << endl;




}//end list Source

void ListRecurring(int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo Food[], RecurringInfo& HomeRent, RecurringInfo CarFuel[], RecurringInfo& ElecBill, RecurringInfo& WaterBill, RecurringInfo& GasBill, RecurringInfo& Wi_Fi, RecurringInfo& MobileBill, RecurringInfo Others[])
{
	if (Food[0].Date != NULL)
	{
		cout << "                         <<_1_ Food detailes >>           \n ";
		cout << "Food no.\tDate\tValue\n";
		for (int i = 0; i < FoodCounter; i++)
		{
			cout << "    " << i + 1 << "     \t" << Food[i].Date << "     \t" << Food[i].Value << endl << endl;
		}
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (CarFuel[0].Date != NULL)
	{
		cout << "                       <<_2_ Car Fuel detailes >>           \n ";
		cout << "car fuel no.\tDate\tValue\n";
		for (int i = 0; i < FuelCounter; i++)
		{
			cout << "     " << i + 1 << "     \t" << CarFuel[i].Date << "    \t" << CarFuel[i].Value << endl << endl;
		}
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (ElecBill.Date != NULL)
	{
		cout << "                        <<_3_ Electricity Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << ElecBill.Date << "  \t\t" << ElecBill.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (HomeRent.Date != NULL)
	{
		cout << "                        <<_4_ Home Rent Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << HomeRent.Date << " \t \t" << HomeRent.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (WaterBill.Date != NULL)
	{
		cout << "                        <<_5_ Water Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << WaterBill.Date << "  \t\t" << WaterBill.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (GasBill.Date != NULL)
	{
		cout << "                        <<_6_ Gas Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << GasBill.Date << "  \t\t" << GasBill.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (Wi_Fi.Date != NULL)
	{
		cout << "                        <<_7_ Wi_Fi Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << Wi_Fi.Date << "  \t\t" << Wi_Fi.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (MobileBill.Date != NULL)
	{
		cout << "                        <<_8_ Mobile Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << MobileBill.Date << " \t \t" << MobileBill.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (Others[0].Date != NULL)
	{
		cout << "                         <<_9_ another detailes >>           \n ";
		cout << "#num\tName\tDate\tValue\n";
		for (int i = 0; i < OtherCounter; i++)
		{
			cout << i + 1 << "\t" << Others[i].RName << "     \t" << Others[i].Date << "     \t" << Others[i].Value << endl << endl;
		}
		cout << endl << "------------------------------------------------------------------------------\n";
	}


}// end list recurring

//function to edit expense of the user
void EditExpense(ExpenseInfo ExIn[], int NumOfExp) {
	string Answer;
	cout << "Hello User :)...\n";
	while (true) {

		int i;
		string NewName;
		int NewMonth;
		int UserChoice, NewDate, ans;
		double NewVal;

		ListExpense(ExIn, NumOfExp);

		cout << "plz choose number of instantaneous expense you want to edit in :: \n";
		cout << "you choice is :: ";
		cin >> UserChoice;
		cout << "choose what do u want to edit in your selectd expense \n_1_name\n_2_value\n_3_date\n_4_month\n";
		cout << "your answer is :: ";
		cin >> ans;
		if (ans == 1)
		{
			cout << "please enter your New name :) : ";
			cin.ignore();
			getline(cin, NewName);
			ExIn[UserChoice - 1].EName = NewName;
			cout << "DONE :) " << endl;

		}
		if (ans == 2)
		{
			cout << "Enter your new value :: ";
			cin >> NewVal;
			ExIn[UserChoice - 1].Value = NewVal;
			cout << "DONE :) " << endl;

		}
		if (ans == 3)
		{
			cout << "Enter you new date :: ";
			cin >> NewDate;
			ExIn[UserChoice - 1].Date = NewDate;
			cout << "DONE :) " << endl;

		}
		if (ans == 4)
		{
			cout << "plz enter your new month ::";
			cin >> NewMonth;
			ExIn[UserChoice - 1].month = NewMonth;

			cout << "DONE :) " << endl;
		}

		cout << " DO U want to EDIT any expenses ???(yes/no) :: ";
		cin.ignore();
		getline(cin, Answer);

		system("cls");

		if (Answer == "No" || Answer == "no")

			break;

		cout << "------------------------------------------------------------------------------------------------\n";


	}//end while

}//end of edit expense function

//function to delete source
void DeleteSource(SourceInfo SoIn[], int& NumSource, double & UserSources) {

	string Answer;


	while (true) {

		ListSource(SoIn, NumSource);//function that the user will choose from to delete

		cout << "\n\nPlease choose the number of the source U want to delete :(... : ";
		int ChoiceNum;
		cin >> ChoiceNum;

		while (cin.fail())
		{
			system("cls");
			cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
			cout << "\n\nPlease choose the number of the source U want to delete :(... ";
			cin >> ChoiceNum;

		}//end while (cin.fail())

		system("cls");

		bool IsDeleted = false;

		for (int i = 0; i < NumSource; i++) {
			if ((ChoiceNum - 1) == i) {//for Instant 
				for (int j = i; j < (NumSource - 1); j++) {
					SoIn[j].SName = SoIn[j + 1].SName;
					SoIn[j].Date = SoIn[j + 1].Date;
					SoIn[j].month = SoIn[j + 1].month;
					SoIn[j].Value = SoIn[j + 1].Value;
					SoIn[j].tybe = SoIn[j + 1].tybe;
					//SoIn[j] = SoIn[j + 1];

				}//end for j

				IsDeleted = true;
				break;
			}//end if (ChoiceNum == i)

			else
				IsDeleted = false;

		}//end for i

		NumSource--;

		if (IsDeleted) {
			UserSources -= SoIn[ChoiceNum - 1].Value;

			cout << "\n-------------------------------------------------------------------------------------------------\n";

			cout << "Items Had Been Deleted :).....\n\n\tDo U want to delete another item :(...\n\n";

			cin.ignore();

			getline(cin, Answer);

			if (Answer == "no" || Answer == "No") {
				system("cls");
				break;

			}//end if answer


		}//end if (IsDeleted) 

		else
		{
			cout << "\n-------------------------------------------------------------------------------------------------\n";

			cout << "Trouble at deleting the items :(....\n\n\tDO U want to check UR choice again ???..\n\n";

			cin.ignore();

			getline(cin, Answer);

			if (Answer == "no" || Answer == "No") {
				system("cls");
				break;

			}//end if answer

		}//end else

	}//end while

	system("cls");


	cout << "\n-------------------------------------------------------------------------------------------------\n";
	cout << "\n\t\tHere is UR source list :) :)...\n\n";

	ListSource(SoIn, NumSource);

	cout << endl << endl;




}//end delete source function
//function to delete expenses
void DeleteExpens(ExpenseInfo ExIn[], int & NumOfExp, double & TotalExpenses) {

	string Answer;

	while (true) {

		ListExpense(ExIn, NumOfExp);//function that the user will choose from to delete

		cout << "\n\nPlease choose the number of the instant expense U want to delete :(... : ";
		int ChoiceNum;
		cin >> ChoiceNum;

		while (cin.fail())
		{
			system("cls");
			cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
			cout << "\n\nPlease choose the number of the instant expense U want to delete :(... : ";
			cin >> ChoiceNum;

		}//end while (cin.fail())

		system("cls");

		bool IsDeleted = false;

		for (int i = 0; i < NumOfExp; i++) {
			if ((ChoiceNum - 1) == i)
			{//for Instant 
				for (int j = i; j < (NumOfExp - 1); j++)
				{
					ExIn[j].EName = ExIn[j + 1].EName;
					ExIn[j].Date = ExIn[j + 1].Date;
					ExIn[j].month = ExIn[j + 1].month;
					ExIn[j].Value = ExIn[j + 1].Value;

				}//end for j

				IsDeleted = true;
				break;
			}//end if (i == choicenum)

			else
				IsDeleted = false;

		}//end for i

		NumOfExp--;

		if (IsDeleted) {

			TotalExpenses -= ExIn[ChoiceNum - 1].Value;
			cout << "\n-------------------------------------------------------------------------------------------------\n";

			cout << "Items Had Been Deleted :).....\n\n\tDo U want to delete another item(yes/no) :(...\n\n";

			cin.ignore();

			getline(cin, Answer);

			if (Answer == "no" || Answer == "No") {
				system("cls");
				break;

			}//end if answer


		}//end if (IsDeleted) 

		else
		{
			cout << "\n-------------------------------------------------------------------------------------------------\n";

			cout << "Trouble at deleting the items :(....\n\n\tDO U want to check UR choice again(yes/no) ???..\n\n";

			cin.ignore();

			getline(cin, Answer);

			if (Answer == "no" || Answer == "No") {
				system("cls");
				break;

			}//end if answer

		}//end else

	}//end while

	system("cls");


	cout << "\n-------------------------------------------------------------------------------------------------\n";
	cout << "\n\t\tHere is UR instant expense list :) :)...\n\n";

	ListExpense(ExIn, NumOfExp);

	cout << endl << endl;



}//end function of delete expense

//function to delete recurring expense
void DeleteRec(int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo Food[], RecurringInfo& HomeRent, RecurringInfo CarFuel[], RecurringInfo& ElecBill, RecurringInfo& WaterBill, RecurringInfo& GasBill, RecurringInfo& Wi_Fi, RecurringInfo& MobileBill, RecurringInfo Others[], double & TotalRecurring)
{

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);



	string Answer;

	while (true)
	{

		cout << "\t\tHERE is UR recurring expense list :)...\n\n";

		cout << "\n-------------------------------------------------------------------------------------------------\n";

		ListRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);

		int ChoiceNum, ItemNum;
		cout << "Please choose what section U want to delete items from :(... \n\n\n";

		cout << "_1_Food\n\n_2_Car Fuel\n\n_3_Electricity Bill\n\n_4_Water Bill\n\n_5_Gas Bill\n\n_6_Wi_Fi <3 \n\n_7_Mobile Bill\n\n_8_Home Rent \n\n_9_OTHERS....\n\n";

		cin >> ChoiceNum;

		while (cin.fail())
		{
			system("cls");
			cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'
			cout << "Please choose what section U want to delete items from :(... \n\n\n";

			cout << "_1_Food\n\n_2_Car Fuel\n\n_3_Electricity Bill\n\n_4_Water Bill\n\n_5_Gas Bill\n\n_6_Wi_Fi <3 \n\n_7_Mobile Bill\n\n_8_Home Rent \n\n_9_OTHERS....\n\n";

			cin >> ChoiceNum;

		}//end while (cin.fail())








		system("cls");

		bool IsDeleted = false;

		switch (ChoiceNum) {

		case 1:
			cout << "Food no.\tDate\tValue\n";
			for (int i = 0; i < FoodCounter; i++)
			{
				cout << i + 1 << "\t" << Food[i].Date << "\t" << Food[i].Value << "$" << endl << endl;
			}
			cout << endl << "------------------------------------------------------------------------------\n";
			cout << "Please choose the number of the item u want to delete :(... \n";
			cin >> ItemNum;

			while (cin.fail())
			{
				system("cls");
				cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'

				cout << "Please choose the number of the item u want to delete :(... \n";
				cin >> ItemNum;

			}//end while (cin.fail())


			for (int i = 0; i < FoodCounter; i++) {
				if ((ItemNum - 1) == i) {
					for (int j = i; j < (FoodCounter - 1); j++) {

						Food[j].Date = Food[j + 1].Date;
						Food[j].Value = Food[j + 1].Value;

					}//end for j

					IsDeleted = true;
					break;

				}//end if (i == ItemNum)

				else
					IsDeleted = false;


			}//end for i


			FoodCounter--;

			if (IsDeleted) {
				TotalRecurring -= Food[ItemNum - 1].Value;

				cout << "\n-------------------------------------------------------------------------------------------------\n";

				cout << "Items Had Been Deleted :).....\n\n\tDo U want to delete another item :(...(yes OR no)\n\n";

				cin.ignore();

				getline(cin, Answer);

				if (Answer == "no" || Answer == "No") {
					system("cls");
					break;

				}//end if answer


			}//end if (IsDeleted) 

			else
			{
				cout << "\n-------------------------------------------------------------------------------------------------\n";

				cout << "Trouble at deleting the items :(....\n\n\tDO U want to check UR choice again(yes/no) ???..\n\n";

				cin.ignore();

				getline(cin, Answer);

				if (Answer == "no" || Answer == "No") {
					system("cls");
					break;

				}//end if answer

			}//end else

			break;
			//end case 1

		case 2:
			cout << "car fuel no.\tDate\tValue\n";
			for (int i = 0; i < FuelCounter; i++)
			{
				cout << i + 1 << "\t" << CarFuel[i].Date << "\t" << CarFuel[i].Value << "$" << endl << endl;
			}
			cout << endl << "------------------------------------------------------------------------------\n";
			cout << "Please choose the number of the item u want to delete :(... \n";
			cin >> ItemNum;

			while (cin.fail())
			{
				system("cls");
				cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'

				cout << "Please choose the number of the item u want to delete :(... \n";
				cin >> ItemNum;

			}//end while (cin.fail())


			for (int i = 0; i < FuelCounter; i++) {
				if ((ItemNum - 1) == i) {
					for (int j = i; j < (FuelCounter - 1); j++) {

						CarFuel[j].Date = CarFuel[j + 1].Date;
						CarFuel[j].Value = CarFuel[j + 1].Value;

					}//end for j

					IsDeleted = true;
					break;

				}//end if (i == ItemNum)

				else
					IsDeleted = false;


			}//end for i


			FuelCounter--;

			if (IsDeleted) {

				TotalRecurring -= CarFuel[ItemNum - 1].Value;
				cout << "\n-------------------------------------------------------------------------------------------------\n";

				cout << "Items Had Been Deleted :).....\n\n\tDo U want to delete another item(yes/no) :(...\n\n";

				cin.ignore();

				getline(cin, Answer);

				if (Answer == "no" || Answer == "No") {
					system("cls");
					break;

				}//end if answer


			}//end if (IsDeleted) 

			else
			{
				cout << "\n-------------------------------------------------------------------------------------------------\n";

				cout << "Trouble at deleting the items :(....\n\n\tDO U want to check UR choice again(yes/no) ???..\n\n";

				cin.ignore();

				getline(cin, Answer);

				if (Answer == "no" || Answer == "No") {
					system("cls");
					break;

				}//end if answer

			}//end else

			break;
			//end case 2

		case 9:
			cout << "#num\tName\tDate\tValue\n";
			for (int i = 0; i < OtherCounter; i++)
			{
				cout << "_" << i + 1 << "_\t " << Others[i].RName << "\t" << Others[i].Date << "\t" << Others[i].Value << "$" << endl << endl;
			}
			cout << endl << "------------------------------------------------------------------------------\n";




			cout << "Please choose the number of the item u want to delete :(... \n";
			cin >> ItemNum;

			while (cin.fail())
			{
				system("cls");
				cout << " !!!!!ERORR :( it doesn't match the input .... \n"; //c error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');// to ignore all the input up to '\n'

				cout << "Please choose the number of the item u want to delete :(... \n";
				cin >> ItemNum;

			}//end while (cin.fail())


			for (int i = 0; i < OtherCounter; i++) {
				if ((ItemNum - 1) == i) {
					for (int j = i; j < (OtherCounter - 1); j++) {

						Others[j].RName = Others[j + 1].RName;
						Others[j].Date = Others[j + 1].Date;
						Others[j].Value = Others[j + 1].Value;

					}//end for j

					IsDeleted = true;
					break;

				}//end if (i == ItemNum)

				else
					IsDeleted = false;


			}//end for i


			OtherCounter--;

			if (IsDeleted) {

				TotalRecurring -= Others[ItemNum - 1].Value;
				cout << "\n-------------------------------------------------------------------------------------------------\n";

				cout << "Items Had Been Deleted :).....\n\n\tDo U want to delete another item (yes/no):(...\n\n";

				cin.ignore();

				getline(cin, Answer);

				if (Answer == "no" || Answer == "No")
				{
					system("cls");
					break;

				}//end if answer


			}//end if (IsDeleted) 

			else
			{
				cout << "\n-------------------------------------------------------------------------------------------------\n";

				cout << "Trouble at deleting the items :(....\n\n\tDO U want to check UR choice again (yes/no)???..\n\n";

				cin.ignore();

				getline(cin, Answer);

				if (Answer == "no" || Answer == "No") {
					system("cls");
					break;

				}//end if answer

			}//end else


			break;
			//end case 9

		case 3:
			TotalRecurring -= ElecBill.Value;
			ElecBill.Date = NULL;
			ElecBill.Value = NULL;
			break;

		case 4:
			TotalRecurring -= WaterBill.Value;
			WaterBill.Date = NULL;
			WaterBill.Value = NULL;

			break;

		case 5:
			TotalRecurring -= GasBill.Value;
			GasBill.Date = NULL;
			GasBill.Value = NULL;

			break;

		case 6:
			TotalRecurring -= Wi_Fi.Value;
			Wi_Fi.Date = NULL;
			Wi_Fi.Value = NULL;

			break;

		case 7:
			TotalRecurring -= MobileBill.Value;
			MobileBill.Date = NULL;
			MobileBill.Value = NULL;

			break;

		case 8:
			TotalRecurring -= HomeRent.Value;
			HomeRent.Date = NULL;
			HomeRent.Value = NULL;

			break;



			//end case 3,4,5,6,7,8
		}//end switch

		cout << "\n\n\tDo U want to delete another item (yes/no):(...\n\n";
		cin >> Answer;
		if (Answer == "no" || Answer == "NO")
			break;

	}//end while

	system("cls");


	cout << "\n-------------------------------------------------------------------------------------------------\n";
	cout << "\n\t\t\tHere is UR Recurring expense list :) :)...\n\n";

	ListRecurring(FoodCounter, FuelCounter, OtherCounter, Food, HomeRent, CarFuel, ElecBill, WaterBill, GasBill, Wi_Fi, MobileBill, Others);

}//end delete recurring expense function


//date range function
double GenerateReport(SourceInfo SoIn[], ExpenseInfo ExIn[], RecurringInfo Food[], RecurringInfo& HomeRent, RecurringInfo CarFuel[], RecurringInfo& ElecBill, RecurringInfo & WaterBill, RecurringInfo &GasBill, RecurringInfo& Wi_Fi, RecurringInfo &MobileBill, RecurringInfo Others[], int& OtherCounter, int& NumSource, int& NumExpense, int& FoodCounter, int& FuelCounter, int& StartDay, int& StartMonth, int& EndDay, int& EndMonth, double& Current)
{

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);



	while (true) {

		for (int i = 0; i < NumSource; i++) {//search for sources

			if (SoIn[i].tybe == 2) {//recurring source

				if (SoIn[i].Date == StartDay) {

					Current += SoIn[i].Value;

					cout << SoIn[i].Date << "/" << StartMonth << "  ";
					cout << "+" << SoIn[i].Value << " ";
					cout << SoIn[i].SName << "  [Tybe = Recuirring]  [Current = " << Current << "]";
					cout << endl << endl;
				}


			}//end if (SoIn[i].tybe == 2)

			if (SoIn[i].tybe == 1) {//instant source

				if (SoIn[i].Date == StartDay && SoIn[i].month == StartMonth) {

					Current += SoIn[i].Value;

					cout << SoIn[i].Date << "/" << SoIn[i].month << "  ";
					cout << "+" << SoIn[i].Value << " ";
					cout << SoIn[i].SName << "  [Tybe = Instantinous]  [Current = " << Current << "]";
					cout << endl << endl;

				}


			}//end if (SoIn[i].tybe == 1)
		}//end search for sources 

		for (int i = 0; i < NumExpense; i++) {//search for instant expenses

			if (ExIn[i].Date == StartDay && ExIn[i].month == StartMonth) {

				Current -= ExIn[i].Value;

				cout << ExIn[i].Date << "/" << ExIn[i].month << "  ";
				cout << "-" << ExIn[i].Value << " ";
				cout << ExIn[i].EName << "  [Tybe = Instantinous]  [Current = " << Current << "]";
				cout << endl << endl;
			}

		}//end search for expenses 

		//search for recurring expenses

		for (int i = 0; i < FoodCounter; i++) {//search for food
			if (Food[i].Date == StartDay) {

				Current -= Food[i].Value;

				cout << Food[i].Date << "/" << StartMonth << "  ";
				cout << "-" << Food[i].Value << " ";
				cout << "Food_" << i + 1 << "_ [Tybe = Recurring]  [Current = " << Current << "]";
				cout << endl << endl;

			}//end if 
		}//end for i


		for (int i = 0; i < FuelCounter; i++) {
			if (CarFuel[i].Date == StartDay) {

				Current -= CarFuel[i].Value;

				cout << CarFuel[i].Date << "/" << StartMonth << "  ";
				cout << "-" << CarFuel[i].Value << " ";
				cout << "CarFuel_" << i + 1 << "_ [Tybe = Recurring]  [Current = " << Current << "]";
				cout << endl << endl;

			}//end if 
		}//end for i


		for (int i = 0; i < OtherCounter; i++) {// search for other rec expenses
			if (Others[i].Date == StartDay) {

				Current -= Others[i].Value;

				cout << Others[i].Date << "/" << StartMonth << "  ";
				cout << "-" << Others[i].Value << " ";
				cout << Others[i].RName << " [Tybe = Recurring]  [Current = " << Current << "]";
				cout << endl << endl;

			}//end if 
		}//end for i

		if (ElecBill.Date == StartDay) {//to check if the Electricity Bill is in this date range

			Current -= ElecBill.Value;

			cout << ElecBill.Date << "/" << StartMonth << "  ";
			cout << "-" << ElecBill.Value << " ";
			cout << "Electricity Bill [Tybe = Recurring]  [Current = " << Current << "]";
			cout << endl << endl;

		}//end if

		if (WaterBill.Date == StartDay) {//to check if the Water Bill is in this date range

			Current -= WaterBill.Value;

			cout << WaterBill.Date << "/" << StartMonth << "  ";
			cout << "-" << WaterBill.Value << " ";
			cout << "Water Bill [Tybe = Recurring]  [Current = " << Current << "]";
			cout << endl << endl;

		}//end if

		if (GasBill.Date == StartDay) {//to check if the Gas Bill is in this date range

			Current -= GasBill.Value;

			cout << GasBill.Date << "/" << StartMonth << "  ";
			cout << "-" << GasBill.Value << " ";
			cout << "Gas Bill [Tybe = Recurring]  [Current = " << Current << "]";
			cout << endl << endl;

		}//end if

		if (Wi_Fi.Date == StartDay) {//to check if the Wi_Fi Bill is in this date range

			Current -= Wi_Fi.Value;

			cout << Wi_Fi.Date << "/" << StartMonth << "  ";
			cout << "-" << Wi_Fi.Value << " ";
			cout << "Wi_Fi Bill [Tybe = Recurring]  [Current = " << Current << "]";
			cout << endl << endl;

		}//end if

		if (MobileBill.Date == StartDay) {//to check if the Mobile Phone Bill is in this date range

			Current -= MobileBill.Value;

			cout << MobileBill.Date << "/" << StartMonth << "  ";
			cout << "-" << MobileBill.Value << " ";
			cout << "Mobile Phone Bill [Tybe = Recurring]  [Current = " << Current << "]";
			cout << endl << endl;

		}//end if

		if (HomeRent.Date == StartDay) {//to check if the Home Rent is in this date range

			Current -= HomeRent.Value;

			cout << HomeRent.Date << "/" << StartMonth << "  ";
			cout << "-" << HomeRent.Value << " ";
			cout << "Home Rent [Tybe = Recurring]  [Current = " << Current << "]";
			cout << endl << endl;

		}//end if

		if (StartMonth == 1 || StartMonth == 3 || StartMonth == 5 || StartMonth == 7 || StartMonth == 8 || StartMonth == 10 || StartMonth == 12) {

			if (StartDay == 31) {
				StartDay = 1;
				StartMonth++;
			}

			else if (StartDay < 31)

				StartDay++;



		}

		else if (StartMonth == 2) {

			if (StartDay == 28) {
				StartDay = 1;
				StartMonth++;
			}

			else if (StartDay < 28)

				StartDay++;

		}

		else if (StartMonth == 4 || StartMonth == 6 || StartMonth == 9 || StartMonth == 11) {


			if (StartDay == 30) {
				StartDay = 1;
				StartMonth++;
			}

			else if (StartDay < 30)

				StartDay++;


		}

		if (StartMonth == EndMonth) {
			if (StartDay == EndDay)
				break;
		}


	}//end while (true)


	return Current;

}//end date range function 

//to comput the total source, expense, reccuring from a specified date range
void DisQuick(double UserSources, double TotalExpenses, double TotalRecurring)
{

	double status = 0;
	status = UserSources - (TotalExpenses + TotalRecurring);
	cout << "your money left is : " << status << endl;
	if (status > 0)
		cout << "Horray :) you are saving money this month" << endl;
	else if (status < 0)
		cout << "OH NO :( you are depated " << endl;
	else
		cout << "you are not Saving any money " << endl;


}
void DisDetalied(SourceInfo SoIn[], ExpenseInfo ExIn[], int NumSource, int NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int FoodCounter, int FuelCounter, int OtherCounter, RecurringInfo Food[], RecurringInfo HomeRent, RecurringInfo CarFuel[], RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill, RecurringInfo Others[])
{
	int i = 0, j = 0, k = 0;
	if (SoIn[0].Value != NULL)
	{
		cout << "------------------------------------------------------------------------------\n";
		cout << "\t\tYour recurrent Sources is :: \n";

		cout << "------------------------------------------------------------------------------" << endl;
		cout << "#num\tname\t date\t value \n";
		cout << "------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < NumSource; i++)
		{
			if (SoIn[i].tybe == 2)
				cout << i + 1 << "\t" << SoIn[i].SName << " \t" << SoIn[i].Date << " \t" << SoIn[i].Value << endl;

		}

		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "\t\tAnd your instant incomes is :: \n";
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "#num\tname\t date\t month\t value \n";
		cout << "-----------------------------------------------------------------------------" << endl;

		for (int i = 0; i < NumSource; i++)
		{
			if (SoIn[i].tybe == 1)
				cout << i + 1 << "\t" << SoIn[i].SName << " \t" << SoIn[i].Date << " \t" << SoIn[i].month << "  \t" << SoIn[i].Value << endl;

		}
	}
	if (ExIn[0].Value != NULL)
	{

		//cout << "-------------------------------------------------------------------------------" << endl;

		cout << "\n----------------------------------------------------------------------\n";

		cout << "                     <<<your instant Expenses information >>>\n";

		for (int i = 0; i < NumExpense; i++)
		{

			cout << "#num\tdate\tvalue\t\n";

			cout << i + 1 << "\t" << ExIn[i].EName << "\t" << ExIn[i].Date << "\t" << ExIn[i].month << "\t" << ExIn[i].Value << "  \t";

			cout << endl;

		}


	}



	cout << "\n----------------------------------------------------------------------\n";
	cout << "\n----------------------------------------------------------------------\n";
	cout << "                    <<<Recurring information Details >>>\n";

	if (Food[0].Value != NULL)
	{
		cout << "                         <<_1_ Food detailes >>           \n ";
		cout << "Food no.\tDate\tValue\n";
		for (int i = 0; i < FoodCounter; i++)
		{
			cout << "    " << i + 1 << "     \t" << Food[i].Date << "     \t" << Food[i].Value << endl << endl;
		}
		cout << endl << "------------------------------------------------------------------------------\n";
	}

	if (CarFuel[0].Value != NULL)
	{

		cout << "                       <<_2_ Car Fuel detailes >>           \n ";
		cout << "car fuel no.\tDate\tValue\n";
		for (int i = 0; i < FuelCounter; i++)
		{
			cout << "     " << i + 1 << "     \t" << CarFuel[i].Date << "    \t" << CarFuel[i].Value << endl << endl;
		}
	}

	if (ElecBill.Value != NULL)
	{

		cout << endl << "------------------------------------------------------------------------------\n";
		cout << "                        <<_3_ Electricity Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << ElecBill.Date << "  \t\t" << ElecBill.Value << endl;
	}
	cout << endl << "------------------------------------------------------------------------------\n";

	if (HomeRent.Value != NULL)
	{

		cout << "                        <<_4_ Home Rent Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << HomeRent.Date << " \t \t" << HomeRent.Value << endl;
	}
	cout << endl << "------------------------------------------------------------------------------\n";
	if (WaterBill.Value != NULL)
	{

		cout << "                        <<_5_ Water Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << WaterBill.Date << "  \t\t" << WaterBill.Value << endl;

		cout << endl << "------------------------------------------------------------------------------\n";

	}
	if (GasBill.Value != NULL)
	{

		cout << "                        <<_6_ Gas Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << GasBill.Date << "  \t\t" << GasBill.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}

	if (Wi_Fi.Value != NULL)
	{

		cout << "                        <<_7_ Wi_Fi Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << Wi_Fi.Date << "  \t\t" << Wi_Fi.Value << endl;
		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (MobileBill.Value != NULL)
	{

		cout << "                        <<_8_ Mobile Bill >>>      \n ";
		cout << "The Date\tValue\n";
		cout << "   " << MobileBill.Date << " \t \t" << MobileBill.Value << endl;

		cout << endl << "------------------------------------------------------------------------------\n";
	}
	if (Others[0].Value != NULL)
	{

		cout << "                         <<_9_ another detailes >>           \n ";
		cout << "#num\tName\tDate\tValue\n";
		for (int i = 0; i < OtherCounter; i++)
		{
			cout << "_" << i + 1 << "_ " << Others[i].RName << "     \t" << Others[i].Date << "     \t" << Others[i].Value << endl << endl;
		}
		cout << endl << "------------------------------------------------------------------------------\n";
	}

	cout << "\n----------------------------------------------------------------------\n";
	cout << "\n----------------------------------------------------------------------\n";

	cout << "                 <<<<your current status  >>>>";
	double status = 0;
	status = UserSources - (TotalExpenses + TotalRecurring);
	cout << "your money left is : " << status << endl << endl;

	cout << "\n----------------------------------------------------------------------\n";


	/*if (status > 0)
	cout << "Horray :) you are saving money this month" << endl;
	else if (status < 0)
	cout << "OH NO :( you are depated " << endl;
	else
	cout << "you are not Saving any money " << endl;
	*/



}// end detailed status


//function to save data in files
void InFile(SourceInfo SoIn[], ExpenseInfo ExIn[], int NumSource, int NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int FoodCounter, int FuelCounter, int OtherCounter, RecurringInfo Food[], RecurringInfo HomeRent, RecurringInfo CarFuel[], RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill, RecurringInfo Others[])
{
	ofstream OutSource, OutExp, OutRecc;

	int SourceCount = NumSource, ExpenseCount = NumExpense, FoodCnt = FoodCounter, FuelCnt = FuelCounter, OthersCnt = OtherCounter;

	//saving the recurrent & instantinous sources in file
	OutSource.open("Source Info.txt");

	OutSource << "Sources\n";
	OutSource << SourceCount << "\n";

	for (int i = 0; i < SourceCount; i++)
	{
		if (SoIn[i].tybe == 1)
			OutSource << i + 1 << "\n" << SoIn[i].tybe << "\n" << SoIn[i].SName << "\n" << SoIn[i].Date << "\n" << SoIn[i].month << "\n" << SoIn[i].Value << endl;

		else if (SoIn[i].tybe == 2)
			OutSource << i + 1 << "\n" << SoIn[i].tybe << "\n" << SoIn[i].SName << "\n" << SoIn[i].Date << "\n" << SoIn[i].Value << endl;

	}

	OutSource.close();


	//saving the instantinous expense in another file
	OutExp.open("Instant Expense Info.txt");

	OutExp << "InstantExpenses\n";
	OutExp << ExpenseCount << "\n";

	for (int i = 0; i < ExpenseCount; i++)
	{

		OutExp << i + 1 << "\n" << ExIn[i].EName << "\n" << ExIn[i].Date << "\n" << ExIn[i].month << "\n" << ExIn[i].Value << "\n";


	}
	OutExp.close();




	//saving the recurring expenses in another file
	OutRecc.open("Reccurring Expenses Info.txt");

	OutRecc << "RecrringExpenses\n";

	OutRecc << FoodCnt << "\n";

	for (int i = 0; i < FoodCnt; i++)
	{
		OutRecc << i + 1 << "\n" << Food[i].Date << "\n" << Food[i].Value << endl;
	}

	OutRecc << FuelCnt << "\n";

	for (int i = 0; i < FuelCnt; i++)
	{
		OutRecc << i + 1 << "\n" << CarFuel[i].Date << "\n" << CarFuel[i].Value << endl;
	}

	OutRecc << ElecBill.Date << "\n" << ElecBill.Value << endl;


	OutRecc << HomeRent.Date << "\n" << HomeRent.Value << endl;


	OutRecc << WaterBill.Date << "\n" << WaterBill.Value << endl;

	OutRecc << GasBill.Date << "\n" << GasBill.Value << endl;

	OutRecc << Wi_Fi.Date << "\n" << Wi_Fi.Value << endl;

	OutRecc << MobileBill.Date << "\n" << MobileBill.Value << endl;

	OutRecc << OthersCnt << "\n";

	for (int i = 0; i < OthersCnt; i++)
	{
		OutRecc << i + 1 << "\n" << Others[i].RName << "\n" << Others[i].Date << "\n" << Others[i].Value << endl;
	}


	OutRecc.close();


}//end save data in files


void ListExpense(ExpenseInfo ExIn[], int NumOfExp)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (ExIn[0].Value != NULL)
	{

		cout << " #Num\t Name\t Day\t Value\t month\n";
		for (int i = 0; i < NumOfExp; i++)
		{
			cout << i + 1 << "\t" << ExIn[i].EName << "\t" << ExIn[i].Date << "\t " << ExIn[i].Value << "$\t" << ExIn[i].month << "\n";

		}
	}
	else
		cout << "No instntaneous expenses are entered yet \n";
	cout << "-----------------------------------------------------\n";
}
//function to read the saved data in files
void ReadData(SourceInfo SoIn[], ExpenseInfo ExIn[], int& NumSource, int& NumExpense, double UserSources, double TotalExpenses, double TotalRecurring, int& FoodCounter, int& FuelCounter, int& OtherCounter, RecurringInfo Others[], RecurringInfo Food[], RecurringInfo HomeRent, RecurringInfo CarFuel[], RecurringInfo ElecBill, RecurringInfo WaterBill, RecurringInfo GasBill, RecurringInfo Wi_Fi, RecurringInfo MobileBill)
{
	ifstream InSource, InExpense, InRecurring;

	string SourceData, ExpenseData, RecData; // the data will save in


	//read the saved data of Recurring & instantinous sources from te saved file

	string Title_1;
	int count_1;


	InSource.open("Source Info.txt");
	if (InSource.is_open()) { //if the file is openend it return true else return false

		//while (!InSource.eof()) {


		InSource >> Title_1;
		InSource >> count_1;

		NumSource = count_1;

		for (int i = 0; i < NumSource; i++)
		{
			int Index = i + 1;

			InSource >> Index;

			InSource >> SoIn[i].tybe;

			if (SoIn[i].tybe == 1) {
				getline(InSource, SoIn[i].SName);
				getline(InSource, SoIn[i].SName);
				//InSource >> SoIn[i].SName;
				InSource >> SoIn[i].Date;
				InSource >> SoIn[i].month;
				InSource >> SoIn[i].Value;
			} //end else if

			else if (SoIn[i].tybe == 2) {
				getline(InSource, SoIn[i].SName);
				getline(InSource, SoIn[i].SName);
				//InSource >> SoIn[i].SName;
				InSource >> SoIn[i].Date;
				InSource >> SoIn[i].Value;


			}//end else if

		}//end for

		//}//end while

		InSource.close();
	}//end if file is opened

	//else {

	//	cerr << "!!!ERROR opening the file :(.. \n\n\tPlease check if it is exist.... \n";

	//	exit(1);//the program faild


	//}


	//read the saved data of instantinous expenses from te saved file

	string Title_2;
	int count_2;


	InExpense.open("Instant Expense Info.txt");

	if (InExpense.is_open()) { //if the file is openend it return true else return false

		//while (!InExpense.eof()) {

		InExpense >> Title_2;
		InExpense >> count_2;

		NumExpense = count_2;

		for (int i = 0; i < NumExpense; i++)
		{
			int Index = i + 1;


			InExpense >> Index;
			getline(InExpense, ExIn[i].EName);
			getline(InExpense, ExIn[i].EName);
			//InExpense >> ExIn[i].EName;
			InExpense >> ExIn[i].Date;
			InExpense >> ExIn[i].month;
			InExpense >> ExIn[i].Value;


		}//end for

		//}//end while

		InExpense.close();

	}//end if file is opened

	//else {

	//	cerr << "!!!ERROR opening the file :(.. \n\n\tPlease check if it is exist.... \n";

	//	exit(1);//the program faild


	//}


	//read the saved data of Recurring expenses from te saved file

	string Title_3;
	int count_3, count_4, count_5;


	InRecurring.open("Reccurring Expenses Info.txt");


	if (InRecurring.is_open()) { //if the file is openend it return true else return false

		//while (!InRecurring.eof()) {

		InRecurring >> Title_3;
		InRecurring >> count_3;

		FoodCounter = count_3;

		for (int i = 0; i < FoodCounter; i++)
		{
			int Index = i + 1;

			InRecurring >> Index;
			InRecurring >> Food[i].Date;
			InRecurring >> Food[i].Value;
		}

		InRecurring >> count_4;
		FuelCounter = count_4;

		for (int i = 0; i < FuelCounter; i++)
		{
			int Index = i + 1;

			InRecurring >> Index;
			InRecurring >> CarFuel[i].Date;
			InRecurring >> CarFuel[i].Value;
		}

		InRecurring >> ElecBill.Date;
		InRecurring >> ElecBill.Value;


		InRecurring >> HomeRent.Date;
		InRecurring >> HomeRent.Value;


		InRecurring >> WaterBill.Date;
		InRecurring >> WaterBill.Value;

		InRecurring >> GasBill.Date;
		InRecurring >> GasBill.Value;

		InRecurring >> Wi_Fi.Date;
		InRecurring >> Wi_Fi.Value;

		InRecurring >> MobileBill.Date;
		InRecurring >> MobileBill.Value;

		InRecurring >> count_5;
		OtherCounter = count_5;

		for (int i = 0; i < OtherCounter; i++)
		{
			int Index = i + 1;

			InRecurring >> Index;
			getline(InRecurring, Others[i].RName);
			getline(InRecurring, Others[i].RName);
			//InRecurring >> Others[i].RName;
			InRecurring >> Others[i].Date;
			InRecurring >> Others[i].Value;
		}

		//}//end while

		InRecurring.close();

	}//end if file is opened

	//else {

	//	cerr << "!!!ERROR opening the file :(.. \n\n\tPlease check if it is exist.... \n";

	//	exit(1);//the program faild


	//}


}//end read data function

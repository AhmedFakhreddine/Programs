
#include <iostream>
#include <vector>
#include<string>
#include <time.h> 
#include <cstdlib>
#include<cctype>
#include<iomanip>


using namespace std;

class Person {
	private:
		string name, id, address;
		int age;
	
	public:
		//void setPrice(int pri) { price = pri; }
		//int getPrice() { return price; }

		Person(string n, string idNum, string add, int a) //Contructor to initalize variables 
		{
			name = n;
			id = idNum;
			address = add;	
			age = a;
		}

		void displayPepole()
		{
			cout << "Coustomer Name: "<< name << endl;
			cout << "Licsense Number: "<< id << endl;
			cout << "Coustmer Address: "<< address << endl;
			cout << "Age: "<< age << endl;
		}
	
};

class Seats {
protected:
	char ch, ticketType, column;
	int row; 
	double ticketTypeSeats;
	int amountPassangers;//Send amountPassangers from Class Flight. this is the amount of passangers inside People Vector
	char form[13][6];

public:
	void setPrice(int pri) { ticketTypeSeats = pri; }
	int getPrice() { return ticketTypeSeats; }

	void loop(int amountPassangers)
	{
		cout << "\n\n----------------------------------------------------------------------------------" << endl;
		cout << "Airplane Seating, please follow the following prompts to secure seats: "<<endl;
		initialize(form);
		amountPassangers = static_cast<char>(toupper(amountPassangers));
		
		for (int x = 0; x < amountPassangers; ++x)
		{
			getData(ticketType, row, column);
			printForm(form, row, column);
			amountPassangers = static_cast<char>(toupper(amountPassangers));	
		}
	}

	void initialize(char form[][6])
	{
		for (int i = 0; i < 13; i++)
			for (int j = 0; j < 6; j++)
				form[i][j] = '*';
	}

	void getData(char& ticketType, int& row, char& column)
	{
		int ticketTypeSeats;
		cout << "The airplane has 13 rows, with  six seats in each row. " << endl;

		cout << "Enter ticket type,\n"
			<< "F for first class (+$50), \n"
			<< "B for business class (+$25),\n"
			<< "E for economy class (+$10):" << endl;
		cin >> ticketType;
		ticketType = static_cast<char>(toupper(ticketType));
		while (ticketType != 'F' && ticketType != 'B'
			&& ticketType && ticketType != 'E')
		{
			cout << "Invalid ticket type." << endl;
			cout << "Enter ticket type,\n"
				<< "F for first class (+$50), \n"
				<< "B for business class (+$25),\n"
				<< "E for economy class (+$10):" << endl;
			cin >> ticketType;
			ticketType = static_cast<char>(toupper(ticketType));
		}
		switch (ticketType)
		{
		case 'F':
			cout << "Row 1 and 2 are first class,\n";
			ticketTypeSeats = 50;
			break;
		case 'B':
			cout << "row 3 throuh 7 are business class,\n";
			ticketTypeSeats = 25;
			break;
		case 'E':
			cout << "row 8 through 13 are economy class." << endl;
			ticketTypeSeats = 10; 
			break;
		}// end switch
		

		cout << "Enter the row number you want to sit: " << endl;
		cin >> row;

		cout << "Enter the seat number (from A to F). " << endl;
		cin >> column;
		column = static_cast<char>(toupper(column));
		

	}
	

	void printForm(char form[][6], int row, char column)
	{
		int i, j;

		if (form[row - 1][static_cast<int>(column - 65)] == 'X')
		{
			cout << "This seat already assigned. Choose another seat: " << endl;
			cin >> column;
			column = static_cast<char>(toupper(column));
		}
		form[row - 1][static_cast<int>(column) - 65] = 'X';

		cout << "* indicates that the seat is available; " << endl;
		cout << "X indicates that the seat is occupied. " << endl;
		cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C"
			<< setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;

		for (i = 0; i < 13; i++)
		{
			cout << left << setw(3) << "Row " << setw(2) << i + 1;
			for (j = 0; j < 6; j++)
			{
				cout << right << setw(6) << form[i][j];
			}
			cout << endl;
		}

	}
};


class Flight :	public Seats {
	private:
		vector<Person>pepole;
		Seats seats;
		string airlineName, airlineType;
		int aproxPassangers;
		int amountPassangers;
		int choice, choice2;
		string flightStateChoice;
		double flightFee, pricePerTicket;
		string stateFlight[50]  = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida",
									"Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland",
									"Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire",
									"New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania",
									"Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah",  "Vermont", "Virginia", "Washington",
									"West Virginia",  "Wisconsin", "Wyoming" };
									
									//miles corresponding to each state in order.
		int flightMiles[50] =	  { 740, 3800, 1911, 822, 2404, 1333, 629, 606, 1220,
									878, 4422, 1491, 409, 250, 582, 901, 365, 1003, 829, 468,
									694, 0, 750, 899, 639, 1500, 955, 1900, 681,
									636, 1400, 615, 664, 998, 177, 1002, 1989, 389,
									699, 738, 950, 597, 1300, 1600, 630, 590, 1900, 
									380, 300, 1200}; 
	public:
		Flight()
		{
			pricePerTicket = 0;
			flightFee = 0;
			choice = 0;
			choice2 = 0;
			amountPassangers = 0;
			srand(time(NULL));
			aproxPassangers = rand() % 80 + 1;
		}

		//////////////////////////////////////////////////////Vector gets added from Main Function//////////////////////////////////////////

		void getPersonInfo( Person p )
		{
			pepole.push_back(p); //adds the pepople to the vector from main and the class Person
			//displayOrder();
		}

		//////////////////////////////////////////////////////Vector gets added from Main Function//////////////////////////////////////////
		void airlines()
		{	
			cout << "\n\n----------------------------------------------------------------------------------" << endl;
			cout << "Select a option of airlines" << endl;
			cout << "1: Delta Airlines \n2: American Airlines \n3: United Arilines \n4: Spirt Airlines" << endl;
			cin >> choice;
			//cout << "The total out of 100 seats taken are " << aproxPassangers << endl;
			
			//this switch statement creates the price per mile by take a random function and calculating price by how many avalible seats.
			switch (choice)
			{
				case 1:
					airlineName = "Delta Arilines";
					if (aproxPassangers < 35)
						flightFee = .02;
					else if(aproxPassangers >= 35 || aproxPassangers < 65)
						flightFee = .03;
					else if (aproxPassangers >= 65 || aproxPassangers <= 80)
						flightFee = .05;
					pricePerTicket = aproxPassangers * flightFee;
					cout << "Deltas price per mile is $ " << pricePerTicket << endl;
					break;//breaks from case 1
				case 2:
					airlineName = "American Airlines";
					if (aproxPassangers < 35)
						flightFee = .01;
					else if (aproxPassangers >= 35 || aproxPassangers < 65)
						flightFee = .02;
					else if (aproxPassangers >= 65 || aproxPassangers <= 80)
						flightFee = .04;
					pricePerTicket = aproxPassangers * flightFee;
					cout << "American price per mile is $ " << pricePerTicket << endl;
					break;//breaks from case 2
				case 3:
					airlineName = "United Arilines";
					if (aproxPassangers < 35)
						flightFee = .02;
					else if (aproxPassangers >= 35 || aproxPassangers < 65)
						flightFee = .03;
					else if (aproxPassangers >= 65 || aproxPassangers <= 80)
						flightFee = .04;
					pricePerTicket = aproxPassangers * flightFee;
					cout << "United price per mile is $ " << pricePerTicket << endl;
					break;//breaks from case 3
				case 4:
					airlineName = "Spirt Airlines";
					if (aproxPassangers < 35)
						flightFee = .01;
					else if (aproxPassangers >= 35 || aproxPassangers < 65)
						flightFee = .02;
					else if (aproxPassangers >= 65 || aproxPassangers <= 80)
						flightFee = .03;
					pricePerTicket = aproxPassangers * flightFee;
					cout << "Spirt price per mile is $ " << pricePerTicket << endl;
					break;//breaks from case 4
				default:
					cout << "Input invailed" << endl;
					cin.ignore();
					airlines();
					break;
			}
			pricePerTicket = pricePerTicket * pepole.size();    //adds how many flighers and muliplys the price per ticket by the size.
			cout << "Price for " << pepole.size() << " Passangers are $ " << pricePerTicket;//displays the amout of passangers and the tickets
			cin.ignore();
			stateSelection();	
		}

		void stateSelection()
		{
			cout << "\n\n----------------------------------------------------------------------------------" << endl;
			cout << "\nEnter the State Destantion like prometed on the screen EX:'Michigan': ";
			getline(cin, flightStateChoice);
				
			for (int x = 0; x < 50; x++)
			{
				if (flightStateChoice == stateFlight[x])
				{
					cout << "\nThe miles for this flight is " << flightMiles[x] << endl;
					pricePerTicket *= flightMiles[x];
					cout << "The Total ticket price is $" << pricePerTicket << endl;
				}
			}											
			seatChoice();
		}

		void seatChoice()
		{
			cout << "\n\n--------------------------------------------------" << endl;
			cout << "\nOne-way or Round Trip?" << endl;
			cout << "1: One-way Trip (+$25)" << endl;
			cout << "2: Round Trip (+$50)" << endl;
			cout << "\nEnter your choice: ";
			cin >> choice2;

			switch (choice2)
			{			
			case 1:				
				cout << "One Way flight is an addtional $25" << endl;
				airlineType = "One Way";
				pricePerTicket += 25;
				cout << "Total Price: " << pricePerTicket<<endl;
				break;				
			case 2:				
				cout << "Round Trip flight is an addtional $50" << endl;
				airlineType = "Round Trip";
				pricePerTicket += 50;
				cout << "Total Price: " << pricePerTicket << endl;
				break;	
			case 0:
				system("cls");
				break;
			default:
				cout << "\nInvalid Choice! Sorry, the program will exit now.\n\n";
				system("cls");
				exit(0);
			}
			amountPassangers=pepole.size();
			loop(amountPassangers);
			pricePerTicket += seats.getPrice();
			//pricePerTicket += ticketTypeSeats;
			
			displayOrder();
			
		}
		
		void displayOrder()
		{
			cout << "\n\n--------------------------------------------------" << endl;
			cout << "Passangers In This Order " << pepole.size() << endl;
			for (Person attendding : pepole) //displays the vector like a member function
			{
				attendding.displayPepole(); //Displays the people in the vector
			}
			cout << "AirLine: " << airlineName<<endl;
			cout << "AirLine Path: " << airlineType<<endl; 
			cout << "Total Price: $" << pricePerTicket<<endl;
			cout << "Thank you for choosing United Michigan Airlines Services, come again\n\n\n";
		}

};//end class


int main()
{
	string name, id, address;
	int age;
	char choice = 'Y';
	bool valid = true;
	Flight flight;
	
	cout << "Thank you for choosing United Michigan Airlines Services, welcome" << endl;

	while (valid)//loops to ask if you want to add more pa
	{
		cout << "\nWould you like to add Passanger(Y/N)?" << endl;
		cin >> choice;
		if (choice == 'N' || choice == 'n') {
			flight.airlines();
			break;
		}
		if (choice == 'Y' || choice == 'y')
		{
			cout << "----------------------------------------------------------------------------------" << endl;
			cin.ignore();
			cout << "PASSENGER INFORMATION" << endl;

			cout << "\nEnter Full Name: ";
			getline(cin, name);
			cin.clear();

			cout << "\nEnter ID Number: ";
			getline(cin, id);
			cin.clear();

			cout << "\nEnter Street Address: ";
			getline(cin, address);
			cin.clear();

			cout << "\nEnter Your Age: ";
			cin >> age;

			while (age <= 0) // loop if they entered negative age
			{
				cout << "Sorry you typed in a wrong age" << endl;
				cin >> age;
			}

			while (age != 0)
			{
				if (1 <= age)
				{
					cout << "Welcome\n\n";
					break;
				}
			}

			for (int i = 0; i < 100; i++)
			{
				cout << "Loading...";
				system("cls");
			}
			Person p(name, id, address, age);	
			flight.getPersonInfo(p);		
		}
	}
	
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;


class CPU{
	private:
		string modelNumber;
		float speed;
		string manufacture;
		
	public:
		CPU(string m, string mn, float s)
		{
			modelNumber=mn;
			speed=s;
			manufacture=m;
		}	
		friend ostream& operator<<(ostream& o, CPU &cpu)
		 { 
			o<<"The CPU is made by: "<<cpu.manufacture<<endl; 
			o<<"Model#: "<<cpu.modelNumber<<endl;
			o<<"Speed: "<<cpu.speed<<" GHZ"<<endl;
			return o;
		}	
};//endlcass

class Motherboard{
	private:
		string modelNumber;
		string manufacture;
	public:
		Motherboard(string model, string manu)
		{
			modelNumber=model;
			manufacture=manu;
		}
		friend ostream& operator<<(ostream& o, Motherboard &motherboard)
		 { 
			o<<"The motherboard is made by: "<<motherboard.manufacture<<endl; 
			o<<"Model#: "<<motherboard.modelNumber<<endl;
			return o;
		}	
};

class RAM{
	private:
		int size, speed;
	public:
		RAM(int si, int spe)
		{
			size=si;
			speed=spe;
		}
		friend ostream& operator<<(ostream& o, RAM &ram)
		 { 
			o<<"The motherboard is size by: "<<ram.size<<" GB"<<endl; 
			o<<"Speed: "<<ram.speed<<endl;
			return o;
		}	
};//endlcass

class PersonalComputer{
	private:
		CPU newCpu;
		Motherboard newMother;
		RAM newRam;
		float price;
		
	public:
		int getPrice() {return price;}
		
		PersonalComputer(string mf, string m, float sp,      string mod, string man,       int sii, int spee,     float pric)
		:newCpu(mf,m,sp),  newMother(mod,man),  newRam(sii, spee)
		{
			price=pric;
		}
		friend ostream& operator<<(ostream& o, PersonalComputer &computer)
		 { 
			o<<"\nI am Contructing a PC: "<<endl;
			cout<<computer.newCpu<<endl;
			cout<<computer.newMother<<endl;
			cout<<computer.newRam<<endl;
			o<<"Price: "<<computer.price<<endl;
			return o;
		}
		float operator+=(PersonalComputer computer)
		{
			float total;
			total+=computer.price;
			return total;				
		}
};

int main()
{
	char again;
	int choice;
	float total;
	PersonalComputer computer("Intel","Z196", 5.2, "Asus", "I5-750", 4,1600, 200.23);
	vector <PersonalComputer> comp;
	comp.push_back(computer); 
	
do
{ 	 
	for (unsigned int x=0; x < comp.size(); x++)
	{
		cout<<comp[x];
	}
	// enter 1 or 2 so the PC can be added to total costs.
	cout<<"Would you like to add this to your order Enter 1 for yes and 2 for no?"<<endl;

while(cin>>choice)
{
	if (choice==1)
	{
		cout<<"Total was added"<<endl;
		total += computer.getPrice();
	}
	else if (choice==2)
	{
		cout<<"Did not want to add this PC!!!"<<endl;
	}
	else if (choice<2 || choice>=0)
	{
		cout<<"Invailed choice!! Enter the right choice\n"; 
	}
}//end
	
	//loop question
	cout << "Do you want to play again? y or n\n";
    cin >> again;
	
}while (again == 'y');
    cout << "Thanks for playing.\n";
   ///display the vector contents
    for (unsigned int x=0; x < comp.size(); x++)
	{
		cout<<"\n\nOrder: "<< x+1;
		cout<<comp[x];
	}
	//overloaded display
	cout<<"Total price: "<<total<<endl;
    system("PAUSE");	
	return 0;
	
}

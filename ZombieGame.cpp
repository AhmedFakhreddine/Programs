#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <windows.h>

using namespace std;

class Player
{
	protected:
		string name;
		string userName;
		int age;
	
	public:	 
	
	Player(string n, int a, string u)///non-default constructor
	{
		name= n;
		age=a;
		userName= u;
	}
	
	void userInput()
	{
		while (1)
		{
		cout << "\nEnter your name: ";
		getline(cin, name); 
		bool bRejected = false; 
		for (unsigned int nIndex = 0; nIndex < name.length() && !bRejected; ++nIndex)
		{
			if (isalpha(name[nIndex]))
				continue;
			if (name[nIndex] == ' ')
				continue;
			bRejected = true;
		}
		if (!bRejected)
			break;
		}
		
		cout<<"Enter a userName: ";	
		getline(cin,userName);
		cout<<"\tMUST BE 18 YEARS OR OLDER TO PLAY ";
		cout<<"Enter your age: ";		
		cin>>age;
		
		while(!cin)
		{
    		cout << "That was no integer! Please enter an integer: ";
    		cin.clear();
    		cin.ignore();
    		cin >> age;
		}
		while (age <= 0 ) // loop if they entered negative age
		{
		cout << "Sorry you typed in a wrong age" << endl;
		cin >> age;
		}
		while (age != 0) 
		{
			if ( age >= 18)
			{
				cout << "You are old enough to play!!! \n" ;
				break;
			}
			else if (17 >= age )
	 		{
				cout << "Sorry you are not allowed to play \n" ;
				exit(0);
			}
		} 	
	}
	
	void playerData()
	{
		cout<< "\nPlayer name: "<<name<<endl;
		cout<< "Player Age: "<<age<<endl;
		cout<< "Player user name: "<<userName<<endl;	
	}
	
	
};
//////////END CLASS/////////////////

//////Polymorphisim and virtual functions
class EnemyZombies{
	public:
		int zDogHealth;
		int zattack;
		int zDogAttack;
		int zhealth;
	
		virtual int attack()
		{
			
		}
		virtual int health()
		{
			
		}
};//end class

class Zombies : public EnemyZombies{
	public:
		int attack()
		{
    		zattack = (rand() % 6); 	 
		}
		
		int health()
		{
			zhealth = (rand() % 7 ) + 3;  
		}
};//end class

class ZombieDogs : public EnemyZombies{
	public:
		int attack()
		{
			zDogAttack = (rand() % 10);
			
		}
		int health()
		{			
			zDogHealth = (rand() % 9 ) + 5; 
		}
};/////end class

template< class T>
class GameStart : public Player{
	private:
		int start;		int playerDamage;		int points;			float mp5;			float spas12;		int attackvalue;
		int round;		int gun;				int combatKnife;	int health;			float attack;			int randomBoxHealth2;
		int buy;		float hammer;			float m4A1;		    int randomBoxHealth;
		//template
		T num1, num2, num3, num4;
		int answer;
		double answer2;
		int sum;
		double avg;
		//polymorphism
		Zombies z;
		ZombieDogs zd;
		EnemyZombies *enemy1 = &z;//zombie
		EnemyZombies *enemy2 = &zd;//dog
		//enemy1->attack();
		//enemy2->attack();
		
		
	public:
		GameStart(string na, int ag, string us, T a, T b, T c, T d) : Player( na , ag , us) 
		{
			round=1;
			points=0;
			playerDamage=25;
			combatKnife=1;//damage
			hammer=1.1;//damage
			m4A1=1.4;//damage
			mp5=1.3;//damage
			spas12=1.5;//damage	
			health=100;
			randomBoxHealth=100;
			randomBoxHealth2=50;
			attack = 1;//damage
			
			num1=a;
			num2=b;
			num3=c;
			num4=d;
			
		}
		
		void startGameMenu()
		{
			cout<<"\n\t\t And your journy begins..."<<endl<<endl;
			cout<<"Enter 1 to start or Enter 2 to quit\n"<<endl;
			cin>>start;
			try
			{
				if(start==1)
				{
					startGame();
				}
				else if (start==2)
				{
					exit(0);
				}
				else if (start>2 || start <=0)
						throw (string) (" Error: ");//you have to cast strings for error not to happen	
			}
			catch (string message)
			{
				cout<<"Please selecte options 1-2"<<message<<endl;
				startGameMenu();		
			}			
		}
		
		void startGame()
		{
			cout<<"You started the game"<<endl;
			character();	
		}
		
		int character()
		{
			cout<<"\nSelect a character you want to be from the following menu: "<<endl;
			cout<<"1: Edward Richtofen \t";	cout<<"2: Tank Dempsey \t"; cout<<"3: Takeo Masaki ";
			int select;
			map <int, string> characters;
			characters.insert(make_pair( 1 , "Edward Richtofen" ));
			characters.insert(make_pair( 2 , "Tank Dempsey" ));
			characters.insert(make_pair( 3 , "Takeo Masaki" ));
			cin>>select;
			try
			{
				if(select==1 ||  select==2 || select==3)
				{
					cout<<"You Have Choosen "<<characters.at(select);
				}
				else if (select>3 || select <=0)
					throw (string) (" Error: ");//you have to cast strings for error not to happen	
			}
			catch (string message)
			{
				cout<<"Please select options 1-3"<<message<<endl;
				character();		
			}
       				
			playZombies();
			
		}
		
		void randomBox()
		{
			cout<<"\n\nClick (Y/N) for mystery box [950pt] "<< " ";
			char choice;
			char open;
			while (cin >> choice)     
			{   
				if(points>=950) 
				{								                      
    				if (choice == 'y' || choice == 'Y')
   					{
						try
						{ 
						//try block before anything bad happens.
							cout<<"Press X to open mystery box for [950pt]";
       						cin>>open;
       						while(open!='x' && open!='X')
       						{
       							cout<<"Invalied choice! Press 'X' to open mystery box for[950pt] ";
       							cin>>open;	
							}
							cout<<"\t\t\t\t\t\tPoints: "<< points << endl;
							points = points - 950;
							weapons();
							throw (string) (" Error: ");//you have to cast strings for error not to happen
						}
						catch (string message)
						{
							cout<<"Not enough points"<<message<<endl;
							randomBox();		
						}
       					
       				}
        				
					else if (choice == 'n'|| choice == 'N')
    				{
			   			rounds();       
   					}
				}
				else
				{
					cout<<"\nSorry you dont have enough points right now!"<<endl;
					cout<<"\t\t\t\tPoint: "<<points;
					Sleep(2000);
					rounds();
				}
			}
		}
		
		int weapons()
		{
			srand(time(0));
			gun=(rand() % 7)+1; 
			char x;
			cout<<"Searching for Weapon in Random Box...... "<<endl;
			PlaySound(TEXT("ZombieMyestryBox.wav"),NULL, SND_SYNC);
			//Sleep(3000);

			if (gun==1)
			{
				cout<<"Press x to pick up Combat Knife"<<endl;
				cout<<"Or Press ANY key to not pick up Combat Knife ";
				cin>>x;
				if(x=='x')
				{
					attack=1;
					attack=attack+combatKnife;
					cout<<"\nYou have picked up the Combat Knife"<<endl;
				}
				else 
					cout<<"Did not want the Combat Knife"<<endl;
				
			}
			else if (gun==2)
			{
				cout<<"Press x to pick up Hammer"<<endl;
				cout<<"Or Press ANY key to not pick up Hammer ";
				cin>>x;
				if(x=='x')
				{
					attack=1;
					attack=attack+hammer;
					cout<<"\nYou have picked up the Hammer"<<endl;
				}
				else 
					cout<<"Did not want the Hammer"<<endl;
			}
			else if(gun==3)
			{
				cout<<"Press x to pick up M4-A1"<<endl;
				cout<<"Or Press ANY key to not pick up M4-Al ";
				cin>>x;
				if(x=='x')
				{
					attack=1;
					attack=attack+m4A1;
					cout<<"\nYou have picked up the M4-A1"<<endl;
				}
				else 
					cout<<"Did not want the M4-A1"<<endl;
			}
			else if(gun==4)
			{
				cout<<"Press x to pick up MP-5"<<endl;
				cout<<"Or Press ANY key to not pick up MP-5 ";
				cin>>x;
				if(x=='x')
				{
					attack=1;
					attack=attack+mp5;
					cout<<"\nYou have picked up the MP-5"<<endl;
				}
				else 
					cout<<"Did not want the MP-5"<<endl;
			}
			else if(gun==5)
			{
				cout<<"Press x to pick up Spas-12"<<endl;
				cout<<"Or Press ANY key to not pick up Spas-12 ";
				cin>>x;
				if(x=='x')
				{
					attack=1;
					attack=attack+spas12;
					cout<<"\nYou have picked up the Spas-12"<<endl;
				}
				else 
					cout<<"Did not want the Spas-12"<<endl;
			}
			else if(gun==6)
			{
				cout<<"You got the TeddyBear "<<endl;
				cout<<"You Have been strip away your weapons and are at the default attack damage!!!"<<endl;
				attack=1;
				Sleep(2000);
				
			}
			else if(gun==7)
			{
				cout<<"You got Max Health!!! "<<endl;
				health=health+randomBoxHealth;
				if (health>100)
				{
					health = 100;
				}
				cout<<"Your health: "<<health<<endl;
				Sleep(2000);
			}
			else if(gun==8)
			{
				cout<<"You got 50 Health Added!!! "<<endl;
				health=health+randomBoxHealth2;
				if (health>100)
				{
					health = 100;
				}
				cout<<"Your health: "<<health<<endl;
			}
			rounds();
		}
		
		void playZombies()
		{
			//Easter EGG Round Challenge
			if (round==10)
			{
				cout<<"EASTER EGG ROUND!!!"<<endl;
				cout<<"Solve this problem to gain 5 health. Whats the sum of these two numbers 283 and 238: "<<endl;
				cin>>answer;
				
				if (answer==easterEgg())
				{
					cout<<"You gained 5 health"<<endl;
					health=health+5;
					cout<<"Your Health: "<<health;
				}
			else
				cout<<"Sorry only one try moving on!!"<<endl;	
			}
			
			if (round==20)
			{
				cout<<"EASTER EGG ROUND!!!"<<endl;
				cout<<"Solve this problem to gain 10 health. Whats the avg of these numbers 88 and 99: "<<endl;
				cin>>answer2;
				if (answer2==easterEgg2())
				{
					cout<<"You gained 10 health"<<endl;
					health=health+10;
					cout<<"Your Health: "<<health;
				}
				
				else
					cout<<"Sorry only one try moving on!!"<<endl;
			}//End 
			
			
			cout<<"\n\nRound started and zombies are coming!!! FIGHT THEM OFF!!!"<<endl;
    		enemy1->health();//virtual functions
    		enemy1->attack();//virtual functions
    		enemy2->health();//virtual functions
    		enemy2->attack();//virtual functions
    		if (round==4 || round==8 || round==12 || round==16 || round==20 || round==24 || round==28 || round==32)
    		{
    			//Color effects on screen for design
    			cout<<"ZOMBIE DOGS, DEFENED YOURSELF!!!!!"<<endl;
				for (int i = 0; i < 4; ++i)
				{
		    		system("color 4c");  //  red
    				Sleep(190);
    				system("color 7d");  //  white
    				system("color 4c");  //  red
    				Sleep(190);
    				system("color 7d");  //  white
    				system("color 4c");  //  red
    				system("color 07");  //  white
    			}
    			
    			PlaySound(TEXT("ZombieDogRound.wav"),NULL, SND_SYNC);//////dog round sound
    			
    			while(health > 0 && enemy2-> zDogHealth > 0) 
    			{ 
	  				cout << "\nYou have " << health << " health\n\n";
    				system("pause");
    				cout << "You attack the Dogs...\n";
    				system("pause");
    				enemy2->zDogHealth = enemy2->zDogHealth - attack;
    				cout << "The Zombies Dogs attack...\n";
   					health = health - enemy2->zDogAttack;  				
   				}
			}
			
			else if (round!=4 || round!=8 || round!=12 || round!=16 || round!=20 || round!=24 || round!=28 || round!=32)
			{
				PlaySound(TEXT("ZombieRoundStart.wav"),NULL, SND_SYNC); //Zombie Round Start
				
				while(health > 0 && enemy1->zhealth > 0) 
    			{ 
	  				cout << "\nYou have " << health << " health\n\n";
    				system("pause");
    				cout << "You attack them...\n";
    				system("pause");
    				enemy1->zhealth = enemy1->zhealth - attack;
    				cout << "The zombies attacks...\n";
   					health = health - enemy1->zattack;						
   				}  
			}
			
    		if ( health <= 0 )  //  lose
    		{
    			cout << "You died...\n\n";
    			system("pause");
    			endRoundDisplay();
    			exit(0);
    		}  //  end
    		
    		if ( enemy1->zhealth <= 0 )  //  win
    		{
    			cout << "You defeated the the Zombies!\n\n";
    		}  //  end
    		
    		if ( enemy1->zDogHealth <= 0 )  //  win
    		{
    			cout << "You defeated the the Zombies!\n\n";
    		}  //  end
    		
    		randomBox();
		}
		
		void rounds()
		{ 
			cout<<" \n\n\n\nYou are alive HAHAHAHAH, next round you wont be!!!!!"<<endl;
			cout<<"	You Gained 7 health for surviving the round"<<endl;
			cout<<"	You Gained 400 points for surviving the round"<<endl;
			points=points+400;
			round=round+1;
			health=health+7;
			
			if (health>100)
			{
				health = 100;
			}
			
			cout<<" \t\t\t\t\t\t\t\t\t\t Round: "<<round<<""<<endl<<endl;
			cout<<" \t\t\t\t\t\t\t\t\t\t Points: "<<points<<""<<endl<<endl;
			cout<<" \t\t\t\t\t\t\t\t\t\t Health: "<<health<<""<<endl<<endl;
			
			if (round==40)
			{
				cout<<"\nYou have Won the game"<<endl;
				exit(0);
			}
			playZombies();
		}
		void endRoundDisplay()
		{
			cout<<"\nYOU SURVIVED UP TO ROUND: "<<round;
		}
		
		////Easter Eggggg Functions
		//Templates
		T easterEgg()
		{
			return sum=(num1*num2);	
		}
		T easterEgg2()
		{
			return avg=(num3+num4)/2;	
		}
	
		
};/////end class


///////Regular Main Functions/////////////
bool getFileContent(string fileName, vector<string> & zombieFileStrs)
{
 
	// Open the File
	ifstream zombieFile(fileName.c_str());
 
	// Check if object is valid
	if(!zombieFile)
	{
		cerr << "Cannot open the File : "<<fileName<<endl;
		return false;
	}
	string str;
	// Read the next line from File untill it reaches the end.
	while (getline(zombieFile, str))
	{
		// Line contains string of length > 0 then save it in vector
		if(str.size() > 0)
			zombieFileStrs.push_back(str);
	}
	//Close The File
	zombieFile.close();
	return true;
}


int main()
{
	///////////////File//////////////
	vector<string> zombieFileStr;
	// Get the contents of file in a vector and siplay the file
	bool result = getFileContent("ZombieGameFile.txt", zombieFileStr);
	if(result)
	{
		
		for(string & line : zombieFileStr)
			cout<<line<<endl;
	}
	
	
	/////////////Class Objects///////////////
	GameStart <int>g( " " , 0 , " " , 283, 238, 88, 99);
	g.userInput();	
	g.playerData();
	g.startGameMenu();

	
	return 0;
}

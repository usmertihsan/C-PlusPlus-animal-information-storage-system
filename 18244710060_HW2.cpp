#include <iostream>
using namespace std;

class Animal
{
	protected:
	string name,diet;
	float dailyCaloriesToBeTaken,expectedLifeTime;	
	public:
	Animal(string n,string d,float c) : name(n), diet(d), dailyCaloriesToBeTaken(c) {expectedLifeTime=0;}
	virtual void calculateExpectedLifeTime(float)=0;
	virtual void display()=0;
};
class Mammal : public Animal 
{
	private:
	float brainSize;
	public:
	Mammal(string n,string d,float c,float b) : Animal(n,d,c) { brainSize=b;	}
	 void calculateExpectedLifeTime(float daily){ expectedLifeTime = ((daily*20.0)/dailyCaloriesToBeTaken);}
	 void display()
	  {
	cout<<"Name:"<<name<<endl;
	cout<<"Diet:"<<diet<<endl;
	cout<<"Brain Size:"<<brainSize<<" "<<"m3"<<endl;
	cout<<"Expected Life Time:"<<expectedLifeTime<<endl;
	cout<<endl<<endl;	
	  }		
};
class Bird : public Animal
{
	private:
	float wingSize;
	public:
	Bird(string n,string d,float c,float w) : Animal(n,d,c) { wingSize=w;}
	void calculateExpectedLifeTime(float daily){expectedLifeTime = ((daily*10.0)/dailyCaloriesToBeTaken);}
	void display() 
	{
	cout<<"Name:"<<name<<endl;
	cout<<"Diet:"<<diet<<endl;
	cout<<"Wing Size:"<<wingSize<<" "<<"m"<<endl;
	cout<<"Expected Life Time:"<<expectedLifeTime<<endl;
	cout<<endl<<endl;
	}
};
int main()
{	
	int choice,i=0;
	int animalChoice;
	char exit;
	string name,diet;
	float wing,brain,dailyCalorie,DailyCalorieToBeTaken;
	Animal *array[10];	
    do
    {
    	cout<<"What do you want to do?(1 for add an animal , 2 for remove last added animal , 3 display all):";
    	cin>>choice;  	
    	switch(choice)
    	{	
    	case 1 : 
    	cout<<"Which species do you want to add?(1 for mammals , 2 for birds):";
    	cin>>animalChoice;
    	if(animalChoice==1)
    	{
    		cout<<"Enter its name:";
    		cin>>name;
    		cout<<"Enter its diet:";
    		cin>>diet;
    		cout<<"Enter its brain size:";
    		cin>>brain;
    		cout<<"Enter the its daily calories it should take:";
    		cin>>DailyCalorieToBeTaken;
    		cout<<"Enter the daily calories it takes:";
    		cin>>dailyCalorie;
    		array[i]=new Mammal(name,diet,DailyCalorieToBeTaken,brain);
    		array[i]->calculateExpectedLifeTime(dailyCalorie);
    		i++;    		
		}
		else
		{
			cout<<"Enter its name:";
    		cin>>name;
    		cout<<"Enter its diet:";
    		cin>>diet;
    		cout<<"Enter its wing size:";
    		cin>>wing;
    		cout<<"Enter the its daily calories it should take:";
    		cin>>DailyCalorieToBeTaken;
    		cout<<"Enter the daily calories it takes:";
    		cin>>dailyCalorie;
    		array[i]=new Bird(name,diet,DailyCalorieToBeTaken,wing);
    		array[i]->calculateExpectedLifeTime(dailyCalorie);
    		i++;		
		}		
		break;					
    	case 2 :  		
    		cout<<"Removed animal:"<<endl;
    		array[i-1]->display();
    		delete array[i-1];
    		i=i-1;
    		break; 		
        case 3 :
        	cout<<"All animal in stack:"<<endl;
        	 int j;
        	 for(j=0;j<i;j++)
        	 {
        	 	cout<<j+1<<"."<<""<<"animal"<<endl;
        	 	array[j]->display();
			 }
			 break;
        }        
        cout<<"Enter e for exit:";
        cin>>exit; 
	}while(exit!='e');	
}

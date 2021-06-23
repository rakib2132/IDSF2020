/* Rakib Hossain ID# 1001514252 */
#include<iostream>
#include<string>
#include "SnachMachine.h"
using namespace std;

int main()
{
	
	int cost;
	int payment;
	std::string change;
	int status;
	int amountToAdd;
	int cautch_max_inventory;
	int cautch_inventory_level;

	SnachMachine MySnackMachine("Rakib Snack Machine",50,500,100);


	int choice;
	do
	{
		int choice;
		cout<<"Welcome to "<<MySnackMachine.getMachineName()<<endl;
		cout<<"0. Walk away"<<endl;
		cout<<"1. Buy a snack"<<endl;
		cout<<"2. Restock Machine"<<endl;
		cout<<"3. Add change"<<endl;
		cout<<"4. Display Machine Info"<<endl;
		cout<<"choice:";
		cin>>choice;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(50,'\n');
			cout<<"you must enter a numaric. Renter your choice: ";
			cin>>choice;
		}

		switch(choice)
		{
			case 0:
			cout<<"are you sure you aren't really HUNGRY and need a Snack? "<<endl;
			break;
			case 1:
			cout<<"A snace  cost "<<MySnackMachine.getSnackPrice()<<endl;
			cout<<"Insert Payment: ";
			cin>>payment;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore(50,'\n');
				cout<<"input must be numaric. Please reenter again: ";
				cin>>payment;
			}
			MySnackMachine.BuyASnack(payment,change,status);
			switch(status)
			{
				case exact:
				cout<<"Here is snack.Thank you for exact payment "<<endl;
				break;
				case enum_change:
				cout<<"Here is your snack and your change back: "<<change;
				break;
				case insufficent:
				cout<<"insufficent payment......returning your payment"<<endl;
				break;
				case not_enough_change:
				cout<<"Unable to give change at this time...returning your payment"<<endl;
				break;
				default:
				cout<<"invalid payment"<<endl;

			}
			
			break;
			case 2:

				cout<<"How much product are you adding to the machine: ";
				cin>>amountToAdd;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(50,'\n');
					cout<<"input must be numaric. Please reenter again: ";
					cin>>amountToAdd;
				}
				if(MySnackMachine.incrementInventory(amountToAdd))
				{
					cout<<"Your machine has been restocked"<<endl;
					cout<<"Now your inventory level "<<MySnackMachine.getInventoryLevel()<<endl;
					
				}
				else
				{   
					 cout<<"You have exceeded your machine's max capacity"<<endl;
					 cout<<"Now your inventory level "<<MySnackMachine.getInventoryLevel()<<endl;
				}

			break;
			case 3:

				cout<<"How much change are you adding to the machine?";
				cin>>amountToAdd;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(50,'\n');
					cout<<"input must be numaric. Please reenter again: ";
					cin>>amountToAdd;
				}
				if(MySnackMachine.incrementChangeLevel(amountToAdd))
				{
					cout<<"Your change has been updated"<<endl;
					cout<<"Your change level is "<<MySnackMachine.getChangeLevel();
				}
				else
				{
					cout<<"You exceeded max change capacity"<<endl;
				}
				
			break;
			case 4:
		
				cout<<"Current Inventory Level "<<MySnackMachine.getInventoryLevel()<<endl;
				cout<<"Max Inventory Capacity "<<MySnackMachine.getMaxInventoryCapacity()<<endl;
				cout<<"Current Change Level "<<MySnackMachine.getChangeLevel()<<endl;
				cout<<"Max Change Capacity "<<MySnackMachine.getMaxChangeCapacity()<<endl;
				cout<<"Current Snack Price is "<<MySnackMachine.getSnackPrice()<<endl;
			break;
			default:
				cout<<"Invalid menu options. Please choose again"<<endl;

        }
        cout<<" "<<endl;

	}while(choice!=0);
	
	return 0;
}

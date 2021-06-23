#include<iostream>
#include<string>

enum { exact, enum_change, insufficent,not_enough_change,};

class SnachMachine
{
public:

	SnachMachine(std::string name, int passing_snack_Price, int passing_change_level, int passing_inventory_level)
	: machineName{name}, SnackPrice{passing_snack_Price}, changeLevel{passing_change_level}, inventoryLevel{passing_inventory_level}
	{	
	}

	std::string getMachineName()
	{
		return machineName;
	}
	bool BuyASnack(int payment, std::string& change, int& status)
	{	
	
		if(payment==SnackPrice)
		{	
			status=exact;
			changeLevel+=payment;
			inventoryLevel--;
			return true ;
		}
		else if(payment-SnackPrice>changeLevel)
		{
			status=not_enough_change;
		}
		else if(payment>SnackPrice)
		{
			status=enum_change;
			change=displayMoney(payment-SnackPrice);

			changeLevel+=SnackPrice;
			inventoryLevel--;
			return true;
		}
		else if(payment<SnackPrice)
		{
			status=insufficent;


			return false;
		}
	
	}	

	int getInventoryLevel()
	{
		return inventoryLevel;

	}
	int getMaxInventoryCapacity()
	{
		return maxInventoryCapacity;
	}
	
	bool incrementInventory(int amountToAdd)
	{  
		if(amountToAdd>maxInventoryCapacity-inventoryLevel)
		{
			return false;
		}
		else
		{
			inventoryLevel+=amountToAdd;
			return true;
	    }
		
	}

	
	std::string getChangeLevel()
	{
		return displayMoney(changeLevel);
	}
	bool incrementChangeLevel(int amountToAdd)
	{   
		if(amountToAdd>maxChangeCapacity-changeLevel)
		{
			return false;
		}
		else
		{
			changeLevel+=amountToAdd;
			return true;
		}
	}
	std::string getMaxChangeCapacity()
	{
		return displayMoney(maxChangeCapacity);
	}
	std::string getSnackPrice()
	{
		

		return displayMoney(SnackPrice);
	}
	std::string displayMoney(int amount)
	{
		std::string dollars{std::to_string(amount / 100)};
		std::string cents{std::to_string(std::abs(amount % 100))};
		return "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents; 
	}
private:
	std::string machineName;
	int changeLevel;
	int maxChangeCapacity=5000;
	int SnackPrice;
	int inventoryLevel;
	int maxInventoryCapacity=100;

};


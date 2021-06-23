/* Rakib Hossain ID# 1001514252 */
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<cstring>
#include<stdio.h>
#include<string.h>
#include<chrono>
#include<thread>
#include "TrickOrTreater.h"   
#include "House.h"  
#include "CandyHouse.h"  
#include "ToothbrushHouse.h"
using namespace std;

void get_command_line_params(int argc, char* argv[], std::string& input_file_name1, std::string& input_file_name2, std::string& input_file_name3)
{

	if(argc!=4)
	{
		throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");
	}
	else
	{
		input_file_name1=argv[1];
		input_file_name2=argv[2];
		input_file_name3=argv[3];
	}
}

int main(int argc, char *argv[])
{

	//all the variable


	srand(time(NULL));
	std::string input_file1;
	std::string input_file2;
	std::string input_file3;
	std::string StoreMapFile;
	std::string StoreHouseFile;
	std::ostringstream HouseHeader;
	std::string StoreTotFile;
	char candy[30];
	int ranking;
	std::map<int, string> CandyRankingMap;
	char *token;
	char cstr[100];
	std::vector<House*>setOfHouses;
	std::vector<TrickOrTreater>setOfToT;

	try
	{
		get_command_line_params(argc,argv,input_file1,input_file2,input_file3);
	}
	catch(invalid_argument& ex)
	{
		cerr<<"an exception occurred: "<<ex.what()<<endl;
		exit(0);
	}

	ifstream UserInputCandy{input_file3};
	ifstream UserInputHouse{input_file2};
	ifstream UserInputTOT{input_file1};
	
	if(UserInputCandy.is_open() && UserInputHouse.is_open() && UserInputTOT.is_open())
	{
		while(getline(UserInputCandy,StoreMapFile))
		{   
			strcpy(cstr, StoreMapFile.c_str());
			token=strtok(cstr,"|");
			strcpy(candy,token);
			token=strtok(NULL,"|");
			ranking=atoi(token);
			CandyRankingMap.insert(make_pair(ranking, candy));
			
		}

		HouseHeader<<"          ";
		while(getline(UserInputHouse,StoreHouseFile))
		{
			if(rand()%2)
			{

				setOfHouses.push_back(new CandyHouse{StoreHouseFile,CandyRankingMap});
		    }
		    else
		    {
		    	setOfHouses.push_back(new ToothbrushHouse{StoreHouseFile, CandyRankingMap});
		    }

			HouseHeader<<StoreHouseFile;
			for(int i=0; i<(11-StoreHouseFile.size());i++)
			{
				HouseHeader<<" ";
			}
		}
		HouseHeader<<endl;
		cout<<HouseHeader.str();

		while(getline(UserInputTOT,StoreTotFile))
		{
			setOfToT.push_back(TrickOrTreater{StoreTotFile,setOfHouses});
		}

		for(auto &it: setOfToT)
		{
			it.startThread();
		}

		while(TrickOrTreater::ImDone!=setOfToT.size())
		{
			for(int i=0; i<34;i++)
			{
				cout<<endl;
			}

			cout<<HouseHeader.str();
			for(auto &it: setOfToT)
			{
				cout<<it.getPath()<<it.getName()<<endl;
			}

			this_thread::sleep_for(chrono::milliseconds(5));
		}

		for(auto &it: setOfToT)
		{
			it.joinThread();
		}

	}

	else
	{
		cout<<"File did not open"<<endl;
		exit(0);
	}

	for(auto &it: setOfToT)
	{
		cout<<it;
	}


	for(auto it: setOfHouses)
	{
		delete it;
	}

	
	UserInputCandy.close();
	UserInputHouse.close();
	UserInputTOT.close();

	


	return 0;

}
#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "../nameloader.hpp"
#include "../passwordmaker.hpp"
#include "../hashtable.hpp"

#include <string>


/*******************************************************************
 Student Name:JAMES RUTGER
 File Name: Test.cpp
 Assignment: Project 1 - Hash Table

 Data Structures and Algorithms 2
 Dr.John Coffey

 Class Description:
 Made a few tests to search for inserting and searching names into 
 the hash table.
*****************************************************************/

TEST_CASE ("Book creation and checkout/in")
{

	Nameloader obj;

	std::string answer;
	
	PasswordMaker passes;
	
	for(int i=0;i<90000;i++)
	{	

		if(obj.LoadNames(i))
		{
			//just loads names until none left
		}
	       	else
		{	
			break;
		}
	}


	for(int j=0;j<90000;j++)
	{

		if(obj.NamePassLoader(j))//loads names and passes full line string into array
		{
		}
		else
		{
			break;
		}
	}
	
	
	std::stringstream ss2;
	
	for(int z=0;z<5;z++)
	{

		std::stringstream ss;

		ss << obj.GetNamePasses(z);
		std::string word1;	
		std::string word2;
		ss >> word1 >> word2;

	       	ss2 << passes.Cipherer(word2) << "\n";
		
		if(word2==""){
			break;
		}

	}

	REQUIRE(ss2.str() == "wkyvtkadf\nqqqejicjo\ntmumvmefg\nmlenexksv\nggwcturoi\n");//Tests cipher on first 5 passwords

	Hashtable hash;

	for(int i=0; i<90000;i++)
	{

		std::stringstream ss;

		ss << obj.GetNamePasses(i);
		std::string userID;	
		std::string password;
		std::string encryptedPassword;
		ss >> userID >> password;

		if(userID==""){
			break;
		}

		encryptedPassword = passes.Cipherer(password);

		int index = hash.MakeIndex(userID);

		hash.Insert(index, userID, encryptedPassword);
	
	}

	bool searchResult = hash.Search("SMITH","wkyvtkadf");

	REQUIRE(searchResult == true);


	bool searchResult2 = hash.Search("JOHNSON","qqqejicjo");

	REQUIRE(searchResult2 == true);


	bool searchResult3 = hash.Search("JOHNSON","zzzzzzzzz");

	REQUIRE(searchResult3 == false);


	bool searchResult4 = hash.Search("NOTANME","abcdefghi");

	REQUIRE(searchResult4 == false);
}

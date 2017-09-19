#include "dynamic_array_list.h"
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

//Struct to store each entry
struct data
{
	long long int date;
	std::string name;
	std::string location;
};

//Sorts a dynamic array list starting from the largest to smallest
void sort(DynamicArrayList<data> &x)
{
	data swapper;

	for (int i = 0; i < x.getLength(); i++)
	{
		for (int j = i+1; j < x.getLength(); j++)
		{
			if (x.getEntry(i).date > x.getEntry(j).date)
			{
				swapper = x.getEntry(i);
				x.setEntry(i, x.getEntry(j));
				x.setEntry(j, swapper);
			}
		}
	}
}

//Checks if there are any entries with today's date and returns the entries
DynamicArrayList<data> today(DynamicArrayList<data> &x)
{
	DynamicArrayList<data> result;
	auto now = std::chrono::system_clock::now();
	auto as_time_t = std::chrono::system_clock::to_time_t(now);
	auto as_tm = std::localtime(&as_time_t);
	int this_day = (1900 + as_tm->tm_year) * 10000 + (as_tm->tm_mon + 1) * 100 + as_tm->tm_mday;
	data temp;
	int count = 0;
	for (int i = 0; i < x.getLength(); i++)
	{
		temp = x.getEntry(i);
		if (temp.date / 1000000 == this_day)
		{
			result.insert(count, temp);
			count++;
		}
	}

	
	return result;
}

//Checks if there are any entries with yesterday's date and returns the entries
DynamicArrayList<data> yesterday(DynamicArrayList<data> &x)
{
	auto now = std::chrono::system_clock::now();
	auto as_time_t = std::chrono::system_clock::to_time_t(now);
	auto as_tm = std::localtime(&as_time_t);
	int year = (1900 + as_tm->tm_year);
	int month = as_tm->tm_mon + 1;
	int day = as_tm->tm_mday;
	int count = 0;

	if (day == 1 && month == 1)
	{
		day = 31;
		month = 12;
		year = year - 1;
	}

	else if (day == 1 && month == 3)
	{
		if (year % 4 == 0)
		{
			day = 29;
		}
		else
		{
			day = 28;
		}
		month = 2;
	}

	else if (day == 1)
	{

		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
		{
			day = 31;
			month = month - 1;
		}

		else if (month == 5 || month == 7 || month == 10 || month == 12)
		{
			day = 30;
			month = month - 1;
		}
	}

	else
	{
		day = day - 1;
	}

	DynamicArrayList<data> result;
	int this_day = year * 10000 + month * 100 + day;
	for (int i = 0; i < x.getLength(); i++)
	{
		data temp = x.getEntry(i);
		if (temp.date / 1000000 == this_day)
		{
			result.insert(count, temp);
			count++;
		}
	}
	
	return result;
	
}

//Checks if there are any entries with last week's date  and returns the entries
DynamicArrayList<data> lastWeek(DynamicArrayList<data> &x)
{

	DynamicArrayList<data> result;
	int count = 0;
	for (int i = 0; i < x.getLength(); i++)
	{
		data temp = x.getEntry(i);
		for (int j = 0; j < 7; j++)
		{
			auto now = std::chrono::system_clock::now();
			auto as_time_t = std::chrono::system_clock::to_time_t(now);
			auto as_tm = std::localtime(&as_time_t);
			int year = (1900 + as_tm->tm_year);
			int month = as_tm->tm_mon + 1;
			int day = as_tm->tm_mday;
			
			if (day <= 7 && month == 1)
			{

				if (j + 1 < day)
				{
					day = day - j - 1;
				}
				else
				{
					day = 31 + day - j - 1;
					month = 12;
				}
				year = year - 1;
			}

			else if (day <= 7 && month == 3)
			{
				if (year % 4 == 0)
				{
					if (j + 1 < day)
					{
						day = day - j - 1;
					}
					else
					{
						day = 29 + day - j - 1;
						month = month - 1;
					}

				}
				else
				{
					if (j + 1 < day)
					{
						day = day - j - 1;
					}
					else
					{
						day = 28 + day - j - 1;
						month = month - 1;
					}
					
				}
			}

			else if (day <= 7)
			{

				if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
				{
					if (j + 1 < day)
					{
						day = day - j - 1;
					}
					else
					{
						day = 31 + day - j - 1;
						month = month - 1;
					}
					
				}

				else if (month == 5 || month == 7 || month == 10 || month == 12)
				{
					if (j + 1 < day)
					{
						day = day - j - 1;
					}
					else
					{
						day = 30 + day - j - 1;
						month = month - 1;
					}
					
				}
			}

			else
			{
				day = day - j;
			}

			int this_day = year * 10000 + month * 100 + day;
			
			if (temp.date / 1000000 == this_day)
			{
				result.insert(count, temp);
				count++;
			}

		}
	}

	return result;
}

//Checks if there are any entries with this month's date and returns the entries
DynamicArrayList<data> thisMonth(DynamicArrayList<data> &x)
{
	DynamicArrayList<data> result;
	auto now = std::chrono::system_clock::now();
	auto as_time_t = std::chrono::system_clock::to_time_t(now);
	auto as_tm = std::localtime(&as_time_t);
	int year = (1900 + as_tm->tm_year);
	int month = as_tm->tm_mon + 1;
	

	int this_day = (1900 + as_tm->tm_year) * 100 + (as_tm->tm_mon + 1);
	int count = 0;
	for (int i = 0; i < x.getLength(); i++)
	{
		data temp = x.getEntry(i);
		if (temp.date / 100000000 == this_day)
		{
			result.insert(count, temp);
			count++;
		}
	}

	return result;
}

//Returns entries that include the given str either in location or name
DynamicArrayList<data> findByString(std::string &str_1, DynamicArrayList<data> &x)
{
	DynamicArrayList<data> result;
	int count = 0;
	for (int i = 0; i < x.getLength(); i++)
	{
		data temp = x.getEntry(i);
		

		if (temp.location.find(str_1) != std::string::npos || temp.name.find(str_1) != std::string::npos)
		{
			result.insert(count, temp);
			count++;
		}
	}

	return result;
}

//Deletes an entry
DynamicArrayList<data> deleteEntry(int &n, DynamicArrayList<data> &x, DynamicArrayList<data> &res)
{

	data del = res.getEntry(n - 1);
	DynamicArrayList<data> cle = res;

	if (n > 0)
	{
		res.remove(res.getLength() - n);
		for (int i = 0; i < x.getLength(); i++)
		{
			if (del.date == x.getEntry(i).date && del.location == x.getEntry(i).location && del.name == x.getEntry(i).name)
			{
				x.remove(x.getLength() - i - 1);
			}
		}
	}
	
	else if (n == 0)
	{
		res.clear();
		for (int i = 0; i < x.getLength(); i++)
		{
			for (int j = 0; j < cle.getLength(); j++)
			{
				if (cle.getEntry(j).date == x.getEntry(i).date && cle.getEntry(j).location == x.getEntry(i).location && cle.getEntry(j).name == x.getEntry(i).name)
				{
					x.remove(x.getLength() - i - 1);
				}
			}
			
		}
	}


	return res;
}

// Prints a list
void print(DynamicArrayList<data> &x)
{
	int count = 1;
	for (int i = x.getLength() - 1; i >= 0; i--)
	{
		data temp = x.getEntry(i);
		cout << count << ". " << temp.name << ", " << temp.location << endl;
		count++;
	}
}

//Writes the previous show command to the input file
void writeToFile(DynamicArrayList<data> &x, std::string &fileName)
{
	ofstream out(fileName);

	for (int i = x.getLength() - 1; i >= 0; i--)
	{
		data temp = x.getEntry(i);
		out << temp.date << ',' << temp.name << ',' << temp.location << endl;
	}
	
}


/*
*  Purpose for program
*  This program gets the history from a csv file and it will allow a user to view, search, and remove entries from the file.
*  Uses dynamic array list.
*
*
*  Programmer: Onat Calik
*  Date: November 04, 2016
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/
int main(int argc, char *argv[])
{
	if (argv[1] == NULL)
	{
		argv[1] = "history.csv";
	}

	ifstream in(argv[1]);
	DynamicArrayList<data> dataList; //main list
	DynamicArrayList<data> lastShow; //to record the previous result
	std::string fileName = argv[1]; //filename to be used in w command

	
	data temp;

	std::string a;

	getline(in, a, ',');
	getline(in, temp.name, ',');
	in >> temp.location;

	int i = 0;
	while (!in.fail())
	{

		temp.date = std::stoll(a);
		dataList.insert(i, temp);

		getline(in, a, ',');
		getline(in, temp.name, ',');
		in >> temp.location;

		i++;
	}
	

	
	sort(dataList);
	std::string command;       //stores the command
	std::string notValid = ""; //stores the invalid string

	cout << "Search and edit browser history.\n";
	cout << "Type C-z to halt.\n" << "Command: ";
	cin >> command;

	while (!cin.eof())
	{
		DynamicArrayList<data> result; //stores the result

		if (command == "s")
		{
			int opr = -1;
			cin >> opr;
			if (opr == 0)
			{
				result = dataList;
			}

			else if (opr == 1)
			{
				result = today(dataList);
			}

			else if (opr == 2)
			{
				result = yesterday(dataList);
			}

			else if (opr == 3)
			{
				result = lastWeek(dataList);
			}

			else if (opr == 4)
			{
				result = thisMonth(dataList);
			}

			if (result.getLength() == 0)
			{
				notValid = "No entries";
			}

		}

		else if (command == "f")
		{
			std::string loc; //stores the given string
			cin >> loc;

			result = findByString(loc, dataList);

			if (result.getLength() == 0)
			{
				notValid = "No matches";
			}
		}

		else if (command == "r")
		{
			int num;
			cin >> num;
			
			if (num >= 0 && num <= lastShow.getLength())
			{
				result = deleteEntry(num, dataList, lastShow);
	
			}

			else
			{
				notValid = "Invalid Entry";
			}
		}

		else if (command == "w")
		{
			writeToFile(lastShow, fileName);
			notValid = "File Updated";
		}

		else
		{
			notValid = "Unknown Command";
		}

		if (result.getLength() == 0)
		{
			cout << notValid << endl;
			cout << endl;
		}
		else
		{
			print(result);
		}

		lastShow = result;

		cout << "Search and edit browser history.\n";
		cout << "Type C-z to halt.\n" << "Command: ";
		cin >> command;
	}

	
	return 0;
}

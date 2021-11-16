#include <iostream>
#include <unordered_map>
#include <fstream>
#include <iomanip>			//for alignmnet
#include <vector>			

/*Name: Muhammad Khan, CS 302 Assignment 6
  This assignment opens two files, the first file
  contains the list of studnets and the second file
  cotains the list of Assignments each student has completed.
  There were a total of nine assignments, so if a studnets 
  assignment does not appear in the list, it counts as missing.
  To do this, we will use unordered maps to figure out how many
  missing assignments each student has.
  */

using namespace std;

int main()
{
	unordered_map<string, int> people;		//unordered map for students
	unordered_map<string, int> assignments;//unordered map for the assignments
	vector<string> students;	//user for studnets vector
	vector<string> track;		//a temporary vector that contains assignments
	vector<string> A;			//temp vector that will allow for calculations

	int nine = 9;		//int to help find total missing assignments
	string enter = "";  //user enters a file name and the program opens it
	string keep = "";	//temp string variable for assignment names
	bool check = true;	//check to see if the file has opened or not
	ifstream infile;		//use for students file
	ifstream afile;			//use for assignments file
	string stud = "";		//use for reading students and
	string line = "";		//make a vector with all the students
	//Try to open the students file
	while (check)
	{
		cout << "Enter students file: ";
		cin >> enter;
		infile.open(enter);
		if (infile)
			check = false;
	}

	check = true;
	
	//try to open the assignments file
	while (check)
	{
		cout << "Enter assignments file: ";
		cin >> enter;
		afile.open(enter);
		if (afile)
			check = false;
	}

	//insert the names into the vector
	while (infile >> stud)
	{
		students.push_back(stud);
	}

	//insert the assignments
	while (afile >> stud)
	{
		A.push_back(stud);
	}

	//this is the for loop where all of the magic happens
	for (int i = 0; i < students.size(); i++)
	{
		people[students.at(i)] = 0;				//each student has a number
	}											//associated with them
												//shows how many missing assignments
	//append characters to see if a student has any
	//missing assignments in his or her class
	//and update the unordered map everytime an
	//assignment for that studnet is found, if its duplicate
	//then disregard the duplicate assignment in the file
	for (int i = 0; i < students.size(); i++)
	{
		keep = students.at(i);	//string = student
		keep.append("_A1");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A2");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A3");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A4");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A5");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A6");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A7");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A8");
		track.push_back(keep);
		keep = students.at(i);	//string = student
		keep.append("_A9");
		track.push_back(keep);

		//loop to help keep track of how many missing assignments each
		//studnet has, and keep updating the unordered map to keep track
		//of the missing assignments for each student.
		for (int j = 0; j < A.size(); j++)
		{
			for (int k = 0; k < track.size(); k++)
			{
				if (track.at(k) == A.at(j))
				{
					people[students.at(i)]++;		//add to the undordered map for that particular
					track.erase(track.begin() + k);	//studnet... erase that content in the vector to
				}									//find more missing assignments for that student.
			}
		}
		//add to the unordered map of students, this will
		//show the number of missing assignments each student has
		//each student has a map that has the number of assignments
		//that are missing
		people[students.at(i)] = 9 - people[students.at(i)];
		track.clear();
	}

	//user set width and left/right alignment to make the output look clean
	cout << endl;
	cout << setw(15) << left << "NAME" << setw(20) << left << "MISSING ASSIGNMENTS" << endl;
	
	//print out the studnets name and the corresponding missing assignments for each studnet
	for (int i = 0; i < students.size(); i++)
	{
		cout << setw(15) << left << students.at(i) << setw(20) << left << people[students.at(i)] << endl;
	}
	
	//close both files and then return.
	afile.close();
	infile.close();
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

class Track
{
private:

	std::string nameTrack;
	std::string dateOfCreationTrack;
	int durationTrack;

public:
	std::string valueNameTrack;

	void SetRecordNameTrack()
	{
		std::cout << "Enter track name: ";
		std::cin >> valueNameTrack;
		nameTrack = valueNameTrack;		
	}

	std::string GetNameTrack()
	{
		return nameTrack;
	}

	void SetRecordDateOfCreation()
	{
		std::time_t date = std::time(nullptr);
		std::tm today;
		localtime_s(&today, &date);
		today.tm_year = today.tm_year + 1900;
		++today.tm_mon;		
		dateOfCreationTrack = "";

		std::string result = std::to_string(today.tm_mday);

		dateOfCreationTrack += result + ':';
		result = std::to_string(today.tm_mon);

		dateOfCreationTrack += result + ':';
		result = std::to_string(today.tm_year);

		dateOfCreationTrack += result + ' ';
		result = std::to_string(today.tm_hour);

		dateOfCreationTrack += result + ':';
		result = std::to_string(today.tm_min);
		dateOfCreationTrack += result;		
	}

	std::string GetDateOfCreationTrack()
	{	
		return dateOfCreationTrack;
	}

	void SetDurationTrack()
	{
		int volueDurationTrack = std::rand() % 20;
		durationTrack = volueDurationTrack;
	}

	int GetDurationTrack()
	{
		return durationTrack;
	}
};



int main()
{
	std::srand(std::time(nullptr));
	
	std::vector <Track> track;
	Track composition1;

	composition1.SetRecordNameTrack();
	composition1.SetRecordDateOfCreation();
	composition1.SetDurationTrack();
	track.push_back(composition1);
		
	std::string command;

	do
	{
		std::cout << "Enter command: ";
		std::cin >> command;


	} while (command != "exit");







    return 0;
}



////// C++ Program to create 
//// a vector of class objects 
//#include <iostream> 
//#include <string> 
//#include <vector> 
//
//using namespace std;
//
//int randomInt(int start, int range)
//{
//	// A function to generate random numbers 
//	return (start + rand() % range);
//}
//
//string randomString(int len)
//{
//	// A function to generate random strings of length --> 
//	// "len" 
//	string str;
//	for (int i = 0; i < len; i++) {
//		char ch = 'A' + rand() % 26;
//		str.push_back(ch);
//	}
//	return str;
//}
//
//class Student {
//	int roll;
//	string name;
//	int age;
//	int marks;
//
//public:
//	void getter()
//	{
//		roll = randomInt(100, 50);
//		name = randomString(10);
//		age = randomInt(10, 10);
//		marks = randomInt(200, 300);
//	}
//	void disp()
//	{
//		cout << roll << "\t" << name << "\t" << age << "\t"
//			<< marks << "\n";
//	}
//};
//
//int main()
//{
//	// Vector of class objects 
//	vector<Student> v;
//	Student s;
//
//	for (int i = 0; i < 10; i++) {
//		// getting the random values from 
//		// functions 
//		s.getter();
//		// inserting objects to vector 
//		v.push_back(s);
//	}
//
//	for (int i = 0; i < 10; i++) {
//		// displaying object data 
//		v[i].disp();
//	}
//
//	return 0;
//}
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
		int valueDurationTrack = std::rand() % 20;
		durationTrack = valueDurationTrack;
	}

	int GetDurationTrack()
	{
		return durationTrack;
	}

	void PrintTrack()
	{
		std::cout << nameTrack << " " << dateOfCreationTrack << " " << durationTrack << std::endl;
	}

	
	
};

class Player
{
private:
	std::string nameMusic;
	std::string dateOfCreationMusic;
	int durationMusic;
	int nextNumber;

public:

	std::string GetNameSong(std::string songName, std::vector <Track> track)
	{		
		for (int i = 0; i < track.size(); ++i)
		{
			if (songName == track[i].GetNameTrack())
			{
				return songName;
			}			
		}
		songName = "There is no track with this name in the playlist";
		return songName;
	}









	int GetNumberSong(std::string songName, std::vector <Track> track)
	{
		for (int i = 0; i < track.size(); ++i) {
			if (songName == track[i].GetNameTrack())
			{
				return i;
			}
		}
	}

	void GetSongCreationDate(std::string songName, std::vector <Track> track)
	{

		track[GetNumberSong(songName, track)].PrintTrack();

		//dateOfCreationMusic = GetNumberSong(songName, track);
		////dateOfCreationMusic = track.GetDateOfCreationTrack(GetNumberSong(songName, track));
		//
		//return dateOfCreationMusic;
	}
	
};


int main()
{
	std::srand(std::time(nullptr));
	
	std::vector <Track> track;
	Track composition1;
	Track composition2;
	Track composition3;

	composition1.SetRecordNameTrack();
	composition1.SetRecordDateOfCreation();
	composition1.SetDurationTrack();
	track.push_back(composition1);

	composition2.SetRecordNameTrack();
	composition2.SetRecordDateOfCreation();
	composition2.SetDurationTrack();
	track.push_back(composition2);

	composition3.SetRecordNameTrack();
	composition3.SetRecordDateOfCreation();
	composition3.SetDurationTrack();
	track.push_back(composition3);
		




	Player examination;

	

	
	track[0].PrintTrack();
	track[1].PrintTrack();
	track[2].PrintTrack();
	
	std::string command; 
	std::string songName;
	int timer = 0;
	bool is_playback = false;
	do
	{
		std::cout << "Enter command: ";
		std::cin >> command;

		std::time_t tt = std::time(nullptr);
		std::tm time_tt;
		localtime_s(&time_tt, &tt);

		if (command == "play" && (tt >= timer))
		{
			do {
				std::cout << "Enter song title: ";
				std::cin >> songName;
			} while (examination.GetNameSong(songName, track) == "There is no track with this name in the playlist");			

			track[examination.GetNumberSong(songName, track)].PrintTrack();			

			timer = track[examination.GetNumberSong(songName, track)].GetDurationTrack();			
			std::time_t tt_timer = std::time(nullptr) + timer;
			std::tm time_timer;

			localtime_s(&time_timer, &tt_timer);

			timer = tt_timer;
			is_playback = true;
		}

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
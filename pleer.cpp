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
		int valueDurationTrack = std::rand() % 20 + 10;
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

	int GetNextNumberSong(std::vector <Track> track)
	{
		int number = std::rand() % track.size();
		return number;
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
		else if (command == "pause" && is_playback == true) 
		{
			std::cout << "Paused recording" << std::endl;
			timer = 0;
			is_playback = false;
		}
		else if (command == "next") 
		{
			int nextNumber = examination.GetNextNumberSong(track);
			track[nextNumber].PrintTrack();

			timer = track[nextNumber].GetDurationTrack();			
			std::time_t tt_nextTimer = std::time(nullptr) + timer;
			std::tm time_nextTimer;
			localtime_s(&time_nextTimer, &tt_nextTimer);
			timer = tt_nextTimer;
			is_playback = true;
		}

	} while (command != "exit");
    return 0;
}
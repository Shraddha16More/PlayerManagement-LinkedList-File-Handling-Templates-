#pragma once
class Player
{
	int j_no;
	char name[20];
	int no_of_matches;
	int no_of_runs;
	int no_of_wickets;
	
	public:
	Player();
	Player(int ,const char*, int ,int, int);
	void setJNo(int);
	void setName(const char*);
	void setMatch(int);
	void setRun(int);
	void setWickets(int);
	int getJNo();
	char* getName();
	int getMatch();
	int getRuns();
	int getWickets();
	void displayData();
};


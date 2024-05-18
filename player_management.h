#pragma once
#include"player.h"
#include"node.cpp"
template<class T>
class PlayerManagement
{
	Node<T>* start;
	
	public:
	PlayerManagement();		//parameterized constructor
	void addPlayer(const T&,int);
	void hardCodedData();
	void searchPlayerId(int&);
	void searchPlayerName(const char*);
	void updatePlayer(int);
	void deletePlayer(int);	
	void sortPlayer(int);
	void displayPlayer();
	~PlayerManagement();
};
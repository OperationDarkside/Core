#pragma once
#ifndef STATUSTRANSITION_H
#define STATUSTRANSITION_H



class StatusTransition {
public:
	StatusTransition ();
	~StatusTransition ();

	int getID ();
	void setID (int id);

private:
	int id = 0;
};

#endif // !STATUSTRANSITION_H
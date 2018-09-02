#pragma once
#ifndef STATUSCHANGE_H
#define STATUSCHANGE_H



class StatusChange {
public:
	StatusChange ();
	~StatusChange ();

	int getID ();
	void setID (int _id);

private:
	int id = 0;
};

#endif // !STATUSCHANGE_H
#pragma once
#ifndef STATUS_H
#define STATUS_H



class Status {
public:
	Status ();
	~Status ();

	int getID ();
	void setID (int _id);

private:
	int id = 0;
};

#endif // !STATUS_H
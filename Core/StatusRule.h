#pragma once
#ifndef STATUSRULE_H
#define STATUSRULE_H



class StatusRule {
public:
	StatusRule ();
	~StatusRule ();

	int getID ();
	void setID (int _id);

private:
	int id = 0;
};

#endif // !STATUSRULE_H
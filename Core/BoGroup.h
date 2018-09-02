#pragma once
#ifndef BOGROUP_H
#define BOGROUP_H

class BoGroup {
public:
	BoGroup ();
	~BoGroup ();

	int getID ();
	void setID (int id);

private:
	int id = 0;
};

#endif // !BOGROUP_H
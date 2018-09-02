#pragma once
#ifndef STATUSPERMISSION_H
#define STATUSPERMISSION_H


class StatusPermission {
public:
	StatusPermission ();
	~StatusPermission ();

	int getID ();
	void setID (int id);

private:
	int id = 0;
};

#endif // !STATUSPERMISSION_H
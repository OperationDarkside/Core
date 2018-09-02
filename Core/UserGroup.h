#pragma once
#ifndef USERGROUP_H
#define USERGROUP_H

#include "User.h"

#include <vector>

class UserGroup {
public:
	UserGroup ();
	~UserGroup ();

	int getID ();
	void setID (int id);

private:
	int id = 0;
};

#endif // !USERGROUP_H
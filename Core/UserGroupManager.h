#pragma once
#ifndef USERGROUPMANAGER_H
#define USERGROUPMANAGER_H

#include "UserGroup.h"

#include <vector>
#include <unordered_map>

class UserGroupManager {
public:
	UserGroupManager ();
	~UserGroupManager ();

	int getIndex (int groupID);

	UserGroup& getUserGroup (int index);

private:
	std::vector<UserGroup> groups;
	std::unordered_map<int, int> group_index;
};

#endif // !USERGROUPMANAGER_H
#pragma once
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"

#include <vector>
#include <unordered_map>

class UserManager {
public:
	UserManager ();
	~UserManager ();

	bool exists (int userID);

	User& getUser (int userID);

private:
	std::vector<User> users;
	std::unordered_map<int, int> user_index;
};

#endif // !USERMANAGER_H
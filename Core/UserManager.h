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

	int getIndex (int userID);

	int getIndex (std::string& username);

	User& getUser (int index);

	//User& getUser (std::string& username);

private:
	std::vector<User> users;
	std::unordered_map<int, int> userId_index;
	std::unordered_map<std::string, int> username_index;
};

#endif // !USERMANAGER_H
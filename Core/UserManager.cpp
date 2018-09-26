#include "UserManager.h"



UserManager::UserManager () {}


UserManager::~UserManager () {}

int UserManager::getIndex (int userID) {
	auto user_index_find = userId_index.find (userID);
	if (user_index_find == userId_index.end()) {
		return -1;
	}
	return user_index_find->second;
}

int UserManager::getIndex (std::string & username) {
	auto user_index_find = username_index.find (username);
	if (user_index_find == username_index.end ()) {
		return -1;
	}
	return user_index_find->second;
}

User & UserManager::getUser (int index) {
	//auto user_index_find = userId_index.find (userID);
	
	return users[index/*user_index_find->second*/];
}

/*User & UserManager::getUser (std::string& username) {
	auto user_index_find = username_index.find (username);

	return users[user_index_find->second];
}*/

#include "UserManager.h"



UserManager::UserManager () {}


UserManager::~UserManager () {}

bool UserManager::exists (int userID) {
	auto user_index_find = user_index.find (userID);
	if (user_index_find == user_index.end()) {
		return false;
	}
	return true;
}

User & UserManager::getUser (int userID) {
	auto user_index_find = user_index.find (userID);
	
	return users[user_index_find->second];
}

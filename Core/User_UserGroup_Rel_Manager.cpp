#include "User_UserGroup_Rel_Manager.h"



User_UserGroup_Rel_Manager::User_UserGroup_Rel_Manager () {}


User_UserGroup_Rel_Manager::~User_UserGroup_Rel_Manager () {}

int User_UserGroup_Rel_Manager::getGroupID (int userID) {
	auto rel_find = rel.find (userID);
	if (rel_find == rel.end()) {
		return -1;
	}

	return rel_find->second;
}

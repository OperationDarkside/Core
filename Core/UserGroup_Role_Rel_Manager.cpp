#include "UserGroup_Role_Rel_Manager.h"



UserGroup_Role_Rel_Manager::UserGroup_Role_Rel_Manager () {}


UserGroup_Role_Rel_Manager::~UserGroup_Role_Rel_Manager () {}

int UserGroup_Role_Rel_Manager::getRoleID (int userGroupID) {
	auto rel_find = rel.find (userGroupID);
	if (rel_find == rel.end ()) {
		return -1;
	}

	return rel_find->second;
}

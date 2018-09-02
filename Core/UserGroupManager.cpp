#include "UserGroupManager.h"



UserGroupManager::UserGroupManager () {}


UserGroupManager::~UserGroupManager () {}

bool UserGroupManager::exists (int groupID) {
	auto group_index_find = group_index.find (groupID);
	if (group_index_find == group_index.end ()) {
		return false;
	}
	return true;
}

UserGroup & UserGroupManager::getUserGroup (int groupID) {
	auto group_index_find = group_index.find (groupID);

	return groups[group_index_find->second];
}

#include "UserGroupManager.h"



UserGroupManager::UserGroupManager () {}


UserGroupManager::~UserGroupManager () {}

int UserGroupManager::getIndex (int groupID) {
	auto group_index_find = group_index.find (groupID);
	if (group_index_find == group_index.end ()) {
		return -1;
	}
	return group_index_find->second;
}

UserGroup & UserGroupManager::getUserGroup (int index) {
	//auto group_index_find = group_index.find (groupID);

	return groups[index/*group_index_find->second*/];
}

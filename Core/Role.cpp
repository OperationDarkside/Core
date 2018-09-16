#include "Role.h"



Role::Role () {}


Role::~Role () {}

int Role::getID () {
	return id;
}

void Role::setID (int id) {
	this->id = id;
}

bool Role::hasPermission (int boMetaId) {
	auto perm_find = permissions.find (boMetaId);
	if (perm_find == permissions.end ()) {
		// permission not found...
		return false;
	}
	return true;
}

Permission & Role::getPermission (int boMetaId) {
	auto perm_find = permissions.find (boMetaId);
	return perm_find->second;
}

std::unordered_map<int, Permission>& Role::getPermissions () {
	return permissions;
}

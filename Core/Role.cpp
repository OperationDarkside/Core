#include "Role.h"

Role::Role () {}

Role::~Role () {}

int Role::getID () {
	return id;
}

void Role::setID (int _id) {
	id = _id;
}

int Role::getBoPermissionIndex (int boMetaId) {
	auto perm_find = boPermissionIndex.find (boMetaId);
	if (perm_find == boPermissionIndex.end ()) {
		// permission not found...
		return -1;
	}
	return perm_find->second;
}

BoPermission & Role::getBoPermission (int index) {
	//auto perm_find = boPermissions.find (boMetaId);
	return boPermissions[index];//perm_find->second;
}

int Role::getStatusPermissionIndex (int statusId) {
	auto perm_find = statusPermissionIndex.find (statusId);
	if (perm_find == statusPermissionIndex.end ()) {
		// permission not found...
		return -1;
	}
	return perm_find->second;
}

StatusPermission & Role::getStatusPermission (int index) {
	return statusPermissions[index];
}

int Role::getLayoutPermissionIndex (int layoutId) {
	auto perm_find = layoutPermissionIndex.find (layoutId);
	if (perm_find == layoutPermissionIndex.end ()) {
		// permission not found...
		return -1;
	}
	return perm_find->second;
}

LayoutPermission & Role::getLayoutPermission (int index) {
	return layoutPermissions[index];
}


std::vector<BoPermission>& Role::getBoPermissions () {
	return boPermissions;
}

std::vector<StatusPermission>& Role::getStatusPermissions () {
	return statusPermissions;
}

std::vector<LayoutPermission>& Role::getLayoutPermissions () {
	return layoutPermissions;
}
void Role::setupIndices () {
	for (int i = 0; i < boPermissions.size (); ++i) {
		auto& boPerm = boPermissions[i];

		boPermissionIndex[boPerm.getID()] = i;
	}

	for (int i = 0; i < statusPermissions.size (); ++i) {
		auto& statusPerm = statusPermissions[i];

		statusPermissionIndex[statusPerm.getID ()] = i;
	}

	for (int i = 0; i < layoutPermissions.size (); ++i) {
		auto& layoutPerm = layoutPermissions[i];

		layoutPermissionIndex[layoutPerm.getID ()] = i;
	}
}
/*
std::unordered_map<int, Permission>& Role::getBoPermissions () {
	return boPermissions;
}
*/
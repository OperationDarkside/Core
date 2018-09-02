#include "Permission.h"



Permission::Permission () {}


Permission::~Permission () {}

int Permission::getID () {
	return id;
}

void Permission::setID (int id) {
	this->id = id;
}

int Permission::getBoMetaID () {
	return boMetaId;
}

void Permission::setBoMetaID (int _boMetaId) {
	this->boMetaId = _boMetaId;
}

int Permission::getRoleID () {
	return roleID;
}

void Permission::setRoleID (int _roleId) {
	this->roleID = roleID;
}

std::unordered_map<int, AttributePermission>& Permission::getAttributePermissions () {
	return attributePermissions;
}

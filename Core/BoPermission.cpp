#include "BoPermission.h"



BoPermission::BoPermission () {}


BoPermission::~BoPermission () {}

int BoPermission::getID () {
	return id;
}

void BoPermission::setID (int id) {
	this->id = id;
}

int BoPermission::getBoMetaID () {
	return boMetaId;
}

void BoPermission::setBoMetaID (int _boMetaId) {
	this->boMetaId = _boMetaId;
}

int BoPermission::getRoleID () {
	return roleID;
}

void BoPermission::setRoleID (int _roleId) {
	this->roleID = roleID;
}

bool BoPermission::areAllAttributesAllowed () {
	return this->allAttributesAllowed;
}

void BoPermission::setAllAttributesAllowed (bool allowed) {
	this->allAttributesAllowed = allowed;
}

std::unordered_map<int, AttributePermission>& BoPermission::getAttributePermissions () {
	return attributePermissions;
}

std::unordered_map<int, StatusPermission>& BoPermission::getStatusPermissions () {
	return statusPermissions;
}

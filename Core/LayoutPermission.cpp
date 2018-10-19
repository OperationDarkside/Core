#include "LayoutPermission.h"



LayoutPermission::LayoutPermission () {}


LayoutPermission::~LayoutPermission () {}

int LayoutPermission::getID () {
	return id;
}

void LayoutPermission::setID (int _id) {
	id = _id;
}

int LayoutPermission::getRoleID () {
	return roleID;
}

void LayoutPermission::setRoleID (int _id) {
	roleID = id;
}

int LayoutPermission::getLayoutID () {
	return layoutID;
}

void LayoutPermission::setLayoutID (int _id) {
	layoutID = _id;
}

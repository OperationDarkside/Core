#include "AttributePermission.h"



AttributePermission::AttributePermission () {}


AttributePermission::~AttributePermission () {}

int AttributePermission::getID () {
	return id;
}

void AttributePermission::setID (int id) {
	this->id = id;
}

int AttributePermission::getBoAttributeID () {
	return boAttributeID;
}

void AttributePermission::setBoAttributeID (int attrID) {
	this->boAttributeID = attrID;
}

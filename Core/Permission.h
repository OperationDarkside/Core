#pragma once
#ifndef PERMISSION_H
#define PERMISSION_H

#include "AttributePermission.h"

#include <unordered_map>

class Permission {
public:
	Permission ();
	~Permission ();

	int getID ();
	void setID (int id);

	int getBoMetaID ();
	void setBoMetaID (int _boMetaId);

	int getRoleID ();
	void setRoleID (int _roleId);

	bool areAllAttributesAllowed ();
	void setAllAttributesAllowed (bool allowed);

	std::unordered_map<int, AttributePermission>& getAttributePermissions ();

private:
	int id = 0;
	int boMetaId = 0;
	int roleID = 0;
	bool allAttributesAllowed;
	std::unordered_map<int, AttributePermission> attributePermissions;
};

#endif // !PERMISSION_H
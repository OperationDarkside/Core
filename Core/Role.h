#pragma once
#ifndef ROLE_H
#define ROLE_H

#include "BoPermission.h"
#include "LayoutPermission.h"
#include "StatusPermission.h"

#include <unordered_map>
#include <vector>

class Role {
public:
	Role ();
	~Role ();

	int getID ();
	void setID (int id);

	int getBoPermissionIndex (int boMetaId);
	BoPermission& getBoPermission (int index);

	int getStatusPermissionIndex (int statusId);
	StatusPermission& getStatusPermission (int index);

	int getLayoutPermissionIndex (int layoutId);
	LayoutPermission& getLayoutPermission (int index);

	std::vector<BoPermission>& getBoPermissions ();
	std::vector<StatusPermission>& getStatusPermissions ();
	std::vector<LayoutPermission>& getLayoutPermissions ();

	void setupIndices ();

private:
	int id = 0;

	std::vector<BoPermission> boPermissions;
	std::vector<StatusPermission> statusPermissions;
	std::vector<LayoutPermission> layoutPermissions;

	std::unordered_map<int, int> boPermissionIndex;
	std::unordered_map<int, int> statusPermissionIndex;
	std::unordered_map<int, int> layoutPermissionIndex;
};

#endif // !ROLE_H
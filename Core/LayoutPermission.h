#pragma once
#ifndef LAYOUTPERMISSION_H
#define LAYOUTPERMISSION_H


class LayoutPermission {
public:
	LayoutPermission ();
	~LayoutPermission ();

	int getID ();
	void setID (int _id);

	int getRoleID ();
	void setRoleID (int _id);

	int getLayoutID ();
	void setLayoutID (int _id);

private:
	int id = 0;
	int roleID = 0;
	int layoutID = 0;
};

#endif // !LAYOUTPERMISSION_H
#pragma once
#ifndef LAYOUTPERMISSION_H
#define LAYOUTPERMISSION_H


class LayoutPermission {
public:
	LayoutPermission ();
	~LayoutPermission ();

	int getID ();
	void setID (int _id);

private:
	int id;
};

#endif // !LAYOUTPERMISSION_H
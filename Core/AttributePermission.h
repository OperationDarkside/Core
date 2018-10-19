#pragma once
#ifndef ATTRIBUTEPERMISSION_H
#define ATTRIBUTEPERMISSION_H


class AttributePermission {
public:
	AttributePermission ();
	~AttributePermission ();

	int getID ();
	void setID (int id);

	int getBoMetaID ();
	void setBoMetaID (int id);

	int getBoAttributeID ();
	void setBoAttributeID (int attrID);

	int getBoPermissionID ();
	void setBoPermissionID (int id);

private:
	int id = 0;
	int boMetaID = 0;
	int boAttributeID = 0;
	int boPermissionID = 0;
};

#endif // !ATTRIBUTEPERMISSION_H
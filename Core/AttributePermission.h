#pragma once
#ifndef ATTRIBUTEPERMISSION_H
#define ATTRIBUTEPERMISSION_H


class AttributePermission {
public:
	AttributePermission ();
	~AttributePermission ();

	int getID ();
	void setID (int id);

	int getBoAttributeID ();
	void setBoAttributeID (int attrID);

private:
	int id = 0;
	int boAttributeID = 0;
};

#endif // !ATTRIBUTEPERMISSION_H
#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H



class Component {
public:
	Component ();
	~Component ();

	int getID ();
	void setID (int _id);

private:
	int id = 0;
};

#endif // !COMPONENT_H
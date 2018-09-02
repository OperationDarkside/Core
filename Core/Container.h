#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H



class Container {
public:
	Container ();
	~Container ();

	int getID ();
	void setID (int _id);

private:
	int id = 0;
};

#endif // !CONTAINER_H
#pragma once
#ifndef LAYOUT_H
#define LAYOUT_H



class Layout {
public:
	Layout ();
	~Layout ();

	int getID ();
	void setID (int _id);

private:
	int id = 0;
};

#endif // !LAYOUT_H
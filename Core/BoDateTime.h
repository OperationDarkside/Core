#pragma once
#ifndef BODATETIME_H
#define BODATETIME_H



class BoDateTime {
public:
	BoDateTime ();
	~BoDateTime ();

	unsigned long getMilli ();
	void setMilli (unsigned long milli);

private:
	unsigned long ms_since_epoch = 0;
};

#endif // !BODATETIME_H
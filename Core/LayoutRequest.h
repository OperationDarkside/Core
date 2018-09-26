#pragma once
#ifndef LAYOUTREQUEST_H
#define LAYOUTREQUEST_H

#include "Request.h"

class LayoutRequest : public Request {
public:
	LayoutRequest ();
	~LayoutRequest ();

	int getLayoutID ();
	void setLayoutID (int id);

private:
	int layoutID = 0;
};

#endif // !LAYOUTREQUEST_H
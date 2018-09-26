#pragma once
#ifndef BOLISTRESPONSE_H
#define BOLISTRESPONSE_H

#include "Response.h"

class BoListResponse : public Response {
public:
	BoListResponse ();
	~BoListResponse ();

	bool getSuccess ();
	void setSuccess (bool _success);

private:
	bool success = false;
};

#endif // !BOLISTRESPONSE_H
#pragma once
#ifndef BORESPONSE_H
#define BORESPONSE_H

#include "Response.h"
#include "StatusPermission.h"

class BoResponse : public Response {
public:
	BoResponse ();
	~BoResponse ();

	bool getSuccess ();
	void setSuccess (bool _success);

private:
	bool success = false;
};

#endif // !BORESPONSE_H
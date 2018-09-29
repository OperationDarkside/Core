#pragma once
#ifndef BOMETARESPONSE_H
#define BOMETARESPONSE_H

#include "Response.h"

#include "BoMeta.h"

class BoMetaResponse {
public:
	BoMetaResponse ();
	~BoMetaResponse ();

	bool getSuccess ();
	void setSuccess (bool _success);

private:
	bool success = false;
	
};

#endif // !BOMETARESPONSE_H
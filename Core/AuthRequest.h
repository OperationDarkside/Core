#pragma once
#ifndef AUTHREQUEST_H
#define AUTHREQUEST_H

#include "Request.h"

class AuthRequest : public Request {
public:
	AuthRequest ();
	~AuthRequest ();
};

#endif // !AUTHREQUEST_H
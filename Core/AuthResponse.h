#pragma once
#ifndef AUTHRESPONSE_H
#define AUTHRESPONSE_H

#include "Response.h"

class AuthResponse : public Response {
public:
	AuthResponse ();
	~AuthResponse ();
};

#endif // !AUTHRESPONSE_H
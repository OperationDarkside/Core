#pragma 
#ifndef LAYOUTRESPONSE_H
#define LAYOUTRESPONSE_H

#include "Response.h"
#include "Layout.h"


class LayoutResponse : public Response {
public:
	LayoutResponse ();
	~LayoutResponse ();

	bool isSuccess ();
	void setSuccess (bool _success);

	Layout* getLayout ();
	void setLayout (Layout* _layout);

private:
	bool success = false;

	Layout* layout = nullptr;
};

#endif // !LAYOUTRESPONSE_H
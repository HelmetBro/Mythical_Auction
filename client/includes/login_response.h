#ifndef LOGIN_RESPONSE_H
#define LOGIN_RESPONSE_H

#include <string>
#include <json.hpp>

using json = nlohmann::json;

#include "response.h"

class LoginResponse : public Response {

private:

	std::string result; //invalid, valid, or neither

public:

	int determine_response();

};
#endif
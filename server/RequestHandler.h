//
// Created by darinzh on 10/27/2015.
//

#ifndef CXX_REQUESTHANDLER_H
#define CXX_REQUESTHANDLER_H
#pragma once

#include <lib/http/HttpMessage.h>
#include <bits/unique_ptr.h>
#include "../my/conf.h"

/**
 * Interface to be implemented by objects that handle requests from client
 * ResponseHandler acts as the client for these objects and provides methods to send back the response
 * */
class RequestHandler {
public:
    /**
     *
     * */
    virtual void onRequest(std::unique_ptr<HttpMessage> headers) noexcept = 0;

};


#endif //CXX_REQUESTHANDLER_H

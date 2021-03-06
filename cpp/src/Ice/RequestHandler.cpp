// **********************************************************************
//
// Copyright (c) 2003-2016 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#include <Ice/RequestHandler.h>
#include <Ice/Reference.h>

using namespace std;
using namespace IceInternal;

#ifndef ICE_CPP11_MAPPING
IceUtil::Shared* IceInternal::upCast(RequestHandler* p) { return p; }
IceUtil::Shared* IceInternal::upCast(CancellationHandler* p) { return p; }
#endif


RetryException::RetryException(const Ice::LocalException& ex)
{
    ICE_RESET_EXCEPTION(_ex, ex.ice_clone());
}

RetryException::RetryException(const RetryException& ex)
{
    ICE_RESET_EXCEPTION(_ex, ex.get()->ice_clone());
}

const Ice::LocalException*
RetryException::get() const
{
    assert(_ex.get());
    return _ex.get();
}

RequestHandler::RequestHandler(const ReferencePtr& reference) :
    _reference(reference),
    _response(reference->getMode() == Reference::ModeTwoway)
{
}

// **********************************************************************
//
// Copyright (c) 2003-2014 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#pragma once

module Test
{

interface TestIntf
{
    void sleep(int seconds);
    void sleepAndHold(int seconds);
    void interruptSleep();
};

interface RemoteObjectAdapter
{
    TestIntf* getTestIntf();
    void activate();
    void hold();
    void deactivate();
};

interface RemoteCommunicator
{
    RemoteObjectAdapter* createObjectAdapter(int acmTimeout, int close, int heartbeat);
    void shutdown();
};

};

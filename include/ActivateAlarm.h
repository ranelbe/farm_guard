#pragma once
#include <iostream>
#include <cstdlib>
#include <curl/curl.h>

class ActivateAlarm {

    public:
    void activateAlarm();
    void SendingEMLWithSMTP();
};
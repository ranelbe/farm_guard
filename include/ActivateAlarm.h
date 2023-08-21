#pragma once

#include "macros.h"

class ActivateAlarm {
    CURL *_curl;
    CURLcode _res = CURLE_OK;

    public:
    ActivateAlarm();
    ~ActivateAlarm();
    void activateAlarm();
    void SendingEMLWithSMTP();
    void SendingSMSWithTwilio();
};
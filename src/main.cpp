#include <iostream>

#include "ActivateAlarm.h"

using std::cout;
using std::endl;

int main()
{
    ActivateAlarm alarm;
    alarm.activateAlarm();
    alarm.SendingEMLWithSMTP();

    return EXIT_SUCCESS;
}

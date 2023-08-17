//#include <iostream>
//
//#include "ActivateAlarm.h"
//
//using std::cout;
//using std::endl;
//
//int main()
//{
//    ActivateAlarm alarm;
//    alarm.activateAlarm();
//    alarm.SendingEMLWithSMTP();
//
//    return EXIT_SUCCESS;
//}

#include <iostream>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        // Set API endpoint URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.twilio.com/2010-04-01/Accounts/AC63460cbdbbd7e6e54811abd7a285e393/Messages.json");

        // Set HTTP POST request
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Set data to be sent (URL-encoded)
        std::string data = "From=+18146489292&To=+972506550336&Body=Hello%20from%20C%2B%2B";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        // Set basic authentication
        std::string auth = "AC63460cbdbbd7e6e54811abd7a285e393:96dd678939d243e8cd8f96c6b4078cd1";
        curl_easy_setopt(curl, CURLOPT_USERPWD, auth.c_str());

        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK)
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}

#include "ActivateAlarm.h"

ActivateAlarm::ActivateAlarm() {
    curl_global_init(CURL_GLOBAL_ALL);
    _curl = curl_easy_init();
}

void ActivateAlarm::activateAlarm() {
//    SendingEMLWithSMTP();
    SendingSMSWithTwilio();
    std::cout << "sent an sms to the farmer" << std::endl;
}

void ActivateAlarm::SendingEMLWithSMTP() {
    if (_curl) {
        std::string from = "ex5springyaakovhaimoff@gmail.com";
        std::string to = "hyaakov@aol.com";
        std::string subject = "Test Subject";
        std::string body = "This is the email body.";

        std::string url = "smtps://smtp.gmail.com:465";
        curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(_curl, CURLOPT_USERNAME, from.c_str());
        curl_easy_setopt(_curl, CURLOPT_PASSWORD, "pgxd qvbr rfiy dbyl");

        std::string payload = "From: " + from + "\r\nTo: " + to + "\r\nSubject: " + subject + "\r\n\r\n" + body;
        curl_easy_setopt(_curl, CURLOPT_READDATA, payload.c_str());
        curl_easy_setopt(_curl, CURLOPT_UPLOAD, 1L);

        _res = curl_easy_perform(_curl);

        if (_res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(_res));
        }
    }
}

void ActivateAlarm::SendingSMSWithTwilio() {
    if (_curl) {
        // Set API endpoint URL
        curl_easy_setopt(_curl, CURLOPT_URL,
                         "https://api.twilio.com/2010-04-01/Accounts/ACe3ae33a0ff68abf9bab8a30c5a07c9ed/Messages.json");

        // Set HTTP POST request
        curl_easy_setopt(_curl, CURLOPT_POST, 1L);

        std::string from = "+18146489292";
        std::string to = "+972506550336";
        std::string body = "Alert: Snakes detected in your coop. "
                           "Please take immediate action to ensure the safety of your animals.";

        // Set data to be sent (URL-encoded)
        std::string data = "From=" + from + "&To=" + to + "&Body=" + body;

        curl_easy_setopt(_curl, CURLOPT_POSTFIELDS, data.c_str());

        std::string ssid = "ACe3ae33a0ff68abf9bab8a30c5a07c9ed";
        std::string auth_token = "4c06074e54733e60220af20ddc304737";

        // Set basic authentication
        std::string auth = ssid + ":" + auth_token;
        curl_easy_setopt(_curl, CURLOPT_USERPWD, auth.c_str());

        _res = curl_easy_perform(_curl);

        // Check for errors
        if (_res != CURLE_OK)
            std::cerr << "Error: " << curl_easy_strerror(_res) << std::endl;


    }
}

ActivateAlarm::~ActivateAlarm() {
    curl_easy_cleanup(_curl);
    curl_global_cleanup();
}


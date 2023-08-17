#include "ActivateAlarm.h"

void ActivateAlarm::activateAlarm() {
    std::cout << "Alarm activated!" << std::endl;
}

void ActivateAlarm::SendingEMLWithSMTP() {
    CURL *curl;
    curl = curl_easy_init();

    if (curl) {
        std::string from = "ex5springyaakovhaimoff@gmail.com";
        std::string to = "hyaakov@aol.com";
        std::string subject = "Test Subject";
        std::string body = "This is the email body.";

        std::string url = "smtps://smtp.gmail.com:465";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_USERNAME, from.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "pgxd qvbr rfiy dbyl");

        std::string payload = "From: " + from + "\r\nTo: " + to + "\r\nSubject: " + subject + "\r\n\r\n" + body;
        curl_easy_setopt(curl, CURLOPT_READDATA, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
}

void ActivateAlarm::SendingSMSWithTwilio() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        // Set API endpoint URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.twilio.com/2010-04-01/Accounts/ACe3ae33a0ff68abf9bab8a30c5a07c9ed/Messages.json");

        // Set HTTP POST request
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Set data to be sent (URL-encoded)
        std::string data = "From=+18146489292&To=+972506550336&Body="
                           "Alert: Snakes detected in your coop. "
                           "Please take immediate action to ensure the safety of your animals.";

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        // Set basic authentication
        std::string auth = "ACe3ae33a0ff68abf9bab8a30c5a07c9ed:e95ccac232150f6a27b5e8e685bcf089";
        curl_easy_setopt(curl, CURLOPT_USERPWD, auth.c_str());

        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK)
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

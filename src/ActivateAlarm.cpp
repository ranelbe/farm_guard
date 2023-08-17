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

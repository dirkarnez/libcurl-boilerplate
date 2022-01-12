#include <iostream>
#include <cstdio>
#include <curl/curl.h>
#include <string>


using namespace std;

size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

int main(int argc, char** argv) {
	curl_global_init(CURL_GLOBAL_DEFAULT);

	CURL* curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://jsonplaceholder.typicode.com/todos/1");

		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
		curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
		curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		/* use a GET to fetch this */
		curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

		string response_string;
		string header_string;

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
		curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);
		
		/* Perform the request */
		CURLcode res = curl_easy_perform(curl);
		if(res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));
		}

		curl_easy_cleanup(curl);

		curl_global_cleanup();

		curl = nullptr;

		cout << response_string << endl;
	}
}
/* Playboi Carti I AM MUSIC Time between the start of rollout to the current date calculator */
#include <iostream>
#include <ctime> // For time functions

using namespace std;

int main() {
    // Current time
    time_t currentTime;
    time(&currentTime);

    char currentTimeStr[26]; // Buffer for ctime_s (26 bytes for date string)
    if (ctime_s(currentTimeStr, sizeof(currentTimeStr), &currentTime) != 0) {
        cerr << "Error: Unable to compute the current time string." << endl;
        return 1;
    }
    cout << "The Current Date is:\n" << currentTimeStr << endl;

    // Define the start date of the rollout
    struct tm rolloutDate = {};
    rolloutDate.tm_year = 2023 - 1900; // Year of rollout (years since 1900)
    rolloutDate.tm_mon = 11;          // December (0-based index)
    rolloutDate.tm_mday = 7;          // December 7th, 2023
    rolloutDate.tm_hour = 0;
    rolloutDate.tm_min = 0;
    rolloutDate.tm_sec = 0;

    // Convert the rollout date to time_t
    time_t rolloutTimestamp = mktime(&rolloutDate);

    if (rolloutTimestamp == -1) {
        cerr << "Error: Unable to compute rollout timestamp." << endl;
        return 1;
    }

    char rolloutTimeStr[26]; // Buffer for ctime_s
    if (ctime_s(rolloutTimeStr, sizeof(rolloutTimeStr), &rolloutTimestamp) != 0) {
        cerr << "Error: Unable to compute the rollout time string." << endl;
        return 1;
    }
    cout << "PBC started the I AM MUSIC rollout on:\n" << rolloutTimeStr << endl;

    // Calculate the time difference
    double secondsSinceRollout = difftime(currentTime, rolloutTimestamp);
    double daysSinceRollout = secondsSinceRollout / (60 * 60 * 24);

    cout << "Days since PBC started the I AM MUSIC rollout:\n" << daysSinceRollout << " days" << endl;

    // Pause the console to view the output in Visual Studio
    system("pause");
    return 0;
}

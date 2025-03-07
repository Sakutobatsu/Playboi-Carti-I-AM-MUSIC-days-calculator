#ifndef PBC_H
#define PBC_H

#include<iostream>
#include<ctime>
#include<string>

using namespace std;

class RolloutTimer {
    private:
        time_t currentTime;
        time_t rolloutTimestamp;
        
        // Helper function to convert time_t to string
        string formatTime(time_t timestamp) const {
            char buffer[26];
            if (ctime_s(buffer, sizeof(buffer), &timestamp) != 0) {
                return "Error: Unable to compute time string.";
            }
            return string(buffer);
        }
    
    public:
        // Constructor to initialize time values
        RolloutTimer() {
            time(&currentTime); // Get current time
    
            // Define the rollout date (December 7th, 2023)
            struct tm rolloutDate = {};
            rolloutDate.tm_year = 2023 - 1900;
            rolloutDate.tm_mon = 11;
            rolloutDate.tm_mday = 7;
            rolloutDate.tm_hour = 0;
            rolloutDate.tm_min = 0;
            rolloutDate.tm_sec = 0;
    
            // Convert to timestamp
            rolloutTimestamp = mktime(&rolloutDate);
    
            if (rolloutTimestamp == -1) {
                cerr << "Error: Unable to compute rollout timestamp." << endl;
            }
        }
    
        // Function to display times
        void displayTimes() const {
            cout << "The Current Date is:\n" << formatTime(currentTime) << endl;
            cout << "PBC started the I AM MUSIC rollout on:\n" << formatTime(rolloutTimestamp) << endl;
        }
    
        // Function to compute days since rollout
        double getDaysSinceRollout() const {
            return difftime(currentTime, rolloutTimestamp) / (60 * 60 * 24);
        }
    };
#endif
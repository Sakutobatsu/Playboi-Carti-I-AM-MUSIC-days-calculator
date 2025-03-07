#include<iostream>
#include"PBC.h"


using namespace std;

int main(){

    RolloutTimer timer;
    timer.displayTimes();
    
    cout << "Days since PBC started the I AM MUSIC rollout:\n"
         << timer.getDaysSinceRollout() << " days" << endl;

    system("pause"); // Only needed for Windows (remove if unnecessary)
    return 0;

};
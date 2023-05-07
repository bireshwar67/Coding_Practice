#include <iostream>
#include <string>

using namespace std;

string convertTo24HrFormat(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));
    string meridiem = time.substr(9, 2);

    if (meridiem == "PM" && hour != 12) {
        hour += 12;
    } else if (meridiem == "AM" && hour == 12) {
        hour = 0;
    }

    string hrString = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
    string minString = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
    string secString = (second < 10) ? "0" + to_string(second) : to_string(second);

    return hrString + ":" + minString + ":" + secString;
}

int main() {
    string time = "12:02:11 AM";
    string time24 = convertTo24HrFormat(time);
    cout << "The 24-hour time equivalent of " << time << " is " << time24 << endl;

    return 0;
}

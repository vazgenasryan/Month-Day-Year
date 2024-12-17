#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class mdy {
private:
    int day, month, year;
    string months[12] = { "jan", "feb", "mar", "apr", "may", "june",
                          "july", "aug", "sep", "oct", "nov", "dec" };
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    mdy(int dd = 29, int mm = 2, int yy = 2024) {
        if (mm < 1 || mm > 12) {
            day = 0;
            month = 0;
            year = 0;
        } else {
            month = mm;
            year = yy;

            if (mm == 2 && yy % 4 == 0) {
                days[1] = 29;
            }
            if (dd < 1 || dd > days[mm - 1]) {
                day = 0;
                month = 0;
                year = 0;
            } else {
                day = dd;
            }
        }
    }

    void out_m_d_y() {
        cout << setfill('0') << setw(2) << month << "/"
             << setw(2) << day << "/"
             << setw(2) << year % 100 << endl;
    }

    void out_ddd_yyyy() {
        int ddd = day;
        for (int i = 0; i < month - 1; i++) {
            ddd += days[i];
        }
        if (month > 2 && year % 4 == 0) {
            ddd++;
        }
        cout << ddd << " " << year << endl;
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }
};

int main() {
    mdy object(5, 7, 2005);
    object.out_m_d_y();
    object.out_ddd_yyyy();

    mdy leapDate(29, 2, 2024);
    leapDate.out_m_d_y();
    leapDate.out_ddd_yyyy();

    mdy invalidDate(31, 2, 2023);
    invalidDate.out_m_d_y();
    invalidDate.out_ddd_yyyy();

    return 0;
}

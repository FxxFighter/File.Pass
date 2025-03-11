#include <iostream>
#include <fstream>

using namespace std;

void checkPassword() {
    ifstream file("Pass");
    if (!file) {
        cout << "خطا: فایل 'Pass' پیدا نشد." << endl;
        return;
    }

    char line[100], userPassword[100];
    int attempts = 5;

    while (attempts > 0) {
        cout << "لطفاً پسورد خود را وارد کنید: ";
        cin >> userPassword;

        file.clear();
        file.seekg(0, ios::beg);
        bool isValid = false;

        while (file.getline(line, 100)) {
            bool match = true;
            for (int i = 0; line[i] | userPassword[i]; i++) {
                if (line[i] != userPassword[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                isValid = true;
                break;
            }
        }

        if (isValid) {
            cout << "ورود موفقیت‌آمیز" << endl;
            return;
        } else {
            attempts--;
            cout << "پسورد اشتباه است. " << attempts << " تلاش باقی مانده است." << endl;
        }
    }

    cout << "قفل شدن برنامه" << endl;
}

int main() {
    checkPassword();
    return 0;
}

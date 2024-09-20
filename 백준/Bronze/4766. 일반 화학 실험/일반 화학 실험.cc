#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float old_temp, new_temp;
    cin >> old_temp;

    while (true) {
        cin >> new_temp;

        if (new_temp == 999)
            break;

        cout << fixed << setprecision(2) << new_temp - old_temp << '\n';
        old_temp = new_temp;
    }

    return 0;
}
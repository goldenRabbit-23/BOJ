#include <iostream>
#include <string>
using namespace std;

int arr[100000];

bool isEmpty(int f, int r, int d) {
	return d == 1 && f > r || d == -1 && f < r;
}

void inputNum(string& l) {
	string num;
	int idx = 0;
	for (size_t i = 1; i < l.size(); i++) {
		char c = l[i];
		if (i == 1 && c == ']') { break; }
		if (c == ',' || c == ']') {
			arr[idx] = stoi(num);
			idx++;
			num.clear();
		}
		else { num += c; }
	}
}

void print(int f, int r, int d) {
	if (isEmpty(f, r, d)) { cout << "[]\n"; }
	else {
		cout << '[';
		for (int i = f; d == 1 ? i < r : i > r; i += d)
			cout << arr[i] << ',';
		cout << arr[r] << "]\n";
	}
}

int main() {
	int T, n, front, rear, dir;
	string func, list;
	cin >> T;

	while (T--) {
		cin >> func >> n >> list;
		inputNum(list);

		front = 0;
		rear = n - 1;
		dir = 1;

		for (size_t i = 0; i < func.size(); i++) {
			char f = func[i];
			if (f == 'R') {
				int t = front;
				front = rear;
				rear = t;
				dir *= -1;
			}
			else if (f == 'D') {
				if (isEmpty(front, rear, dir)) {
					cout << "error\n";
					goto NEXT;
				}
				front += dir;
			}
		}

		print(front, rear, dir);

	NEXT:
		continue;
	}

	return 0;
}
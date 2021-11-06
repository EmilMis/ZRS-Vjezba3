#include <iostream>
#include <vector>

using namespace std;

int max(int n1, int n2) {
	if (n1 > n2) {
		return n1;
	}
	return n2;
}

int min(int n1, int n2) {
	if (n1 < n2) {
		return n1;
	}
	return n2;
}

int main(void) {
	int broj_redaka;
	int brojevi_u_redku;
	vector<vector<int>> brojevi = {};

	scanf_s("%d%d", &broj_redaka, &brojevi_u_redku);

	for (int i = 0; i < broj_redaka; i++) {
		vector<int> jedan_redak = {};
		for (int j = 0; j < brojevi_u_redku; j++) {
			int neki_broj;
			scanf_s("%d", &neki_broj);
			jedan_redak.push_back(neki_broj);
		}
		brojevi.push_back(jedan_redak);
	}

	vector<int> current_list = brojevi[brojevi.size() - 1];

	for (int i = brojevi.size() - 2; i > -1; i--) {
		vector<int> lista_brojeva = brojevi[i];
		for (int i = 0; i < lista_brojeva.size(); i++) {
			if (i == 0) {
				lista_brojeva[i] += current_list[i + 1];
			}
			else if (i == lista_brojeva.size() - 1) {
				lista_brojeva[i] += current_list[i - 1];
			}
			else {
				lista_brojeva[i] += max(current_list[i + 1], current_list[i - 1]);
			}
		}
		current_list = lista_brojeva;
	}

	cout << "\n";

	int max_element = -INFINITY;

	for (int element : current_list) {
		if (element > max_element) {
			max_element = element;
		}
	}

	cout << max_element;

}

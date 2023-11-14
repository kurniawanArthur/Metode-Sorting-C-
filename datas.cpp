#include <iostream>
#include <ctime>    // Untuk fungsi waktu saat ini time().
#include <vector>
#include <chrono>


using namespace std;
bool isSorted = false;
std::vector<int> user_data;

void printResultAscending() {
	std::cout << "\nPengurutan secara ascending: " << endl;
	for (const auto& num : user_data) {
		std::cout << num << " ";
	}
	cout << endl;
}
void printResultDescending() {
	std::cout << "\nPengurutan secara ascending: " << endl;
	for (const auto& num : user_data) {
		std::cout << num << " ";
	}
	cout << endl;
}

//Buble sort
void bubbleSortAscending(std::vector<int>& data) {
	int n = data.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (data[j] > data[j + 1]) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}
void bubbleSortDescending(std::vector<int>& data) {
	int n = data.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (data[j] < data[j + 1]) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}

//Selection sort
void selectionSortAscending(std::vector<int>& data) {
	int n = data.size();
	for (int i = 0; i < n - 1; ++i) {
		int min_index = i;
		for (int j = i + 1; j < n; ++j) {
			if (data[j] < data[min_index]) {
				min_index = j;
			}
		}
		std::swap(data[i], data[min_index]);
	}
}
void selectionSortDescending(std::vector<int>& data) {
	int n = data.size();
	for (int i = 0; i < n - 1; ++i) {
		int max_index = i;
		for (int j = i + 1; j < n; ++j) {
			if (data[j] > data[max_index]) {
				max_index = j;
			}
		}
		std::swap(data[i], data[max_index]);
	}
}

//Insertion sort
void insertionSortAscending(std::vector<int>& data) {
	int n = data.size();
	for (int i = 1; i < n; ++i) {
		int key = data[i];
		int j = i - 1;

		while (j >= 0 && data[j] > key) {
			data[j + 1] = data[j];
			j = j - 1;
		}

		data[j + 1] = key;
	}
}
void insertionSortDescending(std::vector<int>& data) {
	int n = data.size();
	for (int i = 1; i < n; ++i) {
		int key = data[i];
		int j = i - 1;

		while (j >= 0 && data[j] < key) {
			data[j + 1] = data[j];
			j = j - 1;
		}

		data[j + 1] = key;
	}
}

//Merge sort
void merge(std::vector<int>& arr, int left, int mid, int right, bool ascending) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> leftArr(n1);
	std::vector<int> rightArr(n2);

	for (int i = 0; i < n1; ++i) {
		leftArr[i] = arr[left + i];
	}

	for (int j = 0; j < n2; ++j) {
		rightArr[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if ((ascending && leftArr[i] <= rightArr[j]) || (!ascending && leftArr[i] >= rightArr[j])) {
			arr[k] = leftArr[i];
			++i;
		}
		else {
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	while (j < n2) {
		arr[k] = rightArr[j];
		++j;
		++k;
	}
}
void mergeSort(std::vector<int>& arr, int left, int right, bool ascending) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid, ascending);
		mergeSort(arr, mid + 1, right, ascending);

		merge(arr, left, mid, right, ascending);
	}
}

//Quick sort
int partition(std::vector<int>& arr, int low, int high, bool ascending) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; ++j) {
		if ((ascending && arr[j] <= pivot) || (!ascending && arr[j] >= pivot)) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}

	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}
void quickSort(std::vector<int>& arr, int low, int high, bool ascending) {
	if (low < high) {
		int pi = partition(arr, low, high, ascending);

		quickSort(arr, low, pi - 1, ascending);
		quickSort(arr, pi + 1, high, ascending);
	}
}

int main() {
	int n;
	cout << "-=== Selamat datang di program sorting sederhana ini. ===-" << endl;

	// Melakukan generate data random sebanyak sesuai kemauan user
	cout << "Masukkan banyak data yang kamu mau: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		user_data.push_back(rand() % 999999);
	}
	cout << n << " Data acak dengan rentang 1-999999 berhasil dibuat!" << endl;
	int metode;
	
	do {
		cout << "\nMetode Sorting:\n";
		cout << "1. Bubble sort Ascending\n";
		cout << "2. Bubble sort Descending\n";
		cout << "3. Selection sort Ascending\n";
		cout << "4. Selection sort Descending\n";
		cout << "5. Insertion sort Ascending\n";
		cout << "6. Insertion sort Descending\n";
		cout << "7. Merge sort Ascending\n";
		cout << "8. Merge sort Descending\n";
		cout << "9. Quick sort Ascending\n";
		cout << "10. Quick sort Descending\n";
		cout << "11. Keluar\n";
		cout << "\nPilih metode pengurutan yang akan digunakan(1-11): ";
		cin >> metode;

		// Memulai waktu
		auto start_time = std::chrono::high_resolution_clock::now();

		switch (metode) {
		case 1: 
			//Bubble sort ascending
			bubbleSortAscending(user_data);
			printResultAscending();
			isSorted = true;
			break;
		case 2:
			// Bubble sort descending
			bubbleSortDescending(user_data);
			printResultDescending();
			isSorted = true;
			break;
		case 3:
			// Selection sort ascending
			selectionSortAscending(user_data);
			printResultAscending();
			isSorted = true;
			break;
		case 4:
			// Selection sort descending
			selectionSortDescending(user_data);
			printResultDescending();
			isSorted = true;
			break;
		case 5:
			// Insertion sort ascending
			insertionSortAscending(user_data);
			printResultAscending();
			isSorted = true;
			break;
		case 6:
			// Insertion sort descending
			insertionSortDescending(user_data);
			printResultDescending();
			isSorted = true;
			break;
		case 7:
			// Merge sort ascending
			mergeSort(user_data, 0, n - 1, true);
			printResultAscending();
			isSorted = true;
			break;
		case 8:
			// Merge sort descending
			mergeSort(user_data, 0, n - 1, false);
			printResultDescending();
			isSorted = true;
			break;
		case 9:
			// Quick sort ascending
			quickSort(user_data, 0, n - 1, true);
			printResultAscending();
			isSorted = true;
			break;
		case 10:
			// Quick sort descending
			quickSort(user_data, 0, n - 1, false);
			printResultDescending();
			isSorted = true;
			break;
		case 11:
			exit(0);
		}
		// Selesai waktu
		auto end_time = std::chrono::high_resolution_clock::now();

		// Menghitung durasi eksekusi dalam mikrodetik
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

		// Menampilkan durasi eksekusi dalam mikrodetik
		std::cout << "Waktu eksekusi: " << duration << " mikrodetik" << std::endl;
	} while (metode != 11 && isSorted == false);


	return 0;
}
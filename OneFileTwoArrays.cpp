#include <iostream>
#include <fstream>

void arrayRebuildFirst(std::ifstream* file, int array[], int size) {
	*file >> array[size - 1];
	for (int i = 0; i < size - 1; i++) {
		*file >> array[i];
	}
}

void arrayRebuildSecond(std::ifstream* file, int array[], int size) {
	for (int i = 1; i < size; i++) {
		*file >> array[i];
	}
	*file >> array[0];
}

void fileOutput(std::ofstream* file, int array[], int size) {
	*file << size << "\n";
	for (int i = 0; i < size; i++) {
		*file << array[i] << " ";
	}
	*file << "\n";
}

int main() {
	std::string inpath = "./TestFiles/in.txt";
	std::string outpath = "./TestFiles/out.txt";

	int n = 0;
	int m = 0;
	int temp = 0;

	std::ifstream infile(inpath);

	if (infile.is_open()) {

		infile >> n;
		int* n_array = new int[n];

		arrayRebuildFirst(&infile, n_array, n);

		infile >> m;
		int* m_array = new int[m];

		arrayRebuildSecond(&infile, m_array, m);

		std::ofstream outfile(outpath);

		fileOutput(&outfile, m_array, m);
		fileOutput(&outfile, n_array, n);

		delete[] m_array;
		delete[] n_array;

		outfile.close();
	}
	else {
		std::cout << "File not open, or not in folder!";
	}

	infile.close();


}
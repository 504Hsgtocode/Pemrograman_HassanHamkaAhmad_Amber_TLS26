// Dalam sebuah misi luar angkasa, terdapat sejumlah astronot
// yang harus mengikuti sebuah proses seleksi untuk menentukan
// siapa yang akan menjadi astronot terakhir yang bertahan. Para
// astronot berdiri membentuk sebuah lingkaran dan masing-
// masing memiliki nomor unik mulai dari 1 hingga N. Komandan
// memiliki sebuah sistem eliminasi dengan sebuah nilai K. Sistem
// tersebut bekerja secara berulang hingga hanya tersisa satu
// astronot. Pada awal proses, perhitungan dimulai dari astronot
// nomor 1. Astronot yang mendapatkan hitungan ke-K akan
// dieliminasi dari lingkaran. Setelah seorang astronot dieliminasi,
// proses perhitungan berikutnya dimulai dari astronot yang
// berada tepat setelah posisi astronot tersebut.
// Namun, terdapat aturan khusus pada sistem tersebut. Nilai K
// dapat berubah setelah setiap eliminasi:
// 1. Jika nomor astronot yang dieliminasi genap, maka nilai K
// bertambah 2
// 2. Jika nomor astronot yang dieliminasi ganjil, maka nilai K
// berkurang1
// 3. Nilai K tidak boleh kurang dari 2. Apabila hasil perubahan
// menyebabkan K < 2, maka nilai K menjadi 2.
// Proses tersebut terus dilakukan hingga hanya satu astronot
// yang tersisa.
// Bantulah komandan menentukan seluruh urutan astronot yang
// dieliminasi dan astronot terakhir yang bertahan.

#include <iostream>
using namespace std;

void rmElement(int& arrSize, int* arr, int& I_toDelete) {
    cout << arr[I_toDelete] << (arrSize > 1 ? ", " : "");
    for (int i = I_toDelete; i < arrSize; i++) {
        arr[i] = arr[i+1];
    }
    arrSize--;
}

int main() {
    int N_astronaut, K;
    cin >> N_astronaut >> K;
    if (K < 2) K = 2;

    cout<<"Order Eliminasi: ";

    int* arr = new int[N_astronaut]; for (int i=0; i<N_astronaut; i++) arr[i] = i+1; // populate, 0 index filled with i+1
    int remaining = N_astronaut - 1, // faster than sizecheck array
        pos = 0; // base 0 index

    while (remaining > 0) { // 1 left
        pos = (pos + K - 1) % (remaining + 1); // array loop
        if ((arr[pos] % 2) == 0) K += 2; // Genap
        else K = K <= 2 ? 2 : K - 1; // Ganjil + num check

        rmElement(remaining, arr, pos);
    }

    cout<<"\nMahastronot nomor: "<<arr[0]<<'\n';
    delete[] arr; // No memleek.
    return 0;
}

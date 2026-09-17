// Dari sejumlah astronot yang ada pada misi tersebut, seorang
// astronot menyadari bahwa terdapat alien yang sedang
// berpura-pura menjadi salah satu dari mereka. Untuk mengatasi
// masalah ini, mereka membuat cara komunikasi baru yang
// hanya dapat dipahami oleh manusia asli. Cara komunikasi baru
// ini menggunakan sebuah sistem sandi rahasia.
// Dalam sistem ini, setiap huruf akan diubah menjadi huruf lain
// berdasarkan posisi atau nomor dari huruf sebelumnya. Huruf
// pertama tidak mengalami perubahan, sedangkan setiap huruf
// berikutnya akan digeser sebanyak nilai dari huruf yang berada
// tepat sebelumnya. Untuk menentukan nilai setiap huruf,
// gunakan posisi huruf dalam alfabet, dengan A =1, B = 2, C =3....,
// Z = 26. Jika hasil pergeseran melewati Z, perhitungan kembali
// dimulai dari A.

#include <iostream>
using namespace std;

int main() {
    int sLen;
    cout<<"String length: "; cin>>sLen;
    if(sLen<=0) { // basic check
        cout<<"String cant be 0 or less in length.";
        return 1;
    }

    char* str = new char[sLen+1];
    cout<<"Your string (ALL CAPS): "; cin>>str; // assume input is always capital letters & same as sLen in length

    // Proecss the first character exclusively
    int prevVal = int(*str) - 64; // capital A is ascii 65
    
    char* strPoint = str; // special var that we use to easily traverse str
    strPoint++; // reference next char

    while(*strPoint != '\0') {
        char& c = *strPoint;
        c += prevVal; // Add previous value to the current char
        while (int(c)>90) c -= 26; // Keep the character within 65 and 90
        prevVal=int(c) - 64;
        strPoint++;
    }

    cout<<"Resulting string: "<<str;
    delete[] str; // Don't forget memleak
}

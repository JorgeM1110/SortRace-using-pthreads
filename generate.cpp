#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <ctime> 



using namespace std;

int main(int argc, char *argv[]){

    if(argc != 4){
        cout << "Error\n Generate COUNT MIN MAX" << endl; 
        return 1; 
    }

    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;
    cout << "argv[2]: " << argv[2] << endl;
    cout << "argv[3]: " << argv[3] << endl;

    int count = stoi(argv[1]);
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);

    srand(time(0));

    ofstream fout("numbers.dat");

    for (int i = 0; i < count; i++){
        int count_number = rand() % (max - min + 1) + min;
        fout << count_number << endl;
    }


    fout.close();

    return 0; 
    



}



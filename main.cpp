#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROW = 200;
const int COL = 320;

int pixels[ROW][COL];


void readData(string fileName){
    ifstream file(fileName);
    for(int i=0; i < ROW; i++){
        for( int j =0; j< COL; j++){
            file >> pixels[i][j];
        }
    }
    file.close();
}


int main(){

    readData("dane.txt");


    // Zadanie 6.1
    ofstream out_file("wyniki6.txt");

    int maxPixel = 0;
    int minPixel = 255;
    for(int i=0; i < ROW; i++){
        for( int j =0; j< COL; j++){
            maxPixel = max(maxPixel, pixels[i][j]);
            minPixel = min(minPixel, pixels[i][j]);
        }
    }
    out_file << "Zadanie 6.1:" << endl;
    out_file << "brightest " << maxPixel  << " darkest " << minPixel << endl;


    // Zadanie 6.2
    int minRows = 0;
    for(int i=0; i < ROW; i++){

            for(int j = 0; j < COL/2; j++){
                if( pixels[i][j] != pixels[i][COL-1-j]){
                    minRows++;
                    break;
                }
            }

    }
    out_file << "Zadanie 6.2:" << endl;
    out_file << "min rows " << minRows  << endl;



    // Zadanie 6.3
    int count = 0;

    for(int i=1; i < ROW-1; i++){

        for(int j = 1; j < COL-1; j++){

            if (abs(pixels[i][j] - pixels[i][j-1]) > 128){
                count++;
                continue;
            }

            if (abs(pixels[i][j] - pixels[i][j+1]) > 128){
                count++;
                continue;
            }

            if (abs(pixels[i][j] - pixels[i-1][j]) > 128){
                count++;
                continue;
            }

            if (abs(pixels[i][j] - pixels[i+1][j]) > 128){
                count++;
                continue;
            }
        }

    }

    for(int j = 1; j < COL-1; j++){
            if (abs(pixels[0][j] - pixels[0][j-1]) > 128){
                count++;
                continue;
            }
            if (abs(pixels[0][j] - pixels[0][j+1]) > 128){
                count++;
                continue;
            }
    }

    for(int j = 1; j < COL-1; j++){
            if (abs(pixels[ROW-1][j] - pixels[ROW-1][j-1]) > 128){
                count++;
                continue;
            }
            if (abs(pixels[ROW-1][j] - pixels[ROW-1][j+1]) > 128){
                count++;
                continue;
            }
    }

    for(int i=1; i < ROW-1; i++){

        if (abs(pixels[i][0] - pixels[i-1][0]) > 128){
            count++;
            continue;
        }

        if (abs(pixels[i][0] - pixels[i+1][0]) > 128){
            count++;
            continue;
        }
    }

    for(int i=1; i < ROW-1; i++){

        if (abs(pixels[i][COL-1] - pixels[i-1][COL-1]) > 128){
            count++;
            continue;
        }

        if (abs(pixels[i][COL-1] - pixels[i+1][COL-1]) > 128){
            count++;
            continue;
        }
    }


    out_file << "Zadanie 6.3:" << endl;
    out_file << "contrast pixels " << count  << endl;




    // Zadanie 6.4

    int max_length = 0;

    for(int j=0; j < COL; j++){

            int pixels_count = 1;

            for(int i = 0; i < ROW-1; i++){

                    if (pixels[i][j] == pixels[i+1][j] ){
                            cout << setw(4) << pixels[i][j];
                            pixels_count++;
                            max_length = max(max_length, pixels_count);

                            if( max_length > 6 ){
                                cout << "                    coordinates " << i << " " << j << endl;
                            }


                    }
                    else{
                            if( pixels_count > 4)
                                {
                                    //cout << "    " << pixels_count;
                                    pixels_count = 1;
                                    cout << endl;
                                }
                    }

            }


    }

    out_file << "Zadanie 6.4:" << endl;
    out_file << "the most length vertical line " << max_length  << endl;





    out_file.close();
}

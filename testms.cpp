// g++ -std=c++17 testms.cpp -o testms  `pkg-config --cflags --libs opencv4`
#include<bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace cv;
namespace fs = std::filesystem;
using namespace std;


int main()
{
    string dir_path = "../dataset/enhanced-890";
    string image_path;
    string image_name;
    Mat enhanced,reference;
    int channels,nRows,nCols;
    double diff,sum,score,n;
    uchar* p;
    uchar* q;
    ofstream myfile;
    myfile.open("../fusion_scores_meansquare.txt",ios::app);


    for (const auto & entry : fs::directory_iterator(dir_path))
    {
        image_path = entry.path();
        image_name = image_path.substr(image_path.find_last_of("/\\") + 1);

        enhanced = imread(image_path);
        reference = imread("../dataset/reference-890/"+image_name);

        Mat& enhanced1 = enhanced;
        Mat& reference1 = reference;


        channels = enhanced1.channels();
        nRows = enhanced1.rows;
        nCols = enhanced1.cols * channels;

        if (enhanced1.isContinuous())
        {
            nCols *= nRows;
            nRows = 1;
        }

        diff=0; sum=0;
        n=(double)nCols*(double)nRows;

        
        for(int i = 0; i < nRows; ++i)
        {
            p = enhanced1.ptr<uchar>(i);
            q = reference1.ptr<uchar>(i);
            for (int j = 0; j < nCols; ++j)
            {
                diff = (double)p[j] - (double)q[j];
                diff *= diff;
                diff=diff/n;
                sum += diff;
            }
        }

        score = sqrt(sum);
        myfile<<image_name<<", "<<score<<"\n";
    }

    myfile.close();
    return 0;
}
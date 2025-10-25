#include<opencv4/opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void getContours(Mat imgDil,Mat img,string color){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    int area;
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
   for (int i=0;i<contours.size();i++){
        area=contourArea(contours[i]);
        if (area>9100&&area<9650){
            float peri=arcLength(contours[i],true);
            approxPolyDP(contours[i],conPoly[i],0.02*peri,true);
            boundRect[i]=boundingRect(conPoly[i]);
            rectangle(img,boundRect[i].tl(),boundRect[i].br(),(0,255,255),5);
            putText(img,color,Point(10,50),FONT_HERSHEY_PLAIN,2,Scalar(0,69,255),2);
        }
    }   
}  

void transfer(Mat imgHSV,Mat img2,Scalar upper,Scalar lower,string type){
    Mat mask,gauss,canny,dil;
    inRange(imgHSV,lower,upper,mask);
    GaussianBlur(mask,gauss,Size(3,3),5,0);
    Canny(gauss,canny,25,75);
    Mat kernel=getStructuringElement(MORPH_RECT,Size(5,5));
    dilate(canny,dil,kernel);
    getContours(dil,img2,type);
}


int main(){
    string path="TrafficLight.mp4";
    VideoCapture cap(path);
    Mat img,img_r;
    Scalar lower_r(170,0,110);
    Scalar upper_r(179,255,255);
    Scalar lower_g(80,153,110);
    Scalar upper_g(96,255,212);
    double fps=cap.get(CAP_PROP_FPS);
    int w=cap.get(CAP_PROP_FRAME_WIDTH)*0.5;
    int h=cap.get(CAP_PROP_FRAME_HEIGHT)*0.5;
    VideoWriter writer("result.avi",VideoWriter::fourcc('X','V','I','D'),fps,Size(w,h));

    while (true){ 
        if(!cap.read(img)){break;}
        Mat imgHSV;
        resize(img,img_r,Size(),0.5,0.5);
        cvtColor(img_r,imgHSV,COLOR_BGR2HSV);
        transfer(imgHSV,img_r,upper_r,lower_r,"Red");
        transfer(imgHSV,img_r,upper_g,lower_g,"Green");
        imshow("output",img_r);
        writer.write(img_r);
        waitKey(1);
    }
    return 0;
}

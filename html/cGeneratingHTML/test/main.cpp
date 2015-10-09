#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ofstream myfile;
    myfile.open ("duc.html");
    string start = " <!DOCTYPE html><html><style>img {position: absolute;}</style><body><script>function inputPanoramic(message) {var myWindow = window.open('test.html?msg=' + message,'','width=1200, height=600');} </script> <img src='first-floor.jpg'style='z-index: -1;left: 0px;top: 0px;'> ";
    myfile << start << endl; //starting html
    
    
    
    //format
    
    /*<a onclick="inputPanoramic('Panoramic/duc000.jpg')">
     <img src="info.png"
     style="z-index: 1;
     left: 151.918365px;
     top: 475.568634px;
     width: 15px;
     height: 15px;">
     </a> */
    
    
    
    string formatFirst = "<a onclick='inputPanoramic('Panoramic/";
    //duc000
    string formatSecond = ".jpg')'> <img src='info.png' style='z-index: 1; left: ";
    //150      //left
    string coordLeft = "px;top: ";
    //475      //top
    string coordTop = "px;width: 15px;height: 15px;'></a> ";
    
    
    string name[2];
    name[0] = "duc000";
    name[1] = "duc001";
    
    double x[2];
    double y[2];
    x[0]= 151.918365;
    x[1]= 475.568634;
    y[0]= 185.110657;
    y[1]= 512.952148;
    
    
    for(int i = 0; i < 2; i++) {
        string tempName = name[i];
        double tempLeft = x[i];
        double tempTop = y[i];
        myfile << formatFirst << tempName << formatSecond << tempLeft << coordLeft << tempTop << coordTop << endl;
    }
    
    
    
    
    
    
    myfile << "</body></html>";
    myfile.close();
    
    
    return 0;
}

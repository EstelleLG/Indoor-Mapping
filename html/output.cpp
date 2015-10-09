#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Eigen/Sparse>
#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <gflags/gflags.h>



using namespace std;
using namespace Eigen;

void generateHtml(const map<string, Vector2d>& expected_uv_data, string& html_data) {
    
    string start = " <!DOCTYPE html><html><style>img {position: absolute;}</style><body><script>function inputPanoramic(message) {var myWindow = window.open(\"test.html?msg=\" + message,\"\",\"width=1200, height=600\");} </script> <img src=\"first-floor.jpg\"style=\"z-index: -1;left: 0px;top: 0px;\"> ";
    html_data +=start;//starting html
    
    string formatFirst = "<a onclick=\"inputPanoramic('Panoramic/";
    //duc000
    string formatSecond = ".jpg')\"> <img src=\"info.png\" style=\"z-index: 1; left: ";
    //150      //left
    string coordLeft = "px;top: ";
    //475      //top
    string coordTop = "px;width: 15px;height: 15px;\"></a> ";
    
    //loop through map to get the point
    //map<string,Vector2d>::iterator
    //for (auto itr = expected_uv_data.begin(); itr != expected_uv_data.end(); itr++) {
    
    for (const auto& itr : expected_uv_data) {
        string tempName = itr.first;
        double tempLeft = (itr.second)[0];
        double tempTop = (itr.second)[1];
        html_data += formatFirst + tempName + formatSecond + to_string(tempLeft) + coordLeft + to_string(tempTop) + coordTop;
    }
    
    html_data += "</body></html>";
    
}


int main(int argc, const char * argv[]) {
    
    //test expected uv data
    map<string,Vector2d> expected_uv_data;
    Vector2d one(151.918365, 475.568634);
    Vector2d two(185.110657, 512.952148);
    expected_uv_data.insert(pair<string, Vector2d>("duc000", one));
    expected_uv_data.insert(pair<string, Vector2d>("duc001", two));
    
    //call function and create html file.
    ofstream myfile("duc.html");
    string html_data;
    generateHtml(expected_uv_data, html_data);
    myfile << html_data;
    myfile.close();
    
    
    return 0;
}



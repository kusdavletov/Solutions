// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.
// [3, 5, 6, 10, 100, 140 .....]
// [1, 8, 15, 20, 150, 160 .....]
// [7, 85, 96, 267, 400, 500 .....]

// [76, 87, 91]
// [78, 79, 89]

#include <vector>

using namespace std;

struct Point {
  double x;
  double y;
};

struct Rectangle {
  Point lowerLeft;
  double height;
  double width;
};

bool overaps(const Rectangle& r1, const Rectangle& r2) {
    double x1, x2, y1, y2;
    double z1, z2, h1, h2;
    x1 = r1.lowerLeft.x;
    x2 = x1 + r1.width;
    y1 = r1.lowerLeft.y;
    y2 = y1 + r1.height;
    z1 = r2.lowerLeft.x;
    z2 = z1 + r2.width;
    h1 = r2.lowerLeft.y;
    h2 = h1 + r2.height;

    if (z1 > x2 || x1 > z2 || h1 > y2 || y1 > h2)
        return false;
    else
        return true;
}

vector<Rectangle> mergeOverlapping(const vector<Rectangle>& v) {
    vector<Rectangle> final;
    final.push_back(v[0]);
    for (int i = 1; i < v.size(); i++){
        if(overlaps(final[final.size() - 1], v[i])){
            Rectangle merged;
            Rectangle r1 = v[i - 1];
            Rectangle r2 = v[i];
            double x1, x2, y1, y2;
            double z1, z2, h1, h2;
            x1 = r1.lowerLeft.x;
            x2 = x1 + r1.width;
            y1 = r1.lowerLeft.y;
            y2 = y1 + r1.height;
            z1 = r2.lowerLeft.x;
            z2 = z1 + r2.width;
            h1 = r2.lowerLeft.y;
            h2 = h1 + r2.height;
            if (x1 < z1){
                merged.lowerLeft.x = x1;
            }
            else {
                merged.lowerLeft.x = z1;
            }
            if (y1 < z1){
                merged.lowerLeft.y = y1;
            }
            else{
                merged.lowerLeft.y = z1;
            }
            final.push_back(merged);
        }
        else {
            final.push_back(v[i - 1]);
            if (i == v.size() - 1)
                final.push_back(v[i]);
        }
    }
    return final;
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Point { 
    int x; 
    int y; 
}; 

struct Line {
    Point p1;
    Point p2;
};

string remove_char(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return str;
}

bool onSegment(Point p, Point q, Point r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

int orientation(Point p, Point q, Point r) { 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false;
}

int main() {
    int n;
    cin >> n;
    Line* lines = new Line[n];

    for (int i = 0; i < n; ++i) {
        string sp1, sp2;
        cin >> sp1 >> sp2;
        sp1 = remove_char(remove_char(sp1, '('), ')');
        sp2 = remove_char(remove_char(sp2, '('), ')');
        auto it1 = sp1.find(',');
        auto it2 = sp2.find(',');
        lines[i].p1.x = stoi(sp1.substr(0, it1));
        lines[i].p1.y = stoi(sp1.substr(it1 + 1));
        lines[i].p2.x = stoi(sp2.substr(0, it2));
        lines[i].p2.y = stoi(sp2.substr(it2 + 1));
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        bool possible = true;
        for (int j = 0; j < n; ++j)
            if (i != j && doIntersect(lines[i].p1, lines[i].p2, lines[j].p1, lines[j].p2)) {
                possible = false;
                break;
            }
        if (possible)
            ++sum;
    }

    cout << sum << endl;
    return 0;
}
#include <iostream>

using namespace std;

class box{
    private:
        int h;
        int w;
        int l;
        int smallest;
        int perimeter; // yk what i mean
        int cubic;
    public:
        box(int, int, int);
        int get_perimeter(); // smallest perimeter
        int get_smallest();
        int get_area();
};

box::box(int in_w, int in_h, int in_l) {
    w = in_w;
    h = in_h;
    l = in_l;
    cubic = w*h*l;

    int wh = w*h;
    int wl = w*l;
    int hl = h*l;

    smallest = wh;
    if (smallest > hl) smallest = hl;
    if (smallest > wl) smallest = wl;
    
    wh = 2*w + 2*h;
    wl = 2*w + 2*l;
    hl = 2*h + 2*l;

    perimeter = wh;
    if (perimeter > wl) perimeter = wl;
    if (perimeter > hl) perimeter = hl;
}

int box::get_smallest(){
    return smallest;
}

int box::get_perimeter(){
    return perimeter + cubic;
}


int box::get_area(){
    return 2*h*w + 2*h*l + 2*w*l + smallest;
}

int main(void) {
    int w, h, l;
    int flag;
    int sumA = 0, sumB = 0;

    while (scanf("%dx%dx%d", &l, &w, &h) != EOF) {
        box current_box(w, h, l);
        sumA += current_box.get_area();
        sumB += current_box.get_perimeter();
    }
    
    cout << "part A: " << sumA << endl;
    cout << "part B: " << sumB << endl;
    return 0;
}

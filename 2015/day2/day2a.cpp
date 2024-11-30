#include <iostream>

using namespace std;

class box{
    private:
        int h;
        int w;
        int l;
        int smallest;
    public:
        box(int, int, int);
        int get_smallest();
        int get_area();
};

box::box(int in_w, int in_h, int in_l) {
    w = in_w;
    h = in_h;
    l = in_l;
    int wh = w*h;
    int wl = w*l;
    int hl = h*l;

    smallest = wh;
    if (smallest > hl) smallest = hl;
    if (smallest > wl) smallest = wl;
}

int box::get_smallest(){
    return smallest;
}

int box::get_area(){
    return 2*h*w + 2*h*l + 2*w*l + smallest;
}

int main(void) {
    int w, h, l;
    int flag;
    int sum = 0;
    while (scanf("%dx%dx%d", &l, &w, &h) != EOF) {
        box current_box(w, h, l);
        sum += current_box.get_area();
    }
    
    cout << sum << endl;
    return 0;
}

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

using namespace std;

class Point{

public:

Point(){
    x=y=0;
}
Point punto(int coordenada_X, int coordenada_Y){
    this->x=coordenada_X;
    this->y=coordenada_Y;
    return *this;
}

void setX(int coord_X){
    this->x=coord_X;
}
void setY(int coord_Y){
    this->y=coord_Y;
}

int getX(){
    cout<<"X: ";
    return this->x;
}
int getY(){
    cout<<"Y: ";
    return this->y;
}

friend ostream& operator<<(ostream &o, const Point &p){
    cout<<"Las coordenadas son:"<<endl<<"X: ";
    o<<p.x;
    cout<<" Y: ";
    o<<p.y;
    return o;
}

friend istream& operator>>(istream &in, Point &p){
    cout << "Coordenada X: ";
    in >> p.x;
    cout << endl<<"Coordenada Y: ";
    in >> p.y;
    return in;
}

private:
    int x,y;
};



#endif // POINT_H_INCLUDED

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

double modul_side(vector<int> f_point,const vector<int>s_point ){
    vector<int>cord_of_side;
    double s=0;
    for(int i=0;i<f_point.size();i++)
        {
            cord_of_side.push_back(s_point[i]-f_point[i]);
        }
    for(int cord : cord_of_side){
        s+=pow(cord,2);
    }
    return sqrt(s);
}

int area_triangle(int x1,int y1,int x2,int y2, int x3,int y3){
    int S=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return abs(S);
}
string belong(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    int S_main=area_triangle(x1,y1,x2,y2,x3,y3);
    int S1=area_triangle(x1,y1,x2,y2,x4,y4);
    int S2=area_triangle(x1,y1,x3,y3,x4,y4);
    int S3=area_triangle(x2,y2,x3,y3,x4,y4);
    if(S_main==S1+S2+S3)
        return "Yes";
    else
        return "No";
}
struct point{
    int x,y;
};
string isInside(vector<point>polygon,point dot){
    int n = 0;
    for (int i=0;i<polygon.size();i++){
        point apex = polygon[i];
        point apex_next=polygon [(i+1) % polygon.size()];
        if((apex.y>dot.y) != (apex_next.y>dot.y) && dot.x < (apex_next.x - apex.x) * (dot.y - apex.y)/(apex_next.y-apex.y) + apex.x)
            n++;
    }   
    if (n%2==1)
        return "Yes";
    else
        return "No";
}
int main()
{
    cout<<"kalculate modul of side"<<endl;
    vector<int>point_1;
    vector<int>point_2;
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int b;
        int c;
        cin>>b>>c;
        point_1.push_back(b);
        point_2.push_back(c);
    }
    double a=modul_side(point_1,point_2);
    cout<<a<<endl;


    cout<<"belong?"<<endl;
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    string result=belong(x1,y1,x2,y2,x3,y3,x4,y4);
    cout<<result<<endl;

    cout<<"isInside?"<<endl;
    cin>>n;
    vector<point>polygon;
    for(int i=0;i<n;i++){
        point cord;
        cin>>cord.x>>cord.y;
        polygon.push_back(cord);
    }
    point dot;
    cin>>dot.x>>dot.y;
    result=isInside(polygon,dot);
    cout<<result;
    return 0;
}
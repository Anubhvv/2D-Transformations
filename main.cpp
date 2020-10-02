#include <bits/stdc++.h>
#include <graphics.h>


using namespace std;
int MAXX=900,MAXY=500;
int n;
double points[25][2];
double ans[][1] = {{0},
                   {0},
                   {0}};
double tx,ty;
double theta;
double Sx,Sy;
double PI=3.141592653589793238;
void display(int n)
{
        for(int i=1;i<n+n-1;i++)
            line(points[(i-1)%n][0]+MAXX,-points[(i-1)%n][1]+MAXY,points[i%n][0]+MAXX,-points[i%n][1]+MAXY);
}
void display_points()
{
    for(int i=0; i < n; i++)
        cout<<"( "<<points[i][0]<<" , "<<points[i][1]<<" )\n";

}
void translation(double tx, double ty)
{
    void MATRIX_MULTIPLICATION(int,int,double [][3],int,int,double [][1],int,int,double [][1]);
    double T[][3] = { { 1, 0, tx },
                      { 0, 1, ty },
                      { 0, 0, 1  } };
    double x,y;
    for(int i=0;i<n; i++){
        x=points[i][0];
        y=points[i][1];
        double P[3][1]={ {x},
                        {y},
                        {1}};
        MATRIX_MULTIPLICATION(3,3,T,3,1,P,3,1,ans);
        points[i][0]=ans[0][0];
        points[i][1]=ans[1][0];
    }

}
void rotation(double theta)
{
    void MATRIX_MULTIPLICATION(int,int,double [][3],int,int,double [][1],int,int,double [][1]);
    double R[][3] = { { 1.00*cos(theta),-1.00*sin(theta) , 0 },
                      { 1.00*sin(theta), 1.00*cos(theta), 0 },
                      { 0, 0, 1 } };
    double x,y;
    for(int i=0;i<n; i++){
        x=points[i][0];
        y=points[i][1];

        double P[3][1]={ {x},
                    {y},
                    {1}};
        MATRIX_MULTIPLICATION(3,3,R,3,1,P,3,1,ans);
        points[i][0]=ans[0][0];
        points[i][1]=ans[1][0];
    }
}
void scale(double Sx,double Sy)
{
    void MATRIX_MULTIPLICATION(int,int,double [][3],int,int,double [][1],int,int,double [][1]);
    double S[][3] = { { Sx, 0, 0 },
                      { 0, Sy, 0 },
                      { 0, 0, 1 } };
    double x,y;
    for(int i=0;i<n; i++){
        x=points[i][0];
        y=points[i][1];

        double P[3][1]={ {x},
                        {y},
                        {1}};


        MATRIX_MULTIPLICATION(3,3,S,3,1,P,3,1,ans);
        points[i][0]=ans[0][0];
        points[i][1]=ans[1][0];
    }
}
void menu()
{
        cout<<"\n\n\t\tSelect the operation\n\n";
        cout<<"\t\t translation\n";
        cout<<"\t\t scaling\n\t\t rotation about origin\n";
        cout<<"\t\t reflect about a line\n\t\t Yreflect about line parallel to y axis (slope =infinity)\n\t\t shear\n\n\n";
}
void shear(double Shx, double Shy)
{
    void MATRIX_MULTIPLICATION(int,int,double [][3],int,int,double [][1],int,int,double [][1]);
    double T[][3] = { { 1, Shx, 0 },
                    { Shy, 1, 0 },
                    { 0, 0, 1 } };
    double x,y;
    for(int i=0;i<n; i++){
        x=points[i][0];
        y=points[i][1];

        double P[3][1]={ {x},
                        {y},
                        {1}};

        MATRIX_MULTIPLICATION(3,3,T,3,1,P,3,1,ans);
        points[i][0]=ans[0][0];
        points[i][1]=ans[1][0];
    }

}
int main()
{   void MATRIX_MULTIPLICATION(int,int,double [][3],int,int,double [][1],int,int,double [][1]);
    initwindow(2000,1000);
    line(MAXX,0, MAXX,2000);
    line(0,MAXY,2000,MAXY);
    cout<<"\t\tEnter the number of points:\n";
    cin>>n;
    cout<<"\t\tEnter the coordinates:\n";
    for(int i=0;i<n;i++)
        cin>>points[i][0]>>points[i][1];
    display(n);
    while(true)
    {
        double x,y;
        char s[40];
        menu();
        cin >> s;
    if(s[0]=='t')
            {cout<<"enter tx, ty\n";
                    cin>>tx >> ty;
                    translation(tx,ty);

                    cout<<"Points After Transformation(s)\n";
                    display_points();
                    display(n);
            }
            else if(s[0]=='r' and s[1]=='o'){
            cout<<"\t\t   enter theta in degrees\n";
                    cin>>theta;
                    theta = theta*(PI/180);


                   rotation(theta);

                    cout<<"Points After Transformation(s)\n";
                    display_points();
                    display(n);
            }
            else if(s[0]=='s' and s[1]=='c'){
                    cout<<"\t\t enter Sx, Sy\n";
                    cin>>Sx>>Sy;

                    scale(Sx,Sy);

                    cout<<"Points After Transformation(s)\n";
                    display_points();
                    display(n);
        }
        else if(s[0]=='r'){
            cout<<"\t\ty=mx+c , Enter values of 'm' and 'c':\n";
                    double c;
                    cin>>theta>>c;
                    translation(0,-c);
                    theta=-atan(theta);
                    rotation(theta);
                    scale(1,-1);

                    rotation(-theta);
                    translation(0,c);
                    cout<<"Points After Transformation(s)\n";
                    display_points();
                    display(n);



        }
        else if(s[0]=='s'){
                cout<<"enter Shx Shy\n";
                    double Shx,Shy;
                    cin>>Shx >> Shy;
                    double T[][3] = { { 1, Shx, 0 },
                                { Shy, 1, 0 },
                                { 0, 0, 1 } };
                    for(int i=0;i<n; i++){
                    x=points[i][0];
                    y=points[i][1];

                    double P[3][1]={ {x},
                                {y},
                                {1}};


                    MATRIX_MULTIPLICATION(3,3,T,3,1,P,3,1,ans);
                    points[i][0]=ans[0][0];
                    points[i][1]=ans[1][0];
                    }
                    cout<<"Points After Transformation(s)\n";
                    display_points();
                    display(n);

        }
    else if(s[0]=='y')
    {
        cout<<"Enter value of c for line x=c :\n ";
        double c;
        cin>>c;
        translation(-c,0);
        scale(-1,1);
        translation(c,0);

        cout<<"Points After Transformation(s)\n";
        display_points();
        display(n);
    }

    }

    return 0;
}

void MATRIX_MULTIPLICATION(int r1, int c1, double mat1[][3],
              int r2, int c2, double mat2[][1],
              int ans_r,int ans_c,double ans[][1]) {

    int x, i, j;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            ans[i][j] = 0;
            for (x = 0; x < c1; x++)
            {
                *(*(ans + i) + j) += *(*(mat1 + i) + x) *
                                     *(*(mat2 + x) + j);
            }
        }
    }
}

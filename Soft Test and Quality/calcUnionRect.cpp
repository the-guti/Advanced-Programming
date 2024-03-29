//  A01019608
// Created by Roberto Alejandro Gutierrez Guillen on 2019-10-18.
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;









/*

// Doesnt work, it takes into account too many intercepts
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<float, float> pairs;
// Calculate union of all the rectangles
// More efficient approach would be to sort the array, take the first area then iterate decreasing from max X to small X,
// looking from a y bigger than the first one, when u find one, the prev max Y is you new 0 and only calculate the area from that,
// you add it

// E1- Error en toda la funcion main en multiples lineas
    // H - Faltan ) parentesis cerrar en creacion de tuplas
// E2 - No se encuentra la variable vector
    // H Se escribio vector y se llamaba solo v
// E3 - No encuentra la estructura tuples
    // H - Falta importar tuple

float calcAreaRect(float x, float y){
    return (x*y);
}

float calcInt(float x1, float y1,float x2, float y2){
    return (min(x1, x2) * min(y1, y2));
}

float calcUnion(vector<pair<float, float> > v){
    // Calculate all areas
    float areasSum = 0;
    for(int i = 0; i < v.size();i++){
        areasSum+= calcAreaRect(v[i].first,v[i].second);
    }
    areasSum *= (v.size()/sqrt(v.size()));
    cout << areasSum << "\n "; 

    float intSum = 0;
    // Calculate all intercepts
    for(int i = 0; i< v.size();i++){
        for(int j = i+1;j<v.size() ;j++){
            intSum+= calcInt(v[i].first,v[i].second, v[j].first,v[j].second);
        }
    }
    cout << intSum << "\n "; 

    // Union equals areas minus intercepts
    return (areasSum - intSum);
}

int main(){
    vector<pair<float, float> > v;
    v.push_back(make_pair(2.050027e-04,3.432857e-05));
    v.push_back(make_pair(2.367507e-04,4.018590e-05));
    v.push_back(make_pair(2.285439e-04,1.264791e-06));
    v.push_back(make_pair(7.941429e-04,3.976792e-04));
    v.push_back(make_pair(8.499579e-04,1.546354e-04));
    v.push_back(make_pair(2.115751e-03,4.098230e-04));
    v.push_back(make_pair(2.065485e-03,2.559472e-04));
    v.push_back(make_pair(1.852948e-03,5.098387e-04));
    v.push_back(make_pair(3.440477e-03,1.779515e-04));
    v.push_back(make_pair(4.549663e-03,3.014085e-04));
    v.push_back(make_pair(1.797588e-03,1.396358e-03));
    v.push_back(make_pair(4.767429e-03,5.613301e-04));
    v.push_back(make_pair(4.136026e-03,4.426686e-04));
    v.push_back(make_pair(4.367523e-03,1.155300e-03));
    v.push_back(make_pair(9.306622e-04,2.541372e-04));
    v.push_back(make_pair(5.680124e-03,1.432165e-05));
    v.push_back(make_pair(1.490228e-03,4.229576e-04));
    v.push_back(make_pair(2.522978e-05,2.854546e-06));
    v.push_back(make_pair(6.610025e-03,1.371327e-03));
    v.push_back(make_pair(4.374467e-03,4.785881e-04));
    v.push_back(make_pair(7.973659e-03,8.198998e-04));
    v.push_back(make_pair(8.551307e-03,4.158759e-03));
    v.push_back(make_pair(3.690370e-03,1.827869e-04));
    v.push_back(make_pair(1.698429e-02,2.867370e-03));
    v.push_back(make_pair(4.182426e-03,4.400267e-04));
    v.push_back(make_pair(6.383462e-03,6.341947e-03));
    v.push_back(make_pair(1.299448e-02,5.364461e-04));
    v.push_back(make_pair(4.883480e-03,3.214258e-04));
    v.push_back(make_pair(6.898288e-03,7.258450e-05));
    v.push_back(make_pair(1.080667e-02,1.238736e-03));
    v.push_back(make_pair(1.604697e-02,9.578654e-04));
    v.push_back(make_pair(1.427762e-03,2.143895e-04));
    v.push_back(make_pair(1.297334e-02,6.389248e-04));
    v.push_back(make_pair(1.156949e-02,1.284602e-03));
    v.push_back(make_pair(2.957158e-03,3.013526e-04));
    v.push_back(make_pair(2.078436e-03,2.627491e-04));
    v.push_back(make_pair(1.868344e-03,3.216004e-04));
    v.push_back(make_pair(9.865930e-03,2.990217e-05));
    v.push_back(make_pair(1.238108e-02,1.410623e-03));
    v.push_back(make_pair(8.785646e-03,4.866803e-03));
    v.push_back(make_pair(2.690037e-04,4.609743e-05));
    v.push_back(make_pair(8.090692e-03,7.719370e-04));
    v.push_back(make_pair(8.743903e-03,9.801073e-04));
    v.push_back(make_pair(1.466630e-02,2.132126e-04));
    v.push_back(make_pair(8.484121e-03,1.020964e-03));
    v.push_back(make_pair(2.391372e-03,4.073911e-05));
    v.push_back(make_pair(1.448791e-02,2.295302e-03));
    v.push_back(make_pair(2.237820e-02,2.551107e-03));
    v.push_back(make_pair(1.405326e-02,6.961262e-04));
    v.push_back(make_pair(5.220865e-03,2.601469e-04));
    v.push_back(make_pair(2.788245e-02,3.460234e-03));
    v.push_back(make_pair(5.730653e-03,4.525818e-04));
    v.push_back(make_pair(1.402374e-02,1.486041e-03));
    v.push_back(make_pair(4.683988e-03,4.978664e-04));
    v.push_back(make_pair(1.105775e-02,9.608953e-04));
    v.push_back(make_pair(1.315487e-03,8.446719e-05));
    v.push_back(make_pair(2.599340e-02,2.491113e-03));
    v.push_back(make_pair(1.047936e-02,2.081829e-03));
    v.push_back(make_pair(6.803583e-03,7.851202e-04));
    v.push_back(make_pair(2.123573e-02,1.714729e-03));

    cout << calcUnion(v) << "\n";
    return 0;
}
*/
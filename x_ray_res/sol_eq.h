#pragma once

#include <cmath>

using namespace std;

class Solution {
private:
    float Anode_Radius = 1; // mm
    float Anode_Length = 1; // mm
    float Target_Length = 1; // mm
    float Focal_Spote = 1; // mm

    //float Anode_Radius; // mm
    //float Anode_Length; // mm
    //float Target_Length; // mm
    //float Focal_Spote; // mm

    float lambda_copper = 389.6;
    int lambda_tungsten = 173;
    int n_zero = 10;
    float* ZEROS = NULL;
public:
    /*Solution(float Anode_Radius = 1, float Anode_Length = 1, float Target_Length = 1, float Focal_Spote = 1) : Anode_Radius(Anode_Radius),
        Anode_Length(Anode_Length),
        Target_Length(Target_Length),
        Focal_Spote(Focal_Spote) {

    }*/
    Solution();
    Solution(float Anode_Radius, float Anode_Length, float Target_Length, float Focal_Spote, int n_zero);
    float* j1_zeros(int n_zero, float* ZEROS);
    float beta(int i, float* ZEROS);
    float R(int i, float r, float* ZEROS);
    float M(int i, float z, float* ZEROS);
    float L(int i, float z, float* ZEROS);
    float exp_function(int i, float* ZEROS);
    float get_Anode_Radius();
    float get_Anode_Length();
    float get_Target_Length();
    float get_Focal_Spote();
    int get_n_zero();
    ~Solution();
    /*~Solution() {
        delete[] ZEROS;
    };*/
};
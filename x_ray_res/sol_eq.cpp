
#include <cmath>

#include "sol_eq.h"

Solution::Solution() {
    //float* ZEROS = (float*)malloc(sizeof(float) * n_zero);
    //ZEROS = new float[n_zero];

    //this->n_zero = n_zero;

    this->ZEROS = new float[n_zero];
}
Solution::Solution(float Anode_Radius, float Anode_Length, float Target_Length, float Focal_Spote, int n_zero) {
    //float* ZEROS = (float*)malloc(sizeof(float) * n_zero);
    //ZEROS = new float[n_zero];

    this->Anode_Radius = Anode_Radius;
    this->Anode_Length = Anode_Length;
    this->Target_Length = Target_Length;
    this->Focal_Spote = Focal_Spote;
    this->n_zero = n_zero;

    this->ZEROS = new float[n_zero];
}
//Solution::Solution() {
//    ZEROS = new float[n_zero];
//}
float* Solution::j1_zeros(int n_zero, float* ZEROS)       //n_zero - null number, ZEROS - vector of nulls
{
    int count = 0;
    float delta = 0.001;
    int MAX_ITER = 100000;

    float Now_Step = 0;
    float Future_Step = 0;

        //float* ZEROS = (float*)malloc(sizeof(float) * n_zero);

    for (int i = 0; i < MAX_ITER; i++) {

        //Now_Step = _j1(i * 1.0 * delta);
        //Future_Step = _j1((i * 1.0 + 1) * delta);
        float sign = _j1(i * 1.0 * delta) * _j1((i * 1.0 + 1) * delta);

        if (sign < 0) {
            ZEROS[count] = i * 1.0 * delta;
            count++;
        }
        if (count == n_zero)
            return ZEROS;
    }
    return NULL;
}
float Solution::beta(int i, float* ZEROS)
{
    float BETA = j1_zeros(i, ZEROS)[i - 1] / Anode_Radius;

    return BETA;
}
float Solution::R(int i, float r, float* ZEROS)
{
    float xi = j1_zeros(i, ZEROS)[i - 1];
    float J0_br = _j0(beta(i, ZEROS) * r);
    float J0_xi = _j0(xi);

    float R_func = J0_br / (xi * J0_xi * J0_xi);

    return R_func;
}
float Solution::M(int i, float z, float* ZEROS)
{
    float k = lambda_copper / lambda_tungsten;

    float numerator = sinh(beta(i, ZEROS) * (Anode_Length + z));
    float denominator_1 = sinh(beta(i, ZEROS) * Anode_Length) * sinh(beta(i, ZEROS) * Target_Length);
    float denominator_2 = cosh(beta(i, ZEROS) * Anode_Length) * cosh(beta(i, ZEROS) * Target_Length);
    float denominator = denominator_1 + k * denominator_2;

    float M_func = numerator / denominator;

    return M_func;
}
float Solution::L(int i, float z, float* ZEROS)
{
    float k = lambda_copper / lambda_tungsten;

    float numerator_1 = sinh(beta(i, ZEROS) * Anode_Length) * cosh(beta(i, ZEROS) * z);
    float numerator_2 = cosh(beta(i, ZEROS) * Anode_Length) * sinh(beta(i, ZEROS) * z);
    float numerator = numerator_1 + k * numerator_2;

    float denominator_1 = sinh(beta(i, ZEROS) * Anode_Length) * sinh(beta(i, ZEROS) * Target_Length);
    float denominator_2 = cosh(beta(i, ZEROS) * Anode_Length) * cosh(beta(i, ZEROS) * Target_Length);
    float denominator = denominator_1 + k * denominator_2;

    float L_func = numerator / denominator;

    return L_func;
}
float Solution::exp_function(int i, float* ZEROS)
{
    float xi = j1_zeros(i, ZEROS)[i - 1];
    float indicator = ((0.5 * xi) * (Focal_Spote / Anode_Radius)) * ((0.5 * xi) * (Focal_Spote / Anode_Radius));

    float exp_func = exp(-indicator);

    return exp_func;
}
float Solution::get_Anode_Radius()
{
    return Anode_Radius;
}
float Solution::get_Anode_Length()
{
    return Anode_Length;
}
float Solution::get_Target_Length()
{
    return Target_Length;
}
float Solution::get_Focal_Spote()
{
    return Focal_Spote;
}
int Solution::get_n_zero()
{
    return n_zero;
}
Solution::~Solution() {
    //delete[] ZEROS;
    free(ZEROS);
};
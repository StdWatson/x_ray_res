#include <iostream>
//#include <cmath>

#include "sol_eq.h"

using namespace std;

//float Anode_Radius = 1; // mm
//float Anode_Length = 1; // mm
//float Target_Length = 1; // mm
//float Focal_Spote = 1; // mm

//struct Input_parametrs {
//    float Anode_Radius = 1; // mm
//    float Anode_Length = 1; // mm
//    float Target_Length = 1; // mm
//    float Focal_Spote = 1; // mm
//};

//class Solution {
//private:
//    float Anode_Radius = 1; // mm
//    float Anode_Length = 1; // mm
//    float Target_Length = 1; // mm
//    float Focal_Spote = 1; // mm
//
//    float lambda_copper = 389.6;
//    int lambda_tungsten = 173;
//public:
//    Solution(float Anode_Radius = 1, float Anode_Length = 1, float Target_Length = 1, float Focal_Spote = 1) : Anode_Radius(Anode_Radius),
//                                                                                                                Anode_Length(Anode_Length),
//                                                                                                                Target_Length(Target_Length),
//                                                                                                                Focal_Spote(Focal_Spote) {
//
//    }
//    float* j1_zeros(int n_zero, float* ZEROS)       //n_zero - null number, ZEROS - vector of nulls
//    {
//        int count = 0;
//        float delta = 0.001;
//        int MAX_ITER = 100000;
//
//        float Now_Step = 0;
//        float Future_Step = 0;
//
//        //float* ZEROS = (float*)malloc(sizeof(float) * n_zero);
//
//        for (int i = 0; i < MAX_ITER; i++) {
//            //Now_Step = _j1(i * 1.0 * delta);
//            //Future_Step = _j1((i * 1.0 + 1) * delta);
//            float sign = _j1(i * 1.0 * delta) * _j1((i * 1.0 + 1) * delta);
//
//            if (sign < 0) {
//                ZEROS[count] = i * 1.0 * delta;
//                count++;
//            }
//            if (count == n_zero) {
//                return ZEROS;
//            }
//        }
//        return NULL;
//    }
//
//    float beta(int i, float* ZEROS)
//    {
//        float BETA = j1_zeros(i, ZEROS)[i - 1] / Anode_Radius;
//
//        return BETA;
//    }
//
//    float R(int i, float r, float* ZEROS)
//    {
//        float xi = j1_zeros(i, ZEROS)[i - 1];
//        float J0_br = _j0(beta(i, ZEROS) * r);
//        float J0_xi = _j0(xi);
//
//        float R_func = J0_br / (xi * J0_xi * J0_xi);
//
//        return R_func;
//    }
//
//    float M(int i, float z, float* ZEROS) {
//
//        float k = lambda_copper / lambda_tungsten;
//
//        float numerator = sinh(beta(i, ZEROS) * (Anode_Length + z));
//        float denominator_1 = sinh(beta(i, ZEROS) * Anode_Length) * sinh(beta(i, ZEROS) * Target_Length);
//        float denominator_2 = cosh(beta(i, ZEROS) * Anode_Length) * cosh(beta(i, ZEROS) * Target_Length);
//        float denominator = denominator_1 + k * denominator_2;
//
//        float M_func = numerator / denominator;
//
//        return M_func;
//    }
//
//    float L(int i, float z, float* ZEROS)
//    {
//
//        float k = lambda_copper / lambda_tungsten;
//
//        float numerator_1 = sinh(beta(i, ZEROS) * Anode_Length) * cosh(beta(i, ZEROS) * z);
//        float numerator_2 = cosh(beta(i, ZEROS) * Anode_Length) * sinh(beta(i, ZEROS) * z);
//        float numerator = numerator_1 + k * numerator_2;
//
//        float denominator_1 = sinh(beta(i, ZEROS) * Anode_Length) * sinh(beta(i, ZEROS) * Target_Length);
//        float denominator_2 = cosh(beta(i, ZEROS) * Anode_Length) * cosh(beta(i, ZEROS) * Target_Length);
//        float denominator = denominator_1 + k * denominator_2;
//
//        float L_func = numerator / denominator;
//
//        return L_func;
//    }
//
//    float exp_function(int i, float* ZEROS) {
//
//        float xi = j1_zeros(i, ZEROS)[i - 1];
//        float indicator = ((0.5 * xi) * (Focal_Spote / Anode_Radius)) * ((0.5 * xi) * (Focal_Spote / Anode_Radius));
//
//        float exp_func = exp(-indicator);
//
//        return exp_func;
//    }
//};
int main()
{
    /*int n_zero;
    cout << "input n_zero: " << endl;
    cin >> n_zero;*/
    //float* ZEROS = (float*)malloc(sizeof(float) * n_zero);

    int ch;
    float Anode_Radius, Anode_Length, Target_Length, Focal_Spote;
    int n_zero;

    /*cout << "Input number of zeros: ";
    cin >> n_zero;*/

    //Solution solution(n_zero);
    //Solution* solution = NULL;

    std::cout << "press 1 if you want defoult parametrs" << std::endl;
    /*cout << "defoult parametrs:" << endl;
    cout << "Anode_Radius = " << solution.get_Anode_Radius() << " mm" << endl;
    cout << "Anode_Length = " << solution.get_Anode_Length() << " mm" << endl;
    cout << "Target_Length = " << solution.get_Target_Length() << " mm" << endl;
    cout << "Focal_Spote = " << solution.get_Focal_Spote() << " mm" << endl;*/
    std::cin >> ch;

    if (ch == 1) {
        std::cout << "input numbers in mm" << std::endl;
        std::cout << "Anode_Radius = ";
        std::cin >> Anode_Radius;
        std::cout << "Anode_Length = ";
        std::cin >> Anode_Length;
        std::cout << "Target_Length = ";
        std::cin >> Target_Length;
        std::cout << "Focal_Spote = ";
        std::cin >> Focal_Spote;
        std::cout << "n_zero = ";
        std::cin >> n_zero;

        //solution = Solution::Solution(Anode_Radius, Anode_Length, Target_Length, Focal_Spote, n_zero);
        Solution solution = Solution::Solution(Anode_Radius, Anode_Length, Target_Length, Focal_Spote, n_zero);
        //*solution = Solution::Solution(Anode_Radius, Anode_Length, Target_Length, Focal_Spote, n_zero);
    }
    else {
        Solution solution = Solution::Solution();
        std::cout << "defoult parametrs:" << std::endl;
        std::cout << "Anode_Radius = " << solution.get_Anode_Radius() << " mm" << std::endl;
        std::cout << "Anode_Length = " << solution.get_Anode_Length() << " mm" << std::endl;
        std::cout << "Target_Length = " << solution.get_Target_Length() << " mm" << std::endl;
        std::cout << "Focal_Spote = " << solution.get_Focal_Spote() << " mm" << std::endl;
        std::cout << "Number of zeros = " << solution.get_n_zero() << std::endl;
    }

    //switch(ch) {
    //    case 1:
    //        cout << "input numbers in mm" << endl;
    //        cout << "Anode_Radius = ";
    //        cin >> Anode_Radius;
    //        cout << "Anode_Length = ";
    //        cin >> Anode_Length;
    //        cout << "Target_Length = ";
    //        cin >> Target_Length;
    //        cout << "Focal_Spote = ";
    //        cin >> Focal_Spote;
    //        cout << "n_zero = ";
    //        cin >> n_zero;

    //        //solution = Solution::Solution(Anode_Radius, Anode_Length, Target_Length, Focal_Spote, n_zero);
    //        /*Solution solution = Solution::Solution(Anode_Radius, Anode_Length, Target_Length, Focal_Spote, n_zero);*/
    //        *solution = Solution::Solution(Anode_Radius, Anode_Length, Target_Length, Focal_Spote, n_zero);
    //        break;
    //    default:
    //        //Solution solution = Solution::Solution();
    //        cout << "defoult parametrs:" << endl;
    //        cout << "Anode_Radius = " << solution->get_Anode_Radius() << " mm" << endl;
    //        cout << "Anode_Length = " << solution->get_Anode_Length() << " mm" << endl;
    //        cout << "Target_Length = " << solution->get_Target_Length() << " mm" << endl;
    //        cout << "Focal_Spote = " << solution->get_Focal_Spote() << " mm" << endl;
    //        cout << "Number of zeros = " << solution->get_n_zero() << endl;
    //        break;
    //}
    std::cout << "proga is working" << std::endl;

    return 0;
}
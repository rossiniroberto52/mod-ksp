#include<iostream>
#include<cstdlib>
#include <cmath>
#include "gravity_calc.h"
using namespace std;

void system_pause() {
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #elif defined(__linux__)
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    #endif
}
/**
 * @brief Main entry point for the orbital mechanics calculator program.
 *
 * This program provides a menu-driven interface for performing various orbital mechanics calculations,
 * including:
 *   1. Delta-V calculation for rockets.
 *   2. Gravitational force between a satellite and another body.
 *   3. Angular velocity and orbital period calculations.
 *   4. Time to complete one revolution in orbit.
 *   5. Calculation using Kepler's third law.
 *
 * The user is prompted to select an option and provide the necessary input values for each calculation.
 * The program continues to prompt the user until the "Exit" option is selected.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
    float massF, massE, distance;
    const float mass_terra = 5.972e24;
    float eng_imp, gravity_acell, MassF, MassE;
    int opcao;
    while(true){
        // Limpar tela de forma portável
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif defined(__linux__)
            system("clear");
        #endif

        cout << "==============================================" << endl;
        cout << "opções:" << endl;
        cout << "1) DeltaV calc" << endl;
        cout << "2) satelite gravitational force" << endl;
        cout << "3) angular velocity" << endl;
        cout << "4) time to revolution" << endl;
        cout << "5) third kepler law" << endl;
        cout << "6) Exit" << endl;
        cout << "opção: ";
        cin >> opcao;
        cout << "==============================================" << endl;

        cout << "Mass Full (Kg)" << endl;
        cin >> massF;
        cout << "Mass Empyt (Kg)" <<endl;
        cin >> massE;
        cout << "distance (Km)" << endl;
        cin >> distance;

        if(opcao == 1){
            
            cout << "forca do motor (TEP): " << endl;
            cin >> eng_imp; 
            cout << "aceleracao da gravidade (m/s^2): " << endl;
            cin >> gravity_acell;

            float deltaV = DeltaV_calc(eng_imp, gravity_acell, massF, massE);
            float orbit_needed = reach_orbit_calc(mass_terra, 35);

            cout << "DeltaV: " << deltaV << endl;
            cout << "nescessario para orbita: " << orbit_needed << endl;

            if(orbit_needed > deltaV){
                cout << "não é possivel ir a orbita!" << endl;
            }else{
                cout << "é possivel ir a orbita!" << endl;
            }
            system_pause();
            
        }else if(opcao == 2){
            float gravity_str;
            float res = gravity_art_satelit(massF, massE, distance);
            cout << "força gravitacional do satelite: " << res << endl;
            system_pause();
        }else if(opcao == 3 || opcao == 4 || opcao == 5) {
            if(opcao == 3) {
                float time = orbit_period_time(massF, massE, distance);
                float velocity = angular_velocity_angular_momenty(time);
                cout << "velocity on corpse: " << velocity << " (m/s)" << endl;
                cout << "time to revolution: " << time << " (Hours)" << endl;
                system_pause();
            } else if(opcao == 4) {
                float time = orbit_period_time(massF, massE, distance);
                cout << "time to revolution: " << time << " days" << endl;
                system_pause();
            } else if(opcao == 5) {
                cout << "K = " << thirty_kepler_law(massF, massE, distance) << endl;
                system_pause();
            }
        } else if(opcao == 6) {
            return 0; // Exit the program
        } else {
            cout << "Invalid option!" << endl;
            system_pause();
        }
    }
    
    return 0;
}

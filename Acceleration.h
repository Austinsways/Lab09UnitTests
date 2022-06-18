#pragma once
/* This file Includes all the code for the acceleration class*/
class Acceleration {
	//this is currently stubbed out and will be written later.
public:
	double ddx = 0;
	double ddy = 0;
	double airDensity;
	double forceOnShell = 0;

	Acceleration() {
		//TODO
	};

	double getDDX() {
	};

	double getDDY() {

	};

	double setDDX(int value) {};
	double setDDY(int value) {};

	double calculateAcceleration() {};


	double calculateForceOnShell(double cDrag) {};
};
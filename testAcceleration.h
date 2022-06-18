/*
Written by Austin Eldredge on 6/18/2022
*/

#pragma once
//this is the test counterpart for the acceleration class.
#include "Acceleration.h"
#include "bullet.hpp"
#include <cassert>

class TestAcceleration {
public:
	double ddx; 
	double ddy;
	double forceOnShell;

	//run all the test cases.
	void run() {

		//test constructor
		testDefaultAcceleration();

		//test getters and setter
		testGetDDX();
		testGetDDY();
		testSetDDX();
		testSetDDY();

		//run acceleration claculation tests
		testCalculateAccelerationNegative();
		testCalculateAccelerationExtremelyHigh();
		testCalculateAccelerationPositive();
		testCalculateAccelerationSmallValue();
		testCalculateAccelerationZeros();

		//run Force on shell Calculation tests
		testCalculateForceOnShellPositive();
		testCalculateForceOnShellNegative();
		testCalculateForceOnShellZero();
		testCalculateForceOnShellExtremelyHigh();
		testCalculateForceOnShellSmallValue();
	};
	//testing constructor
	void testDefaultAcceleration() {
		//setup
		Acceleration* acceleration = new Acceleration;
		//the constructor excerszes itself when constructed.

		//verify
		assert(acceleration->ddx == 0);
		assert(acceleration->ddy == 0);
		assert(acceleration->forceOnShell == 0);
		//teardown
		delete acceleration;
	};

	//testing getters
	void testGetDDX() {
		//setup
		Acceleration* acceleration = new Acceleration;
		acceleration->ddx = 0;
		//excersize and verify
		assert(acceleration->getDDX() == 0);
		//teardown
		delete acceleration;
	};
	void testGetDDY() {
		//setup
		Acceleration* acceleration = new Acceleration;
		acceleration->ddy = 0;
		//excersize and verify
		assert(acceleration->getDDY() == 0);
		//teardown
		delete acceleration;
	}
	//testing Setters
	void testSetDDX() {
		//setup
		Acceleration* acceleration = new Acceleration;
		//excersize
		acceleration->setDDX(400);
		//verify
		assert(acceleration->ddx == 400);
		//teardown
		delete acceleration;
	}
	void testSetDDY() {
		//setup
		Acceleration* acceleration = new Acceleration;
		//excersize
		acceleration->setDDX(400);
		//verify
		assert(acceleration->ddx == 400);
		//teardown
		delete acceleration;
	}

	//testing thoroughly the Acceleration class
	void testCalculateAccelerationNegative() {
		//setup
		Acceleration* acceleration = new Acceleration;
		acceleration->forceOnShell = -10;
		//excersize and verify
		assert(acceleration->calculateAcceleration() == -0.214133); 
		//teardown
		delete acceleration;
	};
	void testCalculateAccelerationPositive() {
		//setup
		Acceleration* acceleration = new Acceleration;
		acceleration->forceOnShell = 10;
		//excersize and verify
		assert(acceleration->calculateAcceleration() == 0.214133);
		//teardown
		delete acceleration;
	};
	void testCalculateAccelerationZeros() {
		//setup
		Acceleration* acceleration = new Acceleration;
		acceleration->forceOnShell = 0;
		//execute and verify
		assert(acceleration->calculateAcceleration() == 0.0); 
		//teardown
		delete acceleration;
	};
	void testCalculateAccelerationExtremelyHigh() {
		//setup
		Acceleration* acceleration = new Acceleration;
		acceleration->forceOnShell = 1000000;
		//excersize and verify
		assert(acceleration->calculateAcceleration() == 21413.3); 
		//teardown
		delete acceleration;
	};
	void testCalculateAccelerationSmallValue() {
		//setup
		Acceleration* acceleration = new Acceleration;
		acceleration->forceOnShell = .01;
		//excersize and verify
		assert(acceleration->calculateAcceleration() == 0.000214133); 
		//teardown
		delete acceleration;
	};

	//testing thoroughly the Force on Shell class
	void testCalculateForceOnShellPositive() {
		//setup
		double cDrag = 10;
		Acceleration* acceleration = new Acceleration;
		acceleration->airDensity = 1.2250000;
		acceleration->ddy = 100;
		acceleration->ddx = 100;
		//excersize and verify
		assert(acceleration->calculateForceOnShell(cDrag) == 78930.4);
		//teardown
		delete acceleration;

		
	};
	void testCalculateForceOnShellNegative() {
		//setup
		double cDrag = -10;
		Acceleration* acceleration = new Acceleration;
		acceleration->airDensity = 1.2250000;
		acceleration->ddy = 100;
		acceleration->ddx = 100;
		//excersize and verify
		assert(acceleration->calculateForceOnShell(cDrag) == -78930.4);
		//teardown
		delete acceleration;
		
	};
	void testCalculateForceOnShellZero() {
		//setup
		double cDrag = 0;
		Acceleration* acceleration = new Acceleration;
		acceleration->airDensity = 1.2250000;
		acceleration->ddy = 100;
		acceleration->ddx = 100;
		//excersize and verify
		assert(acceleration->calculateForceOnShell(cDrag) == 0.0);
		//teardown
		delete acceleration;
	};
	void testCalculateForceOnShellExtremelyHigh() {
		//setup
		double cDrag = 100;
		Acceleration* acceleration = new Acceleration;
		acceleration->airDensity = 1.2250000;
		acceleration->ddy = 100;
		acceleration->ddx = 100;
		//excersize and verify
		assert(acceleration->calculateForceOnShell(cDrag) == 789304);
		//teardown
		delete acceleration;
	};
	void testCalculateForceOnShellSmallValue() {
		//setup
		double cDrag = .001;
		Acceleration* acceleration = new Acceleration;
		acceleration->airDensity = 1.2250000;
		acceleration->ddy = 100;
		acceleration->ddx = 100;
		//excersize and verify
		assert(acceleration->calculateForceOnShell(cDrag) == 7.89304);
		//teardown
		delete acceleration;
	};
};
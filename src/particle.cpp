#include "particle.h"
#include <iostream>
#include <fstream>
#include <iomanip>


// Constructors
Particle::Particle() {
	float zero[3];
	zero[0] = zero[1] = zero[2] = 0;
	init(0, zero, zero, 3);
}

Particle::Particle(float mass_) {
	float zero[3];
	zero[0] = zero[1] = zero[2] = 0;
	init(mass_, zero, zero, 3);
}

Particle::Particle(float mass_, float* pos_) {
	float zero[3];
	zero[0] = zero[1] = zero[2] = 0;
	init(mass_, pos_, zero, 3);
}

Particle::Particle(float mass_, float* pos_, float* vel_) {
	init(mass_, pos_, vel_, 3);
}

Particle::Particle(float mass_, float* pos_, float* vel_, unsigned int dimensions_) {
	init(mass_, pos_, vel_, dimensions_);
}

// The 'Real' Constructor
void Particle::init(float mass_, float* pos_, float* vel_, unsigned int dimensions_) {
	mass = mass_;
	dimensions = dimensions_;
	
	pos = new float[dimensions];
	for (unsigned int i = 0; i < dimensions; i++){
		pos[i] = pos_[i];
	}

	vel = new float[dimensions];
	for (unsigned int i = 0; i < dimensions; i++){
		vel[i] = vel_[i];
	}

	force = new float[dimensions];
	for (unsigned int i = 0; i < dimensions; i++){
		force[i] = 0;
	}

	accel = new float[dimensions];
	for (unsigned int i = 0; i < dimensions; i++){
		accel[i] = 0;
	}
}


// Destructor
Particle::~Particle() {
	delete pos;
	delete vel;
	delete force;
	pos = vel = force = NULL;
}


// Accessors
float Particle::getMass() const {
	return mass;
}

float* Particle::getAccel() const {
	return accel;
}

float* Particle::getPos() const {
	return pos;
}

float* Particle::getVel() const {
	return vel;
}


// Mutators
// Adds a force to the stack for superposition
void Particle::applyForce(float* forces) {
	for (unsigned int i = 0; i < dimensions; i++) {
		force[i] += forces[i];
	}
}
// Adds an acceleration, ie gravity
void Particle::applyAcceleration(float* accel_) {
	for (unsigned int i = 0; i < dimensions; i++) {
		accel[i] += accel_[i];
	}
}


// Sets the position of a particle
void Particle::setPos(float* newPos) {
	for (unsigned int i = 0; i < dimensions; i++) {
		pos[i] = newPos[i];
	}
}

// Sets the velocity of a particle
void Particle::setVel(float* newVel) {
	for (unsigned int i = 0; i < dimensions; i++) {
		vel[i] = newVel[i];
	}
}

// Updates the particles kinomatics
void Particle::update(float dt) {
	updateVelocity(dt);
	updatePosition(dt);
	for (unsigned int i = 0; i < dimensions; i++) {
		force[i] = 0;		// Reset all forces on the object to 0
	}
}


// Private
//Calculates the particles acceleration, given current force
void Particle::updateAcceleration() {
	for (unsigned int i = 0; i < dimensions; i++) {
		accel[i] += force[i] / mass;
	}
}

// Calculates the particles velocity, given the current force
void Particle::updateVelocity(float dt) {
	for (unsigned int i = 0; i < dimensions; i++) {
		vel[i] += accel[i] * dt;	// v = a * dt
	}
}

// Claculates the particles position, given current velocities
void Particle::updatePosition(float dt) {
	for (unsigned int i = 0; i < dimensions; i++) {
		pos[i] += vel[i] * dt;		// x = v  * dt
	}
}


// Outside functions
//Print function
std::ostream& operator<<(std::ostream& out, const Particle& p) {
	out << "Particle Mass: " << p.getMass() << std::fixed << std::setprecision(4) ;
	out << "\t\tVelocity: X: " << p.getVel()[0] << "\tY: " << p.getVel()[1] << "\tZ: " << p.getVel()[2];
	out << "\t\tPosition: X: " << p.getPos()[0] << "\tY: " << p.getPos()[1] << "\tZ: " << p.getPos()[2];
	return out;
}

void logParticle(std::ofstream& file, const Particle& p, float time) {
	file << std::fixed << std::setprecision(4) 
	  << time << '\t' << p.getMass() << '\t' << p.getVel()[0] << '\t'
	  << p.getVel()[1] << '\t' << p.getVel()[2] << '\t' << p.getPos()[0]
	  << '\t' << p.getPos()[1] << '\t' << p.getPos()[2] << '\n';
}
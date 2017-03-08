#include "particle.h"
#include <iostream>
#include <fstream>


// Constructors
Particle::Particle() {
	float zero[2];
	zero[0] = zero[1] = 0;
	init(0, zero, zero, 2);
}

Particle::Particle(float mass_) {
	float zero[2];
	zero[0] = zero[1] = 0;
	init(mass_, zero, zero, 2);
}

Particle::Particle(float mass_, float* pos_) {
	float zero[2];
	zero[0] = zero[1] = 0;
	init(mass_, pos_, zero, 2);
}

Particle::Particle(float mass_, float* pos_, float* vel_) {
	init(mass_, pos_, vel_, 2);
}

Particle::Particle(float mass_, float* pos_, float* vel_, unsigned int dimensions_) {
	init(mass_, pos_, vel_, dimensions);
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
}


// Destructor
// Particle::~Particle() {
// 	std::cout << "HIT";
// 	delete pos;
// 	delete vel;
// 	delete force;
// 	pos = vel = force = NULL;
// }


// Accessors
const float Particle::getMass() const {
	return mass;
}

const float* Particle::getPos() const {
	return pos;
}

const float* Particle::getVel() const {
	return vel;
}


// Mutators
// Adds a force to the stack for superposition
void Particle::applyForce(float* forces) {
	for (unsigned int i = 0; i < dimensions; i++) {
		force[i] += forces[i];
		std::cout << i << forces[i];
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
// Calculates the particles velocity, given the current force
void Particle::updateVelocity(float dt) {
	for (unsigned int i = 0; i < dimensions; i++) {
		vel[i] += (force[i] / mass) * dt;	// v = (f/m) * dt
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
	out << "Particle Mass: " << p.getMass();
	out << "\tVelocity: X: " << p.getVel()[0] << " Y: " << p.getVel()[1];
	out << "\tPosition: X: " << p.getPos()[0] << " Y: " << p.getPos()[1];
	return out;
}

void logParticle(std::ofstream& file, const Particle& p, float time) {
	file << time << ' ' << p.getMass() << ' ' << p.getVel()[0] << ' '
	  << p.getVel()[1] << ' ' << p.getPos()[0] << ' ' << p.getPos()[1] << '\n';
}
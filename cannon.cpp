#include "particle.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
	float pos[2] = {1, 1};
	Particle* p = new Particle(1, pos);
	std::cout << *p << std::endl;
	float vel[2] = {0, 1000};
	p -> setVel(vel);
	std::cout << *p << std::endl;
	
	float dt = 0.1;
	float time = 0;
	float gravity[2] = {0, -9.8 * p -> getMass()};
	std::cout << gravity[0];

	std::ofstream log("log.txt");
	logParticle(log, *p, time);

	while (p -> getPos()[1] > 0) {
		p -> applyForce(gravity);
		p -> update(dt);
		logParticle(log, *p, time);
		std::cout << "Time : " << time << " " << *p << std::endl;
		time += dt;
	}


	delete p;
	return 0;
}
#include <math.h>

void foo(float * theta, float * sth) {
	_assume_aligned(theta,, 32);
	_assume_aligned(sth,, 32);	
	for (int i = 0; i < 128; i++) {
		sth[i] = sinf(theta[i] + 3.1415927f); 
	}
}


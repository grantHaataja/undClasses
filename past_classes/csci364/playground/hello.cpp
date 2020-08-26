#include <iostream>
#include <sstream>
#include "omp.h"                      

int main(int argc,char *argv[]) {           
	int id, nthreads;
	
#pragma omp parallel private(id)
	{
		id = omp_get_thread_num();
		std::ostringstream oss;
		oss << "hello from " << id << std::endl;
		std::cout << oss.str();
#pragma omp ordered
	if (id == 0) {
		nthreads = omp_get_num_threads();
		std::cout << "There are " << nthreads << " threads\n" << std::endl;
	}
	}
}                                            

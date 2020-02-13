#include<iostream>
#include<thread>
#include<sstream>

int num_threads = 10;
void hello(int tid) {
	std::ostringstream oss;oss << "Hello from thread " << tid << std::endl;
	std::cout << oss.str();
}

int main(int argc, char *argv[]) {
	// keep track of the threads
	std::thread t[num_threads];
	
	// launch the threads
	for (int i = 0; i < num_threads; i++) {
		t[i] = std::thread(hello, i);
	}

	std::ostringstream oss;
	oss << "Hello from main" << std::endl;
	std::cout << oss.str();

	// have main wait for the hello threads
	for (int i = 0; i < num_threads; i++) {
		t[i].join();
	}

	return 0;
}
